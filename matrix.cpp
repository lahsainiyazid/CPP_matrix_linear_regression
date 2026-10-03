#include "matrix.hpp"
#include <stdexcept>

  matrix::matrix(size_t r,size_t c,const std::vector<double>&vec):rows(r),cols(c),vals(vec)
  {if (r*c !=vals.size()){
      throw std::invalid_argument("Invalid matrix size!");}}













int main (){
  return 0;
}
