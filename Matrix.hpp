#ifndef MATRIX_HPP
#define MATRIX_HPP
#include <iostream>
#include <vector>
#include <stdexcept> //for throw


using std::vector, std::cout, std::endl, std::invalid_argument;
namespace pp{

template <class T>
class Matrix{
private:
    vector<vector<T>> _matrix;
public:
    //deafult construcotr
    Matrix(): Matrix<T>(vector<vector<T>>{{0}}){}

    //parametrized constructor
    Matrix(const vector<vector<T>> & matrix): _matrix(matrix){
        if(matrix.empty()){
            cout<<"Matrix must have arguments"<<endl;
        }
        int cols=matrix[0].size();

        for(int i=0; i<matrix.size(); i++){
            if(matrix[i].size()!=cols){
                cout<<"Rows must have the same size"<<endl;
            }
        }
    }

    //setter, getter

    void setMatrix(size_t a, size_t b, size_t c){
        if(a<_matrix.size() && b<_matrix[0].size()){
            _matrix[a][b]=c;
        }
    }

    T getMatrix(int a, int b) const{
        if(a>=_matrix.size() || b>=_matrix[0].size()){
            throw std::invalid_argument("Wrong index");
        }
        return _matrix[a][b];
    }

    //overloading
    /*ADD*/
    Matrix operator+(const Matrix<T>& other) const{
        vector<vector<T>> v;
        v.resize(_matrix.size());
        
        if(_matrix.size()!=other._matrix.size() || 
        _matrix[0].size()!=other._matrix[0].size()){
            throw std::invalid_argument("Matrices must have the same size"); 
        }

        for(int i=0; i<_matrix.size(); i++){
            v[i].resize(_matrix[i].size());
        }

        for(int i=0; i<_matrix.size(); i++){
            for(int j=0; j<_matrix[i].size(); j++){
                v[i][j]=_matrix[i][j]+other._matrix[i][j];
            }
        }
        return Matrix(v);
    }
    /*SUBSTRACTION*/
    Matrix operator-(const Matrix<T>& other) const{
        vector<vector<T>> v;
        v.resize(_matrix.size());
        
        if(_matrix.size()!=other._matrix.size() || 
        _matrix[0].size()!=other._matrix[0].size()){
            throw std::invalid_argument("Matrices must have the same size"); 
        }

        for(int i=0; i<_matrix.size(); i++){
            v[i].resize(_matrix[i].size());
        }

        for(int i=0; i<_matrix.size(); i++){
            for(int j=0; j<_matrix[i].size(); j++){
                v[i][j]=_matrix[i][j]-other._matrix[i][j];
            }
        }
        return Matrix(v);
    }
    
    /*MULTIPLICATION*/
    Matrix operator*(const Matrix<T>& other) const{
        vector<vector<T>> v;
        v.resize(_matrix.size());
        
        if(_matrix[0].size()!=other._matrix.size()){
            throw std::invalid_argument("The size of the columns of one matrix must match the size of the rows of the other");
        }

        for(int i=0; i<_matrix.size(); i++){
            v[i].resize(other._matrix[0].size());
        }

        for(int i=0; i<_matrix.size(); i++){ //rows A
            for(int j=0; j<other._matrix[0].size(); j++){ //columns B
                T sum=0;
                for(int k=0; k<_matrix[0].size(); k++){
                    sum+=_matrix[i][k]*other._matrix[k][j];
                }
                v[i][j]=sum;
            }
        }
        return Matrix(v);
    }
    /*COMPARISIONS*/
    bool operator==(const Matrix<T>& other) const{       
        if(_matrix.size()!=other._matrix.size() || 
        _matrix[0].size()!=other._matrix[0].size()){
            return false;
        }

        for(int i=0; i<_matrix.size(); i++){
            for(int j=0; j<_matrix[i].size(); j++){
                if(_matrix[i][j]!=other._matrix[i][j]){
                    return false;
                } 
            }
        }
        return true;
    }

    /*CONTRADICTION*/

    bool operator!=(const Matrix<T>& other) const{       
        if(_matrix.size()!=other._matrix.size() || 
        _matrix[0].size()!=other._matrix[0].size()){
            return false;
        }

        for(int i=0; i<_matrix.size(); i++){
            for(int j=0; j<_matrix[i].size(); j++){
                if(_matrix[i][j]!=other._matrix[i][j]){
                    return true;
                } 
            }
        }
        return false;
    }
    /*SCALAR MULTIPLICATION*/

    Matrix operator*(const T& scalar) const{
        vector<vector<T>> v;
        v.resize(_matrix.size());

       for(int i=0; i<_matrix.size(); i++){
            v[i].resize(_matrix[0].size());
        }
        for(int i=0; i<_matrix.size(); i++){
            for(int j=0; j<_matrix[i].size(); j++){
                v[i][j]=_matrix[i][j]*scalar;
            }
        }
        return Matrix(v);
    }

    /*SCALAR DIVISION*/
    Matrix operator/(const T& scalar) const{
        vector<vector<T>> v;
        v.resize(_matrix.size());

       for(int i=0; i<_matrix.size(); i++){
            v[i].resize(_matrix[0].size());
        }
        for(int i=0; i<_matrix.size(); i++){
            for(int j=0; j<_matrix[i].size(); j++){
                v[i][j]=_matrix[i][j]/scalar;
            }
        }
        return Matrix(v);
    }
    //void 
    void read(){
        for(int i=0; i<_matrix.size(); i++){
            for(int j=0; j<_matrix[0].size(); j++){
                cout<<_matrix[i][j]<<" ";
            }
        cout<<endl;
        } 
    }

    double determinant(){
        double det=1.0;
        auto mtx=_matrix;
        int n=_matrix.size();  
        
        if(mtx.size()!=mtx[0].size()){
            throw std::invalid_argument("Rows and columns size must be the same");
        }

        for(int k=0; k<n; k++){
            if(mtx[k][k]==0) return 0.0;
            for(int r=k+1; r<n; r++){
                T m=mtx[r][k]/mtx[k][k];
                for(int i=k+1; i<n; i++){
                    mtx[r][i]-=m*mtx[k][i];
                }//for3
            }//for2
        }//for1

        for(int i=0; i<n; i++){
            det*=mtx[i][i];
        }

        return det;
    }
}; //class

} //namespace
#endif