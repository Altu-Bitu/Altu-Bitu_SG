#include <iostream>
#include <vector>

using namespace std;

//부분 행렬 원소 뒤집는 함수
void reverseMtx(int row, int col, vector<string> &matrix_a) {//행의 개수, 열의 개수, 행렬을 파라미터로
    for (int i = row; i < row + 3; i++) {//3개씩 원소 바꾸기
        for (int j = col; j < col + 3; j++) {//3개씩 원소 바꾸기
            if (matrix_a[i][j] == '1') //1이면
                matrix_a[i][j] = '0';//0으로
            else
                matrix_a[i][j] = '1'; //0이면 1로 바꾸기
        }
    }
}

//마지막으로 A == B인지 확인하는 함수
int isPossible(int n, int m, vector<string> &matrix_a, vector<string> &matrix_b) {
    for (int i = 0; i < n; i++) {//행
        for (int j = 0; j < m; j++) {//열
            if (matrix_a[i][j] != matrix_b[i][j]) //a랑 b랑 해당 원소가 같지 않으면 false
                return false;
        }
    }

    return true; //같으면 true
}

/**
 * (0, 0) 인덱스부터 부분행렬을 만들 수 있는 마지막 인덱스까지 검사하며 그리디하게 푸는 문제
 * A, B 행렬의 현재 인덱스 값이 서로 다르다면 A 행렬에서 현재 인덱스로 '시작'하는 3x3 크기만큼의 부분 행렬 원소 뒤집기
 * 검사가 모두 끝난 후, A와 B가 서로 다르다면 바꿀 수 없는 경우임
 * !주의! 입력이 공백없이 주어지므로 string으로 받음
 */

int main() {
    int n, m;

    //입력
    cin >> n >> m;
    vector<string> matrix_a(n); //n개의 행으로 된 행렬 a
    vector<string> matrix_b(n);//n개의 행으로 된 행렬 b
    for (int i = 0; i < n; i++)
        cin >> matrix_a[i]; //행렬 요소 입력 받기

    for (int i = 0; i < n; i++)
        cin >> matrix_b[i]; //행렬 요소 입력 받기

    //연산
    int ans = 0;
    for (int i = 0; i <= n - 3; i++) { //3*3씩 검사할 거니까 i<=n-3까지
        for (int j = 0; j <= m - 3; j++) {//3*3씩 검사할 거니까 j<=ㅡ-3까지
            if (matrix_a[i][j] != matrix_b[i][j]) { //(i, j)원소가 서로 다르다면
                reverseMtx(i, j, matrix_a);//바꾸기
                ans++;//그리고 바꾼 횟수에 +1
            }
        }
    }

    //만약에 4*3 행렬이라면
    //

    //출력
    if (!isPossible(n, m, matrix_a, matrix_b))
        ans = -1; //최종으로 바꾸고도 ans+1이 됐으니까 출력하기 전에는 -1해주기
    cout << ans;

    return 0;
}
