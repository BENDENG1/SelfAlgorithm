/*
경사로

*/
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void input();
void solve();
void check(int idx, bool isRow);

int n, l, answer = 0;
vector<vector<int>> v;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);

    input();
    solve();

    cout <<answer;
}

void input() {
    cin >> n >> l;
    v.resize(n,vector<int>(n,0));

    for(int i = 0 ; i < n; i++){
        for(int j = 0; j < n; j++ ){
            cin >> v[i][j];
        }
    }
}

void solve() {
    for(int i = 0 ; i < n; i++){
        check(i,true);
        check(i,false);
    }
}

void check(int idx, bool isRow){
    vector<bool> visited(n, false);
    int beforeHeight = isRow ? v[idx][0] : v[0][idx]; 
    bool flag = true;

    for(int i = 0; i < n; i++){
        int currentHeight = isRow ? v[idx][i] : v[i][idx];
        int diff = beforeHeight - currentHeight;

        // 길이 차이가 2 이상이면 x
        if(abs(diff) > 1){
            flag = false;
            break;
        }
        // 길이 차이가 1 
        if(diff == 1){
            if (i + l - 1 >= n) {
                flag = false;
                break;
            }
            for (int j = i; j < i + l; j++) {
                if ((isRow ? v[idx][j] : v[j][idx]) != currentHeight || visited[j]) {
                    flag = false;
                    break;
                }
                visited[j] = true;
            }
            i += l - 1;
        }else if(diff == -1){
            if (i - l < 0) {
                flag = false;
                break;
            }
            for (int j = i - l; j < i; j++) {
                if ((isRow ? v[idx][j] : v[j][idx]) != beforeHeight || visited[j]) {
                    flag = false;
                    break;
                }
                visited[j] = true;
            }
        }

        if(!flag) break;
        beforeHeight = currentHeight;
    }

    if(flag){
        answer++;
    }
        
}