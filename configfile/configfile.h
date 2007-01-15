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


#ifndef CONFIGFILE_H
#define CONFIGFILE_H

#include <iostream>
#include <string>
#include <map>

namespace GMapping{

class AutoVal {
public:
  AutoVal() {};
  explicit AutoVal(const std::string&);
  explicit AutoVal(double);
  explicit AutoVal(int);
  explicit AutoVal(unsigned int);
  explicit AutoVal(bool);
  explicit AutoVal(const char*);

  AutoVal(const AutoVal&);
  AutoVal& operator=(AutoVal const&);

  AutoVal& operator=(double);
  AutoVal& operator=(int);
  AutoVal& operator=(unsigned int);
  AutoVal& operator=(bool);
  AutoVal& operator=(std::string const&);

public:
  operator std::string() const;
  operator double() const;
  operator int() const;
  operator unsigned int() const;
  operator bool() const;

protected:
  std::string toLower(std::string const& source) const;

private:
  std::string m_value;
};

class ConfigFile {
  std::map<std::string,AutoVal> m_content;
  
public:
  ConfigFile();
  ConfigFile(std::string const& configFile);

  bool read(std::string const& configFile);
  
 
  AutoVal const& value(std::string const& section, 
			 std::string const& entry) const;

  AutoVal const& value(std::string const& section, 
			 std::string const& entry, 
			 double def);

  AutoVal const& value(std::string const& section, 
			 std::string const& entry, 
			 bool def);

  AutoVal const& value(std::string const& section, 
			 std::string const& entry, 
			 int def);

  AutoVal const& value(std::string const& section, 
			 std::string const& entry, 
			 unsigned int def);

  AutoVal const& value(std::string const& section, 
			 std::string const& entry, 
			 std::string const& def);

  void dumpValues(std::ostream& out);


 protected:
  std::string trim(std::string const& source, char const* delims = " \t\r\n") const;
  std::string truncate(std::string const& source, const char* atChar) const;
  std::string toLower(std::string const& source) const;
  void insertValue(std::string const& section, std::string const& entry, std::string const& thevalue );
};

};

#endif
