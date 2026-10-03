#include<iostream>
#include<vector>
#include<stdexcept>


//c(i,j)=sigma(a(i,k)*b(k,j))

matrix operator *(const matrix &other){
  if (cols!=other.rows){
    throw std::invalid_argument("Inner dimesnions must match!");
  }
  std::vector<double>vec(rows*other.cols,0.0);
  matrix result(rows,other.cols,vec);
  for (size_t i=0;i<rows;i++){
    for (size_t j=0;j<other.cols;j++){
      double sum=0.0;
      for (size_k =0;k<cols;k++){
        sum+=(*this)(i,k)* other(k,j);
      }
    result(i,j)=sum;}
  }
return result;}

int main (){

}
