#include<iostream>
#include "matrix.hpp"
#include <stdexcept>
  //Constructors:
  matrix::matrix(size_t r,size_t c,const std::vector<double>&vec):rows(r),cols(c),vals(vec)
  {if (r*c !=vals.size()){
      throw std::invalid_argument("Invalid matrix size!");}}
  matrix::matrix(size_t r,size_t c):rows(r),cols(c),vals(std::vector<double>(r*c,0))
  {if (r*c !=vals.size()){
                           throw std::invalid_argument("Invalid matrix size!");}}
  //Selection operators:
 double& matrix::operator()(size_t r,size_t c){
   return vals[r*cols+c];
 }
 double matrix::operator()(size_t r,size_t c)const{
   return vals[r*cols+c];
 }
  //Scalar operations:
    matrix matrix::operator *(double a)const{
      std::vector<double>vec(vals.size(),0);
      for (size_t i=0;i<vals.size();i++){
        vec[i]=vals[i]*a;
      }
      return matrix(rows,cols,vec);
    }
 matrix matrix::operator +(double a)const{
   std::vector<double>vec(vals.size(),0);
   for (size_t i=0;i<vals.size();i++){
     vec[i]=vals[i]+a;
   }
 return matrix(rows,cols,vec);}
 matrix matrix::operator -(double a)const{
   std::vector<double>vec(vals.size(),0);
    for (size_t i=0;i<vals.size();i++){
      vec[i]=vals[i]-a;
    }
 return matrix (rows,cols,vec);}
 //Matrix arithmetic operations on matrix:
 matrix matrix::operator *(matrix &other) const{
   if (cols != other.rows ){
     throw std::invalid_argument("Inner dimensions must match!");
   }
   std::vector<double>vec(rows*other.cols,0);
   matrix result=matrix(rows,other.cols,vec);
   for (size_t i=0;i<rows;i++){
     for (size_t j=0;j<other.cols;j++){
       for (size_t k=0;k<cols;k++){
         result(i,j)+=(*this)(i,k) * other (k,j);
       }
     }
   }
 return result;}













int main (){
  std::cout<<"Creating matrix class from scratch!"<<std::endl;
  return 0;
}
