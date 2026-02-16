# Matrix Library (C++ OOP)

A small object-oriented C++ library for matrix operations.
The project implements a base `Matrix` class with derived specializations (`Identity`, `Diagonal`) and provides operator overloading and common linear algebra utilities such as transpose and determinant calculation.

This project was developed individually as a practice project for object-oriented programming in C++.

---

## Features

* Operator overloading 
* Matrix transpose
* Determinant calculation
* Inheritance-based design
* Specialized matrices:

  * `Identity`
  * `Diagonal`
* Simple example program (`main.cpp`)
* CMake build configuration

---

## Project Structure
---

CMakeLists.txt
Doxyfile
```
/include
Matrix.hpp, Diagonal.hpp, Identity.hpp
```
/src
main.cpp
---

### Class Design

### Matrix

Base class representing a general matrix.

Provides:

* constructors and destructor
* element access
* arithmetic operations
* transpose
* determinant

Example responsibilities:

* storing matrix data
* validating dimensions
* performing calculations

---

### Identity : public Matrix

Represents an identity matrix.

Properties:

* square matrix
* ones on the main diagonal
* zeros elsewhere

---

### DiagonalMatrix : public Matrix

Represents a diagonal matrix.

Properties:

* non-zero elements only on the main diagonal

---

## Implemented Operations

### Transpose

Returns a matrix with swapped rows and columns.

```
A(i, j) -> A(j, i)
```

### Determinant

Computes the determinant of a square matrix.

Supported for:

* 2×2
* 3×3
* larger matrices (depending on implementation method, e.g. recursive expansion or Gaussian elimination)

---

## Educational Purpose

The goal of this project was to practice:

* object-oriented design
* inheritance and polymorphism
* operator overloading
* building projects using CMake

---

## Author

Created as an individual project.
