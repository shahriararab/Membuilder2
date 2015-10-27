//
//  Distributer.h
//  lipid-test2
//
//  Created by saman on 10/25/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef lipid_test2_Distributer_h
#define lipid_test2_Distributer_h

#include <vector>
#include "InputParser.h"

class Distributer{
public:
    
    /*
    
    int numberOfPOPGU;
    int numberOfPOPCU;
    int numberOfPOPEU;
    int numberOfDPPCU;
    int numberOfCholesterolU;
    int numberOfDMPCU;
    int numberOfDMTAPU;
    int numberOfDOPCU;
    
    int numberOfPOPGD;
    int numberOfPOPCD;
    int numberOfPOPED;
    int numberOfDPPCD;
    int numberOfCholesterolD;
    int numberOfDMPCD;
    int numberOfDMTAPD;
    int numberOfDOPCD;
    
    */
    
    vector<int> numberUps;
    vector<int> numberDowns;
    
    vector<int> distributionUps;
    vector<int> distributionDowns;
     
    //Distributer( float POPGPercU, float POPCPercU, float POPEPercU, float DPPCPercU, float cholesterolPercU, float DMPCPercU, float DMTAPPercU, float DOPCPercU, float POPGPercD, float POPCPercD, float POPEPercD, float DPPCPercD, float cholesterolPercD, float DMPCPercD, float DMTAPPercD, float DOPCPercD, double realWidth, double realHeight, double moleculeWidth, double moleculeHeight );
    
    Distributer( InputParser, float, float, float, float );
    
    ~Distributer();
    
    int getMoleculeChoiceU( InputParser );
    int getMoleculeChoiceD( InputParser );
    
};

#endif
