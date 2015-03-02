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
        std::cout <<"Failed to open data file..." << std::endl;
        exit(0);
    }
    
    for (int i=0; i<dataRows; i++) {
        for(int j = 0; j < dataColumn; j++) {
            dataPoints >> A[i][j];
        }
    }
    
    // SDV of problem
    /* Find expressions for the elements in the matrix A and the right-hand side, say z,
       for the associated systems of linear equations for the pa- rameters q = (x0, y0, a, b).
    */
    
    
    
    /* Read the files with values, insert them in A and compute U, W og V using the method from NR. 
       State (with arguments based on the SVD matrices) if there are linear dependencies between 
       the parameters x0, y0, a, b.
    */
    
    
    
    /* Estimate the parameters q = (x0, y0, a, b) and state your results. 
       State also the residual error ∥Aq − z∥.
    */
    
    
    
    
    /* The values of the x(i), y(i)’s are measured with a camera, and there is a measurement uncertainty 
       that is estimated to 1mm on each coordinate. Estimate the resulting errors on the found parameters 
       using NR, Eq. (15.4.19).
    */
    
    
    std::cout <<"Hello world..." << std::endl;
    return 0;
}
