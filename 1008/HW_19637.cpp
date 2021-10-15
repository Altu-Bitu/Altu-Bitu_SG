#include <iostream>
#include <map>

using namespace std;

/**
 * 모든 캐릭터와 칭호를 매칭하는 브루트 포스를 사용하기엔 최대 연산 횟수 10^5 * 10^5 -> 100억!
 * 특정 전투력 '이하'까지 해당하는 칭호를 받을 수 있음
 * -> 이분 탐색
 *
 * 맵과 셋은 원소를 정렬된 상태로 저장하기 때문에 알고리즘 헤더 없이 자체적으로 이분 탐색 함수를 사용할 수 있음
 */
int main() {
    //입출력 속도 향상을 위한 코드
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    map<int, string> title; //칭호와 그 칭호의 전투력 상한값

    int n, m, power; //칭호의 개수, 캐릭터 수, 전투력
    string name; //칭호 이름

    //입력
    cin >> n >> m;
    while (n--) { //n개 만큼의 칭호와 전투력 상한값을 입력받고
        cin >> name >> power;
        if (title[power].empty()) //전투력 상한값이 나온 적이 없는 값이라면, 즉 다른 것들 보다 크거나 아니면 작거나
            title[power] = name; //해당 상한값에 칭호를 지정한다
    }

    //출력
    while (m--) {//m개의 캐릭터에 대해서
        cin >> power; //캐릭터의 전투력을 입력받고
        cout << title.lower_bound(power)->second << '\n';
        //해당 이미 정렬된 title에서 power보다 처음으로 큰 해당 전투력에 해당하는 명칭을 출력한다.
    }
}

