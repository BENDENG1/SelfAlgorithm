/*
톱니바퀴

톱니바퀴 k번 회전


맞닿은 극에 따라서 회전ox 결정됨
맞닿은 부분 다름 -> 반대로(시계 반대 방향) 같음 -> 회전x
 1인 경우는 시계 방향이고, -1인 경우는 반시계 방향
*/
#include <iostream>
#include <deque>
#include <vector>
#include <cmath>

using namespace std;

vector<deque<int>> v(4,deque<int>()); //dq의 front가 맨 위(12시) 시계방향
vector<int> rotate(4,0); // -1 반시계, 0 가만히, 1 시계

void rotateWheel();
void printAnswer();

int main() {
    ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);

    int k;

    for(int i = 0; i < 4; i++){
        string s;
        cin >> s;
        for(char c : s){
            v[i].push_back(c - '0');
        }
    }

    cin >> k;

    for(int i = 0 ; i < k; i++){
        int num, dir, idx = 0;
        fill(rotate.begin(), rotate.end(), 0);
        cin >> num >> dir;

        idx = num - 1;
        rotate[idx] = dir;
        while(idx < 3){
            if(v[idx][2] != v[idx + 1][6]){
                rotate[idx + 1] = rotate[idx] * -1;
            }else{
                rotate[idx + 1] = 0;
                break;
            }
            idx++;
        }

        idx = num - 1;
        while(0 < idx) {
            if(v[idx][6] != v[idx -1][2]){
                rotate[idx - 1] = rotate[idx] * -1;
            }else{
                rotate[idx - 1] = 0;
                break;
            }
            idx--;
        }
        rotateWheel();
    }
    printAnswer();
}

void rotateWheel(){
    for(int i = 0; i < 4; i++){
        if(rotate[i] == 0)
            continue;
        else if(rotate[i] == 1){
            int back = v[i].back();
            v[i].pop_back();
            v[i].push_front(back);
        }else {
            int front = v[i].front();
            v[i].pop_front();
            v[i].push_back(front);
        }
    }
}

void printAnswer(){
    int answer = 0;

    for(int i = 0 ; i < 4;i++){
        answer += v[i].front() * pow(2,i);
    }
    cout << answer;
}