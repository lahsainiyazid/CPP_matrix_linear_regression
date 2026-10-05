#include<iostream>
#include<stdexcept>
#include "descent_regression.hpp"



descent_regression::descent_regression(const matrix &X_features,const matrix &y_targets):X(X_features),y(y_targets),w(matrix(X_features.cols,1)),alpha(0.1){
if (X_features.rows!=y_targets.rows){
  throw std::invalid_argument("Missing data");
}
if (X_features.cols!=w.rows){
  throw std::invalid_argument("Invalid features/weights matrix!");
}
}
descent_regression::descent_regression(const matrix &X_features,const matrix &y_targets,double learning_rate):X(X_features),y(y_targets),w(matrix(X_features.cols,1)),alpha(learning_rate)
{
  if (X_features.rows!=y_targets.rows){
    throw std::invalid_argument("Missing data!");
  }
if(X_features.cols!=w.rows){
  throw std::invalid_argument("Invalid features/weights/matrix");
}
}




