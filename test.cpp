#include<iostream>
#include<vector>
#include<stdexcept>

class matrix {
  public:
  size_t rows,cols;
  std::vector<double>vals;
  matrix(size_t r,size_t c,const std::vector<double> &v):
    rows(r),cols(c),vals(std::move(v))              //We write them in the order we initialized our params!
  {if (vals.size()!=rows*cols){
                                throw std::invalid_argument("Number of elements do not match!");}}; 
};
int main (){
  std::cout<<"Loading matrix class!"<<std::endl;
  return 0;
}
