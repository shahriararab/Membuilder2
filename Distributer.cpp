//
//  Distributer.cpp
//  lipid-test2
//
//  Created by saman on 10/25/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "Distributer.h"
#include <stdlib.h>
#include <algorithm>
using namespace std;

#define DEBUG_MODE 0


Distributer::Distributer( InputParser myInputParser, float realWidth, float realHeight, float moleculeWidth, float moleculeHeight ){
    
    
    int width = realWidth / moleculeWidth;
    int height = realHeight / moleculeHeight;
    
    int totalNumberOfCells = width * height;
    
    int totalNumberOfUps = 0;
    int totalNumberOfDowns = 0;
    
    //cout << width << " " << height << endl;
    
    
    for( int i = 0; i < myInputParser.size; i++ ){
        numberUps.push_back( myInputParser.upPercents.at(i) );
        numberDowns.push_back( myInputParser.downPercents.at(i) );
        
        if( DEBUG_MODE )
            cout << numberUps.at(i) << " " << numberDowns.at(i) << endl;
        
        totalNumberOfUps = totalNumberOfUps + numberUps.at(i);
        totalNumberOfDowns = totalNumberOfDowns + numberDowns.at(i);
    }
    
    for( int i = 0; i < numberUps.size(); i++ ){
        for( int j = 0; j < numberUps.at(i); j++ )
            distributionUps.push_back(i);
    }
    
    for( int i = 0; i < numberDowns.size(); i++ ){
        for( int j = 0; j < numberDowns.at(i); j++ )
            distributionDowns.push_back(i);
    }

    
    random_shuffle( distributionUps.begin(), distributionUps.end() );
    random_shuffle( distributionDowns.begin(), distributionDowns.end() );
    
    cout << "hello" << endl;
    cout << distributionDowns.size() << endl;
    cout << distributionUps.size() << endl;
    
    
    
    if( totalNumberOfUps != totalNumberOfCells ){
        
        cout << "ERROR: something wrong happend." << endl;
        cout << "ERROR: number of prefered atoms doesn't equal to number of grid cells." << endl;
        exit( 0 );
        
    }
    
    
    if( totalNumberOfDowns != totalNumberOfCells ){
        
        cout << "ERROR: something wrong happend." << endl;
        cout << "ERROR: number of prefered atoms doesn't equal to number of grid cells." << endl;
        exit( 0 );
        
    }
    
    
}

int Distributer::getMoleculeChoiceU( InputParser myInputParser ){
    
    cout << "up" << endl;
    
    int k = 0;
    
    while( 1 ){
        
        //k = rand() % myInputParser.size;
        
        k = rand() % distributionUps.size();
        cout << k << endl;
        cout << distributionUps.at(28) << endl;
        
        if( distributionUps.at(k) != -1 ){
            int temp = distributionUps.at(k);
            distributionUps.at(k) = -1;
            return temp;
        }
        else{
            continue;
        }
        
    }
}

int Distributer::getMoleculeChoiceD( InputParser myInputParser ){
    
    cout << "down" << endl;
    
    int k = 0;
    
    while( 1 ){
        
        //k = rand() % myInputParser.size;
        
        k = rand() % distributionDowns.size();
        
        if( distributionDowns.at(k) != -1 ){
            int temp = distributionDowns.at(k);
            distributionDowns.at(k) = -1;
            //numberDowns.at(k)--;
            return temp;
        }
        else{
            continue;
        }
        
    }
}


Distributer::~Distributer(){
    
}
