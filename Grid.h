//
//  Grid.h
//  lipid-test2
//
//  Created by saman on 10/7/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef lipid_test2_Grid_h
#define lipid_test2_Grid_h

#include <iostream>
#include <vector>
#include <string>
#include "Molecule.h"
#include "Distributer.h"
#include "InputParser.h"

using namespace std;

class Grid{
public:
    
    vector< vector< Molecule> > myGridUpLayer;
    vector< vector< Molecule> > myGridDownLayer;
    
    double realWidth;
    double realHeight;
    int width;
    int height;
    
    double moleculeWidth;
    double moleculeHeight;
    
    //Grid( double realWidth, double realHeight, double moleculeWidth, double moleculeHeight, char* moleculeAddress1,  char* moleculeAddress2, char* moleculeAddress3, char* moleculeAddress4, char* moleculeAddress5, char* moleculeAddress6, char* moleculeAddress7, char* moleculeAddress8, Distributer* myDistributer, float LayersDistance);
    
    Grid( float realWidth, float realHeight, float moleculeWidth, float moleculeHeight, InputParser myInputParser, Distributer* myDistributer, float LayersDistance ); 
    
    ~Grid();
    
    void printGridInFile( string, InputParser );
    void printGridInFileSequential( string, InputParser );  
    void printGridInScreen( );
    
};

#endif
