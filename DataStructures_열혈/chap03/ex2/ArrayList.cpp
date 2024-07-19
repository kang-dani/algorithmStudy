#include "ArrayList.hpp"

void ArrayList::AddNode(int _data)
{
    if(IsEmpty())
    {
        data = new int;
        *data = _data;
    }
    else
    {
        int* temp = new int[count + 1];
        for(int i = 0; i < count; i++)
        {
            temp[i] = data[i];
        }
        temp[count] = _data;
        delete data;
        data = temp;
    }
    count++;
}

void ArrayList::DeleteNodeData(int _data)
{
    if(IsEmpty())
    {
        cout << "데이터가 비어있어 해당 작업을 진행할 수 없습니다." << endl;
    }
    else
    {
        int deleteCount = 0;
        for(int i = 0; i < count; i++)
        {
            if(data[i] == _data)
            {
                deleteCount++;
            }
        }

        int tempIndex = 0;
        int* temp = new int[count - deleteCount];
        for(int i = 0; i < count; i++)
        {
            if(data[i] != _data)
            {
                temp[tempIndex] = data[i];
                tempIndex++;
            }
        }
        count -= deleteCount;
        delete data;
        data = temp;
    }
}

void ArrayList::DeleteIndex(int _index)
{
    if(IsEmpty())
    {
        cout << "리스트가 비어있어서 해당 작업을 진행할 수 없습니다. " << endl;
        return;
    }
    else
    {
        int* temp = new int[count - 1];
        int tempIndex = 0;
        for(int i = 0; i < count; i++)
        {
            if(i != _index)
            {
                temp[tempIndex] = data[i];
                tempIndex++;
            }
        }
        delete data;
        data = temp;
        count--;
    }
}

bool ArrayList::IsEmpty()
{
    if(data == nullptr || count == 0)
    {
        return true;
    }
    return false;
}

void ArrayList::PrintAll()
{
    if(!IsEmpty())
    {
        for(int i = 0; i < count; i++)
        {
            cout << "data[" << i << "] : " << data[i] << endl;
        }
    }
    else cout << "리스트에 데이터가 들어있지 않습니다." << endl;
}

int ArrayList::GetListSize()
{
    return count;
}

int ArrayList::GetNodeData(int _index)
{
    if(_index >= 0 && _index < count)
    {
        return data[_index];
    }
    cout << "해당 인덱스 값은 존재하지 않습니다. " << endl;
    return -1;
}

ArrayList::ArrayList()
{
    data = nullptr;
    count = 0;
}

ArrayList::~ArrayList()
{
    delete data;
    data = nullptr;
    count = 0;
}