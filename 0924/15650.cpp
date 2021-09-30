//이 문제 조건에는 수열을 중복없이 오름차순으로 출력하라는 조건이 있는데
//오름차순이 되면 자동으로 중복은 제거가 되니까 15649번과 다르게 check 배열은 필요가 없다
#include <iostream>

using namespace std;

const int SIZE = 8; //수가 최대 8개까지 입력될 수 있으니까 SIZE를 상수 8로 지정

int n, m; //n개의 수 중에 m개의 수를 골라서 수열로 출력할거야
int num[SIZE]; //1부터 n까지의 수를 넣을 배열

//재귀함수로 구현한 백트래킹
void backtracking(int cnt, int start) {
    //cnt는 0으로 들어갈거고, 이게 m과 같아지면 출력을 한다. 즉 m개의 수로 이루어진 수열을 출력하기 위한 변수
    //start는 만약 1 2 / 1 3 / 1 4 모두 출력 됐다면 2 1 이렇게 2부터 시작해서 다시 수열을 출력하기 위한 변수

    if (cnt == m) {//반복문 m번 돌아서 m개의 수를 포함한 수열 출력 준비 완.
        for (int i = 0; i < cnt; i++)
            cout << num[i] << ' '; //수열의 요소를 공백으로 구분한다
        cout << '\n'; //수열 하나씩 출력하고 줄바꿈
        return;
    }

    for (int i = start; i <= n; i ++) {
            num[cnt] = i; //수열 저장
            backtracking(cnt + 1, i + 1); //재귀함수로 2,3,4 나머지 수를 하나씩 배열에 넣고 출력
    }
}

//i==start==1
//backtraking(0,1) -> num[0]=1 -> backtracking(1,2) -> num[1]=2 -> backtracking(2,3) -> cnt==m==2 -> 1 2 출력
//backtracking(1,3) -> num[1]=3 backtracking(2,4) -> cnt==m==2 -> 1 3 출력
//backtracking(1,4) -> num[1]=4 backtracking(2,5) -> cnt==m==2 -> 1 4 출력

//i==2
//num[0]=2 -> backtracking(1,3) -> num[1]=3 -> backtracking(2,4) -> cnt==m==2 -> 2 3 출력
//backtracking(1,4) -> num[1]=4 backtracking(2,5) -> cnt==m==2 -> 2 4 출력

//i==3,i==4에서도 이 과정 반복한다

int main(){
    //입력
    cin>>n>>m;

    //연산+출력
    backtracking(0,1);

    return 0;

}