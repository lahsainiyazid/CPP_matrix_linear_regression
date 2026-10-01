#include<iostream>
#include<vector>
#include<stdexcept>
class matrix{
  public:
    size_t rows;
    size_t cols;
    std::vector<double>vals;
   matrix (size_t r,size_t c,const std::vector<double> &vec):
     rows (r),cols(c),vals(std::move(vec))
   {if (r*c !=vals.size()){
                            throw std::invalid_argument("rows *cols must match vector size!");
                          }}; 
    };
int main (){
  std::cout<<"Testing vector class !"<<std::endl;
  return 0;
}
