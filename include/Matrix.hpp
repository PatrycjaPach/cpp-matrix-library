#ifndef MATRIX_HPP
#define MATRIX_HPP

/**
 * \brief Class representing a general matrix.
 *
 * Provides a general matrix implementation with common
 * methods and operator overloads used by derived matrix
 * classes.
 */
#include <iostream>
#include <vector>
#include <stdexcept> //for throw


using std::vector, std::cout, std::endl, std::invalid_argument;
/**
 * \brief namespace pp containing the matrix class
 */
namespace pp{

template <class T>
class Matrix{
private:
    vector<vector<T>> _matrix;
public:
    /*---CONSTRUCTORS---*/

    /**
     * \brief default constructor
     * a constructor that creates a matrix with one 0
     */
    Matrix(): Matrix(vector<vector<T>>{{0}}){}
    
    /**
     * \brief parametrized constructor
    * Creates a matrix from a two-dimensional vector.
    * Checks whether the matrix is non-empty and whether
    * all rows have the same number of columns.
    *
    * \param matrix Two-dimensional vector representing the matrix.
    */
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
    
    /**
     * \brief setter
     * 
     * Assigns a value to the element at position (a, b)
     * 
     * \param a Row 
     * \param b Column 
     * \param c Value to be assigned
     */
    void setMatrix(size_t a, size_t b, size_t c){
        if(a<_matrix.size() && b<_matrix[0].size()){
            _matrix[a][b]=c;
        }
    }

    /**
     * \brief getter
     * 
     * Return a value to the element at position (a, b)
     * 
     * \param a Row 
     * \param b Column 
     */
    T getMatrix(int a, int b) const{
        if(a>=_matrix.size() || b>=_matrix[0].size()){
            throw std::invalid_argument("Wrong index");
        }
        return _matrix[a][b];
    }
    /**
    * \brief Adds two matrix
    * Performs element-wise addition of two matrix.
    * Both matrix must have the same dimensions.
    * \param other Matrix to be added.
    */
    Matrix operator+(const Matrix<T>& other) const{
        vector<vector<T>> v;
        v.resize(_matrix.size());
        
        if(_matrix.size()!=other._matrix.size() || 
        _matrix[0].size()!=other._matrix[0].size()){
            throw std::invalid_argument("Matrix must have the same size"); 
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
    /**
     * \brief Adds another matrix to this matrix
     * 
     * Perform element-wise addition of two matrix
     * and save it in first matrix.
     * Both matrix must have the same dimensions.
     * 
     * \param other Matrix to be added.
     */
    Matrix& operator+=(const Matrix<T>& other){
        if(_matrix.size()!=other._matrix.size() || 
        _matrix[0].size()!=other._matrix[0].size()){
            throw std::invalid_argument("Matrix must have the same size"); 
        }

        for(int i=0; i<_matrix.size(); i++){
            for(int j=0; j<_matrix[0].size(); j++){
                _matrix[i][j]+=other._matrix[i][j];
            }
        }
        return *this;
    }
    /**
    * \brief Subtracts two matrix
    *
    * Performs element-wise subtraction of two matrix
    * Both matrix must have the same dimensions.
    *
    * \param other Matrix to be subtracted.
    */
    Matrix operator-(const Matrix<T>& other) const{
        vector<vector<T>> v;
        v.resize(_matrix.size());
        
        if(_matrix.size()!=other._matrix.size() || 
        _matrix[0].size()!=other._matrix[0].size()){
            throw std::invalid_argument("Matrix must have the same size"); 
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
    /**
    * \brief Subtracts another matrix from this matrix.
    *
    * Performs element-wise subtraction of two matrix
    * and save it in first matrix.
    * Both matrix must have the same dimensions.
    *
    * \param other Matrix to be subtracted.
    */
    Matrix& operator-=(const Matrix<T>& other){
        if(_matrix.size()!=other._matrix.size() || 
        _matrix[0].size()!=other._matrix[0].size()){
            throw std::invalid_argument("Matrix must have the same size"); 
        }

        for(int i=0; i<_matrix.size(); i++){
            for(int j=0; j<_matrix[0].size(); j++){
                _matrix[i][j]-=other._matrix[i][j];
            }
        }
        return *this;
    }
    /**
     * \brief multiplicates matrix
     * 
     * Perform matrix multiplicaton
     * Throws an error when the dimensions of the columns 
     * do not match the dimensions of the rows of 
     * the second matrix.
     * 
     * \param other Matrix to be multiplicated
     */
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
    /**
     * \param multiplicated another matrix from this matrix
     * 
     * Multiplies two matrix.
     * 
     * Throws an error when the dimensions of the columns do 
     * not match the dimensions of the rows of the second matrix.
     */
    Matrix& operator*=(const Matrix<T>& other){
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
        _matrix=v;
        return *this;
    }
    /**
    * \brief Compares two matrix for equality
    * 
    * Copmares two matrix
    * 
    * Checks whether two matrix have the same dimensions
    * and identical elements
    */ 
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
	/**
	* \brief Compares two matrix for inequality
	* 
	* Compares two matrix
	* 
	* Checks whether two matrix have different dimensions
	* or different elements.
	*/
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
	/**
	* \brief Multiplies matrix by a scalar.
	*
	* Multiplies each matrix element by a scalar value.
	*/
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
	/**
	* \brief Divides matrix by a scalar
	*
	* Divides each matrix element by a scalar value
	*/
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

    

	/**
	* \brief Reads matrix values.
    * Reads matrix elements
    */
    void read(){
        for(int i=0; i<_matrix.size(); i++){
            for(int j=0; j<_matrix[0].size(); j++){
                cout<<_matrix[i][j]<<" ";
            }
        cout<<endl;
        } 
    }

    /**
     * \brief Calculates matrix determinant
     * 
     * Calculates the determinant of the matrix
     * using the Gaussian elimination method
     * 
     * \param det the determinant of the matrix
     * \param mtx copy of the matrix
     * \param n matrix size
    */
    double determinant(){
        double det {1.0};
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
    /**
     * \brief Calculates the transpose matrix
     * 
     * Calculate the transpose matrix
     * 
     * \param mtx copy of the matrix
     * \param v calculated
     * \param n matrix size
     */
    Matrix<T> transpose() {
        auto mtx=_matrix;
        vector<vector<T>> v;
        int n=_matrix.size();
        int m=_matrix[0].size();
        
        v.resize(m);
        for(int i=0; i<m; i++){
            v[i].resize(n);
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                v[j][i] = _matrix[i][j];
            }
        }
        return Matrix<T>(v);
    }
}; //class

} //namespace
#endif