/*
소프티어 근무시간

걍 하면 됨
*/
#include<iostream>
#include <string>

using namespace std;

int calculate(string start, string end){
    return (stoi(end.substr(0,2)) * 60 + stoi(end.substr(3,2))) - (stoi(start.substr(0,2)) * 60 + stoi(start.substr(3,2)));
}

int main(int argc, char** argv)
{
    int sum = 0;
    for(int i = 0 ; i < 5; i++){
        string start, end;
        cin >> start >>end;
        sum += calculate(start, end);
    }

    cout << sum;
    return 0;
}