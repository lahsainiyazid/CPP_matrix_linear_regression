#include<iostream>
#include "descent_regression.hpp"

descent_regression::descent_regression(const matrix &X_features,const matrix &y_targets)():X(X_features),y(y_targets),w(matrix()){
if (X_features.rows!=y_targets.rows){
  throw std::invalid_agument("Missing data");
}
}



int main (){
  return 0;
}
