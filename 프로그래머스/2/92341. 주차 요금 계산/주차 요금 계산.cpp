/*
주차 요금 계산

출차 기록 x -> 23:59 출차 간주
기본 시간 이하 -> 기본요금
기본시간 초과 -> 기본요금 + (초과분 단위시간 마다 단위요금 (올림 나머지 0아니면 무조건 올림))

fees / records 

fees
기본 시간 / 기본요금 / 단위시간 / 단위요금
records
시각 / 차량번호 / 내역

우선 시간은 일괄적 분으로 치환 -> 06 : 30은 390
*/
#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int timeToMinutes(string time);
bool checkIsIn(string s);
int calculateSumFee(const vector<int>& fees, int time);

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    
    //둘 다 key는 차 넘버
    map<string, int> m;
    map<string, int> sumMap;
    
    for(string s : records) {
        int time = timeToMinutes(s.substr(0,5));
        string carNumber = s.substr(6,4);
        bool isIn = checkIsIn(s.substr(11));
        
        if(isIn){
            m[carNumber] = time;
        }else {
            time -= m[carNumber];
            
            if(sumMap.find(carNumber) == sumMap.end()){
                sumMap.insert({carNumber, time});
            }else{
                sumMap[carNumber] += time;
            }
            m.erase(carNumber);
        }
    }
    
    for(auto it = m.begin(); it != m.end(); it++){
        string carNumber = it -> first;
        int inTime = it -> second;
        
        sumMap[carNumber] += (23 * 60 + 59) - inTime;
    }
    
    for(auto it = sumMap.begin(); it != sumMap.end(); it++){
        answer.push_back(calculateSumFee(fees, it->second));
    }
    
    
    return answer;
}

int timeToMinutes(string time) {
    int hour = stoi(time.substr(0,2));
    int minute = stoi(time.substr(3));
    
    return hour * 60  + minute;
}

bool checkIsIn(string s){
    return s == "IN";
}

int calculateSumFee(const vector<int>& fees, int time){
    if(time <= fees[0]){
        return fees[1];
    }else{
        time -= fees[0];
        return fees[1] + ((time / fees[2]) + (time % fees[2] > 0 ? 1 : 0)) * fees[3];
    }
}