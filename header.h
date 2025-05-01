#pragma once
#include<iostream>
#include<string>
using namespace std;

const int Size = 1000;


class ADT {


public:

    virtual  void push(char val) = 0;
    virtual  char pop() = 0;
    virtual char peek() = 0;
    virtual  bool isEmpty() = 0;

};


class ArrayStack :public ADT {
private:
    char arr[Size];
    int top;

public:
    ArrayStack();

    void push(char val);

    char pop();

    char peek();

    bool isEmpty();
};

string balance(string data);


class stringStack {
private:
    string arr[Size];
    string undo[Size];
    string unVal[Size];
    string Redo[Size];
    string ReVal[Size];
    int unTop;
    int ReTop;
    int top;

public:
    stringStack();

    void type(string val);

    string pop();

    void undoFun();

    void redoFun();

    string peek();

    bool isEmpty();
    void display();



}; 
