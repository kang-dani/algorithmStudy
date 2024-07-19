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
        delete temp;
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
        delete data;
        data = temp;
        delete temp;
        
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