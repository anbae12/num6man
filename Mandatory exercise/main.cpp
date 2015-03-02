//
//  main.cpp
//  Mandatory exercise
//
//  Created by Anders Launer Bæk on 01/03/15.
//  Copyright (c) 2015 Anders Launer Bæk. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "nr3.h"

int main() {
    
    // Reading the data file
    const int dataRows = 500;
    const int dataColumn = 4;
    MatDoub A(dataRows,dataColumn);
    
    std::ifstream dataPoints("/Users/Anders/Dropbox/6.\ semester/NUM6/Mandatory\ exercise/d1.txt"); // Anders
//    std::ifstream dataPoints("/Users//d1.txt"); // Mikkel
    if ( ! dataPoints.is_open() ) {
        cout <<" Failed to open data file..." << endl;
        exit(0);
    }
    
    for (int i=0; i<dataRows; i++) {
        for(int j = 0; j < dataColumn; j++) {
            dataPoints >> A[i][j];
        }
    }
    
    // SDV of problem

    
    
    
    
    
    
    
    return 0;
}
