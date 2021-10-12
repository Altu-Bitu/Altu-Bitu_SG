#include <iostream>
#include <vector>

using namespace std;

//남학생의 스위치 바꾸기
vector<int> changeSwitchBoy(int n, int number, vector<int> switches) { //스위치개수, 남학생이 받은 번호, 스위치 벡터를 파라미터로 받는다
    for (int i = number; i <= n; i += number) //배수에 있는 스위치 바꾸기
        switches[i] = !switches[i]; //아 ! 이렇게 하면 0은 1로, 1은 0으로 바꿀 수 있구낭,,,나는 if문으로 복잡하게 했는데 ㅠㅅㅠ 또 배웠당

    return switches; //그래서 상태가 바뀐 스위치 벡터를 리턴한다
}

//여학생의 스위치 바꾸기
vector<int> changeSwitchGirl(int n, int number, vector<int> switches) {
    switches[number] = !switches[number]; //일단 여학생이 받은 그 수의 인덱스에 위치한 스위치의 상태 바꾸고
    for (int i = 1; i < number; i++) { //number를 가운데 두고 양쪽을 비교하는 거니까 i도 number 전까지만 증가시킴
        if ((number + i > n) || (switches[number - i] != switches[number + i])) //스위치 범위 넘어가거나 좌우 대칭이 아니면
            break;
        //왼쪽은 number-i, 오른쪽은 number+i로
        //스위치 범위 넘어가는 건 생각을 못했는데 오른쪽에 치우져진 번호를 받으면 그럴 수도 있겠구나
        //스위치 범위 넘어가는 것도 그러면 탈출조건에 넣어주기
        switches[number - i] = !switches[number - i]; //위 if문에서 안걸리면 양쪽이 똑같은 거니까 0은 1로, 1은 0으로
        switches[number + i] = !switches[number + i];
    }

    return switches; //상태 바뀐 스위치 벡터 리턴하기
}

/**
 * 남학생 -> 해당 번호의 배수에 해당하는 스위치 상태 바꾸기
 * 여학생 -> 해당 번호를 중심으로 좌우 대칭이면서 가장 많은 스위치 포함하는 구간의 상태 모두 바꾸기
 *
 * 좌우 대칭 검사 시, 스위치 범위 주의 (주어진 스위치 범위 넘어가지 않도록)
 * 스위치 20개씩 출력하는 부분 주의
 */
int main() {
    int n, m; //스위치 개수, 학생 수
    int student, number; //성별과 할당받은 번호

    //입력
    cin >> n;
    vector<int> switches(n + 1, 0); //인덱스로 비교해야하니까 n+1 크기만큼의 스위치 벡터를 만들어준다
    for (int i = 1; i <= n; i++)
        cin >> switches[i]; //스위치 상태 입력받기

    //입력 & 연산
    cin >> m;
    while (m--) {
        cin >> student >> number; //성별과 할당받은 번호 입력
        if (student == 1) //남자면
            switches = changeSwitchBoy(n, number, switches);
        else //여자면
            switches = changeSwitchGirl(n, number, switches);
    }

    //출력
    for (int i = 1; i <= n; i++) {
        cout << switches[i] << ' '; //스위치 상태를 쭉 출력하는데
        if (i % 20 == 0) //개수가 20개 넘어가면 20단위로 잘라서 아랫줄에 출력하기
            cout << '\n';
    }
    return 0;
}