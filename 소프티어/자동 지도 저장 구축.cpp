/*
소프티어 지도 자동구축

정사각형 줌심에 점 추가

3 5 9 17
1 2 3 4
뭐 이런식으로 ((2n + 1) * 2 + 1) * 2 + 1.. 개 만큼의 점화식이 세워진다.
*/

#include<iostream>


using namespace std;

int main(int argc, char** argv)
{
    int n, num = 3;
    cin >>n;

    for(int i = 2; i <= n; i++){
        num = 2 * num - 1;
    }

    cout << num * num;
   return 0;
}