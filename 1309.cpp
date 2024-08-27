#include <iostream>
#include <cstring>
using namespace std;


int cache[100001];

int main(){
    int N;
    cin >> N;
    memset(cache, -1, sizeof(cache));
    cout << lion(N) << endl;
}


int lion(int num){
    // 기저 사례
    if (num == 0)
        return 0;
    if (num == 1)
        return 3;
    // 참조형 변수 설정
    int& ret = cache[num];
    if(ret != -1)
        return ret;
    ret = 2 * lion(num - 1) + lion(num - 2);
    ret %= 9901;
    return ret;
}