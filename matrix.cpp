#include<iostream>
#include<vector>
#include<stdexcept>
class matrix{
  public:
    size_t rows;
    size_t cols;
    std::vector<double>vals;
   matrix (size_t r,size_t c,const std::vector<double> &vec):
     rows (r),cols(c),vals(vec)
   {if (r*c !=vals.size()){
                            throw std::invalid_argument("rows *cols must match vector size!");
                          }}; 
    
   //Read and write overload of our () method!: operator () is a special element allowing us to access elements!
   double &operator()(size_t r,size_t c){
     return vals[r*cols +c ];
   } 
   //Read only of our overload () method: First const so it is read only second const to diferentiate from our first function +object doesnt change in c++ we don't overload by return type!
   //Here const enforces a read only contract on the obejct calling it
   const double &operator()(size_t r,size_t c)const{
     return vals[r*cols +c];
   }
 matrix operator+(const matrix &other)const {
    if (rows!=other.rows||cols!=other.cols){
      throw std::invalid_argument("Matrix rows and cols must match!");
    }
    std::vector<double>vec(vals.size());
    for (size_t i=0;i<vals.size();i++){
        vec[i]=vals[i]+other.vals[i];
    }
  return matrix(rows,cols,vec);}
 //We do const because methods inside of class have this pointer to object const allows us to put a smart contract forcing it to be a const pointer
   matrix operator - (const matrix &other)const{
     if (rows!=other.rows||cols!=other.cols){
       throw std::invalid_argument("Matrix rows and cols must match!");
     }
     std::vector<double> vec(vals.size());
     for (size_t i=0;i<vals.size();i++){
       vec[i]=vals[i]-other.vals[i];
     }
  return matrix(rows,cols,vec);}
  matrix operator *(const double a)const {
 
    std::vector<double>vec(vals.size());
    for (size_t i=0;i<vals.size();i++){
      vec[i]=vals[i]*a;
    }
    return matrix(rows,cols,vec);
  }
 };
int main (){
  std::cout<<"Testing vector class !"<<std::endl;
  return 0;
}
