//
//  InputParser.cpp
//  lipid-test2
//
//  Created by saman on 11/10/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "InputParser.h"

#define DEBUG_MODE 0
 

InputParser::InputParser( char* fileDestination ){
    
    ifstream inFile( fileDestination, fstream::in );
    if( !inFile.is_open() ){
        cout << "cannot open the file with name: " << fileDestination << endl;
      return;
    }
    
    size = 0;
    
    if( DEBUG_MODE )
        cout << "it is open" << endl;
    
    
    while( !inFile.eof() ){
        
        string moleculeDestination;
        inFile >> moleculeDestination;
        
        if( moleculeDestination == "*" ) break;
        
        int upPercent;
        inFile >> upPercent;
        
        int downPercent;
        inFile >> downPercent;
        
        string moleculeName;
        inFile >> moleculeName;
        
        if( moleculeDestination == "" || moleculeName == "" )
            break;
        
        moleculeDestinations.push_back(moleculeDestination);
        upPercents.push_back(upPercent);
        downPercents.push_back(downPercent);
        moleculeNames.push_back(moleculeName);
        size++;
        
        if( DEBUG_MODE ){
            cout << moleculeDestination << " " << upPercent << " " << downPercent << " " << moleculeName << endl;
        } 
        
    }
    
    inFile >> gridWidth >> gridHeight >> moleculeWidth >> moleculeHeight >> layersDistance;
   
}

void InputParser::printResult(){
    
    
    for( int i = 0; i < size; i++ ){
        cout << moleculeDestinations.at(i) << " " << upPercents.at(i) << " " << downPercents.at(i) << " " << moleculeNames.at(i) << endl;
    }
    
}

InputParser::~InputParser(){
    
    
}
