//
// Created by 류수한 on 2021-09-26.
//
#include <iostream>

using namespace std;

int main() {
    int R, B, L, W;
    //입력
    cin >> R >> B;

    //세로와 가로 중 작은 것은 A+B를 더한 것의 제곱근보다는 무조건 작거나 같다는 것 착안
    for (int i = 1; i * i <= (R + B); i++) {
        if ((i - 2) * (((R + B) / i) - 2) == B) {
            //갈색은 (가로-2)*(세로-2)와 같으니까
            L = i;
            W = (R + B) / i;
            break;
        } else
            continue;
    }

    if (L < W) { //큰 것을 L로 넣기 위한 부분
        int temp=W;
        W=L;
        L=temp;
    }

    //출력
    cout << L << ' ' << W;

    return 0;
}
