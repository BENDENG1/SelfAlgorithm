/*
미세먼지 안녕!

r행 c열
공청기 1열에 있고 두칸(두행) 차지
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int r, c, t;
int airPosition[2] = {0,};
int dy[4] = {0,0,1,-1};
int dx[4] = {1,-1,0,0};

vector<vector<int>> v;
vector<vector<int>> dust;

void spreadDust();
void runAirPurifier();
void printOutput();

int main(){
    ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);

    cin >> r >> c >> t;

    v.resize(r,vector<int>(c, 0));
    dust.resize(r, vector<int>(c, 0));

    for(int i = 0 ; i < r;i++){
        for(int j =0; j < c; j++){
            cin >> v[i][j];
            if(v[i][j] == -1){
                if(airPosition[0] == 0) 
                    airPosition[0] = i; 
                else 
                    airPosition[1] = i;
            }
        }
    }

    for(int i = 0 ; i < t; i++){
        //1. 미세먼지 확산
        spreadDust();
        
        //1-1 확산 동기화
        v = dust;
        
        //2. 공청기 작동
        runAirPurifier();
        
    }

    //남아있는 미세먼지 양 출력
    printOutput();
}

void spreadDust() {
    for(int i = 0 ; i < r; i++){
        for(int j = 0; j < c; j++){
            dust[i][j] = 0;
        }
    }
    dust[airPosition[0]][0] = -1;
    dust[airPosition[1]][0] = -1;

    queue<pair<int, int>> q;
    for(int i = 0 ; i < r; i ++){
        for(int j = 0 ; j < c; j++){
            if(v[i][j] > 0){
                int canDir = 0;

                for(int dir = 0; dir < 4; dir++){
                    int ny = i + dy[dir];
                    int nx = j + dx[dir];
                    if(ny < 0 || nx < 0 || ny >= r || nx >= c || v[ny][nx] == -1)
                        continue;
                    q.push({ny,nx});
                    canDir++;
                }
                dust[i][j] += v[i][j] - (v[i][j] / 5) * canDir;
                while(!q.empty()){
                    int y = q.front().first;
                    int x = q.front().second;

                    q.pop();
                    dust[y][x] += v[i][j] / 5;
                }
            }
        }
    }
}

void runAirPurifier() {

    //1. 공청기 위아래
    for(int i = airPosition[0] - 1 ; i > 0; i--){
        v[i][0] = v[i-1][0];
    }

    for(int i = airPosition[1] + 1; i < r - 1; i++){
        v[i][0] = v[i + 1][0];
    }

    // 2. 맨위 맨 아래 가로
    for(int i = 0 ; i < c - 1; i++){
        v[0][i] = v[0][i + 1];
        v[r - 1][i] = v[r - 1][i + 1];
    }

    //맨 오른쪽
    for(int i = 0; i < airPosition[0]; i++){
        v[i][c - 1] = v[i  + 1][c - 1];
    }
    for(int i = r - 1; i > airPosition[1]; i--){
        v[i][c - 1] = v[i - 1][c - 1];
    }

    //공청기 수평방향
    for(int i = c - 1; i > 1; i--){
        v[airPosition[0]][i] = v[airPosition[0]][i - 1];
        v[airPosition[1]][i] = v[airPosition[1]][i - 1];
    }

    v[airPosition[0]][1] = 0;
    v[airPosition[1]][1] = 0;

}

void printOutput() {
    int sum = 0;
    for(int i = 0 ; i < r; i++){
        for(int j = 0 ; j < c; j++){
            if(v[i][j] != -1){
                sum += v[i][j];
            }
        }
    }

    cout << sum;
}