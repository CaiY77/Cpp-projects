#include <iostream>
#include<stdexcept>

using namespace std;

class SquareMatrix
{
    public:
        SquareMatrix();

        ~SquareMatrix(); //destructor
        SquareMatrix (const SquareMatrix&); // constructor copy
        SquareMatrix (SquareMatrix &&); // copy
        SquareMatrix& operator=(const SquareMatrix&); // move assign
        SquareMatrix& operator=(SquareMatrix&&); //move
        
        SquareMatrix operator+(const SquareMatrix& rhs);
        bool operator==(SquareMatrix& rhs);
        size_t size();
        void resize(size_t size);
        size_t& at(size_t r, size_t c);

        void print (int r, int c){
            cout<< _matrix[r][c]<<endl;
        }
    private:
        size_t _size;
        size_t** _matrix;
};



SquareMatrix::SquareMatrix(){
    _size = 0;
}

SquareMatrix::~SquareMatrix(){
    if(_matrix != nullptr){
        for(int i = 0; i < _size; i++){
            delete[] _matrix[i];
        }
        delete[] _matrix;
    }
}

SquareMatrix::SquareMatrix (const SquareMatrix& trg){
    _size = trg._size;
     _matrix = new size_t* [_size];

    for(int i = 0; i < _size; i++){
        _matrix[i] = new size_t[_size];
    }

    for(size_t r = 0; r < _size; r++){
        for(size_t c = 0; c < _size; c++){
           _matrix[r][c] = trg._matrix[r][c];
        }
    }

}

SquareMatrix::SquareMatrix (SquareMatrix&& trg){

    _size = trg._size;
    _matrix = trg._matrix;

    trg._matrix = nullptr;

}

SquareMatrix& SquareMatrix::operator=(SquareMatrix&& assign){
    if(_matrix != nullptr){

        for(int i = 0; i < _size; i++){
            delete[] _matrix[i];
        }
        delete[] _matrix;  
    }

    _size = assign._size;
    _matrix = assign._matrix;

    assign._matrix = nullptr;

    return *this;
}

SquareMatrix& SquareMatrix::operator=(const SquareMatrix& assign){
    if(this != &assign){

        if(_matrix != nullptr){

            for(int i = 0; i < _size; i++){
                delete[] _matrix[i];
            }
            delete[] _matrix;  
        }
        
        _size = assign._size;
        _matrix = new size_t* [_size];
        for(int i = 0; i < _size; i++){
            _matrix[i] = new size_t[_size];
        }

        for(size_t r = 0; r < _size; r++){
            for(size_t c = 0; c < _size; c++){
                _matrix[r][c] = assign._matrix[r][c];
            }
        }
    }
    return *this;
}

SquareMatrix SquareMatrix::operator+(const SquareMatrix& rhs){
    SquareMatrix temp;
    temp.resize(_size);

    for(size_t r = 0; r < _size; r++){
        for(size_t c = 0; c < _size; c++){
            temp.at(r,c) = _matrix[r][c] + rhs._matrix[r][c];
        }
    }

    return temp;
}

bool SquareMatrix::operator==(SquareMatrix& rhs){
    
    for(size_t r = 0; r < _size; r++){
        for(size_t c = 0; c < _size; c++){
            if(_matrix[r][c] != rhs._matrix[r][c]){
                return false;
            }
        }
    }
    
    return true;
}

size_t SquareMatrix::size(){
    return _size;
}

void SquareMatrix::resize(size_t size){
    _size = size;

    _matrix = new size_t* [_size];

    for(int i = 0; i < _size; i++){
        _matrix[i] = new size_t[_size];
    }

    for(size_t r = 0; r < _size; r++){
        for(size_t c = 0; c < _size; c++){
           _matrix[r][c] = 0;
        }
    }

}

size_t& SquareMatrix::at(size_t r, size_t c){
  if( r < _size && c < _size ){
        size_t& ref = _matrix[r][c];
        return ref;
    }else{
        throw std::out_of_range("index is out of the matrix's range");
    }  

}