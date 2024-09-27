/*
치킨배달

0 빈 1 집 2 치킨집

절댓값 x,y 거리 -> 치킨거리
모든 합 -> 도시의 치킨거리

수익을 가장 많이 낼수 있는 치킨집의 수 m

*/
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

#define MAX_DISTANCE 100000
struct point {
    int y;
    int x;
};

vector<point> houseV, chickenV, selectedChickenV;
vector<bool> visited;
int n, m;
int chickenSize, ans = MAX_DISTANCE;

void input();
void backTracking(int idx, int cnt);

int main() {
    ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);

    input();
    chickenSize = chickenV.size();
    backTracking(0,0);

    cout << ans;
}

void input(){
    int tmp;
    cin >> n >> m;
    visited.resize(n,false);
    
    for(int i = 0 ; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> tmp;
            if(tmp == 1) houseV.push_back({i,j});
            else if(tmp == 2) chickenV.push_back({i,j});
        }
    }
}

void backTracking(int idx, int cnt){
    if (cnt == m){
        int sum =0;

        for(point house : houseV){
            int houseY = house.y;
            int houseX = house.x;
            int distance = MAX_DISTANCE;

            for(point chicken : selectedChickenV){
                int chickenY = chicken.y;
                int chickenX = chicken.x;
                distance = min(distance, (abs(houseY - chickenY) + abs(houseX - chickenX)));
            }
            sum += distance;
        }
        ans = min(sum , ans);
        return;
    }

    for(int i = idx; i < chickenSize; i++){
        if(visited[i]) continue;
        visited[i] = true;
        selectedChickenV.push_back(chickenV[i]);
        backTracking(i,cnt + 1);
        visited[i] = false;
        selectedChickenV.pop_back();
    }
}