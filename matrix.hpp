#pragma once 
#include<vector>

class matrix{
  public:
    size_t rows;
    size_t cols;
    std::vector<double>vals;
    matrix (size_t r,size_t c,const std::vector<double>&vec);
    matrix (size_t r,size_t c);
};

