/*****************************************************************
 *
 * This file is part of the GMAPPING project
 *
 * GMAPPING Copyright (c) 2004 Giorgio Grisetti, 
 * Cyrill Stachniss, and Wolfram Burgard
 *
 * This software is licensed under the "Creative Commons 
 * License (Attribution-NonCommercial-ShareAlike 2.0)" 
 * and is copyrighted by Giorgio Grisetti, Cyrill Stachniss, 
 * and Wolfram Burgard.
 * 
 * Further information on this license can be found at:
 * http://creativecommons.org/licenses/by-nc-sa/2.0/
 * 
 * GMAPPING is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied 
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 * PURPOSE.  
 *
 *****************************************************************/


#include "configfile.h"

#include <fstream>
#include <iostream>

#include <string>
#include <sstream>
#include <iostream>
#include <ctype.h>

namespace GMapping{
using namespace std;

AutoVal::AutoVal(std::string const& value) {
  m_value=value;
}

AutoVal::AutoVal(const char* c) {
  m_value=c;
}

AutoVal::AutoVal(double d) {
  std::stringstream s;
  s<<d;
  m_value=s.str();
}

AutoVal::AutoVal(bool d) {
  std::stringstream s;
  if(d)
    s << "on";
  else 
    s << "off";
  m_value=s.str();
}


AutoVal::AutoVal(int i) {
  std::stringstream s;
  s<<i;
  m_value=s.str();
}

AutoVal::AutoVal(unsigned int i) {
  std::stringstream s;
  s<<i;
  m_value=s.str();
}

AutoVal::AutoVal(AutoVal const& other) {
  m_value=other.m_value;
}

AutoVal& AutoVal::operator=(AutoVal const& other) {
  m_value=other.m_value;
  return *this;
}

AutoVal& AutoVal::operator=(double d) {
  std::stringstream s;
  s << d;
  m_value = s.str();
  return *this;
}

AutoVal& AutoVal::operator=(bool d) {
  std::stringstream s;
  if(d)
    s << "on";
  else 
    s << "off";
  m_value = s.str();
  return *this;
}


AutoVal& AutoVal::operator=(int i) {
  std::stringstream s;
  s << i;
  m_value = s.str();
  return *this;
}

AutoVal& AutoVal::operator=(unsigned int i) {
  std::stringstream s;
  s << i;
  m_value = s.str();
  return *this;
}


AutoVal& AutoVal::operator=(std::string const& s) {
  m_value=s;
  return *this;
}

AutoVal::operator std::string() const {
  return m_value;
}

AutoVal::operator double() const {
  return atof(m_value.c_str());
}

AutoVal::operator int() const {
  return atoi(m_value.c_str());
}

AutoVal::operator unsigned int() const {
  return (unsigned int) atoi(m_value.c_str());
}

AutoVal::operator bool() const {
  // stupid c++ does not allow compareNoCase...
  if (toLower(m_value)=="on" || atoi(m_value.c_str()) == 1)
    return true;
  return false;
}

std::string AutoVal::toLower(std::string const& source) const {
  std::string result(source);
  char c='\0';
  for (unsigned int i=0; i<result.length(); i++) {
    c = result[i];
    c = ::tolower(c);
    result[i] = c;
  }
  return result;
}


//////////////////////////////////////////////////////////

ConfigFile::ConfigFile() {
}

ConfigFile::ConfigFile(std::string const& configFile) {
  read(configFile);
}

bool ConfigFile::read(std::string const& configFile) {
  std::ifstream file(configFile.c_str());

  if (!file || file.eof())
    return false;

  std::string line;
  std::string name;
  std::string val;
  std::string inSection;
  while (std::getline(file,line)) {

    if (! line.length()) continue;
    // cute the comments
    if (line[0] == '#') continue;
    line = truncate(line,"#");
    line = trim(line);
    if (! line.length()) continue;
    
    if (line[0] == '[') {
      inSection=trim(line.substr(1,line.find(']')-1));
      continue;
    }
    
    istringstream lineStream(line);
    lineStream >> name;
    lineStream >> val;
    insertValue(inSection,name,val);
  }
  return true;
}

void ConfigFile::insertValue(std::string const& section, std::string const& entry, std::string const& thevalue)  {
  m_content[toLower(section)+'/'+toLower(entry)]=AutoVal(thevalue);
}

AutoVal const& ConfigFile::value(std::string const& section, std::string const& entry) const {

  std::map<std::string,AutoVal>::const_iterator ci = 
    m_content.find(toLower(section) + '/' + toLower(entry));
  if (ci == m_content.end()) throw "entry does not exist";

  return ci->second;
}

AutoVal const& ConfigFile::value(std::string const& section, std::string const& entry, double def) {
  try {
    return value(section, entry);
  } catch(const char *) {
    return m_content.insert(std::make_pair(section+'/'+entry, AutoVal(def))).first->second;
  }
}

AutoVal const& ConfigFile::value(std::string const& section, std::string const& entry, bool def) {
  try {
    return value(section, entry);
  } catch(const char *) {
    return m_content.insert(std::make_pair(section+'/'+entry, AutoVal(def))).first->second;
  }
}

AutoVal const& ConfigFile::value(std::string const& section, std::string const& entry, int def) {
  try {
    return value(section, entry);
  } catch(const char *) {
    return m_content.insert(std::make_pair(section+'/'+entry, AutoVal(def))).first->second;
  }
}

AutoVal const& ConfigFile::value(std::string const& section, std::string const& entry, unsigned int def) {
  try {
    return value(section, entry);
  } catch(const char *) {
    return m_content.insert(std::make_pair(section+'/'+entry, AutoVal(def))).first->second;
  }
}

AutoVal const& ConfigFile::value(std::string const& section, std::string const& entry, std::string const& def) {
  try {
    return value(section, entry);
  } catch(const char *) {
    return m_content.insert(std::make_pair(section+'/'+entry, AutoVal(def))).first->second;
  }
}

void ConfigFile::dumpValues(std::ostream& out) {

  for (std::map<std::string,AutoVal>::const_iterator it = m_content.begin();
       it != m_content.end(); it++) {
    out << (std::string) it->first << " " << (std::string)it->second << std::endl;
  }
}


std::string ConfigFile::trim(std::string const& source, char const* delims) const {
  std::string result(source);
  std::string::size_type index = result.find_last_not_of(delims);
  if(index != std::string::npos)
    result.erase(++index);

  index = result.find_first_not_of(delims);
  if(index != std::string::npos)
    result.erase(0, index);
  else
    result.erase();
  return result;
}

std::string ConfigFile::truncate(std::string const& source, const char* atChar) const {
  std::string::size_type index = source.find_first_of(atChar);

  if(index == 0) 
    return "";
  else if(index == std::string::npos) {
    return source;
  }
  return 
    source.substr(0,index);
}

std::string ConfigFile::toLower(std::string const& source) const {
  std::string result(source);
  char c='\0';
  for (unsigned int i=0; i<result.length(); i++) {
    c = result[i];
    c = ::tolower(c);
    result[i] = c;
  }
  return result;
}
};
