/*
구슬탈출 2

기울이는 동작을 그만 하는 것은 더 이상 구슬이 움직이지 않을때 

시뮬레이션 하는데 bfs씀

근데 음 동서남북으로 쭉 밀어버리는데 그걸 동,서,남,북 따로 블루가 먼저 레드가 먼저 이렇게 고려하는거보다

이동을 하고나서 둘다 같은 좌표라면 -> 이동거리가 큰것에 대해서 -dy, -dx를 해버리는게 더 옳바른듯 ㅇㅇ
좀 많이 까다로운 문제인듯

아 그냥 절댓값으로 다 거리 더하면 된다 나눌핖요없음
아 그리고 구슬이 방문 여부가 레드가 1,1 인데 블루가 2,1 / 1,2 이런식의 경우를 따로 visited를 다 관리해야하므로

따로 red,blue visited가 아니라 하나의 visited로 처리해야할듯 싶음
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Bead {
    int blueY, blueX, redY, redX, cnt;
};

int n, m;
int holeY, holeX;
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};

vector<vector<char>> v;
vector<vector<vector<vector<bool>>>> visited;
Bead bead;

void input();
void bfs();
pair<int, int> moveBead(int y, int x, int dy, int dx);

int main() {
    ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);

    cin >> n >> m;
    v.resize(n, vector<char>(m, 0));
    visited.resize(n, vector<vector<vector<bool>>>(m, vector<vector<bool>>(n, vector<bool>(m, false))));
    
    input();
    bfs();
}

void input() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            if (c == '#') v[i][j] = '#';
            else if (c == '.') v[i][j] = '.';
            else if (c == 'O') {
                v[i][j] = 'O';
                holeY = i;
                holeX = j;
            } else if (c == 'R') {
                v[i][j] = 'R';
                bead.redY = i;
                bead.redX = j;
            } else if (c == 'B') {
                v[i][j] = 'B';
                bead.blueY = i;
                bead.blueX = j;
            }
        }
    }
}

void bfs() {
    queue<Bead> q;
    q.push({bead.blueY, bead.blueX, bead.redY, bead.redX, 0});
    visited[bead.blueY][bead.blueX][bead.redY][bead.redX] = true;
    
    while (!q.empty()) {
        int ry = q.front().redY;
        int rx = q.front().redX;
        int by = q.front().blueY;
        int bx = q.front().blueX;
        int cnt = q.front().cnt;
        q.pop();

        if (cnt >= 10) {
            cout << -1;
            return;
        }

        for (int i = 0; i < 4; i++) {
            int dY = dy[i], dX = dx[i];

            pair<int, int> redMove = moveBead(ry, rx, dY, dX);
            int nry = redMove.first;
            int nrx = redMove.second;

            pair<int, int> blueMove = moveBead(by, bx, dY, dX);
            int nby = blueMove.first;
            int nbx = blueMove.second;

            if (v[nby][nbx] == 'O') continue;

            if (v[nry][nrx] == 'O') {
                cout << cnt + 1;
                return;
            }

            if (nry == nby && nrx == nbx) {
                if (abs(nry - ry) + abs(nrx - rx) > abs(nby - by) + abs(nbx - bx)) {
                    nry -= dY;
                    nrx -= dX;
                } else {
                    nby -= dY;
                    nbx -= dX;
                }
            }

            if (!visited[nby][nbx][nry][nrx]) {
                visited[nby][nbx][nry][nrx] = true;
                q.push({nby, nbx, nry, nrx, cnt + 1});
            }
        }
    }

    cout << -1;
}

pair<int, int> moveBead(int y, int x, int dy, int dx) {
    while (v[y + dy][x + dx] != '#' && v[y][x] != 'O') {
        y += dy;
        x += dx;
    }
    return {y, x};
}



/*
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Bead{
    int blueY;
    int blueX;
    int redY;
    int redX;
    int cnt;
};

int n, m;
int holeY,holeX;
int dy[4] = {0,0,1,-1};
int dx[4] = {1,-1,0,0};

vector<vector<char>> v;
vector<vector<bool>> redVisited;
vector<vector<bool>> blueVisited;

Bead bead;

void input();
void bfs();
pair<int, int> moveBead(int y, int x, int dy, int dx);

int main(){
    ios_base::sync_with_stdio(0),cin.tie(NULL),cout.tie(NULL);

    cin >> n >> m;

    v.resize(n,vector<char>(m,0));
    redVisited.resize(n,vector<bool>(m, false));
    blueVisited.resize(n,vector<bool>(m, false));

    input();
    bfs();

}

void input() {
    for(int i = 0 ; i < n; i++){
        for(int j = 0; j < m; j++){
            char c;
            cin >> c;
            if(c== '#')
                v[i][j] = '#';
            else if(c == '.')
                v[i][j] = '.';
            else if(c == 'O'){
                v[i][j] = 'O';
                holeY = i;
                holeX = j;
            } 
            else if(c == 'R'){
                v[i][j] = 'R';
                bead.redY = i;
                bead.redX = j;
            }
            else if(c == 'B'){
                v[i][j] = 'B';
                bead.blueY = i;
                bead.blueX = j;
            }
        }
    }
}

void bfs() {
    queue<Bead> q;
    q.push({bead.blueY, bead.blueX, bead.redY,bead.redX, 0});
    redVisited[bead.blueY][bead.blueX] = true;
    blueVisited[bead.redY][bead.redX] = true;
    
    while(!q.empty()){
        int ry = q.front().redY;
        int rx = q.front().redX;
        int by = q.front().blueY;
        int bx = q.front().blueX;
        int cnt = q.front().cnt;

        q.pop();

        if(cnt >= 10){
            cout << -1;
            return;
        }

        for (int i = 0; i < 4; i++) {
            int dY = dy[i], dX = dx[i];

            pair<int, int> redMove = moveBead(ry, rx, dY, dX);
            int nry = redMove.first;
            int nrx = redMove.second;

            pair<int, int> blueMove = moveBead(by, bx, dY, dX);
            int nby = blueMove.first;
            int nbx = blueMove.second;

            if (v[nby][nbx] == 'O') continue;

            if (v[nry][nrx] == 'O') {
                cout << cnt + 1;
                return;
            }

            if (nry == nby && nrx == nbx) {
                if (dY == 0) {
                    if (rx > bx) {
                        if (dX > 0) nbx -= dX;
                        else nrx -= dX;
                    } else {
                        if (dX > 0) nrx -= dX;
                        else nbx -= dX;
                    }
                } else if (dX == 0) {
                    if (ry > by) {
                        if (dY > 0) nby -= dY;
                        else nry -= dY;
                    } else {
                        if (dY > 0) nry -= dY;
                        else nby -= dY;
                    }
                }
            }

            if (!redVisited[nry][nrx] && !blueVisited[nby][nbx]) {
                redVisited[nry][nrx] = true;
                blueVisited[nby][nbx] = true;
                q.push({nby, nbx, nry, nrx, cnt + 1});
            }
        }
    }
    cout << -1;
}

pair<int, int> moveBead(int y, int x, int dy, int dx) {
    int moveCnt = 0;
    while (v[y + dy][x + dx] != '#' && v[y][x] != 'O') {
        y += dy;
        x += dx;
        moveCnt++;
    }
    return {y, x};
}
*/