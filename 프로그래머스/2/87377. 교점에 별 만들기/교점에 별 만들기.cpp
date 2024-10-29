/*
교점에 별 만들기

ax + by + c = 0을 만족하는 점
최소 사각형 -> xy의 최대와 xy의 최소값을 저장해서 나중에 그리기면 추가하면 됨
근데 점을 어떻게?

ax + by + c = dx + ey + f 이런식으로 해서 x,y의 좌표를 하나씩 넣으면 된다
(a-d)x + (b-e)y + c-f = 0일때 기울기가 똑같지 않다면 무조건 교점은 존재한다 도 특징

같은 선분이 아니면 결국 두 선분의 교점은 하나만! 나온다는게 특징 아닐까?
단, 평행 케이스 확인 ad - bc = 0 -> 평행

엥? 마지막세개 메모리 초과?
*/
#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

#define MAX 9223372036854775807
#define MIN -9223372036854775807

struct Point{
    long long  x;
    long long  y;
    
    // //set + struct 
    // bool operator<(const Point& other) const {
    //     if (x == other.x) return y < other.y;
    //     return x < other.x;
    // }
};

struct LineInfo{
    int a;
    int b;
    int c;
};

vector<string> solution(vector<vector<int>> line) {
    vector<string> answer;
    vector<Point> stars;
    vector<LineInfo> lineV;
    
    long long maxY = MIN, maxX = MIN, minY = MAX, minX = MAX;
    
    for(int i = 0 ; i < line.size();i++){
        LineInfo info = LineInfo();
        info.a = line[i][0];
        info.b = line[i][1];
        info.c = line[i][2];
        lineV.push_back(info);
    }
    
    for(int i = 0 ; i < lineV.size();i++){
        for(int j = i + 1; j < lineV.size();j++){
            long long a = lineV[i].a, c = lineV[j].a;
            long long  b = lineV[i].b, d = lineV[j].b;
            long long  e = lineV[i].c, f = lineV[j].c;
            
            if(a * d - b * c == 0)
                continue;
            
            if((b * f - e * d) % (a * d - b * c) == 0
              && (e * c - a * f) % (a * d - b * c) == 0){
                long long x = (b * f - e * d) / (a * d - b * c);
                long long y = (e * c - a * f) / (a * d - b * c);
                stars.push_back({x, y});
                minX = min(x,minX);
                minY = min(y,minY);
                maxX = max(x, maxX);
                maxY = max(y, maxY);
            }
        }
    }    
    answer.resize(maxY - minY + 1,string(maxX - minX + 1, '.'));
    
    for (const auto& point : stars) {
        answer[maxY - point.y][point.x - minX] = '*';
    }
    
    return answer;
}