#ifndef DIAGONAL_HPP
#define DIAGONAL_HPP

#include <vector>
#include "Matrix.hpp"  

namespace pp{
using std::vector;
template<typename T>
class Diagonal : public Matrix<T> {
public:
    //deafult 
    Diagonal() : Matrix<T>(vector<vector<T>>{{0}}) {}

    //parametrized 
    Diagonal (const vector<T>& val): Matrix<T>(create(val)){
    }

private:
    static Matrix<T> create(const vector<T>& v){
        int n=v.size();
        vector<vector<T>> m;

        for(int i=0; i<n; i++){
            vector<T> row;
            for(int j=0; j<n; j++){
                if(i==j){
                    row.push_back(v[i]);
                } else{
                    row.push_back(0);
                } //if
            }//for j
            m.push_back(row);
        }//for i
        return Matrix<T>(m);
    }//void

}; //class

} //namespace
#endif

