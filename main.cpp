//
//  main.cpp
//  lipid-test2
//
//  Created by saman on 10/7/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "Molecule.h"
#include "Grid.h"
#include "Distributer.h"
#include "InputParser.h"


using namespace std;


int main (int argc, char * argv[])
{
    
    int in;
    
    InputParser myInputParser( argv[1] );
    //myInputParser.printResult();
    
    //cout << "Input parser." << endl;
    
    //InputParser myInputParser( argv, argc );
    
    /*
    if( argc != 23 ){
        cout << "wrong number of inputs." << endl;
        exit( 0 );
    }
    
     
    
    
    if( atoi( argv[1] ) + atoi( argv[2] ) + atoi( argv[3] ) + atoi( argv[4] ) + atoi( argv[5] ) + atoi( argv[6] ) + atoi( argv[7] ) + atoi( argv[8] ) != 100 ){
        cout << "wrong inputs1: sum of all must be 100%." << endl;
        return 0;
    }
    
    if( atoi( argv[9] ) + atoi( argv[10] ) + atoi( argv[11] ) + atoi( argv[12] ) + atoi( argv[13] ) + atoi( argv[14] ) + atoi( argv[15] ) + atoi( argv[16] ) != 100 ){
        cout << "wrong inputs2: sum of all must be 100%." << endl;
        return 0;
    }
    */
    
    //Distributer myDistributer( atoi( argv[1] ), atoi( argv[2] ), atoi( argv[3] ), atoi( argv[4] ), atoi( argv[5] ), atoi( argv[6] ), atoi( argv[7] ), atoi( argv[8] ), atoi( argv[9] ), atoi( argv[10] ), atoi( argv[11] ), atoi( argv[12] ), atoi( argv[13] ), atoi( argv[14] ), atoi( argv[15] ), atoi( argv[16] ), atoi( argv[17] ) * atoi( argv[19] ), atoi( argv[18] ) * atoi( argv[20] ), atoi( argv[19] ), atoi( argv[20] ) );
   
    Distributer myDistributer( myInputParser, myInputParser.gridWidth * myInputParser.moleculeWidth, myInputParser.gridHeight * myInputParser.moleculeHeight, myInputParser.moleculeWidth, myInputParser.moleculeHeight );
    
    //cout << "Distributer." << endl;
    
    
    //Distributer myDistributer( 10, 20, 30, 40, 25, 25, 25, 25, 150, 150, 15, 15 );
    
    /*
     cout << "MESSAGE: Distributer distibiutes: " << endl;
     cout << "MESSAGE: POPGU=>" << myDistributer.numberOfPOPGU << " ";
     cout << "MESSAGE: POPCU=>" << myDistributer.numberOfPOPCU << " ";
     cout << "MESSAGE: POPEU=>" << myDistributer.numberOfPOPEU << " ";
     cout << "MESSAGE: DPPCU=>" << myDistributer.numberOfDPPCU << endl;
     
     cout << "MESSAGE: POPGD=>" << myDistributer.numberOfPOPGD << " ";
     cout << "MESSAGE: POPCD=>" << myDistributer.numberOfPOPCD << " ";
     cout << "MESSAGE: POPED=>" << myDistributer.numberOfPOPED << " ";
     cout << "MESSAGE: POPCD=>" << myDistributer.numberOfDPPCD << endl;
     
     cin >> in;
     */
    
    
    Grid myGrid( myInputParser.gridWidth * myInputParser.moleculeWidth , myInputParser.gridHeight * myInputParser.moleculeHeight, myInputParser.moleculeWidth , myInputParser.moleculeHeight, myInputParser, &myDistributer, myInputParser.layersDistance );
    
    //cout << "Grid" << endl;
    
    myGrid.printGridInFile( argv[2], myInputParser );
    myGrid.printGridInFileSequential(argv[3], myInputParser );
    
    //cout << "print in file." << endl;
    //myGrid.printGridInScreen();
    
    return 0;
    
}