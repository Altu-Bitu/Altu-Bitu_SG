#include <iostream>

using namespace std;

const int SIZE = 15; //입력범위가 15까지

int n, ans;//n*n 체스판 ,answer는 경우의 수
bool check_col[SIZE]; //열 체크
bool check_left[SIZE * 2]; //좌하향 대각선 체크
bool check_right[SIZE * 2]; //우하향 대각선 체크

void backtracking(int cnt) { //cnt: 행(행을 넘어가면서 값을 검사할거야)
    //탈출 조건
    if (cnt == n) { //n개의 퀸이 모두 놓임
        ans++; //정답 증가
        return;
    }
    for (int i = 0; i < n; i++) { //i: 열
        if (!check_col[i] && !check_left[cnt + i] && !check_right[cnt - i + n]) { //모두(열,왼쪽 대각선,오른쪽 대각선) false여야 배치 가능
            //(cnt, i)에 퀸 배치 -> 그에 따른 열, 좌하향 대각선, 우하향 대각선 체크해줌
            check_col[i] = true; //퀸이 놓였으니까 이제 더이상 열 사용 불가
            check_left[cnt + i] = true; //퀸이 놓였으니까 이제 더이상 왼쪽 대각선 사용 불가
            check_right[cnt - i + n] = true; //퀸이 놓였으니까 이제 더이상 오른쪽 대각선 사용 불가
            backtracking(cnt + 1); //다음 행 호출
            //재탐색이 가능하도록 원래상태로 돌려놓음
            check_col[i] = false;
            check_left[cnt + i] = false;
            check_right[cnt - i + n] = false;
        }
    }

}

//backtracking(0)-0행부터 검사를 시작한다 -> i=0 0행 0열이 false고 그 좌우 대각석 선 다 false면 거기에 퀸 하나 놓고 좌우대각선,열 모두 탐색 안되게 false로 바꿔줌
//backtracking(1)-1행 검사 시작 -> i=0~n 1행 0열,1열,~n열까지 하나하나씩 탐색하면서 좌우대각선과 열이 사용가능한 곳을 찾아서 퀸을 놓는다.
//그래서 이 과정을 n번 돌고 n개의 퀸이 놓이게 되면, 그때 경우의 수가 +1이 되는 것!

/**
 * 시간 1684ms
 */

int main() {
    //입력
    cin >> n;

    //연산
    backtracking(0);

    //출력
    cout << ans << '\n';

    return 0;
}
