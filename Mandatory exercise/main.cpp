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
#include "svd.h"

int main() {
    
    // Reading the data file
    const int dataRows = 500;
    const int dataColumn = 4;
    VecDoub theta1(dataRows);
    VecDoub theta2(dataRows);
    VecDoub x(dataRows);
    VecDoub y(dataRows);
    
    
    std::ifstream dataPoints("/Users/Anders/Dropbox/6.\ semester/NUM6/Mandatory\ exercise/d2.txt"); // Anders
//    std::ifstream dataPoints("/Users//d1.txt"); // Mikkel
    if ( ! dataPoints.is_open() ) {
        std::cout <<"Failed to open data file..." << std::endl;
        exit(0);
    }
    for (int i=0; i<dataRows; i++) {
        dataPoints >> theta1[i];
        dataPoints >> theta2[i];
        dataPoints >> x[i];
        dataPoints >> y[i];
    }
    // SDV of problem
    /* Find expressions for the elements in the matrix A and the right-hand side, say z,
       for the associated systems of linear equations for the pa- rameters q = (x0, y0, a, b).
    */
    // Latex
    
    /* Read the files with values, insert them in A and compute U, W og V using the method from NR. 
       State (with arguments based on the SVD matrices) if there are linear dependencies between 
       the parameters x0, y0, a, b.
    */
    MatDoub A(dataRows*2,dataColumn);
    int tempIt=0;
    for (int j=0; j<dataRows*2; j++) {
        if (j%2==0) {
            A[j][0]=1;
            A[j][1]=0;
            A[j][2]=cos(theta1[tempIt]);
            A[j][3]=cos(theta1[tempIt]+theta2[tempIt]);
        } else{
            A[j][0]=0;
            A[j][1]=1;
            A[j][2]=sin(theta1[tempIt]);
            A[j][3]=sin(theta1[tempIt]+theta2[tempIt]);
            tempIt++;
        }
    }
    
    VecDoub b(dataRows*2);
    int tempIt2=0;
    for (int j=0; j<dataRows*2; j++) {
        if (j%2==0) {
            b[j]=x[tempIt2];
        } else{
            b[j]=y[tempIt2];
            tempIt2++;
        }
    }
    SVD obj(A);
    VecDoub W=obj.w;
    MatDoub V=obj.v;
    MatDoub U=obj.u;
    
    std::cout<<"W\n"<<W<<std::endl;
    std::cout<<"V\n"<<V<<std::endl;
//    std::cout<<"U\n"<<U<<std::endl;
    
    
    /* Estimate the parameters q = (x0, y0, a, b) and state your results. 
       State also the residual error ∥Aq − z∥.
    */
    VecDoub q(dataColumn);
    obj.solve(b, q);
    std::cout<<"q\n"<<q<<std::endl;

    VecDoub residual(dataRows*2);
    tempIt=0;
    Doub x0val=q[0];
    Doub y0val=q[1];
    Doub aval=q[2];
    Doub bval=q[3];
    
    
    
    for (int j=0; j<dataRows*2; j++) {
        if (j%2==0) {
            residual[j]= abs((x0val+aval*cos(theta1[tempIt])+ bval*cos(theta1[tempIt]+theta2[tempIt]))-x[tempIt]);
        } else{
            residual[j]= abs((y0val+aval*sin(theta1[tempIt])+ bval*sin(theta1[tempIt]+theta2[tempIt]))-y[tempIt]);
            tempIt++;
        }
    }
    
    
    Doub Sum=0;
    for (int j=0; j<dataRows*2; j++) {
        Sum += residual[j];
        //std::cout<<residual[j]<<std::endl;
    }
    std::cout<<"Residual error\n"<<Sum/(dataRows*2)<<"\n"<<std::endl;
    
    /* The values of the x(i), y(i)’s are measured with a camera, and there is a measurement uncertainty 
       that is estimated to 1mm on each coordinate. Estimate the resulting errors on the found parameters 
       using NR, Eq. (15.4.19).
    */
    VecDoub stddev(dataColumn);
    for (int i=0; i<dataColumn; i++) {
        Doub varians = 0;
        for (int j=0; j<dataColumn; j++) {
            varians += pow(V[i][j]/W[j], 2);
        }
        stddev[i]=sqrt(abs(varians));
    }
    
    std::cout<<"STD\n"<<stddev<<std::endl;
    
    
    return 0;
}