#include <iostream>
#include <assert.h>

namespace dia {

class Vector {
    private:
        int *_data;
        size_t _capacity;
        size_t _size;
    
        size_t next_pow2(size_t x) {
            if (x == 0) return 1;

            x--;
            x |= x >> 1;
            x |= x >> 2;
            x |= x >> 4;
            x |= x >> 8;
            x |= x >> 16;
        #if SIZE_MAX > UINT32_MAX
            x |= x >> 32; // for 64-bit
        #endif
            x++;
            return x;
        }

        bool is_persistant() {
            if (_data == nullptr && _size == 0 && _capacity == 0) {
                return true;
            }
            else if (_data != nullptr && _size <= _capacity) {
                return true;
            }

            return false;
        }

    public:
        Vector(size_t cap = 16): _data(nullptr), _capacity(0), _size(0) {
            std::cout << "Constructor Vector called" << std::endl;

            if (cap > 0) {
                cap = next_pow2(cap);
                _data = new int[cap];
                if(_data == nullptr) {
                    std::cerr << "New is not working yeey!!" << std::endl;
                }
            }

            _capacity = cap;
#ifndef NDEBUG
            assert(is_persistant());
#endif
        }

        ~Vector() {
#ifndef NDEBUG
            assert(is_persistant());
#endif
            std::cout << "Destructor called, memory free" << std::endl;
            
            _size = 0;
            _capacity = 0;
            if (_data != nullptr) {
                delete[] _data;
            }
        }

#ifndef TEST_4
        Vector(const Vector& otherVect): _data(nullptr),_capacity(otherVect._capacity), _size(otherVect._size){
            
            std::cout<<"Copy Constructor called" << std::endl;

            _data = new int[_capacity];

            for(size_t i = 0; i < _size; i++){
                _data[i] = otherVect[i];
            }
        }

        Vector& operator = (const Vector& copyVector){
            std::cout << "Copy Assigment called" << std::endl;

            if(this == &copyVector){
                return *this;
            }

            delete[] _data;

            _capacity = copyVector._capacity;
            _size = copyVector._size;
            
            if(copyVector._data != nullptr){

                _data = new int[_capacity];

                for(size_t i = 0; i < _size; i++){
                    _data[i] = copyVector[i];
                }
            }
            else
            {
                _data = nullptr;
            }
            return *this;
        }

        Vector(Vector&& otherVector) noexcept : _data(otherVector._data), _capacity(otherVector._capacity), _size(otherVector._size){
            
            std::cout<<"Move constructor called"<<std::endl;

            otherVector._data = nullptr;
            otherVector._capacity = 0;
            otherVector._size = 0;


        }

        Vector& operator = (Vector&& moveOtherVect) noexcept {
            std::cout << "Move Assignment called" << std::endl;

            if (this != &moveOtherVect) {          
                delete[] _data;               

                _data = moveOtherVect._data;       
                _size = moveOtherVect._size;
                _capacity = moveOtherVect._capacity;

                moveOtherVect._data = nullptr;     
                moveOtherVect._size = 0;
                moveOtherVect._capacity = 0;
            }

            return *this;
        }
#endif
        
        Vector& push(int x) {
#ifndef NDEBUG
        assert(is_persistant());
#endif

            if (_data == nullptr){
                _capacity = 1;
                _size = 0;
                _data = new int[_capacity];
            }
            else if (_size == _capacity) {
                _capacity *= 2;
                int *new_data = new int[_capacity];
                if(new_data == nullptr) {
                    std::cerr << "New is not working in push yeey!!" << std::endl;
                }
                for (size_t i = 0; i < _size; i ++ ) {
                    new_data[i] = _data[i];
                }
                delete[] _data;
                _data = new_data;
            }

            _data[_size ++] = x;

#ifndef NDEBUG
            assert(is_persistant());
#endif
            return *this;
        }

        int pop() {
#ifndef NDEBUG
            assert(is_persistant());
#endif

            if(_data == nullptr) {
                std::cerr << "Cannot pop empty vector" << std::endl;
                return 0;
            }
            
            int last = std::move(_data[_size - 1]); // todo
            
            _size --;

            if(_size == 0){
                delete[] _data;
                _data = nullptr;
                _capacity = 0;
                return last;
            }

            if(_size * 2 == _capacity){
                _capacity >>= 1; // :2
                int *new_data = new int[_capacity];
                if(new_data == nullptr) {
                    std::cerr << "New is not working in push yeey!!" << std::endl;
                }
                for (size_t i = 0; i < _size; i ++ ) {
                    new_data[i] = _data[i];
                }
                delete[] _data;
                _data = new_data;
            }

#ifndef NDEBUG
            assert(is_persistant());
#endif

            return last;
        }

        int operator[](size_t i) const {
            if (i >= _size) {
                std::cerr << "Index out of bounds" << std::endl;
                return 0;
            }

            return _data[i];
        }

        size_t size() const {
            return _size;
        }

        size_t capacity() const {
            return _capacity;
        }
};

}
