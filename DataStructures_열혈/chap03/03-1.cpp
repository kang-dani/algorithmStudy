/*
1. 리스트를 생성 및 초기화 한 다음, 정수 1부터 9까지 리스트에 저장한다.
2. 리스트에 저장된 값을 순차적으로 참조하여 그 합을 계산하여 출력한다.
3. 리스트에 저장된 값들 중 2의 배수와 3의 배수에 해당하는 값을 모두 삭제한다.
4. 마지막으로 리스트에 저장된 데이터를 순서대로 출력한다. 
*/

#include "ArrayList.hpp"

int main()
{
    //1
    ArrayList list;
    for(int i = 0; i < 9; i++)
    {
        list.AddNode(i + 1);
    }
    list.PrintAll();

    cout << "========================" << endl;

    //2
    int sum;
    for(int i = 0; i < list.count; i++)
    {
        sum += list.GetNodeData(i);
    }
        cout << sum << endl;

    cout << "========================" << endl;

    //3
    for(int i = 0; i < list.count; i++)
    {
        if(list.GetNodeData(i) % 2 == 0)
        {
            list.DeleteIndex(i);
        }
        if(list.GetNodeData(i) % 3 == 0)
        {
            list.DeleteIndex(i);
        }
    }
    //4
    list.PrintAll();

    return 0;
}