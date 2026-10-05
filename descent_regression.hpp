#pragma once 
#include "matrix.hpp"
#include<stdexcept>
class descent_regression{
  public:
  matrix X; //Features matrix;
  matrix w;//Weights matrix;
  matrix y;//Targets matrix;
  double alpha; //Learning rate;
  descent_regression(const matrix &X,const matrix &y);
  descent_regression(const matrix &X_features,const matrix &y_targets,double learning_rate);
  descent_regression& fit( descent_regression &reg,int epochs);
  matrix predict(const descent_regression &reg);
};
