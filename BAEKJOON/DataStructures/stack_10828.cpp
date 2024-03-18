#include <iostream>
#include <string>

using namespace std;

int main()
{
    int* data;
    int size = 0;
    int N;
    cin >> N;
    cin.ignore();   //cin 과 getline 사이의 '/n' 을 버퍼에서 삭제해주는 역할
    for(int i = 0; i < N; i++)
    {
        string command;
        getline(cin, command);

        if(command.find(" ") != string::npos)
        {
            // command 에서 공백 존재, 명령문이 'push X' 임
            // 공백 기준으로 문자열 자르기
            string intNumberX = command.substr(command.find(" ")+1, command.length());
            // 자른 문자열 정수로 변환하기
            int X = atoi(intNumberX.c_str());

            if(size == 0)
            {
                size++;
                data = new int[size];                   // 새로운 크기의 배열 선언
                data[size - 1] = X;                     // 입력 받은 데이터 값 입력
            }
            else                                        // stack이 만들어져 있을 때
            {
                size++;
                int* temp = new int[size];              // 기존보다 하나 큰 크기의 배열 선언
                for(int i = 0; i < size; i++)           // 기존 데이터 값 복사
                {
                    temp[i] = data[i];
                }
                temp[size - 1] = X;                     // 입력 받은 데이터 값 넣어주기
                delete[] data;                          // 기존의 배열 삭제
                data = temp;                            // 새로 만든 배열 연결 
            } 

        }
        else
        {
            // command 에서 공백 존재하지 않을 때. 
            if(command == "pop")
            {
                if(size == 0)                           // 배열에 값이 없을 때
                {
                    cout << -1 << endl;
                }
                else                                    // 배열에 값이 있을 때
                {
                    cout << data[size - 1] << endl;     // 마지막 값 출력
                    int* temp = new int[size - 1];      // 기존보다 하나 작은 배열 선언
                    for(int i = 0; i < size - 1; i++)   // 기존 데이터값 복사
                    {
                        temp[i] = data[i];
                    }
                    delete[] data;                      // data에 연결된 배열 삭제
                    data = temp;                        // 새로 만든 배열 연결
                    size--;
                }
            }
            else if(command == "size")
            {
                cout << size << endl;                   // size 출력
            }
            else if(command == "empty")
            {
                if(size == 0) cout << 1 << endl;        // 배열이 비어있으면 1 출력
                else cout << 0 << endl;                 // 그렇지 않다면 0 출력

            }
            else if(command == "top")
            {
                if(size == 0) cout << -1 << endl;        // 배열이 비어있으면 -1 출력
                else cout << data[size - 1] << endl;     // 스택의 가장 위에 있는 정수 출력
            }
        }
    }

    // 안전하게 데이터의 값을 지워주기 위해 아래 명령 실행
    delete[] data;
    data = nullptr;
    return 0;
}