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



#include <iostream>
#include "configfile.h"

using namespace std;
using namespace GMapping;

int main(int argc, char** argv) {

  if (argc != 2) {
    cerr << "Usage:  " << argv[0] << " [initifle]" << endl;
    exit(0);
  }
  
  ConfigFile cfg;
  cfg.read(argv[argc-1]);

  cout << "-- values from configfile --" << endl;
  cfg.dumpValues(cout);

  cout << "-- adding a value --" << endl;
  cfg.value("unkown","unkown","the new value!");

  cout << "-- values from configfile & added values --" << endl;
  cfg.dumpValues(cout);

  return 0;
}
