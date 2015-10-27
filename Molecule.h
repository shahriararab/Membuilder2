//
//  Molecule.h
//  lipid-test2
//
//  Created by saman on 10/7/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef lipid_test2_Molecule_h
#define lipid_test2_Molecule_h

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class Molecule{
public: 
    vector<double> atomX;
    vector<double> atomY;
    vector<double> atomZ;
    vector<string> atomName;
    vector<string> moleculeName;
    string moleculeNativeName;
    int number;
    
    int numberOfAtoms;
    
    Molecule( char*, string nativeName, int number );
    Molecule( );
    ~Molecule();
    
    void printResult();
    double maxZ( );
    
};

#endif
