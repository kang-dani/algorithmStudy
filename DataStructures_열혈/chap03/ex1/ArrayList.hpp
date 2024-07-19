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
    void DeleteIndex(int _index);
    bool IsEmpty();
    void PrintAll();
    int GetListSize();
    int GetNodeData(int _index);

public:
    ArrayList();
    ~ArrayList();
};