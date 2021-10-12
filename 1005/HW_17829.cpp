#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> matrix; //행렬을 담을 수 있는 2차원 벡터 만들기

//행렬을 2*2 정사각형으로 나누는 함수
int divide(int row, int col, int size) {//행,열의 인덱스 번호, 그리고 행렬의 크기를 파라미터로 받는다
    //Conquer : n의 크기가 1
    if (size == 1)
        return matrix[row][col]; //이게 각 정사각형의 2번쨰로 큰 수를 모으고 쪼개고를 반복해서 남은 최후의 수

    //Divide : 행렬 4등분 하기
    int next_size = size / 2; //행렬 한 변의 크기의 반(즉,행렬을 4등분한다)
    vector<int> sub_problem; //나눈 해당 행렬에서 2번쨰로 큰 값들이 요소로 들어간 벡터
    for (int i = 0; i <= next_size; i += next_size) { //가로 방향
        for (int j = 0; j <= next_size; j += next_size) //세로 방향
            sub_problem.push_back(divide(row + i, col + j, next_size)); //재귀함수 돌면서 사이즈는 계속 반씩 줄어들고
    }
    //행렬의 크기가 1이 되면 해당 원소를 리던하고, 그 요소를 sub_problem에 넣는다
    //재귀함수를 돌면서 요소들이 쌓이고 최종적으로 1*1 정사각형 4개가 모인 정사각형이 만들어지고
    //그 요소들을 아래 sort에서 정렬하여 두번째로 큰 값을 뽑아낸다

    //Combine : 두번째로 큰 수만 남기기
    sort(sub_problem.begin(), sub_problem.end(), greater<>()); //오름차순 대로 벡터 정리하고
    return sub_problem[1];//두번째로 큰, 즉 1번 인덱스의 값 리턴
}

/**
 * 1. 행렬 4등분 하기
 * 2. 행렬의 크기가 1이라면 원소 리턴
 * 3. 리턴된 원소 4개 모아서 두번째로 큰 수만 리턴
 */
int main() {
    int n;

    //입력
    cin >> n; //행렬 n*n
    matrix.assign(n, vector<int>(n)); //행렬을 담을 벡터의 크기 지정하기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j]; //행렬 요소 입력받기
    }

    //연산 & 출력
    cout << divide(0, 0, n);
}

