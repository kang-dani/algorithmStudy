#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    // C++ 과 C 의 표준 스트림 동기화 연결 끊음, 시간 단축을 위함
    // scanf/printf 사용 지양, cin/cout 사용 지향
    ios_base::sync_with_stdio(false);
    // cin 과 cout 의 자동 flush 행동을 해제
    cin.tie(NULL);

    // 시간초과를 방지하기 위해 비효율적인 동적할당 대신 가변성 있는 배열 vector를 사용
    vector<int> data;
    int N;
    cin >> N;
    cin.ignore();   //cin 과 getline 사이의 '/n' 을 버퍼에서 삭제해주는 역할
    for(int i = 0; i < N; i++)
    {
        string command;
        getline(cin, command);
        
        // string::npos == 쓰레기 값 
        // find() 함수는 일치하는 값의 첫번째 인덱스를 반환
        if(command.find(" ") != string::npos)
        {
            // command 에서 공백 존재, 명령문이 'push X' 임
            // 공백 기준으로 문자열 자르기
            string intNumberX = command.substr(command.find(" ")+1, command.length());
            // 자른 문자열 정수로 변환하기 (string to integer)
            int X = stoi(intNumberX);
            
            data.push_back(X);
        } 
        else
        {
            int commandtoInt = stoi(command);
            // command 에서 공백 존재하지 않을 때. 
            switch(commandtoInt)
            {
                case 2:
                    if(data.empty())                           // 배열에 값이 없을 때
                    {
                        // endl; 은 개행의 역할도 하지만 출력 버퍼를 비우는 flush 역할도 하기에 직접 개행을 실행 
                        //-> 실행 속도를 높여주기 위함
                        cout << "-1\n";
                    }
                    else                                    // 배열에 값이 있을 때
                    {
                        cout << data.back() << "\n";        // 마지막 원소값 출력
                        data.pop_back();                    // 마지막 원소 제거
                    }
                    break;
                case 3:
                    cout << data.size() << "\n";                // size 출력
                    break;
                case 4:
                    cout << data.empty() << "\n";
                    break;
                case 5:
                    if(data.empty()) cout << "-1\n";        // 배열이 비어있으면 -1 출력
                    else cout << data.back() << "\n";     // 스택의 가장 위에 있는 정수 출력
                    break;
                default:
                break;
            }
        }
    }
    return 0;
}