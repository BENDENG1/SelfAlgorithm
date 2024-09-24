/*
상어 초등학교

n * n 격자 / 학생의 수 n^2 / 1 ~ n^2번까지 번호 / (r,c) r행 c열
두개의 거리가 1이면 인접(동서남북, 대각선은 아님 절댓값 1)

*/
#include <iostream>
#include <vector>

using namespace std;

struct student{
    int num;
    int like[4];
};

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);

    int n, answer = 0;
    
    cin >> n;

    vector<vector<int>> v(n,vector<int>(n,0));
    vector<student> students(n * n);
    
    for (int i = 0; i < n * n; i++) {
        cin >> students[i].num;
        for (int j = 0; j < 4; j++) {
            cin >> students[i].like[j];
        }
    }
    

    for (auto s : students) {
        int bestX = -1, bestY = -1;
        int maxLikes = -1, maxEmpty = -1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (v[i][j] != 0) continue;

                int likeCount = 0, emptyCount = 0;

                for (int dir = 0; dir < 4; dir++) {
                    int ny = i + dy[dir];
                    int nx = j + dx[dir];
                    if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;

                    if (v[ny][nx] == 0) {
                        emptyCount++;
                    } else {
                        for (int k = 0; k < 4; k++) {
                            if (v[ny][nx] == s.like[k]) likeCount++;
                        }
                    }
                }

                if (likeCount > maxLikes || (likeCount == maxLikes && emptyCount > maxEmpty)) {
                    bestY = i;
                    bestX = j;
                    maxLikes = likeCount;
                    maxEmpty = emptyCount;
                } else if (likeCount == maxLikes && emptyCount == maxEmpty) {
                    if (i < bestY || (i == bestY && j < bestX)) {
                        bestY = i;
                        bestX = j;
                    }
                }
            }
        }

        v[bestY][bestX] = s.num;
    }

    // 디버깅용(배치가 잘 되었는지)
    // for(int i = 0 ; i < v.size();i++){
    //     for(int j = 0; j < v.size();j++){
    //         cout<<v[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }

    // 마지막 점수 계산
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) {
            int number = v[i][j];
            student s;
            for (auto st : students) {
                if (st.num == number) {
                    s = st;
                    break;
                }
            }
            int likeCount = 0;

            for(int dir = 0; dir < 4; dir++){
                int ny = i + dy[dir];
                int nx = j + dx[dir];
                if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                for(int k = 0; k < 4; k++){
                    if (v[ny][nx] == s.like[k]) likeCount++;
                }
            }
            if (likeCount == 1) answer += 1;
            else if (likeCount == 2) answer += 10;
            else if (likeCount == 3) answer += 100;
            else if (likeCount == 4) answer += 1000;
        }
    }
    cout << answer;
}