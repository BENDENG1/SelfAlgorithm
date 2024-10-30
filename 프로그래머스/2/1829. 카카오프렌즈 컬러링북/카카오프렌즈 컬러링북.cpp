/*
카카오 프렌즈 컬러링북

가장 큰 영역이 몇칸 있는지 return한다.

bfs로
*/
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int bfs(int y, int x, const vector<vector<int>>& picture,vector<vector<bool>>& visited);

int dy[4] = {0,0,1,-1};
int dx[4] = {1,-1,0,0};


vector<int> solution(int m, int n, vector<vector<int>> picture) {
    
    vector<vector<bool>> visited(m, vector<bool>(n,false));
    int areaAnswer = 0;
    int maxAnswer = 0;
    
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++) {
            if(picture[i][j] != 0 && !visited[i][j]){
                areaAnswer++;
                maxAnswer = max(maxAnswer, bfs(i, j, picture, visited));
            }
        }
    }
    
    vector<int> answer(2);
    answer[0] = areaAnswer;
    answer[1] = maxAnswer;
    return answer;
}


int bfs(int y, int x, const vector<vector<int>>& picture,vector<vector<bool>>& visited){
    int size = 1;
    int m = visited.size();
    int n = visited[0].size();
    queue<pair<int, int>> q;
    
    visited[y][x] = true;
    q.push({y, x});
    
    while(!q.empty()) {
        int curY = q.front().first;
        int curX = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; i++) {
            int ny = curY + dy[i];
            int nx = curX + dx[i];
            if(ny >= 0 && ny < m && nx >= 0 && nx < n) {
                if(!visited[ny][nx] && picture[y][x] == picture[ny][nx]) {
                    visited[ny][nx] = true;
                    q.push({ny, nx});
                    size++;
                }
            }
        }
    }
    return size;
}