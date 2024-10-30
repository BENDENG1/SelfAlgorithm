/*
백준 틱택토

그냥 조건에 맞춰서 검사하면 될듯 싶은 구현 문제?

1. ox의 갯수 판별
2. ox의 3개연속 완성에 대한 판별
   - 가로, 세로, 대각선
   - 만약 완성이라면 
        - o인 경우는 x의 갯수가 같아야 함 V
        - x인 경우는 o의 갯수 + 1이어야함 V
        - 둘다 완성인 경우는 없음 V
        - 만약 두줄 완성일경우 (o는 안됨) 같은 좌표가 하나라도 존재해야함 V
    -완성X
        - 9개가 다 꽉차는 경우(일직선은 없음) -> 근데 이거는 5개가 꽉채워줘야하는 상황이라 필터에서 걸러짐(갯수가 5개 넘어갈 수 없어서) V
*/
#include <iostream>
#include <vector>

using namespace std;

bool check(const vector<vector<char>> &v);

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);

    string s;
    vector<vector<char>> v(3,vector<char>(3,0));

    while(1){
        cin >> s;
        if(s == "end")
            break;
        for(int i = 0 ; i < 3; i++){
            for(int j = 0; j < 3; j++){
                v[i][j] = s[i * 3  + j];
            }
        }
        
        if(check(v)){
            cout << "valid\n";
        }else{
            cout << "invalid\n";
        }
    }

    return 0;
}

bool check(const vector<vector<char>> &v){
    int XFinish = 0;
    int OFinish = 0;
    int XCount = 0;
    int OCount = 0;
    
    //갯수 확인
    for(auto a : v){
        for(char c : a){
            if(c == 'X'){
                XCount++;
            }else if(c == 'O'){
                OCount++;
            }
        }
    }

    if(!(XCount == OCount || XCount == OCount + 1)){
        return false;
    }

    // 세로가로 대각 확인
    for(int i = 0; i < 3; i++){
        if(v[i][0] == 'X' && v[i][1] =='X' && v[i][2] =='X')
            XFinish++;
        if(v[0][i] == 'X' && v[1][i] == 'X' && v[2][i] == 'X')
            XFinish++;
        if(v[i][0] == 'O' && v[i][1] =='O' && v[i][2] =='O')
            OFinish++;
        if(v[0][i] == 'O' && v[1][i] == 'O' && v[2][i] == 'O')
            OFinish++; 
    }
    if(v[0][0] =='X' && v[1][1] == 'X' && v[2][2] == 'X')
        XFinish++;
    if(v[0][2] =='X' && v[1][1] == 'X' && v[2][0] == 'X')
        XFinish++;
    if(v[0][0] =='O' && v[1][1] == 'O' && v[2][2] == 'O')
        OFinish++;
    if(v[0][2] =='O' && v[1][1] == 'O' && v[2][0] == 'O')
        OFinish++;

    if((XFinish >= 1 && OFinish >= 1) || (OFinish == 1 && XCount != OCount) 
        || (XFinish == 0 && OFinish == 0 && XCount + OCount != 9) ||(XFinish == 1 && XCount == OCount)){
        return false;
    }
    
    return true;
}

