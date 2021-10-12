#include <iostream>

using namespace std;

//큰 수를 찾아내는 함수
string maxNum(string s) {
    string ans = ""; //작은 수, 지금은 비어있지만 하나씩 추가해서 답을 리턴할 것
    string temp = ""; //ans에 추가할 수를 보관하는 임시 장소
    for (int i = 0; i < s.length(); i++) {
        temp += '0'; //그리고 또다른 k가 나오기 전까지 그 자릿수만큼 0을 더해주기(M)
        if (s[i] == 'K') { //K가 마지막으로 끝나는 십진수 변환
            temp[0] = '5'; //K라면 앞자리수가 5가 되니까 temp에 5 넣기
            ans += temp; //그리고 그 5를 ans에 넣어주기
            temp = "";//그리고 temp는 다시 비워주기
        }
    }
    if (temp.length() >= 1) { //K로 끝나지 않았다면 마지막 M모두 1로 변환
        for (int i = 0; i < temp.length(); i++) //temp에 남은 M만큼을 모두 1개씩 취급해서 1로 바꿔주기
            temp[i] = '1';
        ans += temp;//그리고 ans에 temp 값 더해주기
    }
    return ans; //답 반환
}

//작은 수를 찾아내는 함수
string minNum(string s) {
    string ans = ""; //작은 수, 지금은 비어있지만 하나씩 추가해서 답을 리턴할 것
    string temp = ""; //ans에 추가할 수를 보관하는 임시 장소
    char first = '1';
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'M') {//K가 나오기 전까지 M은 묶어서 변환을 할꺼니까 처음에는 1 나머지는 계속 0 더하기
            temp += first;
            first = '0';
        }
        else { //'K' -> 그 전까지 M묶음 변환 더하고, K는 따로 변환
            ans += temp + '5'; //K는 하나씩 따로따로로
            temp = "";
            first = '1'; //0이었던 first 다시 1로 바꾸고 M 들어오면 다시 1000... 이렇게 넣을 수 있게!
        }
    }

    if (temp.length() >= 1) //마지막이 M으로 끝났다면
        ans += temp; //temp에 남아있던 덩어리 한 번에 더해주기
    return ans; //답 반환
}

/**
 * [가장 큰 값]
 * 민겸수에서 마지막이 K일 때, K까지 포함하여 십진수로 변환한다
 * K로 끝나지 않는다면 각 M을 모두 하나로 처리한다 (ex. MMM -> 111)
 *
 * [가장 작은 값]
 * K는 무조건 단독으로 변환한다
 * 나머지 M묶음들은 같이 변환한다
 * ex. MMKMM -> 10510
 */

int main() {
    string s; //민겸수

    //입력
    cin >> s;

    //출력(큰,작은)
    cout << maxNum(s) << '\n' << minNum(s) << '\n';

    return 0;
}
