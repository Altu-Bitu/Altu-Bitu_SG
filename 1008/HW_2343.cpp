#include <iostream>
#include <vector>

using namespace std;

int bluRayNum(vector<int> &lesson, int size) {
    int len = 0; //한 블루레이에 들어가는 강의 길이
    int cnt = 0; //블루레이 개수
    for (int i = 0; i < lesson.size(); i++) {
        if (len + lesson[i] > size) { //한 블루레이에 들어갈 수 있는 길이를 초과
            len = 0; //다시 0으로 초기화하고
            cnt++;//개수는 +1
        }//반복문 돌려서 사이즈를 초과하지 않게 몇개의 블루레이 나오는 지 세기
        len += lesson[i]; //강의 시간 더하기
    }

    return cnt + 1; //마지막 구간의 블루레이 더해서 리턴
}

//이분 탐색 함수
int lowerSearch(vector<int> &lesson, int left, int right, int target) {
    int ans = 0; //m개의 블루레이를 만족할 때 최소 크기
    while (left <= right) {//
        int mid = (left + right) / 2;
        int cnt = bluRayNum(lesson, mid); //블루레이 크기가 mid일 때, 몇 개의 블루레이를 쓰는지 리턴

        if (cnt <= target) {//cnt가 하나의 블루레이에 들어갈 수 있는 강의의 수보다 작다면
            right = mid - 1;
            ans = mid; //cnt == target일 때
        } else { //cnt가 블루레이에 들어갈 수 있는 강의의 수보다 크다면
            left = mid + 1; //left를 mid+1로 바꾸고 다시 이분탐색
        }
    }

    return ans;
}

/**
 * m개의 블루레이에 모든 기타 강의 동영상을 녹화할 때 블루레이 크기의 최소를 구하는 문제
 * -> 특정 블루레이 크기로 기타 강의 동영상을 차례로 녹화할 때, 총 블루레이 개수가 m개가 되는가?
 *
 * left: 가능한 블루레이의 최소 크기 (블루레이 최대 개수) -> 가장 긴 강의 길이값
 * right: 가능한 블루레이의 최대 크기 (블루레이 최소 개수) -> 모든 강의를 더한 길이값
 */

int main() {
    int n, m, left = 0, right = 0; //총 강의의 수, 블루레이에 들어가는 강의의 수, 최소 크기, 최대 크기

    //입력
    cin >> n >> m; //강의 수 입력받기
    vector<int> lesson(n, 0); //강의의 길이를 요소로 가지는 벡터
    for (int i = 0; i < n; i++) {
        cin >> lesson[i]; //강의의 길이 입력받기
        left = max(left, lesson[i]); //가장 긴 강의 길이값 찾기
        right += lesson[i]; //모든 강의 길이 더하기
    }

    //연산 & 출력
    cout << lowerSearch(lesson, left, right, m);

    return 0;
}