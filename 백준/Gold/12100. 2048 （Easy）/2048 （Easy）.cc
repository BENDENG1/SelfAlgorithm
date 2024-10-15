/*
2048(Easy)

모든 케이스 브루트 포스로 진행하면 우선 시간 복잡도가 무조건 1024(4의 5승) * move 했던 시간복잡도 결과가 나옴

무조건 빼박 브루트(백트래킹) 모든경우의 수를 다 확인해야함
*/
#include <iostream>
#include <vector>

using namespace std;

int n, answer = 0;

void input(vector<vector<int>> &v);
void solve(int cnt, vector<vector<int>> &v);
void move(int dir, vector<vector<int>> &v);
int findMaxNumber(const vector<vector<int>> &v);

int main() {
    ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);

    vector<vector<int>> v;

    input(v);
    solve(0, v);
    cout << answer;
}

void input(vector<vector<int>> &v) {
    cin >> n;

    v.resize(n,vector<int>(n,0));

    for(int i = 0 ; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> v[i][j];
        }
    }
}

void solve(int cnt, vector<vector<int>> &v) {
    if(cnt == 5){
        int tmp = findMaxNumber(v);
        answer = max(answer, tmp);
        return;
    }
    
    for(int i = 0 ; i < 4; i++){
        vector<vector<int>> currentBoard = v;
        move(i, v);
        solve(cnt + 1, v);
        v = currentBoard;
    }
}

void move(int dir, vector<vector<int>> &v) {
    int nonZeroIndex;
    if (dir == 0) {
        for (int y = 0; y < n; y++) {
            for (int x = n - 1; x > 0; x--) {
                if (v[y][x] != 0) {
                    int xTmp = x - 1;
                    while (xTmp >= 0 && v[y][xTmp] == 0) {
                        xTmp--;
                    }
                    if (xTmp >= 0 && v[y][x] == v[y][xTmp]) {
                        v[y][x] *= 2;
                        v[y][xTmp] = 0;
                    }
                }
            }
            nonZeroIndex = n - 1;
            for (int x = n - 1; x >= 0; x--) {
                if (v[y][x] != 0) {
                    v[y][nonZeroIndex--] = v[y][x];
                }
            }
            while (nonZeroIndex >= 0) {
                v[y][nonZeroIndex--] = 0;
            }
        }
    } else if (dir == 1) {
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < n - 1; x++) {
                if (v[y][x] != 0) {
                    int xTmp = x + 1;
                    while (xTmp < n && v[y][xTmp] == 0) {
                        xTmp++;
                    }
                    if (xTmp < n && v[y][x] == v[y][xTmp]) {
                        v[y][x] *= 2;
                        v[y][xTmp] = 0;
                    }
                }
            }
            nonZeroIndex = 0;
            for (int x = 0; x < n; x++) {
                if (v[y][x] != 0) {
                    v[y][nonZeroIndex++] = v[y][x];
                }
            }
            while (nonZeroIndex < n) {
                v[y][nonZeroIndex++] = 0;
            }
        }
    } else if (dir == 2) {
        for (int x = 0; x < n; x++) {
            for (int y = n - 1; y > 0; y--) {
                if (v[y][x] != 0) {
                    int yTmp = y - 1;
                    while (yTmp >= 0 && v[yTmp][x] == 0) {
                        yTmp--;
                    }
                    if (yTmp >= 0 && v[y][x] == v[yTmp][x]) {
                        v[y][x] *= 2;
                        v[yTmp][x] = 0;
                    }
                }
            }
            nonZeroIndex = n - 1;
            for (int y = n - 1; y >= 0; y--) {
                if (v[y][x] != 0) {
                    v[nonZeroIndex--][x] = v[y][x];
                }
            }
            while (nonZeroIndex >= 0) {
                v[nonZeroIndex--][x] = 0;
            }
        }
    } else {
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n - 1; y++) {
                if (v[y][x] != 0) {
                    int yTmp = y + 1;
                    while (yTmp < n && v[yTmp][x] == 0) {
                        yTmp++;
                    }
                    if (yTmp < n && v[y][x] == v[yTmp][x]) {
                        v[y][x] *= 2;
                        v[yTmp][x] = 0;
                    }
                }
            }
            nonZeroIndex = 0;
            for (int y = 0; y < n; y++) {
                if (v[y][x] != 0) {
                    v[nonZeroIndex++][x] = v[y][x];
                }
            }
            while (nonZeroIndex < n) {
                v[nonZeroIndex++][x] = 0;
            }
        }
    }
}


int findMaxNumber(const vector<vector<int>> &v) {
    int num = 0;
    for(auto a : v){
        for(int b : a){
            num = max(num, b);
        }
    }
    return num;
}