/*
충돌 위험 찾기

r,c n개의 포인트 존재 1~n 번호
m개 포인트
로봇 x대 0초에 동시출발 (4각으로 이동가능)

최단경로가 여러가지일경우 r,c 에서 r먼저 변하게 함

물류센터 도착하면 끝
2대 이상 모이면 충돌 가능성 -> 위험한 사오항이 몇번 일어나는지 확인

1. 각각의 최단경로를 파악(동일한게 여러개라면 r좌표가 우선적으로 움직이는 것을 선택)
   - 근데 방해물이 없어서 좌표가 차이나는만큼 r을 무조건 먼저 움직이고 c를 움직이면 됨.
2. 그리고 각각 경로를 이동할때 마주치는지에 대한 확인 (시뮬레이션)

음 그냥 모든 경로를 다 기록을 한다 -> 괜찮을지도? 시간을 key로해서 map으로 해당 위치들의 좌표
*/
#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

struct Point{
    int y;
    int x;
    
    bool operator==(const Point& other) const {
        return y == other.y && x == other.x;
    }
};

map<int, vector<Point>> m;

void recordMove(int from, int to,const vector<vector<int>>& points, int &time);


int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    int answer = 0;
    int n = routes.size();
    
    
    for(int i = 0 ; i < n; i++){
        int len = routes[i].size();
        int time = 0;
        for(int j = 0 ; j < len; j++){
            if(j + 1 < len)
                recordMove(routes[i][j], routes[i][j + 1], points, time);
        }
    }
    
    for(const auto &a : m){
        const vector<Point>& points = a.second;
        int size = points.size();
        vector<bool> crash(size, false);
        
        for(int i = 0; i < size; i++) {
            for(int j = i + 1; j < size; j++){
                if(points[i] == points[j]){
                    if(crash[i]){
                        crash[j] = true;
                    }else{
                        answer ++;
                        crash[i] = true;
                        crash[j] = true;
                    }
                }
            }
        }

    }
    
    return answer;
}


void recordMove(int from, int to,const vector<vector<int>>& points, int &time){
    int fromY = points[from - 1][0], fromX = points[from - 1][1];
    int toY = points[to - 1][0], toX = points[to - 1][1];
    
    if(time == 0){
        m[time].push_back({fromY,fromX});
    }
    
    while(1){
        //y좌표 우선 진행(방해물 없어서 간단히 가능)
        if(fromY > toY){
            fromY--; 
        }else if(fromY < toY) {
            fromY++;
        }else if(fromX < toX) {
            fromX++;
        }else {
            fromX--;
        }
        
        m[++time].push_back({fromY,fromX});
        if(fromY == toY && fromX == toX)
            return;
    }     
}