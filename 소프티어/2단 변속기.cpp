/*
소프티어 2단 변속기

걍 하라는대로 하면됨
*/
/*
2단 변속기

*/
#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
    int arr[8];
    bool up = false, down = false;

    for(int i = 0 ; i < 8; i++){
        cin >>arr[i];
        if(i != 0){
            if(arr[i - 1] > arr[i]){
                down = true;
            }else{
                up = true;
            }
        }
    }

    if(up && down){
        cout << "mixed";
    }else if(up){
        cout << "ascending";
    }else{
        cout <<"descending";
    }
    return 0;
}