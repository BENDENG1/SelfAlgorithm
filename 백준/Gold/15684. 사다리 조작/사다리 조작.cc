/*
사다리 조작

i번은 i번이 나와야함

a는 행 b는 b, b+1 열과 연결 (인덱스 -1 조심)
*/
#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_ANSWER 100

using namespace std;

vector<vector<int>> v;
vector<vector<bool>> visited;
int n, m, h, a ,b, answer = MAX_ANSWER;

void backTracking(int cnt, int idx);
bool checkSuccess();

int main() {
    ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);

    cin >> n >> m >> h; // m의 행 n이 열
    v.resize(h, vector<int>(n, 0));
    visited.resize(h, vector<bool>(n, false));


    for(int i = 0 ; i < m; i++){
        cin >> a >> b;
        visited[a - 1][b - 1] = true; // a-1행 b-1/b열끼리 연결
    }

    backTracking(0,0);

    if(answer == MAX_ANSWER)
        cout << -1;
    else
        cout << answer;
}

bool checkSuccess() {
    for(int i = 0 ; i < n; i++){
        int startIdx = i;
        for(int j = 0; j < h; j++){
            if(visited[j][startIdx])
                startIdx++;
            else if(startIdx - 1 >= 0 && visited[j][startIdx - 1])
                startIdx--;
        }
        if(startIdx != i) return false;
    }

    return true;
}

void backTracking(int cnt, int idx){
    if(cnt > 3) return;
    if(checkSuccess()){
        answer = answer = min(answer, cnt);
        return;
    }
    
    for(int i = idx ; i < h ; i++){
        for(int j = 0; j < n - 1 ; j++){
            if(visited[i][j]) continue;
            if(j > 0 && visited[i][j - 1]) continue;

            visited[i][j] = true;
            backTracking(cnt + 1, i);
            visited[i][j] = false;
        }
    }
}