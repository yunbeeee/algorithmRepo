#include <iostream>
#include <cstring>
#include <vector>
#include <string>
using namespace std;

int cache[1000001];

int digit(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int constructor(int num) {
    int& ret = cache[num];
    if (ret != -1)
        return ret;
    int wow = to_string(num).length();
    for (int i = 1; i < num; i++) {
        int cal = i + digit(num);
        if (cal == num) { ret = i; }
        else { ret = 0; }
    }
    return ret;

}

int main() {
    int N;
    cin >> N;
    memset(cache, -1, sizeof(cache));
    cout << constructor(N) << endl;
}