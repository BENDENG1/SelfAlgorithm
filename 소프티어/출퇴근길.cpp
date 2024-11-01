/*
소프티어 출퇴근길

음 단방향으로 벡터를 저장한다.

출발 -> 도착 / 도착 -> 출발

출발 -> 도착 에 대한 단방향 그래프에 대해서 도착을 기점으로 출발을 갈 수 있는것과 출발에서 도착을 갈 수 있는 것을 확인한다.
도착 -> 출발도 동일하다.
*/
#include<iostream>
#include<vector>

using namespace std;

int n, m, s, e, answer = 0;

vector<vector<int>> edge;
vector<vector<int>> reverseEdge;

vector<bool> fromVisited1, fromVisited2, toVisited1, toVisited2;

void dfs(int now,const vector<vector<int>> &v, vector<bool> &visited){
    if (visited[now]) return;
    visited[now] = true;

    for(int i = 0; i < v[now].size(); i++){
        dfs(v[now][i], v, visited);
    }
    return;
}

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    cin >> n >> m;
    edge.resize(n+1);
    reverseEdge.resize(n+1);

    fromVisited1.resize(n+1);
    fromVisited2.resize(n+1);
    toVisited1.resize(n+1);
    toVisited2.resize(n+1);
    
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        edge[x].push_back(y);
        reverseEdge[y].push_back(x);
    }
    cin >> s >> e;

    fromVisited1[e] = true;
    fromVisited2[s] = true;
    dfs(s, edge, fromVisited1);
    dfs(e, edge, fromVisited2);

    dfs(s, reverseEdge, toVisited1);
    dfs(e, reverseEdge, toVisited2);

    
    for(int i = 1; i <= n; i++){
        if (fromVisited1[i] && fromVisited2[i] && toVisited1[i] && toVisited2[i])
            answer++;
    }
    cout << answer - 2;
    
   return 0;
}