//
//  Molecule.cpp
//  lipid-test2
//
//  Created by saman on 10/7/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "Molecule.h"

Molecule::Molecule( char* PDBFileName, string nativeName, int number ){
    
    numberOfAtoms = 0;
    
    int in;
    
    ifstream inFile( PDBFileName, fstream::in );
    if( !inFile.is_open() ){
        cout << "cannot open the file with name: " << PDBFileName << endl;
    }
    
    moleculeNativeName = nativeName;
    this->number = number;
    
    double prevX = 0;
    double prevY = 0;
    double prevZ = 0;
    
    while( !inFile.eof() ){
        
        //cout << "we are in while." << endl;
        
        string ATOM;
        inFile >> ATOM;
        
        int atomNumber;
        inFile >> atomNumber;
        
        string atomName;
        inFile >> atomName;
        
        string molecule;
        inFile >> molecule;
        
        char chain;
        inFile >> chain;
        
        int moleculeNumber;
        inFile >> moleculeNumber;
        
        double X;
        inFile >> X;
        double Y;
        inFile >> Y;
        double Z;
        inFile >> Z;
        
        //cout << ATOM << " " << atomNumber << " " << atomName << " " << molecule << " " << chain << " " << moleculeNumber << " " <<  X << " " << Y << " " << " " << Z << endl;
        
        if( X != prevX || Y != prevY || Z != prevZ ){
            atomX.push_back(X);
            atomY.push_back(Y);
            atomZ.push_back(Z);
            (this->atomName).push_back( atomName );
            (this->moleculeName).push_back( molecule );
            numberOfAtoms++;
            
            //cout << "something has been pushed." << endl;
        }
        else{
            break;
        }
        
        prevX = X;
        prevY = Y;
        prevZ = Z;
        
    }
    
    //cout << "end of reading the molecule file." << endl;
    //cin >> in;
    
    inFile.close();
    
}

Molecule::Molecule( ){
    
}

void Molecule::printResult(){
    
    for( int i = 0; i < numberOfAtoms; i++ ){
        cout << "ATOM " << i << " " << atomName.at(i) << " " << moleculeName.at(i) << " " << atomX.at(i) << " " << atomY.at(i) << " " << atomZ.at(i) << endl;
    }
    
}

Molecule::~Molecule(){
    
}

double Molecule::maxZ(){
    
    double max = 0;
    
    for( int i = 0; i < numberOfAtoms; i++ ){
        if( atomZ.at(i) > max )
            max = atomZ.at(i);
    }
    
    return max;
    
}