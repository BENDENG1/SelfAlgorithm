/*
인구 이동

인구 차이 L 이상 R 이하면 국경선 염 -> 모든 국경선이 열리면 인구 이동 시작

열린것들끼리 이동을 시켜서 
인구수 = 인구수 / 칸 갯수로 통일 시킴

4 10 50
10 100 20 90
80 100 60 70
70 20 30 40
50 20 100 10

답 : 3

이거 테케 모든게 다 0 또는 1 나오는 현상 고치기


*/
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

vector<vector<int>> v;
vector<vector<bool>> visited;
int n, l , r, answer = 0;
bool isFinish = false;
int dy[4] = {0,0,1,-1};
int dx[4] = {1,-1,0,0};

int main(){
    ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);

    cin >> n >> l >> r;

    v.resize(n, vector<int>(n, 0));
    visited.resize(n, vector<bool>(n, false));
    queue<pair<int, int>> q;
    queue<pair<int, int>> divideQ;

    for(int i = 0 ; i < n; i++){
        for(int j =0; j < n; j++){
            cin >> v[i][j];
        }
    }

    while(1){
        isFinish = true;
        for(int i = 0 ; i < n; i++){
            fill(visited[i].begin(), visited[i].end(), false);
        }
        
        for(int i = 0 ; i < n; i++){
            for(int j = 0; j < n; j++){
                if(!visited[i][j]){
                    int cnt = 0;
                    int sum = 0;
                    q.push({i,j});
                    visited[i][j] = true;

                    while(!q.empty()){
                        int y = q.front().first;
                        int x = q.front().second;
                        q.pop();
                        cnt++;
                        sum += v[y][x];
                        divideQ.push({y,x});

                        for(int dir = 0; dir < 4; dir++){
                            int ny = y + dy[dir];
                            int nx = x + dx[dir];
                            if(ny < 0 || nx < 0 || ny >= n || nx >= n || visited[ny][nx])
                                continue;
                            if(l <= abs(v[ny][nx] - v[y][x]) && abs(v[ny][nx] - v[y][x]) <= r){
                                q.push({ny, nx});
                                visited[ny][nx] = true;
                                isFinish = false;
                            }                            
                        }
                    }

                    while(!divideQ.empty()){
                        int y = divideQ.front().first;
                        int x = divideQ.front().second;
                        divideQ.pop();
                        v[y][x] = sum / cnt;
                    }
                }
            }
        }

        if(isFinish) break;

        answer++;
    }

    cout << answer;
}