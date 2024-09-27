/*
마법사 상어와 비바라기

1,n 행 번이 연결 n번 행 아래는 1번임
방향 d[i], 거리 s[i] 8방향임 

음 그냥 구현 문제인듯
*/
#include <iostream>
#include <vector>
#include <deque>
#include <cmath>

using namespace std;

struct wind{
    int y;
    int x;
};

int n, m;
vector<vector<int>> v;
vector<vector<bool>> visited;
int dy[8] = {0,-1,-1,-1,0,1,1,1};
int dx[8] = {-1,-1,0,1,1,1,0,-1};
int diagonalY[4] = {-1,-1,1,1};
int diagonalX[4] = {-1,1,1,-1};

//0 1 2 3 0 1 2 3 0 1

int setPoint(int point){
    if(point >= 0)
        return point % n;
    return (n + (point % n)) % n;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);

    int tmp, dir, step, answer = 0;
    cin >> n >> m;

    v.resize(n,vector<int>(n,0));
    visited.resize(n,vector<bool>(n,false));
    deque<wind> dq;


    for(int i = 0 ; i < n;i++){
        for(int j = 0; j < n; j++){
            cin >> tmp;
            v[i][j] = tmp;
        }
    }

    dq.push_back({n-1, 0});
    dq.push_back({n-1, 1});
    dq.push_back({n-2, 0});
    dq.push_back({n-2, 1});

    for(int i = 0 ; i < m; i++){
        //구름 있었던 위치 False 초기화
        for (auto& row : visited) {
            fill(row.begin(), row.end(), false);
        }
        cin >> dir >> step;

        //구름 이동
        for(int j = 0; j < dq.size(); j++){
            wind front = dq.front();
            int y = front.y;
            int x = front.x;
            dq.pop_front();

            int ny = setPoint(y + dy[dir - 1] * step);
            int nx = setPoint(x + dx[dir - 1] * step);
            dq.push_back({ny,nx});
        }

        
        // 비내리고
        for(int j = 0; j < dq.size(); j++){
            wind front = dq.front();
            dq.pop_front();
            int y = front.y;
            int x = front.x;
            v[y][x] += 1;
            dq.push_back(front);
        }


        //물복사
        while(!dq.empty()){
            wind front = dq.front();
            dq.pop_front();
            int y = front.y;
            int x = front.x;
            visited[y][x] = true;
            for(int d = 0; d < 4; d++){
                int ny = y + diagonalY[d];
                int nx = x + diagonalX[d];
                if(ny < 0 || nx < 0 || ny >= n || nx >= n)
                    continue;
                if(v[ny][nx] >= 1)
                    v[y][x] += 1;
            }
        }

        // 기존 구름을 제외한 새로운 구름이 생김
        for(int j = 0 ; j < n; j++){
            for(int k = 0; k < n; k++){
                if(!visited[j][k] && v[j][k] >= 2){
                    v[j][k] -= 2;
                    dq.push_back({j, k});
                }
            }
        }

        // //디버그용
        // cout <<"\nround = " << i<<"\n";
        // for(int a = 0; a < n; a++){
        //     for(int b = 0; b < n; b++){
        //         cout << v[a][b] <<" ";
        //     }
        //     cout<<"\n";
        // }

    }

    for(auto a : v){
        for(int b : a){
            answer += b;
        }
    }

    cout << answer;
}

