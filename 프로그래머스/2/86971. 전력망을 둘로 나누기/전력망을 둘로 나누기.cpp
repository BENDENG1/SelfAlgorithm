/*
n개의 송전탑 트리 형태

분할 -> 송전탑의 갯수 최대한 맞춤

브루트포스? -> 모든 간선을 자른 경우의 수
bfs로 미리 자르고 너비의 두개의 차이를 구하면 될듯
*/
#include <string>
#include <vector>
#include <queue>
#include <iostream>

#define MAX_AREA 100

using namespace std;

int calculateWidth(int num, const int n);

vector<vector<bool>> visited;
vector<vector<int>> v;

int solution(int n, vector<vector<int>> wires) {
    int answer = MAX_AREA;
    
    visited.resize(n,vector<bool>(n,false));
    v.resize(n,vector<int>(n,0));
    queue<int> q;
    
    for(vector<int> wire : wires){
        v[wire[0] - 1][wire[1] - 1] = 1;
        v[wire[1] - 1][wire[0] - 1] = 1;
    }
    
    for(vector<int> wire : wires){
        for(int i = 0 ; i < visited.size(); i++){
            fill(visited[i].begin(), visited[i].end(), false);
        }
        
        visited[wire[0] - 1][wire[1] - 1] = true;
        visited[wire[1] - 1][wire[0] - 1] = true;
        
        int firstArea = calculateWidth(wire[0] - 1, n);
        int secondArea = calculateWidth(wire[1] - 1, n);
        int diff = abs(firstArea - secondArea);
        
        answer = answer < diff ? answer : diff;
    }
    
    return answer;
}

int calculateWidth(int num, const int n) {
    queue<int> q;
    int sum = 0;
    
    q.push(num);
    
    while(!q.empty()) {
        
        int tmp = q.front();
        q.pop();
        
        sum++;
        
        for(int i = 0 ; i < n; i++){
            if(v[tmp][i] == 1 && !visited[tmp][i]){
                q.push(i);
                visited[tmp][i] = true;
                visited[i][tmp] = true;
            }
        }
    }
    return sum;
}
