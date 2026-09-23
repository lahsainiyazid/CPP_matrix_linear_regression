#include<iostream>
#include <vector>
#include <stdexcept>
struct Matrix{
  size_t rows;
  size_t cols;
  std::vector<double>data;
   Matrix(size_t r,size_t c,double val=0.0){
     rows=r;
     cols=c;
     data=data.assign(r*c,val); //Assigns vector of size r*c and fills it with zeros !
   };

