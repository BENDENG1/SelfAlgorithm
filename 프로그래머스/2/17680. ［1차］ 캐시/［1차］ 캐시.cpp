/*
캐시

캐시 크기 / 도시이름들
도시 이름 영문자 대소문자 구분x 최대 이름 20자

LRU를 사용 -> hit 1 / miss 5 로 진행

존재x -> 덱 추방 + 5 하고 있으면 +1하면서 뒤로 집어넣기? ㅇㅇ

걍 다 소문자 바꾸고 비교때려버리면 끝
*/
#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    
    deque<string> dq;
    if(cacheSize == 0)
        return cities.size() * 5;
    
    for(string& city : cities){
        transform(city.begin(), city.end(), city.begin(), ::tolower);
    }
    
    for(string city : cities){
        auto it = find(dq.begin(), dq.end(), city);
        if(dq.end() == it) {
            if(dq.size() < cacheSize){
                dq.push_back(city);
            }else {
                dq.push_back(city);
                dq.pop_front();
            }
            answer+=5;
        }else{
            dq.erase(it);
            dq.push_back(city);
            answer += 1;
        }
    }
    return answer;
}