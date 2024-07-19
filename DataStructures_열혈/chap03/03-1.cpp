/*
1. 리스트를 생성 및 초기화 한 다음, 정수 1부터 9까지 리스트에 저장한다.
2. 리스트에 저장된 값을 순차적으로 참조하여 그 합을 계산하여 출력한다.
3. 리스트에 저장된 값들 중 2의 배수와 3의 배수에 해당하는 값을 모두 삭제한다.
4. 마지막으로 리스트에 저장된 데이터를 순서대로 출력한다. 
*/

#include "ArrayList.hpp"

int main()
{
    ArrayList list;
    for(int i = 0; i < 4; i++)
    {
        list.AddNode(i);
    }
    list.PrintAll();
    cout << "========================" << endl;
    list.DeleteNodeData(3);
    list.PrintAll();

    return 0;
}