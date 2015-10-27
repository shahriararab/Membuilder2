//
//  InputParser.h
//  lipid-test2
//
//  Created by saman on 11/10/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef lipid_test2_InputParser_h
#define lipid_test2_InputParser_h

#include <vector>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>

using namespace std;

class InputParser{
public:
    
    vector<string> moleculeDestinations;
    vector<int> upPercents;
    vector<int> downPercents;
    vector<string> moleculeNames;
    
    int gridWidth;
    int gridHeight;
    int moleculeWidth;
    int moleculeHeight;
    int layersDistance;
    
    int size;
    
    
    InputParser( char* fileDestination );
    ~InputParser();
    
    void printResult();
    
};


#endif
