#pragma once
#include <iostream>

using namespace std;

class ArrayList
{
public:
    int* data;
    int count;

public:
    void AddNode(int _data);
    void DeleteNodeData(int _data);
    bool IsEmpty();
    void PrintAll();
    int GetListSize();

public:
    ArrayList();
    ~ArrayList();
};