#include<iostream>
#include<stdexcept>


matrix operator+(const matrix &other)const{
  if (rows!=other.rows||cols!=other.cols){
    throw std::invalid_argument("Rows and cols must match!");
  }
  std::vector<double> vec (vals.size());
  for (size_t i=0;i<vals.size();i++){
    vec[i]=vals[i]+other.vals[i];
  }
return matrix(rows,cols,vec);}

int main (){
  return 0;
}
