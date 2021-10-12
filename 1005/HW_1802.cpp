#include <iostream>
#include <algorithm>

using namespace std;

bool divide(string str) {
    //Conquer : 문자열의 길이가 1
    if (str.size() == 1) //원룡이가 접었다가 편 종이를 동호의 규칙대로 접을 수 있음
        return true; //따라서 true 리턴

    //Combine : 가운데 값을 기준으로 접었을 때, 만나게 되는 각 자릿수가 같다면 접을 수 없음
    int len = str.size(); //접혀있는 횟수
    for (int i = 0; i < len / 2; i++) { //가운데를 기준으로 접으니까 i<len/2일 때까지만 반복문 돌림
        if (str[i] == str[len - i - 1])  //len의 자릿수가 4라면 i=0 len-i-1=3 따라서 처음과 끝 요소를 비교하는 것
            return false; //만약에 처음과 끝이 같다면 접을 수 있다.
    }

    //Divide : 문자열을 절반으로 나누기
    return divide(str.substr(0, len / 2));
    //반절 접은 그 종이의 상태를 리턴한다(위로 올라간 부분 or 아래로 내려간 부분을 substr로 잘라냄)
}

/**
 * 1. 가운데를 중심으로 접었을 때, 만나게 되는 각 자릿수가 다르다면 접을 수 있음
 * 2. 문자열의 길이가 1이 될 때까지 종이 접기
 *
 * (ex1)
 * 100 0 110
 * 0을 기준으로 접으면 100과 011이 겹쳐짐 -> 접을 수 있음
 *
 * 100에 대해 다시 가운데를 기준으로 나누면 1 0 0
 * 0을 기준으로 접으면 1과 0이 겹쳐짐 -> 접을 수 있음
 *
 * (ex2)
 * 0 0 0
 * 0을 기준으로 접으면 0과 0이 겹쳐짐 -> 접을 수 없음
 */
int main() {
    int t; //테스트케이스의 갯수
    string str; //종이가 접혀진 상태를 str으로 받아서 size 함수를 써서 길이도 구하고, 각자릿수도 비교하기 쉽게 한다

    cin >> t;
    while (t--) {
        //입력
        cin >> str;

        //연산
        bool ans = divide(str); //접을 수 있는지 아닌지 재귀함수 돌리면서 판단하기

        //출력
        cout << ((ans) ? "YES" : "NO") << '\n';
    }

}