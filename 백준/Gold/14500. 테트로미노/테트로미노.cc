/*
테트로미노

다섯가지 도형 회전이나 대칭 가능

그림을 그렸을때 4칸으로 상하좌우 아무렇게나 진입을 한다면 ㅗ를 제외하고 모두 커버 가능하다는 사실을 알았음 ㅇㅇ

그러면 ㅗ만 따로 엣지 케이스로 관리를 한다면? 그러면 될듯 ㅇㅇ
*/
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> v;
vector<vector<bool>> visited;
int n, m,answer = 0;
int dy[4] = {0,0,1,-1};
int dx[4] = {1,-1,0,0};

void dfs(int cnt, int y, int x, int sum);
void edgeCase(int y, int x);

int main() {
    ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);

    cin >> n >> m;
    
    v.resize(n, vector<int>(m, 0));
    visited.resize(n , vector<bool>(m, false));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> v[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            visited[i][j] = true;
            dfs(1, i, j, v[i][j]);
            edgeCase(i,j);
            visited[i][j] = false;
        }
    }

    cout << answer;
}

void dfs(int cnt, int y, int x, int sum){
    if(cnt == 4){
        answer = answer < sum ? sum : answer;
        return;
    }

    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= m ||visited[ny][nx])
            continue;
        visited[ny][nx] = true;
        dfs(cnt + 1, ny, nx, sum + v[ny][nx]);
        visited[ny][nx] = false;
    }
}

/** ㅗ케이스 */
void edgeCase(int y, int x){
    //가운데를 기준으로 4방향중 한방향씩 제외한 네가지 케이스를 고려하면 됨 
    //범위 안에 들어오는 것만 처리하면 됨

    for(int i = 0 ; i < 4; i++){
        int cnt = 1;
        int sum = v[y][x];
        for(int j = 0; j < 4; j++){
            if(i != j){
                int ny = y + dy[j];
                int nx = x + dx[j];
                if(ny < 0 || nx < 0 || ny >= n || nx >= m)
                    break;
                cnt++;
                sum += v[ny][nx];
            }
        }
        if(cnt == 4){
            answer = answer < sum ? sum : answer;
        }
    }
    
}