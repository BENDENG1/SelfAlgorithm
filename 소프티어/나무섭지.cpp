#include<iostream>
#include <queue>
#include <vector>

#define MAX_DISTANCE 50000

using namespace std;

int n,m;
int exitY, exitX;
vector<vector<int>> ghost;
vector<vector<int>> person;
vector<vector<char>> v;
queue<pair<int,int>> ghostQueue;
queue<pair<int,int>> personQueue;
int dy[4] = {0,0,1,-1};
int dx[4] = {1,-1,0,0};

void input();
void ghostMove();
bool canGoExit();

bool canGoExit(){
    bool flag = false;
    while(!personQueue.empty()){
        int y = personQueue.front().first;
        int x = personQueue.front().second;

        if(y == exitY && x == exitX){
            flag = true;
            break;
        }

        personQueue.pop();

        for(int i = 0 ; i < 4; i ++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny >= 0 && ny < n && nx >= 0 && nx < m ){
                if(person[y][x] + 1 < person[ny][nx] && v[ny][nx] != '#' && person[y][x] + 1 < ghost[ny][nx]){
                    personQueue.push({ny,nx});
                    person[ny][nx] = person[y][x] + 1;
                }
            }                
        }
    }
    return flag;
}

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(0), cin.tie(NULL),cout.tie(NULL);
    input();
    ghostMove();

    if(canGoExit()){
        cout <<"Yes";
    }else{
        cout <<"No";
    }

   return 0;
}

void input() {
    cin >> n >> m;

    v.resize(n,vector<char>(m,'.'));
    ghost.resize(n,vector<int>(m,MAX_DISTANCE));
    person.resize(n,vector<int>(m,MAX_DISTANCE));
    
    for(int i = 0 ; i < n; i++){
        string s;
        cin >> s;
        for(int j = 0; j < m;j++){
            v[i][j] = s[j];
            if(s[j] == 'G'){
                ghost[i][j] = 0;
                ghostQueue.push({i,j});
            }else if(s[j] == 'N'){
                person[i][j] = 0;
                personQueue.push({i,j});
            }else if(s[j] == 'D'){
                exitY = i;
                exitX = j;
            }
        }
    }
}

void ghostMove() {
    vector<vector<bool>> ghostVisited(n,vector<bool>(m,false));
    while(!ghostQueue.empty()){
        int y = ghostQueue.front().first;
        int x = ghostQueue.front().second;

        ghostQueue.pop();
        ghostVisited[y][x] = true;

        for(int i = 0 ; i < 4; i ++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny >= 0 && ny < n && nx >= 0 && nx < m ){
                if(!ghostVisited[ny][nx]){
                    ghostVisited[ny][nx] = true;
                    ghost[ny][nx] = ghost[y][x] + 1;
                    ghostQueue.push({ny,nx});
                }
            }
        }
    }
}