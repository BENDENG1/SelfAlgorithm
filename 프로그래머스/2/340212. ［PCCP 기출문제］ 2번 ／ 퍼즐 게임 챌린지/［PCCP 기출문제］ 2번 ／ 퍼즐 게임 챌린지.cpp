/*
퍼즐 게임 챌린지

n개의 퍼즐 / diff / time_cur / time_prev / level

레벨이 
이상이면 time_cur만큼 걸림
미만이면 diff - level 번 만큼 틀림

우선 그냥 값을 다 더했을때 시간이 통과되는지? -> fail (6가지 테스트케이스)
반복문에서 limit을 넘어가면 break -> fail
값을 이분탐색으로 하고 반복문 체킹?
*/
#include <string>
#include <vector>

using namespace std;

bool isInLimit(const vector<int>& diffs, const vector<int>& times, long long limit, int level) {
    long long sum = 0;
    int n = diffs.size();
    
    for(int i = 0 ; i < n; i++){
        if(diffs[i] - level <= 0){
            sum += times[i];
        }else{
            sum += (diffs[i] - level) * (times[i] + times[i - 1]) + times[i];
        }
        if(sum > limit){
            return false;
        }
    }
    return true;
}

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int n = diffs.size();
    int start = 1, end = 100000;
    
    if(isInLimit(diffs, times, limit, 1)) return 1;
    
    while(start < end - 1){
        //bool isInLimit(const vector<int>& diffs, const vector<int>& times, long long limit, int level)
        int mid = (start + end) / 2;
        
        if(isInLimit(diffs, times, limit, mid))
            end = mid;
        else
            start = mid;
    }
    
    return end;
}