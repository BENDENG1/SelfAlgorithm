/*
감시 15683 백준

1~5번의 cctv 종류에 따라 (회전 가능)
사각지대 최소 갯수 찾기 문제
*/
#include <iostream>
#include <vector>

using namespace std;

struct Point {
    int y;
    int x;
};

void input();
void solve(int idx);
int countBlindSpot();
void see(int y, int x, int dir);

int n, m, answer = 100;
vector<vector<int>> v;
vector<Point> cctv;
Point direction[4] = {{-1,0},{0,1},{1,0},{0,-1}};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);

    input();
    solve(0);

    cout <<answer;
}

void input() {
    cin >> n >> m;
    v.resize(n,vector<int>(m,0));

    for(int i = 0 ; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> v[i][j];
            if(1 <= v[i][j] && v[i][j] <= 5){
                cctv.push_back({i,j});
            }
        }
    }
}

void solve(int idx) {
    if(idx == cctv.size()){
        int curCount = countBlindSpot();
        answer = answer < curCount ? answer : curCount;
        return;
    }

    int y = cctv[idx].y;
    int x = cctv[idx].x;
    vector<vector<int>> copyV(n,vector<int>(m, 0));


    for(int dir = 0; dir < 4; dir++){
        copyV = v;

        if(v[y][x] == 1){
            see(y, x, dir);
        }else if(v[y][x] == 2){
            see(y, x, dir);
            see(y, x, dir + 2);
        }else if (v[y][x] == 3){
            see(y, x, dir);
            see(y, x, dir + 1);
        }else if (v[y][x] == 4){
            see(y, x, dir);
            see(y, x, dir + 1);
            see(y, x, dir + 2);
        }else {
            see(y, x, dir);
            see(y, x, dir + 1);
            see(y, x, dir + 2);
            see(y, x, dir + 3);
        }

        solve(idx + 1);
        v = copyV;
    }

}

void see(int y, int x, int dir){
    int ny = y, nx = x;
    while(1) {
        ny += direction[dir % 4].y;
        nx += direction[dir % 4].x;
        if(ny < 0 || ny >= n || nx < 0 || nx >= m || v[ny][nx] == 6)
            break;
        if(v[ny][nx] == 0){
            v[ny][nx] = -1;
        }
    }
}

int countBlindSpot() {
    int cnt = 0;
    for(int i = 0 ; i < n; i++){
        for(int j = 0; j < m; j++){
            if(v[i][j] == 0) cnt++;
        }
    }
    return cnt;
}