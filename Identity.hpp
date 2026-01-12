#ifndef IDENTITY_HPP
#define IDENTITY_HPP

#include <vector>
#include "Matrix.hpp"

namespace pp {

using std::vector;

template<typename T>
class Identity : public Matrix<T> {
public:
    //deaf
    Identity() : Matrix<T>(vector<vector<T>>{{1}}){}
    //param
    Identity(int n) : Matrix<T>(create(n)){}
private:
    static Matrix<T> create(int n){
        vector<vector<T>> m;

        for(int i=0; i<n; i++){
            vector<T> row;
            for(int j=0; j<n; j++){
                if(i==j){
                    row.push_back(1);
                }else{
                    row.push_back(0);
                }//if
            }//for j
            m.push_back(row);
        }//for i
        return Matrix<T>(m);
    }//void
};

} // namespace pp

#endif
