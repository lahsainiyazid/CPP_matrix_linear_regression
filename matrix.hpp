#pragma once 
#include<vector>

class matrix{
  public:
    //Elements of our matrix object:
    size_t rows;
    size_t cols;
    std::vector<double>vals;
    matrix (size_t r,size_t c,const std::vector<double>&vec);
    matrix (size_t r,size_t c);
    //Selection operators:
    double& operator()(size_t r,size_t c);//We pass reference so we can do read+write 
    double operator()(size_t r,size_t c) const; //We pass copy to read only +const to ensure that this pointer doesnt change!
    //Scalar operations on our matrix object:
    matrix operator *(double a)const;
    matrix  operator +(double a)const;
    matrix  operator -(double a)const;
    //Matrix operations for our matrix object :
    matrix operator *(const matrix &other)const; 
    matrix operator -(const matrix &other)const;
    //Transpose matrix:
    matrix T()const;
  
};

