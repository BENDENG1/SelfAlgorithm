/*
연구소

바이러스가 퍼지지 않게 안전영역 최댓값 찾기 

3개의 기둥을 둘 수 있음
음.. 모든 경우의 수를 확인해봐야 할듯?
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> v;
vector<vector<bool>> visited;
int answer = 0;
int n, m;
int dy[4] = {0,0,1,-1};
int dx[4] = {1,-1,0,0};

void backTracking(int idx, int cnt);
int countSafe();


int main() {
    ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);


    cin >> n >> m;

    v.resize(n, vector<int>(m,0));
    visited.resize(n, vector<bool>(m, false));

    for(int i = 0 ; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> v[i][j];
        }
    }
    backTracking(0,0);

    cout << answer;
}

void backTracking(int idx ,int cnt){
    if(cnt == 3){
        answer = max(answer, countSafe());
        return;
    }
    
    for(int i = idx ; i < n * m; i++){
        int y = i / m;
        int x = i % m;

        if(visited[y][x] || v[y][x] != 0)
            continue;
        
        visited[y][x] = true;
        v[y][x] = 1;
        backTracking(i + 1, cnt + 1);
        v[y][x] = 0;
        visited[y][x] = false;
    }
}

int countSafe(){
    vector<vector<int>> virus = v;
    vector<vector<bool>> virusVisited(n, vector<bool>(m,false));
    queue<pair<int,int>> q;
    int sum = 0;

    for(int i = 0 ; i < n; i++){
        for(int j = 0; j < m; j++){
            if(virus[i][j] == 2){
                q.push({i,j});
            }
        }
    }

    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;

        q.pop();
        virusVisited[y][x] = true;

        for(int i = 0 ; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny >= 0 && nx >= 0 && ny < n && nx < m && !virusVisited[ny][nx]){
                if(virus[ny][nx] == 0){
                    virus[ny][nx] = 2;
                    q.push({ny, nx});
                }
                virusVisited[ny][nx] = true;
            }
        }
    }

    for(auto a : virus){
        for(int b : a){
            if(b == 0) sum ++;
        }
    }

    return sum;
}