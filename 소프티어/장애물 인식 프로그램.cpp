/*
소프티어 장애물 인식 프로그램

걍 bfs
*/
#include<iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int dy[4] = {0,0,1,-1};
int dx[4] = {1,-1,0,0};

int main(int argc, char** argv)
{
    int n, cnt = 0;
    cin >> n;

    vector<vector<int>> v(n, vector<int>(n,0));
    vector<vector<bool>> visited(n, vector<bool>(n, 0));
    vector<int> area;
    
    for(int i = 0 ; i < n; i++){
        string s;
        cin >> s;
        for(int j = 0; j < s.length(); j++){
            v[i][j] = s[j] - '0';
            if(s[j] == '0'){
                visited[i][j] = true;
            }
        }
    }

    for (int i = 0 ; i < n; i++){
        for (int j = 0 ; j < n; j++){
            if(visited[i][j]){
                continue;
            }
            
            queue<pair<int, int>> q;
            q.push({i,j});
            visited[i][j] = true;
            int sum = 1;
            cnt++;

            while(!q.empty()){
                int y = q.front().first;
                int x = q.front().second;
                q.pop();
                
                for(int dir = 0; dir < 4; dir++){
                    int ny = y + dy[dir];
                    int nx = x + dx[dir];
                    if(ny < 0 || ny >= n || nx < 0 || nx >= n || visited[ny][nx])
                        continue;
                    visited[ny][nx] = true;
                    sum++;
                    q.push({ny,nx});
                }
            }
            area.push_back(sum);
        }
    }

    sort(area.begin(), area.end());

    cout << cnt <<"\n";
    for(int a : area){
        cout << a << "\n";
    }
    
    return 0;
}