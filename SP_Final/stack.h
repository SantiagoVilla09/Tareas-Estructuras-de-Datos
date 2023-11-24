#pragma once
#include <stdexcept>

template<typename T>
class Stack{

public:

    Stack(const Stack&) = delete;
    Stack<T>& operator=(const Stack&) = delete;

    Stack(int capacity){
        _capacity = capacity;
        _data = new T[_capacity];
        _top = 0;
    }
    ~Stack(){
        delete[] _data;
    }

    void push(T value){

        if(_top==_capacity){
            throw std::overflow_error("Stack Overflow");
        }

        _data[_top] = value;
        ++_top;
    }

    T pop(){

        if(_top==0){
            throw std::underflow_error("Stack Underflow");
        }
        --_top;
        return _data[_top];
    }

    T peek() const{

        if(_top==0){
            throw std::underflow_error("Stack Underflow");
        }
        return _data[_top-1];
    }

    int size() const{
        return _top;
    }

    int capacity() const{
        return _capacity;
    }

    bool is_empty() const{
        return size()==0;
    }

    void clear(){
        _top = 0;
    }

private:
    T* _data;
    int _capacity;
    int _top;


};