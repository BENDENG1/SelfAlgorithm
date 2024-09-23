/*
컨베이어 벨트 위의 로봇

1~2n 번호가 메겨져있음
1번칸이 올리는 위치 n번칸이 내리는 위치

한번 진행 내구도 1 감소
*/

#include <iostream>
#include <deque>

using namespace std;


struct Robot{
    int num;
    bool isRobot;
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
    int n, k, cnt =0,step = 0;

    cin >> n >> k;

    deque<Robot> dq;
    for(int i = 0 ; i < 2 * n; i ++){
        int tmp;
        cin >> tmp;
        dq.push_back({tmp,false});
    }
    
    while(1){
        step++;

        dq.push_front(dq.back());
        dq.pop_back();

        if (dq[n-1].isRobot) {
            dq[n-1].isRobot = false;
        }

        for (int i = n - 2; i >= 0; i--) {
            if (dq[i].isRobot && !dq[i+1].isRobot && dq[i+1].num > 0) {
                dq[i].isRobot = false;
                dq[i+1].isRobot = true;
                dq[i+1].num--;
            }
        }

                if (dq[n-1].isRobot) {
            dq[n-1].isRobot = false;
        }

        if (!dq[0].isRobot && dq[0].num > 0) {
            dq[0].isRobot = true;
            dq[0].num--;
        }

        cnt = 0;
        for (int i = 0; i < 2 * n; i++) {
            if (dq[i].num == 0) cnt++;
        }

        if (cnt >= k) break;
    }

    cout << step << "\n";
}

