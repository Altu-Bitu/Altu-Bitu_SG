//
// Created by 류수한 on 2021-09-28.
//
#include <iostream>

using namespace std;

const int SIZE = 8;

int n, m; //1부터 n까지의 자연수 중 m개를 고르는 문제
int num[SIZE]; //1부터 n까지의 자연수
//수열에 들어갈 수 있는 1~n까지의 수를 넣는 배열
bool check[SIZE + 1]; //1번 인덱스부터 사용하니까!
//중복되지 않게 출력하기 위해서 check 배열을 통해 중복 여부를 검사해준다.

//재귀함수로 구현한 백트래킹
void backtrackg(int cnt) {//cnt: 수열의 인덱스
    //탈출조건
    if (cnt == m) { //밑에 반복문이 2번 돌아서 수가 num에 이미 2개 들어갔으니까 여기서는 출력
        for (int i = 0; i < cnt; i++)
            cout << num[i] << ' '; // 1 2 이런 식으로 중간에 공백 두고 출력하기
        cout << '\n'; //한 수열 출력할 때마다 줄바꿈
        return;
    }

    for (int i = 1; i <= n; i++) {
        if(!check[i]){ //check[i]가 true가 아니면(이미 들어간 값이 아니면)
            num[cnt] = i; //수열의 해당 인덱스에 값을 넣어주기
            check[i]=true;//값을 넣어줬으니까 true로 바꿔서 또 다시 들어갈 수 없게
            backtrackg(cnt + 1); //바로 다음 수열 인덱스 호출
            check[i]=false; //원래 상태로 돌려놓기
        }


    }
}
//i=1
// backtracking(0) -> num[0]=1 -> backtraking(1) -> check[1]이 true니까 num[1]=2 -> backtraking(2) -> 1 2 출력
//num[1]=3 ->  -> 1 3 출력 ->num[1]=4 -> backtraking(2) -> 1 4 출력 -> check[1] false

//i=2
// backtracking(0) -> num[0]=2 -> backtraking(1) -> num[1]= 1 -> backtraking(2) -> 2 1 출력
//num[1]=2는 안됨 check[2]가 true라서 따라서 num[1]=3 -> backtraking(2) -> 2 3 출력 ->num[1]=4 -> backtraking(2) -> 2 4 출력 -> check[2] false

//이 과정 i=3,i=4일 때 똑같이 반복해주면 됨

int main() {

    //입력
    cin >> n >> m;

    //연산+출력
    backtrackg(0); //num의 0번 인덱스부터 수열을 채워넣으니까
    return 0;
}
