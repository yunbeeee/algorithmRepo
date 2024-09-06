#include <iostream>
#include <cstring>
#include <vector>
using namespace std;


int cache[100001];

int lion(int num){
    // 기저 사례
    if (num == 0)
        return 1;
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

int main(){
    int N;
    cin >> N;
    // cache 초기화
    memset(cache, -1, sizeof(cache));
    cout << lion(N) << endl;
}