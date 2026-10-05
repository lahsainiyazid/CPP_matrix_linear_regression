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
 matrix matrix::operator *(const matrix &other) const{
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
 matrix matrix::operator -(const matrix &other)const {
   if (rows!=other.rows){
     throw std::invalid_argument("Rows sizes must match!");
   }
   if (cols !=other.cols){
     throw std::invalid_argument("Columns sizes must match");
   }
   std::vector<double>val(rows*cols,0);
   for (size_t i=0;i<rows*cols;i++){
     val[i]=vals[i]-other.vals[i];
   }
 return  matrix(rows,cols,val);}
  //Transpose:
  matrix matrix::T()const{
    std::vector<double>vec(vals.size(),0);
    matrix result=matrix(cols,rows,vec);
    for (size_t i=0;i<rows;i++){
      for (size_t j=0;j<cols;j++){
        result (j,i)=(*this) (i,j);
      }
    }
  return result;}
  //Mae:
  double matrix::mae(const matrix &other)const {
    if (rows!=other.rows||cols!=other.cols||vals.size()==0){
      throw std::invalid_argument("Invalid shape!");
    }
    double sum=0.0;
    double len=static_cast<double>(vals.size());
    for (size_t i=0;i<vals.size();i++){
      double raw=vals[i]-other.vals[i];
     if (raw<0){
       raw=-raw;
     } 
     sum+=raw;
    }
    return sum/len;

  }












int main (){
  std::cout<<"Creating matrix class from scratch!"<<std::endl;
  return 0;
}
