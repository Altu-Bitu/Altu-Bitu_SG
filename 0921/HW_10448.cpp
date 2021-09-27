//
// Created by 류수한 on 2021-09-26.
//

//배애애앰...시간초과....

#include <iostream>
#include <vector>

using namespace std;
vector<int> v;

void pop(vector<int> v1) {
    for (int i = 0; i < v1.size(); i++) {
        v1.pop_back();
    }
}

//3개의 삼각수로 표현이 가능한지 판별하는 함수
int triangular(int n) {
    //for (int i = 0; i < v.size(); i++)
    //이렇게 하면 삼중반복문에서는 v.size()함수를 3번 돌려야 하니까
    //연산횟수 줄이기 위해서 변수에 v.size() 저장

    for (int j = 1;; j++) {
        int k = j * (j + 1) / 2;
        if (k > n) break;
        v.push_back(k);
    } //n보다 작거나 같은 삼각수들을 모두 벡터에 담는다

    int s = v.size();

    for (int i = 0; i < s; i++) {
        for (int j = 0; j < s; j++) {
            for (int t = 0; t < s; t++) {
                if (v[i] + v[j] + v[t] == n) {
                    pop(v);
                    return 1;
                }
            }
        }
    }

    pop(v);
    return 0;


}

int main() {
    int n, k;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> k;
        cout << triangular(k);
    }

    return 0;
}

