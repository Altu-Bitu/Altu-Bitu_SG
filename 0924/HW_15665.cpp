#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int SIZE = 7; //배열 크기
const int RANGE = 10000; //주어지는 수 범위

int n, m, leng; //leng: 서로 다른 수의 개수
int num[SIZE], ans[SIZE]; //입력된 수를 중복을 제외하고 담을 배열 num과 수열을 출력하기 위해 m만큼의 크기를 가진 ans 생성

void backtracking(int cnt) {//여기서 cnt는 ans의 인덱스
    if (cnt == m) { //길이 m이라면 (기저조건)
        for (int i = 0; i < cnt; i++)
            cout << ans[i] << ' '; //요소 사이에 공백을 넣어 수열 출력하기
        cout << '\n';
        return;
    }
    for (int i = 0; i < leng; i++) { //중복 수 모두 제거되었으므로 따로 체크할 필요 없이 수열을 만든다
        ans[cnt] = num[i];
        backtracking(cnt + 1); //재귀함수로 수열의 다음 요소들 넣기
    }
}

//예를 들어 n=4, m=4 1 1 2 2 가 입력되었다고 가정하자
//그러면 지금 num=[1,2]인 상태
//backtraking(0)->ans[0]=1->backtraking(1)->answer[1]=1->backtraking(2)->answer[2]=1->backtraking(3)->answer[3]=1->backtracking(4)
//cnt==m이니까 1 1 1 1 출력
//backtraking(3)->answer[3]=2->backtracking(4) 1 1 1 2 출력
//backtraking(2)->answer[2]=2->backtraking(3)->answer[3]=1 ->backtracking(4) 1 1 2 1
//이런 과정 쭉 반복하면 사전 순으로 수열을 출력시킬 수 있다
//포인트는 중복을 제외하고 그 수를 새로운 배열에 넣은 것 & 새로운 요소의 개수만큼 반복문을 돌려서 새 수열을 만드는 것

/**
 * [백트래킹 풀이] (176ms)
 * 조건: 같은 수 여러 번 사용 가능, 수열은 중복되면 안됨, 사전 순으로 출력
 * '같은 수 여러 번' -> 완전탐색
 * '수열 중복되면 안됨'
 * -> 현재 중복으로 들어오는 수가 존재하여, 그냥 완전탐색을 진행하면 중복 수열이 생김
 * -> 따라서, 중복으로 들어오는 수를 제거하여 다른 배열에 저장한 후, 완전탐색을 하자!
 * '사전 순으로 출력' (N과 M(1)과 동일)
 */

int main() {
    vector<bool> check(RANGE, false); //중복 수 제거하며 받기 위한 체크 배열
    int a; //입력받을 수

    //입력 (중복 제거하며 num 배열에 저장하기)
    cin >> n >> m; //n개 중 m개를 골라 수열 만들기
    for (int i = 0; i < n; i++) { //n개 만큼
        cin >> a; //수 입력받기
        if (!check[a]) //처음 나온 수라면
            num[leng++] = a; //이렇게 입력받고 num에 넣으면 num에는 4 4 2 이렇게 입력되도 4 2만 저장됨!
        check[a] = true; //이미 나온 수인지 아니면 새로 나온 수인지를 체크한다
    }

    //연산
    sort(num, num + leng); //num에 중복없이 들어온 수들을 오름차순으로 정렬하기

    //연산 + 출력
    backtracking(0);

    return 0;
}