//
//  Grid.cpp
//  lipid-test2
//
//  Created by saman on 10/7/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//


#include "Grid.h"
#include <stdlib.h>
#include <math.h>
#define DEBUG_MODE 0

Grid::Grid( float realWidth, float realHeight, float moleculeWidth, float moleculeHeight, InputParser myInputParser, Distributer* myDistributer, float LayersDistance ){
    
    int in;
    
    this->realWidth = realWidth;
    this->realHeight = realHeight;
    this->moleculeWidth = moleculeWidth;
    this->moleculeHeight = moleculeHeight;
    
    this->width = realWidth / moleculeWidth;
    this->height = realHeight / moleculeHeight;
    
    for( int i = 0; i < width; i++ ){
        myGridUpLayer.push_back( vector<Molecule>() );
        myGridDownLayer.push_back( vector<Molecule>() );
    }
    
    if( DEBUG_MODE )
        cout << "Width is: " << this->width << " and Height: " << this->height << endl;
    
    
    vector<Molecule> sampleMolecules;
    
    
    for( int i = 0; i < myInputParser.size; i++ ){
        
        Molecule sampleMolecule( (char*)myInputParser.moleculeDestinations.at(i).c_str(), myInputParser.moleculeNames.at(i), i );
        sampleMolecules.push_back( sampleMolecule );
        
    }
    
    /*
    Molecule sampleMoleculePOPG( moleculeAddress1, "POPG" );
    Molecule sampleMoleculePOPC( moleculeAddress2, "POPC" );
    Molecule sampleMoleculeDPPC( moleculeAddress3, "DPPC" );
    Molecule sampleMoleculePOPE( moleculeAddress4, "POPE" );
    Molecule sampleMoleculeCHOLESTROL( moleculeAddress5, "CHOLESTROL" );
    Molecule sampleMoleculeDMPC( moleculeAddress6, "DMPC" );
    Molecule sampleMoleculeDMTAP( moleculeAddress7, "DMTAP" );
    Molecule sampleMoleculeDOPC( moleculeAddress8, "DOPC" ); 
    */
    
    
    if( DEBUG_MODE ){
        
        for( int i = 0; i < myInputParser.size; i++ ){
            cout << "molecule" << endl;
            sampleMolecules.at(i).printResult();
            cout << "number of atom " << sampleMolecules.at(i).moleculeNativeName << endl;
        }
        
    }
    
    /*
    if( DEBUG_MODE ){
        cout << "molecule" << endl;
        sampleMoleculePOPG.printResult();
        cout << "number of atom POPG is: " << sampleMoleculePOPG.numberOfAtoms << endl;
        //cin >> in;
    }
    
    if( DEBUG_MODE ){
        cout << "molecule" << endl;
        sampleMoleculePOPC.printResult();
        cout << "number of atom POPC is: " << sampleMoleculePOPC.numberOfAtoms << endl;
    }
    
    if( DEBUG_MODE ){
        cout << "molecule" << endl;
        sampleMoleculeDPPC.printResult();
        cout << "number of atom DPPC is: " << sampleMoleculeDPPC.numberOfAtoms << endl;
    }
    
    if( DEBUG_MODE ){
        cout << "molecule" << endl;
        sampleMoleculePOPE.printResult();
        cout << "number of atoms POPE is: " << sampleMoleculePOPE.numberOfAtoms << endl;
    }
    
    if( DEBUG_MODE ){
        cout << "molecule" << endl;
        sampleMoleculeCHOLESTROL.printResult();
        cout << "number of atoms CHOLESTROL is: " << sampleMoleculeCHOLESTROL.numberOfAtoms << endl;
    }
    
    if( DEBUG_MODE ){
        cout << "molecule" << endl;
        sampleMoleculeDMPC.printResult();
        cout << "number of atoms DMPC is: " << sampleMoleculeDMPC.numberOfAtoms << endl;
    }
    
    if( DEBUG_MODE ){
        cout << "molecule" << endl;
        sampleMoleculeDMTAP.printResult();
        cout << "number of atoms DMTAP is: " << sampleMoleculeDMTAP.numberOfAtoms << endl;
    }
    
    if( DEBUG_MODE ){
        cout << "molecule" << endl;
        sampleMoleculeDOPC.printResult();
        cout << "number of atoms DOPC is: " << sampleMoleculeDOPC.numberOfAtoms << endl;
    }
     
    */
    // cout << width << " " << height << endl;
    
    for( int i = 0; i < width; i++ ){
        for( int j = 0; j < height; j++ ){
            
            int randChoice = myDistributer->getMoleculeChoiceU( myInputParser );
            
            myGridUpLayer.at(i).push_back(sampleMolecules.at(randChoice));
            
            /*
            if( randChoice == 0 ){
                //cout << "POPG selected." << endl;
                myGridUpLayer.at(i).push_back( sampleMoleculePOPG );
            }
            else if( randChoice == 1 ){
                //cout << "POPC selected." << endl;
                myGridUpLayer.at(i).push_back( sampleMoleculePOPC );
            }
            else if( randChoice == 2 ){
                //cout << "POPE selected." << endl;
                myGridUpLayer.at(i).push_back( sampleMoleculePOPE );
            }
            else if( randChoice == 3 ){
                //cout << "DPPC selected." << endl;
                myGridUpLayer.at(i).push_back( sampleMoleculeDPPC );
            }
            else if( randChoice == 4 ){
                myGridUpLayer.at(i).push_back( sampleMoleculeCHOLESTROL );
            }
            else if( randChoice == 5 ){
                myGridUpLayer.at(i).push_back( sampleMoleculeDMPC );
            }
            else if( randChoice == 6 ){
                myGridUpLayer.at(i).push_back( sampleMoleculeDMTAP );
            }
            else if( randChoice == 7 ){
                myGridUpLayer.at(i).push_back( sampleMoleculeDOPC ); 
            }
             
            */ 
        }
    }
    
    for( int i = 0; i < width; i++ ){
        for( int j = 0; j < height; j++ ){
            
            int randChoice = myDistributer->getMoleculeChoiceD(myInputParser);
            
            myGridDownLayer.at(i).push_back(sampleMolecules.at(randChoice));
            
            /*
            if( randChoice == 0 ){
                //cout << "POPG selected." << endl;
                myGridDownLayer.at(i).push_back( sampleMoleculePOPG );
            }
            else if( randChoice == 1 ){
                //cout << "POPC selected." << endl;
                myGridDownLayer.at(i).push_back( sampleMoleculePOPC );
            }
            else if( randChoice == 2 ){
                //cout << "POPE selected." << endl;
                myGridDownLayer.at(i).push_back( sampleMoleculePOPE );
            }
            else if( randChoice == 3 ){
                //cout << "DPPC selected." << endl;
                myGridDownLayer.at(i).push_back( sampleMoleculeDPPC );
            }
            else if( randChoice == 4 ){
                myGridDownLayer.at(i).push_back( sampleMoleculeCHOLESTROL );
            }
            else if( randChoice == 5 ){
                myGridDownLayer.at(i).push_back( sampleMoleculeDMPC );
            }
            else if( randChoice == 6 ){
                myGridDownLayer.at(i).push_back( sampleMoleculeDMTAP );
            }
            else if( randChoice == 7 ){
                myGridDownLayer.at(i).push_back( sampleMoleculeDOPC ); 
            }
            */
        }
    }
    
    //cout << "calculating maxZ" << endl;
    //cin >> in;
    
    /*
    float maxZPOPG = sampleMoleculePOPG.maxZ();
    float maxZPOPC = sampleMoleculePOPC.maxZ();
    float maxZPOPE = sampleMoleculePOPE.maxZ();
    float maxZDPPC = sampleMoleculeDPPC.maxZ();
    float maxZCHOLESTROL = sampleMoleculeCHOLESTROL.maxZ();
    float maxZDMPC = sampleMoleculeDMPC.maxZ();
    float maxZDMTAP = sampleMoleculeDMTAP.maxZ();
    float maxZDOPC = sampleMoleculeDOPC.maxZ();
    */
    float maxZ = sampleMolecules.at(0).maxZ();
    /*
    if( maxZ < maxZDPPC )
        maxZ = maxZDPPC;
    if( maxZ < maxZPOPC )
        maxZ = maxZPOPC;
    if( maxZ < maxZPOPE )
        maxZ = maxZPOPE;
    if( maxZ < maxZCHOLESTROL )
        maxZ = maxZCHOLESTROL;
    if( maxZ < maxZDMPC )
        maxZ = maxZDMPC;
    if( maxZ < maxZDMTAP )
        maxZ = maxZDMTAP;
    if( maxZ < maxZDOPC )
        maxZ = maxZDOPC;
     */
    
    for( int i = 0; i < myInputParser.size; i++ ){
        if( maxZ < sampleMolecules.at(i).maxZ() )
            maxZ = sampleMolecules.at(i).maxZ();
    }
    
    
    //cout << maxZ << endl;
    
    //cout << "modifying the down layer." << endl;
    
    for( int i = 0; i < width; i++ ){
        for( int j = 0; j < height; j++ ){
            double shiftInWidth = 0;
            double shiftInHeight = 0;
            
            shiftInWidth = moleculeWidth * i;
            shiftInHeight = moleculeHeight * j;
            
            int numberOfAtoms = myGridDownLayer.at(i).at(j).numberOfAtoms;
            //cout << numberOfAtoms << endl;
            //cin >> in;
            for( int k = 0; k <numberOfAtoms; k++ ){
            randomRotateAroundZ(myGridDownLayer.at(i).at(j).atomX.at(k),
                                    myGridDownLayer.at(i).at(j).atomY.at(k));
                myGridDownLayer.at(i).at(j).atomX.at(k) += shiftInWidth;
                myGridDownLayer.at(i).at(j).atomY.at(k) += shiftInHeight;
                myGridDownLayer.at(i).at(j).atomZ.at(k) -= maxZ;
                myGridDownLayer.at(i).at(j).atomZ.at(k) -= LayersDistance/2;
            }
        }
    }
    
    //cout << "modifying the up layer." << endl;
    
    for( int i = 0; i < width; i++ ){
        for( int j = 0; j < height; j++ ){
            double shiftInWidth = 0;
            double shiftInHeight = 0;
            
            shiftInWidth = moleculeWidth * i;
            shiftInHeight = moleculeHeight * j;
            
            int numberOfAtoms = myGridUpLayer.at(i).at(j).numberOfAtoms;
            for( int k = 0; k < numberOfAtoms; k++ ){
                randomRotateAroundZ(myGridUpLayer.at(i).at(j).atomX.at(k),
                                    myGridUpLayer.at(i).at(j).atomY.at(k));
                myGridUpLayer.at(i).at(j).atomY.at(k) *= -1;
                myGridUpLayer.at(i).at(j).atomX.at(k) += shiftInWidth;
                myGridUpLayer.at(i).at(j).atomY.at(k) += shiftInHeight;
                myGridUpLayer.at(i).at(j).atomZ.at(k) *= -1;
                myGridUpLayer.at(i).at(j).atomZ.at(k) += maxZ;
                myGridUpLayer.at(i).at(j).atomZ.at(k) += LayersDistance/2;
            }
        }
    }
    
}

void Grid::randomRotateAroundZ(double& x, double& y){
    float teta = rand() * 360.0f / RAND_MAX;
    x = cos(teta)*x - sin(teta)*y;
    y = sin(teta)*x + cos(teta)*y;
}

void Grid::printGridInFile( string destination, InputParser myInputParser ){
    
    //cout << "we are in print grid in file" << endl;
    //int in;
    
    /*
    vector< int > dppcsX;
    vector< int > dppcsY;
    vector< int > dppcPlace;
    
    vector< int > popcsX;
    vector< int > popcsY;
    vector< int > popcPlace;
    
    vector< int > popesX;
    vector< int > popesY;
    vector< int > popePlace;
    
    vector< int > popgsX;
    vector< int > popgsY;
    vector< int > popgPlace;
    
    vector< int > cholestrolsX;
    vector< int > cholestrolsY;
    vector< int > cholestrolsPlace;
    
    vector< int > dmpcsX;
    vector< int > dmpcsY;
    vector< int > dmpcsPlace;
    
    vector< int > dmtapsX;
    vector< int > dmtapsY;
    vector< int > dmtapsPlace;
    
    vector<int> dopcsX;
    vector<int> dopcsY;
    vector<int> dopcsPlace;
    */
    
    vector< vector<int> > X;
    for( int i = 0; i < myInputParser.size; i++ ) 
        X.push_back( vector<int>() );
    vector< vector<int> > Y;
    for( int i = 0; i < myInputParser.size; i++ ) 
        Y.push_back( vector<int>() );
    vector< vector<int> > place;
    for( int i = 0; i < myInputParser.size; i++ )
        place.push_back( vector<int>() );
    
    
    
    for( int i = 0; i < width; i++ ){
        for( int j = 0; j < height; j++ ){
            
            int randNumberTemp = rand() % myInputParser.size;
            
            X.at( randNumberTemp ).push_back(i);
            Y.at( randNumberTemp ).push_back(j);
            place.at( randNumberTemp ).push_back(0);
            
            /*
            if( myGridUpLayer.at(i).at(j).moleculeNativeName == "DPPC" ){
                dppcsX.push_back(i);
                dppcsY.push_back(j);
                dppcPlace.push_back(0);
            }
            else if( myGridUpLayer.at(i).at(j).moleculeNativeName == "POPC" ){
                popcsX.push_back(i);
                popcsY.push_back(j);
                popcPlace.push_back(0);
            }
            else if( myGridUpLayer.at(i).at(j).moleculeNativeName == "POPE" ){
                popesX.push_back(i);
                popesY.push_back(j);
                popePlace.push_back(0);
            }
            else if( myGridUpLayer.at(i).at(j).moleculeNativeName == "POPG" ){
                popgsX.push_back(i);
                popgsY.push_back(j);
                popgPlace.push_back(0);
            }
            else if( myGridUpLayer.at(i).at(j).moleculeNativeName == "CHOLESTROL" ){
                cholestrolsX.push_back(i);
                cholestrolsY.push_back(j);
                cholestrolsPlace.push_back(0);
            }
            else if( myGridUpLayer.at(i).at(j).moleculeNativeName == "DMPC" ){
                dmpcsX.push_back(i);
                dmpcsY.push_back(j);
                dmpcsPlace.push_back(0);
            }
            else if( myGridUpLayer.at(i).at(j).moleculeNativeName == "DMTAP" ){
                dmtapsX.push_back(i);
                dmtapsY.push_back(j);
                dmtapsPlace.push_back(0);
            }
            else if( myGridUpLayer.at(i).at(j).moleculeNativeName == "DOPC" ){
                dopcsX.push_back(i);
                dopcsY.push_back(j);
                dopcsPlace.push_back(0);
            }
            */
            
            
            X.at( randNumberTemp ).push_back(i);
            Y.at( randNumberTemp ).push_back(j);
            place.at( randNumberTemp ).push_back(1);
            
            /*
            if( myGridDownLayer.at(i).at(j).moleculeNativeName == "DPPC" ){
                dppcsX.push_back(i);
                dppcsY.push_back(j);
                dppcPlace.push_back(1);
            }
            else if( myGridDownLayer.at(i).at(j).moleculeNativeName == "POPC" ){
                popcsX.push_back(i);
                popcsY.push_back(j);
                popcPlace.push_back(1);
            }
            else if( myGridDownLayer.at(i).at(j).moleculeNativeName == "POPE" ){
                popesX.push_back(i);
                popesY.push_back(j);
                popePlace.push_back(1);
            }
            else if( myGridDownLayer.at(i).at(j).moleculeNativeName == "POPG" ){
                popgsX.push_back(i);
                popgsY.push_back(j);
                popgPlace.push_back(1);
            }
            else if( myGridDownLayer.at(i).at(j).moleculeNativeName == "CHOLESTROL" ){
                cholestrolsX.push_back(i);
                cholestrolsY.push_back(j);
                cholestrolsPlace.push_back(1);
            }
            else if( myGridDownLayer.at(i).at(j).moleculeNativeName == "DMPC" ){
                dmpcsX.push_back(i);
                dmpcsY.push_back(j);
                dmpcsPlace.push_back(1);
            }
            else if( myGridDownLayer.at(i).at(j).moleculeNativeName == "DMTAP" ){
                dmtapsX.push_back(i);
                dmtapsY.push_back(j);
                dmtapsPlace.push_back(1);
            }
            else if( myGridDownLayer.at(i).at(j).moleculeNativeName == "DOPC" ){
                dopcsX.push_back(i);
                dopcsY.push_back(j);
                dopcsPlace.push_back(1);
            }
            */
            
        }
    }
    
    ofstream outFile( destination.c_str(), fstream::out );
    
    int serialNumber = 1;
    int residueSequenceNumber = 1;
    
    for( int j = 0; j <= 1; j++ ){
    
    for( int z = 0; z < width; z++ ){
    
    for( int i = 0; i < height; i++ ){
        
        Molecule tempMolecule;
        
        if( j == 1 )
            tempMolecule = myGridDownLayer.at(z).at(i);
        else
            tempMolecule = myGridUpLayer.at(z).at(i);
        
        //cout << tempMolecule.moleculeNativeName << endl;
        
        for( int k = 0; k < tempMolecule.numberOfAtoms; k++ ){
            
            //cout << "number of atoms is : " << tempMolecule.numberOfAtoms << endl;
            //cin >> in;
            
            // inserting atom label
            outFile << "ATOM  ";
            
            // inserting serial number-
            char serialChar[6] = { '\0' };
            sprintf( serialChar, "%d", serialNumber );
            int serialCharLength = strlen( serialChar );
            if( DEBUG_MODE == 1 )
                cout << "serial char length is: " << serialCharLength << endl;
            
            for( int k = 0; k < 5-serialCharLength; k++ ){
                outFile << " ";
            }
            outFile << serialChar;
            
            // inserting atom name
            char atomName[5] = { '\0' };
            strcpy( atomName, tempMolecule.atomName.at(k).c_str() );
            int atomNameLength = strlen( atomName );
            
            for( int k = 0; k < 5-atomNameLength; k++ ){
                outFile << " ";
            }
            outFile << atomName;
            
            // inserting Character
            outFile << " ";
            
            // insering residue name
            outFile << tempMolecule.moleculeName.at(k);
            outFile << " ";
            
            // inserting chain ID
            outFile << "A";
            
            // inserting residue sequence number
            char resSeqNumChar[5] = { '\0' };
            sprintf( resSeqNumChar, "%d", residueSequenceNumber );
            int resSeqNumCharLength = strlen( resSeqNumChar );
            
            for( int k = 0; k < 4-resSeqNumCharLength; k++ ){
                outFile << " ";
            }
            outFile << resSeqNumChar;
            
            // inserting Achar
            outFile << "    ";
            
            //inserting X
            char X[9] = { '\0' };
            sprintf( X, "%f", tempMolecule.atomX.at(k) );
            int XLength = strlen( X );
            X[XLength-1] = '\0';
            X[XLength-2] = '\0';
            X[XLength-3] = '\0';
            XLength -= 3;
            
            for( int k = 0; k < 8-XLength; k++ ){
                outFile << " ";
            }
            outFile << X;
            
            // inserting Y
            char Y[9] = { '\0' };
            sprintf( Y, "%f" , tempMolecule.atomY.at(k) );
            int YLength = strlen( Y );
            Y[YLength-1] = '\0';
            Y[YLength-2] = '\0';
            Y[YLength-3] = '\0';
            YLength -= 3;
            
            for( int k = 0; k < 8-YLength; k++ ){
                outFile << " ";
            }
            outFile << Y;
            
            // inserting Z
            char Z[9] = { '\0' };
            sprintf( Z, "%f" , tempMolecule.atomZ.at(k) );
            int ZLength = strlen( Z );
            Z[ZLength-1] = '\0';
            Z[ZLength-2] = '\0';
            Z[ZLength-3] = '\0';
            ZLength -= 3;
            
            
            for( int k = 0; k < 8-ZLength; k++ ){
                outFile << " ";
            }
            outFile << Z;
            outFile << endl;
            
            serialNumber++;
        }
        
        residueSequenceNumber++;
    }
    }
    }
    /*
    for( int i = 0; i < popcsX.size(); i++ ){
        
        Molecule tempMolecule;
        
        if( popcPlace.at(i) == 1 )
            tempMolecule = myGridDownLayer.at(popcsX.at(i)).at(popcsY.at(i));
        else
            tempMolecule = myGridUpLayer.at(popcsX.at(i)).at(popcsY.at(i));
        
        for( int k = 0; k < tempMolecule.numberOfAtoms; k++ ){
            
            //cout << "number of atoms is : " << tempMolecule.numberOfAtoms << endl;
            //cin >> in;
            
            // inserting atom label
            outFile << "ATOM  ";
            
            // inserting serial number-
            char serialChar[6] = { '\0' };
            sprintf( serialChar, "%d", serialNumber );
            int serialCharLength = strlen( serialChar );
            if( DEBUG_MODE == 1 )
                cout << "serial char length is: " << serialCharLength << endl;
            
            for( int k = 0; k < 5-serialCharLength; k++ ){
                outFile << " ";
            }
            outFile << serialChar;
            
            // inserting atom name
            char atomName[5] = { '\0' };
            strcpy( atomName, tempMolecule.atomName.at(k).c_str() );
            int atomNameLength = strlen( atomName );
            
            for( int k = 0; k < 5-atomNameLength; k++ ){
                outFile << " ";
            }
            outFile << atomName;
            
            // inserting Character
            outFile << " ";
            
            // insering residue name
            outFile << tempMolecule.moleculeName.at(k);
            outFile << " ";
            
            // inserting chain ID
            outFile << "A";
            
            // inserting residue sequence number
            char resSeqNumChar[5] = { '\0' };
            sprintf( resSeqNumChar, "%d", residueSequenceNumber );
            int resSeqNumCharLength = strlen( resSeqNumChar );
            
            for( int k = 0; k < 4-resSeqNumCharLength; k++ ){
                outFile << " ";
            }
            outFile << resSeqNumChar;
            
            // inserting Achar
            outFile << "    ";
            
            //inserting X
            char X[9] = { '\0' };
            sprintf( X, "%f", tempMolecule.atomX.at(k) );
            int XLength = strlen( X );
            X[XLength-1] = '\0';
            X[XLength-2] = '\0';
            X[XLength-3] = '\0';
            XLength -= 3;
            
            for( int k = 0; k < 8-XLength; k++ ){
                outFile << " ";
            }
            outFile << X;
            
            // inserting Y
            char Y[9] = { '\0' };
            sprintf( Y, "%f" , tempMolecule.atomY.at(k) );
            int YLength = strlen( Y );
            Y[YLength-1] = '\0';
            Y[YLength-2] = '\0';
            Y[YLength-3] = '\0';
            YLength -= 3;
            
            for( int k = 0; k < 8-YLength; k++ ){
                outFile << " ";
            }
            outFile << Y;
            
            // inserting Z
            char Z[9] = { '\0' };
            sprintf( Z, "%f" , tempMolecule.atomZ.at(k) );
            int ZLength = strlen( Z );
            Z[ZLength-1] = '\0';
            Z[ZLength-2] = '\0';
            Z[ZLength-3] = '\0';
            ZLength -= 3;
            
            
            for( int k = 0; k < 8-ZLength; k++ ){
                outFile << " ";
            }
            outFile << Z;
            outFile << endl;
            
            serialNumber++;
        }
        
        residueSequenceNumber++;
    }
    
    for( int i = 0; i < popesX.size(); i++ ){
        
        Molecule tempMolecule;
        
        if( popePlace.at(i) == 1 )
            tempMolecule = myGridDownLayer.at(popesX.at(i)).at(popesY.at(i));
        else
            tempMolecule = myGridUpLayer.at(popesX.at(i)).at(popesY.at(i));
        
        for( int k = 0; k < tempMolecule.numberOfAtoms; k++ ){
            
            //cout << "number of atoms is : " << tempMolecule.numberOfAtoms << endl;
            //cin >> in;
            
            // inserting atom label
            outFile << "ATOM  ";
            
            // inserting serial number-
            char serialChar[6] = { '\0' };
            sprintf( serialChar, "%d", serialNumber );
            int serialCharLength = strlen( serialChar );
            if( DEBUG_MODE == 1 )
                cout << "serial char length is: " << serialCharLength << endl;
            
            for( int k = 0; k < 5-serialCharLength; k++ ){
                outFile << " ";
            }
            outFile << serialChar;
            
            // inserting atom name
            char atomName[5] = { '\0' };
            strcpy( atomName, tempMolecule.atomName.at(k).c_str() );
            int atomNameLength = strlen( atomName );
            
            for( int k = 0; k < 5-atomNameLength; k++ ){
                outFile << " ";
            }
            outFile << atomName;
            
            // inserting Character
            outFile << " ";
            
            // insering residue name
            outFile << tempMolecule.moleculeName.at(k);
            outFile << " ";
            
            // inserting chain ID
            outFile << "A";
            
            // inserting residue sequence number
            char resSeqNumChar[5] = { '\0' };
            sprintf( resSeqNumChar, "%d", residueSequenceNumber );
            int resSeqNumCharLength = strlen( resSeqNumChar );
            
            for( int k = 0; k < 4-resSeqNumCharLength; k++ ){
                outFile << " ";
            }
            outFile << resSeqNumChar;
            
            // inserting Achar
            outFile << "    ";
            
            //inserting X
            char X[9] = { '\0' };
            sprintf( X, "%f", tempMolecule.atomX.at(k) );
            int XLength = strlen( X );
            X[XLength-1] = '\0';
            X[XLength-2] = '\0';
            X[XLength-3] = '\0';
            XLength -= 3;
            
            for( int k = 0; k < 8-XLength; k++ ){
                outFile << " ";
            }
            outFile << X;
            
            // inserting Y
            char Y[9] = { '\0' };
            sprintf( Y, "%f" , tempMolecule.atomY.at(k) );
            int YLength = strlen( Y );
            Y[YLength-1] = '\0';
            Y[YLength-2] = '\0';
            Y[YLength-3] = '\0';
            YLength -= 3;
            
            for( int k = 0; k < 8-YLength; k++ ){
                outFile << " ";
            }
            outFile << Y;
            
            // inserting Z
            char Z[9] = { '\0' };
            sprintf( Z, "%f" , tempMolecule.atomZ.at(k) );
            int ZLength = strlen( Z );
            Z[ZLength-1] = '\0';
            Z[ZLength-2] = '\0';
            Z[ZLength-3] = '\0';
            ZLength -= 3;
            
            
            for( int k = 0; k < 8-ZLength; k++ ){
                outFile << " ";
            }
            outFile << Z;
            outFile << endl;
            
            serialNumber++;
        }
        
        residueSequenceNumber++;
    }
    
    for( int i = 0; i < popgsX.size(); i++ ){
        
        Molecule tempMolecule;
        
        if( popgPlace.at(i) == 1 )
            tempMolecule = myGridDownLayer.at(popgsX.at(i)).at(popgsY.at(i));
        else
            tempMolecule = myGridUpLayer.at(popgsX.at(i)).at(popgsY.at(i));
        
        for( int k = 0; k < tempMolecule.numberOfAtoms; k++ ){
            
            //cout << "number of atoms is : " << tempMolecule.numberOfAtoms << endl;
            //cin >> in;
            
            // inserting atom label
            outFile << "ATOM  ";
            
            // inserting serial number-
            char serialChar[6] = { '\0' };
            sprintf( serialChar, "%d", serialNumber );
            int serialCharLength = strlen( serialChar );
            if( DEBUG_MODE == 1 )
                cout << "serial char length is: " << serialCharLength << endl;
            
            for( int k = 0; k < 5-serialCharLength; k++ ){
                outFile << " ";
            }
            outFile << serialChar;
            
            // inserting atom name
            char atomName[5] = { '\0' };
            strcpy( atomName, tempMolecule.atomName.at(k).c_str() );
            int atomNameLength = strlen( atomName );
            
            for( int k = 0; k < 5-atomNameLength; k++ ){
                outFile << " ";
            }
            outFile << atomName;
            
            // inserting Character
            outFile << " ";
            
            // insering residue name
            outFile << tempMolecule.moleculeName.at(k);
            outFile << " ";
            
            // inserting chain ID
            outFile << "A";
            
            // inserting residue sequence number
            char resSeqNumChar[5] = { '\0' };
            sprintf( resSeqNumChar, "%d", residueSequenceNumber );
            int resSeqNumCharLength = strlen( resSeqNumChar );
            
            for( int k = 0; k < 4-resSeqNumCharLength; k++ ){
                outFile << " ";
            }
            outFile << resSeqNumChar;
            
            // inserting Achar
            outFile << "    ";
            
            //inserting X
            char X[9] = { '\0' };
            sprintf( X, "%f", tempMolecule.atomX.at(k) );
            int XLength = strlen( X );
            X[XLength-1] = '\0';
            X[XLength-2] = '\0';
            X[XLength-3] = '\0';
            XLength -= 3;
            
            for( int k = 0; k < 8-XLength; k++ ){
                outFile << " ";
            }
            outFile << X;
            
            // inserting Y
            char Y[9] = { '\0' };
            sprintf( Y, "%f" , tempMolecule.atomY.at(k) );
            int YLength = strlen( Y );
            Y[YLength-1] = '\0';
            Y[YLength-2] = '\0';
            Y[YLength-3] = '\0';
            YLength -= 3;
            
            for( int k = 0; k < 8-YLength; k++ ){
                outFile << " ";
            }
            outFile << Y;
            
            // inserting Z
            char Z[9] = { '\0' };
            sprintf( Z, "%f" , tempMolecule.atomZ.at(k) );
            int ZLength = strlen( Z );
            Z[ZLength-1] = '\0';
            Z[ZLength-2] = '\0';
            Z[ZLength-3] = '\0';
            ZLength -= 3;
            
            
            for( int k = 0; k < 8-ZLength; k++ ){
                outFile << " ";
            }
            outFile << Z;
            outFile << endl;
            
            serialNumber++;
        }
        
        residueSequenceNumber++;
    }
    
    for( int i = 0; i < cholestrolsX.size(); i++ ){
        
        Molecule tempMolecule;
        
        if( cholestrolsPlace.at(i) == 1 )
            tempMolecule = myGridDownLayer.at(cholestrolsX.at(i)).at(cholestrolsY.at(i));
        else
            tempMolecule = myGridUpLayer.at(cholestrolsX.at(i)).at(cholestrolsY.at(i));
        
        //cout << tempMolecule.moleculeNativeName << endl;
        
        for( int k = 0; k < tempMolecule.numberOfAtoms; k++ ){
            
            //cout << "number of atoms is : " << tempMolecule.numberOfAtoms << endl;
            //cin >> in;
            
            // inserting atom label
            outFile << "ATOM  ";
            
            // inserting serial number-
            char serialChar[6] = { '\0' };
            sprintf( serialChar, "%d", serialNumber );
            int serialCharLength = strlen( serialChar );
            if( DEBUG_MODE == 1 )
                cout << "serial char length is: " << serialCharLength << endl;
            
            for( int k = 0; k < 5-serialCharLength; k++ ){
                outFile << " ";
            }
            outFile << serialChar;
            
            // inserting atom name
            char atomName[5] = { '\0' };
            strcpy( atomName, tempMolecule.atomName.at(k).c_str() );
            int atomNameLength = strlen( atomName );
            
            for( int k = 0; k < 5-atomNameLength; k++ ){
                outFile << " ";
            }
            outFile << atomName;
            
            // inserting Character
            outFile << " ";
            
            // insering residue name
            outFile << tempMolecule.moleculeName.at(k);
            outFile << " ";
            
            // inserting chain ID
            outFile << "A";
            
            // inserting residue sequence number
            char resSeqNumChar[5] = { '\0' };
            sprintf( resSeqNumChar, "%d", residueSequenceNumber );
            int resSeqNumCharLength = strlen( resSeqNumChar );
            
            for( int k = 0; k < 4-resSeqNumCharLength; k++ ){
                outFile << " ";
            }
            outFile << resSeqNumChar;
            
            // inserting Achar
            outFile << "    ";
            
            //inserting X
            char X[9] = { '\0' };
            sprintf( X, "%f", tempMolecule.atomX.at(k) );
            int XLength = strlen( X );
            X[XLength-1] = '\0';
            X[XLength-2] = '\0';
            X[XLength-3] = '\0';
            XLength -= 3;
            
            for( int k = 0; k < 8-XLength; k++ ){
                outFile << " ";
            }
            outFile << X;
            
            // inserting Y
            char Y[9] = { '\0' };
            sprintf( Y, "%f" , tempMolecule.atomY.at(k) );
            int YLength = strlen( Y );
            Y[YLength-1] = '\0';
            Y[YLength-2] = '\0';
            Y[YLength-3] = '\0';
            YLength -= 3;
            
            for( int k = 0; k < 8-YLength; k++ ){
                outFile << " ";
            }
            outFile << Y;
            
            // inserting Z
            char Z[9] = { '\0' };
            sprintf( Z, "%f" , tempMolecule.atomZ.at(k) );
            int ZLength = strlen( Z );
            Z[ZLength-1] = '\0';
            Z[ZLength-2] = '\0';
            Z[ZLength-3] = '\0';
            ZLength -= 3;
            
            
            for( int k = 0; k < 8-ZLength; k++ ){
                outFile << " ";
            }
            outFile << Z;
            outFile << endl;
            
            serialNumber++;
        }
        
        residueSequenceNumber++;
    }
    
    for( int i = 0; i < dmpcsX.size(); i++ ){
        
        Molecule tempMolecule;
        
        if( dmpcsPlace.at(i) == 1 )
            tempMolecule = myGridDownLayer.at(dmpcsX.at(i)).at(dmpcsY.at(i));
        else
            tempMolecule = myGridUpLayer.at(dmpcsX.at(i)).at(dmpcsY.at(i));
        
        //cout << tempMolecule.moleculeNativeName << endl;
        
        for( int k = 0; k < tempMolecule.numberOfAtoms; k++ ){
            
            //cout << "number of atoms is : " << tempMolecule.numberOfAtoms << endl;
            //cin >> in;
            
            // inserting atom label
            outFile << "ATOM  ";
            
            // inserting serial number-
            char serialChar[6] = { '\0' };
            sprintf( serialChar, "%d", serialNumber );
            int serialCharLength = strlen( serialChar );
            if( DEBUG_MODE == 1 )
                cout << "serial char length is: " << serialCharLength << endl;
            
            for( int k = 0; k < 5-serialCharLength; k++ ){
                outFile << " ";
            }
            outFile << serialChar;
            
            // inserting atom name
            char atomName[5] = { '\0' };
            strcpy( atomName, tempMolecule.atomName.at(k).c_str() );
            int atomNameLength = strlen( atomName );
            
            for( int k = 0; k < 5-atomNameLength; k++ ){
                outFile << " ";
            }
            outFile << atomName;
            
            // inserting Character
            outFile << " ";
            
            // insering residue name
            outFile << tempMolecule.moleculeName.at(k);
            outFile << " ";
            
            // inserting chain ID
            outFile << "A";
            
            // inserting residue sequence number
            char resSeqNumChar[5] = { '\0' };
            sprintf( resSeqNumChar, "%d", residueSequenceNumber );
            int resSeqNumCharLength = strlen( resSeqNumChar );
            
            for( int k = 0; k < 4-resSeqNumCharLength; k++ ){
                outFile << " ";
            }
            outFile << resSeqNumChar;
            
            // inserting Achar
            outFile << "    ";
            
            //inserting X
            char X[9] = { '\0' };
            sprintf( X, "%f", tempMolecule.atomX.at(k) );
            int XLength = strlen( X );
            X[XLength-1] = '\0';
            X[XLength-2] = '\0';
            X[XLength-3] = '\0';
            XLength -= 3;
            
            for( int k = 0; k < 8-XLength; k++ ){
                outFile << " ";
            }
            outFile << X;
            
            // inserting Y
            char Y[9] = { '\0' };
            sprintf( Y, "%f" , tempMolecule.atomY.at(k) );
            int YLength = strlen( Y );
            Y[YLength-1] = '\0';
            Y[YLength-2] = '\0';
            Y[YLength-3] = '\0';
            YLength -= 3;
            
            for( int k = 0; k < 8-YLength; k++ ){
                outFile << " ";
            }
            outFile << Y;
            
            // inserting Z
            char Z[9] = { '\0' };
            sprintf( Z, "%f" , tempMolecule.atomZ.at(k) );
            int ZLength = strlen( Z );
            Z[ZLength-1] = '\0';
            Z[ZLength-2] = '\0';
            Z[ZLength-3] = '\0';
            ZLength -= 3;
            
            
            for( int k = 0; k < 8-ZLength; k++ ){
                outFile << " ";
            }
            outFile << Z;
            outFile << endl;
            
            serialNumber++;
        }
        
        residueSequenceNumber++;
    }
    
    for( int i = 0; i < dmtapsX.size(); i++ ){
        
        Molecule tempMolecule;
        
        if( dmtapsPlace.at(i) == 1 )
            tempMolecule = myGridDownLayer.at(dmtapsX.at(i)).at(dmtapsY.at(i));
        else
            tempMolecule = myGridUpLayer.at(dmtapsX.at(i)).at(dmtapsY.at(i));
        
        //cout << tempMolecule.moleculeNativeName << endl;
        
        for( int k = 0; k < tempMolecule.numberOfAtoms; k++ ){
            
            //cout << "number of atoms is : " << tempMolecule.numberOfAtoms << endl;
            //cin >> in;
            
            // inserting atom label
            outFile << "ATOM  ";
            
            // inserting serial number-
            char serialChar[6] = { '\0' };
            sprintf( serialChar, "%d", serialNumber );
            int serialCharLength = strlen( serialChar );
            if( DEBUG_MODE == 1 )
                cout << "serial char length is: " << serialCharLength << endl;
            
            for( int k = 0; k < 5-serialCharLength; k++ ){
                outFile << " ";
            }
            outFile << serialChar;
            
            // inserting atom name
            char atomName[5] = { '\0' };
            strcpy( atomName, tempMolecule.atomName.at(k).c_str() );
            int atomNameLength = strlen( atomName );
            
            for( int k = 0; k < 5-atomNameLength; k++ ){
                outFile << " ";
            }
            outFile << atomName;
            
            // inserting Character
            outFile << " ";
            
            // insering residue name
            outFile << tempMolecule.moleculeName.at(k);
            outFile << " ";
            
            // inserting chain ID
            outFile << "A";
            
            // inserting residue sequence number
            char resSeqNumChar[5] = { '\0' };
            sprintf( resSeqNumChar, "%d", residueSequenceNumber );
            int resSeqNumCharLength = strlen( resSeqNumChar );
            
            for( int k = 0; k < 4-resSeqNumCharLength; k++ ){
                outFile << " ";
            }
            outFile << resSeqNumChar;
            
            // inserting Achar
            outFile << "    ";
            
            //inserting X
            char X[9] = { '\0' };
            sprintf( X, "%f", tempMolecule.atomX.at(k) );
            int XLength = strlen( X );
            X[XLength-1] = '\0';
            X[XLength-2] = '\0';
            X[XLength-3] = '\0';
            XLength -= 3;
            
            for( int k = 0; k < 8-XLength; k++ ){
                outFile << " ";
            }
            outFile << X;
            
            // inserting Y
            char Y[9] = { '\0' };
            sprintf( Y, "%f" , tempMolecule.atomY.at(k) );
            int YLength = strlen( Y );
            Y[YLength-1] = '\0';
            Y[YLength-2] = '\0';
            Y[YLength-3] = '\0';
            YLength -= 3;
            
            for( int k = 0; k < 8-YLength; k++ ){
                outFile << " ";
            }
            outFile << Y;
            
            // inserting Z
            char Z[9] = { '\0' };
            sprintf( Z, "%f" , tempMolecule.atomZ.at(k) );
            int ZLength = strlen( Z );
            Z[ZLength-1] = '\0';
            Z[ZLength-2] = '\0';
            Z[ZLength-3] = '\0';
            ZLength -= 3;
            
            
            for( int k = 0; k < 8-ZLength; k++ ){
                outFile << " ";
            }
            outFile << Z;
            outFile << endl;
            
            serialNumber++;
        }
        
        residueSequenceNumber++;
    }
    
    for( int i = 0; i < dopcsX.size(); i++ ){
        
        Molecule tempMolecule;
        
        if( dopcsPlace.at(i) == 1 )
            tempMolecule = myGridDownLayer.at(dopcsX.at(i)).at(dopcsY.at(i));
        else
            tempMolecule = myGridUpLayer.at(dopcsX.at(i)).at(dopcsY.at(i));
        
        //cout << tempMolecule.moleculeNativeName << endl;
        
        for( int k = 0; k < tempMolecule.numberOfAtoms; k++ ){
            
            //cout << "number of atoms is : " << tempMolecule.numberOfAtoms << endl;
            //cin >> in;
            
            // inserting atom label
            outFile << "ATOM  ";
            
            // inserting serial number-
            char serialChar[6] = { '\0' };
            sprintf( serialChar, "%d", serialNumber );
            int serialCharLength = strlen( serialChar );
            if( DEBUG_MODE == 1 )
                cout << "serial char length is: " << serialCharLength << endl;
            
            for( int k = 0; k < 5-serialCharLength; k++ ){
                outFile << " ";
            }
            outFile << serialChar;
            
            // inserting atom name
            char atomName[5] = { '\0' };
            strcpy( atomName, tempMolecule.atomName.at(k).c_str() );
            int atomNameLength = strlen( atomName );
            
            for( int k = 0; k < 5-atomNameLength; k++ ){
                outFile << " ";
            }
            outFile << atomName;
            
            // inserting Character
            outFile << " ";
            
            // insering residue name
            outFile << tempMolecule.moleculeName.at(k);
            outFile << " ";
            
            // inserting chain ID
            outFile << "A";
            
            // inserting residue sequence number
            char resSeqNumChar[5] = { '\0' };
            sprintf( resSeqNumChar, "%d", residueSequenceNumber );
            int resSeqNumCharLength = strlen( resSeqNumChar );
            
            for( int k = 0; k < 4-resSeqNumCharLength; k++ ){
                outFile << " ";
            }
            outFile << resSeqNumChar;
            
            // inserting Achar
            outFile << "    ";
            
            //inserting X
            char X[9] = { '\0' };
            sprintf( X, "%f", tempMolecule.atomX.at(k) );
            int XLength = strlen( X );
            X[XLength-1] = '\0';
            X[XLength-2] = '\0';
            X[XLength-3] = '\0';
            XLength -= 3;
            
            for( int k = 0; k < 8-XLength; k++ ){
                outFile << " ";
            }
            outFile << X;
            
            // inserting Y
            char Y[9] = { '\0' };
            sprintf( Y, "%f" , tempMolecule.atomY.at(k) );
            int YLength = strlen( Y );
            Y[YLength-1] = '\0';
            Y[YLength-2] = '\0';
            Y[YLength-3] = '\0';
            YLength -= 3;
            
            for( int k = 0; k < 8-YLength; k++ ){
                outFile << " ";
            }
            outFile << Y;
            
            // inserting Z
            char Z[9] = { '\0' };
            sprintf( Z, "%f" , tempMolecule.atomZ.at(k) );
            int ZLength = strlen( Z );
            Z[ZLength-1] = '\0';
            Z[ZLength-2] = '\0';
            Z[ZLength-3] = '\0';
            ZLength -= 3;
            
            
            for( int k = 0; k < 8-ZLength; k++ ){
                outFile << " ";
            }
            outFile << Z;
            outFile << endl;
            
            serialNumber++;
        }
        
        residueSequenceNumber++;
    }
     
     */
    
    
    outFile.close();
    
}
void Grid::printGridInFileSequential( string destination, InputParser myInputParser ){
    
    
    vector< vector<int> > X;
    for( int i = 0; i < myInputParser.size; i++ ) 
        X.push_back( vector<int>() );
    vector< vector<int> > Y;
    for( int i = 0; i < myInputParser.size; i++ ) 
        Y.push_back( vector<int>() );
    vector< vector<int> > place;
    for( int i = 0; i < myInputParser.size; i++ )
        place.push_back( vector<int>() );
    
    
    
    for( int i = 0; i < width; i++ ){
        for( int j = 0; j < height; j++ ){
            
            X.at( myGridUpLayer.at(i).at(j).number ).push_back(i);
            Y.at( myGridUpLayer.at(i).at(j).number ).push_back(j);
            place.at( myGridUpLayer.at(i).at(j).number ).push_back(0);
            
            
            X.at( myGridDownLayer.at(i).at(j).number ).push_back(i);
            Y.at( myGridDownLayer.at(i).at(j).number ).push_back(j);
            place.at( myGridDownLayer.at(i).at(j).number ).push_back(1);
            
            
        }
    }
    
    ofstream outFile( destination.c_str(), fstream::out );
    
    int serialNumber = 1;
    int residueSequenceNumber = 1;
    
    for( int z = 0; z < myInputParser.size; z++ ){
        
        for( int i = 0; i < X.at(z).size(); i++ ){
            
            Molecule tempMolecule;
            
            if( place.at(z).at(i) == 1 )
                tempMolecule = myGridDownLayer.at(X.at(z).at(i)).at(Y.at(z).at(i));
            else
                tempMolecule = myGridUpLayer.at(X.at(z).at(i)).at(Y.at(z).at(i));
            
            //cout << tempMolecule.moleculeNativeName << endl;
            
            for( int k = 0; k < tempMolecule.numberOfAtoms; k++ ){
                
                //cout << "number of atoms is : " << tempMolecule.numberOfAtoms << endl;
                //cin >> in;
                
                // inserting atom label
                outFile << "ATOM  ";
                
                // inserting serial number-
                char serialChar[6] = { '\0' };
                sprintf( serialChar, "%d", serialNumber );
                int serialCharLength = strlen( serialChar );
                if( DEBUG_MODE == 1 )
                    cout << "serial char length is: " << serialCharLength << endl;
                
                for( int k = 0; k < 5-serialCharLength; k++ ){
                    outFile << " ";
                }
                outFile << serialChar;
                
                // inserting atom name
                char atomName[5] = { '\0' };
                strcpy( atomName, tempMolecule.atomName.at(k).c_str() );
                int atomNameLength = strlen( atomName );
                
                for( int k = 0; k < 5-atomNameLength; k++ ){
                    outFile << " ";
                }
                outFile << atomName;
                
                // inserting Character
                outFile << " ";
                
                // insering residue name
                outFile << tempMolecule.moleculeName.at(k);
                outFile << " ";
                
                // inserting chain ID
                outFile << "A";
                
                // inserting residue sequence number
                char resSeqNumChar[5] = { '\0' };
                sprintf( resSeqNumChar, "%d", residueSequenceNumber );
                int resSeqNumCharLength = strlen( resSeqNumChar );
                
                for( int k = 0; k < 4-resSeqNumCharLength; k++ ){
                    outFile << " ";
                }
                outFile << resSeqNumChar;
                
                // inserting Achar
                outFile << "    ";
                
                //inserting X
                char X[9] = { '\0' };
                sprintf( X, "%f", tempMolecule.atomX.at(k) );
                int XLength = strlen( X );
                X[XLength-1] = '\0';
                X[XLength-2] = '\0';
                X[XLength-3] = '\0';
                XLength -= 3;
                
                for( int k = 0; k < 8-XLength; k++ ){
                    outFile << " ";
                }
                outFile << X;
                
                // inserting Y
                char Y[9] = { '\0' };
                sprintf( Y, "%f" , tempMolecule.atomY.at(k) );
                int YLength = strlen( Y );
                Y[YLength-1] = '\0';
                Y[YLength-2] = '\0';
                Y[YLength-3] = '\0';
                YLength -= 3;
                
                for( int k = 0; k < 8-YLength; k++ ){
                    outFile << " ";
                }
                outFile << Y;
                
                // inserting Z
                char Z[9] = { '\0' };
                sprintf( Z, "%f" , tempMolecule.atomZ.at(k) );
                int ZLength = strlen( Z );
                Z[ZLength-1] = '\0';
                Z[ZLength-2] = '\0';
                Z[ZLength-3] = '\0';
                ZLength -= 3;
                
                
                for( int k = 0; k < 8-ZLength; k++ ){
                    outFile << " ";
                }
                outFile << Z;
                outFile << endl;
                
                serialNumber++;
            }
            
            residueSequenceNumber++;
        }
    }
   
    outFile.close();
    
}

    

void Grid::printGridInScreen(){
    
    cout << "myGridUpLayer" << endl;
    
    for( int i = 0; i < width; i++ ){
        for( int j = 0; j < height; j++ ){
            
            cout << "coordinate " << i << " " << j << endl;
            for( int k = 0; k < myGridUpLayer.at(i).at(j).numberOfAtoms; k++ ){
                cout << "ATOM " << k << " " << myGridUpLayer.at(i).at(j).atomName.at(k) << " " << myGridUpLayer.at(i).at(j).atomX.at(k) << " " << myGridUpLayer.at(i).at(j).atomY.at(k) << " " << myGridUpLayer.at(i).at(j).atomZ.at(k) << endl;
            }
        }
    }
    
    cout << "myGridDownLayer" << endl;
    
    for( int i = 0; i < width; i++ ){
        for( int j = 0; j < height; j++ ){
            
            cout << "coordinate " << i << " " << j << endl;
            for( int k = 0; k < myGridDownLayer.at(i).at(j).numberOfAtoms; k++ ){
                cout << "ATOM " << k << " " << myGridDownLayer.at(i).at(j).atomName.at(k) << " " << myGridDownLayer.at(i).at(j).atomX.at(k) << " " << myGridDownLayer.at(i).at(j).atomY.at(k) << " " << myGridDownLayer.at(i).at(j).atomZ.at(k) << endl;
            }
        }
    }    
}


Grid::~Grid(){
    
}



