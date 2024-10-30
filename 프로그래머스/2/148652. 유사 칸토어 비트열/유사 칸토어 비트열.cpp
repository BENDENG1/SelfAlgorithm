/*
유사 칸토어 비트열

3등분하여 가운데 구간을 반복적으로 제외하는 방식?

0번째 비트열은 1
n번째 -> n -1 번째 1을 11011로 치환 0 을 00000치환

1
11011/
11011 11011 00000 11011 11011
11011 11011 00000 11011 11011 두번 / 00000 다섯번 / 11011 11011 00000 11011 11011 두번
...
이런식으로 규칙이 생긴다
음 5^20까지 가능한데 모든걸 구하라는 문제는 절대 아니고

전체에서 5로 나뉘었을때 가운데는 무조건 전체가 0이라는 규칙이 있다.
계속 5로 나눈다면?

재귀로 n개일때 5^N-1 을 몫이 2라면 -> 무조건 그 구간은 0임
아니라면 재귀로 5^N-2 5^N-3.. 이런식으로 확인해서 결국 몫이 2면! 0 아니면 1
*/
#include <string>
#include <cmath>

using namespace std;

int recursiveFive(long long idx, int n)
{
    if (n == 0)
        return 1;
    
    long long size = pow(5, n - 1); 
    if (size * 2 <= idx && idx < size * 3)
        return 0;
    
    return recursiveFive(idx % size, n - 1);
}

int solution(int n, long long l, long long r) {
    int answer = 0;
    for (long long i = l - 1; i < r; i++)
        answer += recursiveFive(i, n);
    
    return answer;
}