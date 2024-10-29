/*
택배 배달과 수거하기

n개 / i번째 i 거리 / cap 개 실음 / 

음.. 백트래킹? 모든 경우의 수를 확인해보는 브루트포스?

음 근데 가장 먼곳에서 끝났을때 
ex) cap 3 7이면 3번을 왔다갔다 해야함 -> 근데 3번을 하면 2의 잉여가 발생함

이걸 전칸을 확인함 1칸? 그럼 또 전칸 이런식으로
그렇게 해서 하면 됨 ㅇㅇ

그리디로 풀면 될듯
*/
#include <string>
#include <vector>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    long long deliverCount = 0;
    long long pickupCount = 0;
    
    for(int i = n - 1; i >= 0; i--) {
        deliverCount -= deliveries[i];
        pickupCount -= pickups[i];
        int cnt = 0;
        while(deliverCount < 0 || pickupCount < 0) {
            deliverCount += cap;
            pickupCount += cap;
            cnt++;
        }
        answer += (i + 1) * 2 * cnt;
    }
    return answer;
}