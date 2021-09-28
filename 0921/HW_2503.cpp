#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> ci;

//baseball이라는 구조체를 만들어서 민혁이가 말한 숫자 + 그 수의 스트라이크, 볼 여부 담기!
//그리고 이 구조체를 요소로 하는 벡터를 만들어서 순회할 거야
struct baseball {
    string num;       //서로 다른 세 자리 수
    int strike, ball; //스트라이크 개수, 볼 개수
};

//스트라이크랑 볼의 횟수를 셀거야
//매개변수를 string으로 넣어야 세자릿수를 한 자리수씩 비교할 수 있다!
//이 아이디어 잘 기억해두기! 항상 여기서 좀 헤맸음ㅠㅜ
ci cntStrikeBall(string &s1, string &s2) {
    int strike_cnt = 0; //s1과 s2사이의 strike 개수
    int ball_cnt = 0;   //s1과 s2사이의 ball 개수

    //세자리의 수니까 반복을 세 번 돌면서 각자리 수를 분석할거야
    for (int i = 0; i < 3; i++) {
        if (s1[i] == s2[i]) //위치+수 정확히 일치 -> 스트라이크
            strike_cnt++;
        else if (s1.find(s2[i]) != s1.npos) //위치 다른데 수가 존재 -> 볼
            ball_cnt++;
        //여기서 npos는 find 함수에서 찾으려고 하는 요소가 없을 때 반환하는 주소 값이다!
        //그래서 != s1.npos 는 찾으려고 하는 그 요소가 존재한다는 의미!
    }

    return ci(strike_cnt, ball_cnt); //스트라이크, 볼 횟수를 담은 pair ci 반환하기
}

//본격적으로 게임을 시작하지.
int game(int n, vector<baseball> &question) {//매개변수로 질문 횟수, 그리고 민혁이가 말한 수와 그것의 스트라이크, 볼 횟수를 가진 벡터
    int ans = 0; //정답 개수

    //123부터 987까지의 수 중 서로 다른 세 수로 이뤄진 세자릿수만 고려할 거니까
    //1억개가 안돼서 그냥 브루트포스를 쓰자!
    for (int i = 123; i <= 987; i++) { //i는 영수가 생각하고 있을 가능성이 있는 수!
        bool check = true;
        string s1 = to_string(i);  //정답인지 확인할 수
        //각 자릿수를 비교해야되니까 string으로 바꿔준다!

        //서로 다른 세 수로 이뤄진 세자릿수만 고려하기 위한 부분
        if (s1[0] == '0' || s1[1] == '0' || s1[2] == '0') //0이 하나라도 있다면
            continue;
        if (s1[0] == s1[1] || s1[0] == s1[2] || s1[1] == s1[2]) //서로 같은 수 하나라도 있다면
            continue;

        for (int j = 0; j < n; j++) {
            string s2 = question[j].num; //질문으로 들어온 수
            ci cnt = cntStrikeBall(s1, s2); //s1과 s2사이의 스트라이크와 볼 개수
            if (cnt.first != question[j].strike || cnt.second != question[j].ball) { //하나라도 다르면
                check = false;
                break;
            }
            //만약에 s1이 125 s2가 369이면 cnt는 (0,0)일거야
            //근데 입력된 값이 369 1 0 이라면 125는 배제시키는거지
        }

        if (check)
            ans++;
        //cnt가 (1,1)이고 입력된 볼,스트라이크도 1 1 이면 위에 for문에서 안걸리니까
        //처음에 설정한 check=true에 변화가 없음.
        //그래서 이 i값은 영수가 생각하고 있는 수일 가능성이 있으니까 ans에 +1을 해준다.
    }

    return ans;
}

/**
 * [숫자 야구]
 * 서로 다른 세 자리 수에서 위치+수 같으면 스트라이크, 위치는 다르고 수가 존재하면 볼
 * n개의 질문으로 수와 스트라이크와 볼 개수가 주어질 때, 이를 모두 만족하는 서로 다른 세 자리 정답 수의 개수
 *
 * [풀이]
 * 서로 다른 세 자리수는 123 ~ 987이 가능하다. 이는 총 865가지
 * 질문 n의 범위는 최대 100
 * 따라서 123부터 하나씩 증가시키며 정답이 되는지 검사해도 865 * 100 * 3(자릿수)으로 접근 충분히 가능!
 */

int main() {
    int n; //질문의 횟수

    //입력
    cin >> n;

    vector<baseball> question(n); //질문의 횟수를 크기로 하는 벡터를 만든다
    for (int i = 0; i < n; i++) {
        cin >> question[i].num >> question[i].strike >> question[i].ball;
    }//민혁이가 말한 숫자 / 스트라이크 횟수 / 볼 횟수 차례로 입력

    //연산 + 출력
    cout << game(n, question);

    return 0;
}

//본격 게임을 하는 함수 부분 / 볼과 스트라이크 횟수를 세는 함수 따로 나누면 생각하기가 더 쉬워짐!