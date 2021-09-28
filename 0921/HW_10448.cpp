//
// Created by 류수한 on 2021-09-26.
//


#include <iostream>
#include <vector>

using namespace std;
vector<int> v(50,0);

void put_num(int n){
    for (int j = 1;; j++) {
        int k = j * (j + 1) / 2;
        if (k >= n) break;
        v[j-1]=k;
    }
}

//3개의 삼각수로 표현이 가능한지 판별하는 함수
int triangular(int n) {
    //for (int i = 0; i < v.size(); i++)
    //이렇게 하면 삼중반복문에서는 v.size()함수를 3번 돌려야 하니까
    //연산횟수 줄이기 위해서 변수에 v.size() 저장

     //n보다 작거나 같은 삼각수들을 모두 벡터에 담는다
     put_num(n);

    for (int i = 0; v[i]!=0; i++) {
        for (int r = 0; v[r]!=0; r++) {
            for (int t = 0; v[t]!=0; t++) {
                if (v[i] + v[r] + v[t] == n) {
                    return 1;
                }
            }
        }
    }

    return 0;
}

int main() {
    int n, k;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> k;
        cout << triangular(k)<<'\n';
    }

    return 0;
}

