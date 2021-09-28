#include <iostream>
#include <vector>

using namespace std;

struct info { //내구도와 로봇 존재 여부
    int power;
    bool is_on;
}; //그러면 belt라는 벡터 안에 이 info라는 구조체 요소가 2N(0번~2n-1번)개 들어있을 것.

vector<info> belt;  //컨테이너 벨트 정보(내구도, 로봇 존재 여부)
int zero_power;     //내구도가 0인 벨트 칸의 개수

//한칸씩 갈 때마다 올리는 위치와 내리는 위치가 하나씩 줄어드는 걸 구현한 함수
int minusPosition(int n, int pos) { //인덱스 감소
    if (--pos >= 0)
        return pos;
    return n * 2 - 1; //만약에 pos가 0이었다면 올리는 위치 or 내리는 위치가 -1번 이 되는 게 아니라 2n-1번으로 옮겨아야됨
}

//옆칸으로 이동할 수 있는 지 판단하는 함수
void second(int n, int start, int end) {
    int cur = end; //현재 내리는 위치
    while (cur != start) { //end - 1 부터 start 까지 검사
        cur = minusPosition(n, cur); //cur에 end-1을 대입하고
        int next = (cur + 1) % (n * 2); //다음 위치__2n-1이라면 next==0/나머지는 그냥 다 자기 자신+1이 나올 것
        if (belt[cur].is_on && !belt[next].is_on && belt[next].power) { //현재 위치에 로봇이 있고, 다음 위치에 로봇이 없으며 내구성 1이상인 경우 -> 로봇 옮김
            belt[cur].is_on = false; //로봇을 옮겼으니까 현재 위치에는 로봇이 없어
            belt[next].power--; //로봇 옆으로 옮겼으니까 옆칸은 내구성 -1하기
            if (next != end) //내리는 위치 아닐 경우만__내리는 위치라면 올렸지만 바로 내려야하니까 그냥 내구성만 떨어짐(이게 맞나,,)
                belt[next].is_on = true; //로봇 옮기기
            if (belt[next].power == 0) //만약에 옆칸의 내구성이 0이면
                zero_power++; //내구성이 0인 칸의 개수에 +1 하기
        }
    }
}

//second가 로봇을 옆칸으로 옮길 수 있는지 없는지였다면 third는 올릴 수 있는지 없는지 내구도를 보는 것!
void third(int start) {
    if (belt[start].power) { //올리는 위치의 내구도가 0이 아니라면 로봇 올림
        belt[start].is_on = true; //로봇 올라감
        belt[start].power--; //올린 칸의 내구도는 -1 해야함
        if (belt[start].power == 0) //그리고 그 칸의 내구도가 만약에 0이 되었다면
            zero_power++; //내구도가 0인 칸의 개수에 +1하기
    }
}

/**
 * [컨베이어 벨트 위의 로봇 문제]
 * 1. 벨트가 각 칸 위의 로봇과 함께 한 칸 회전
 * 2. 가장 먼저 벨트에 올라간 로봇부터, 벨트 회전 방향으로 한 칸 이동할 수 있다면 이동 (이동가능: 이동하려는 칸에 로봇이 없고, 그 칸의 내구도가 1 이상이어야 함)
 * 3. 올리는 위치에 있는 칸의 내구도가 0이 아니면 올리는 위치에 로봇 올림
 * 4. 내구도가 0인 칸의 개수가 k개 이상이라면 과정 종료. 그렇지 않다면 1로 돌아감
 * -> 1 ~ 3까지가 1단계
 *
 * [문제 풀이]
 * 벨트의 로봇을 옮기는 게 아니라, 올리는 위치와 내리는 위치의 인덱스 값을 바꿔서 접근
 * 필요한 컨테이너: 내구도와 로봇의 존재여부를 체크할 배열
 * 1번: 벨트의 방향이 오른쪽이므로, 벨트 한 칸 회전 시 올리는 위치와 내리는 위치의 인덱스 값은 하나 감소
 * 2번: 가장 먼저 올라간 로봇부터 고려해야 하므로 (내리는 위치 - 1)부터 (올리는 위치)까지 검사 -> 로봇 옮기는 거 가능하면 존재여부 체크하고 내구도 감소
 * 3번: 올리는 위치 칸 내구도 0이 아니라면 해당 칸 로봇 존재 여부 체크 + 내구도 감소
 */

int main() {
    //입출력 속도를 가속시키기 위한 코드입니당
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k; //컨베이어 벨트의 길이 , 내구도가 0인 칸이 몇 개 있어야 작동이 멈추는지

    //입력
    cin >> n >> k;
    belt.assign(n * 2, {0, false}); //2n개의 칸을 할당한다

    //2n개 칸의 각각의 내구도 입력받기
    for (int i = 0; i < n * 2; i++)
        cin >> belt[i].power;

    //연산
    int start = 0;    //올리는 위치
    int end = n - 1;  //내리는 위치
    int step = 0;     //단계 수

    while (true) {
        start = minusPosition(n, start); //한 칸 앞으로 가면서 올리는 위치 -1됨
        end = minusPosition(n, end); //그리고 내리는 위치 -1됨
        if (belt[end].is_on) //벨트 회전 후, 로봇이 내리는 위치에 있다면 내리기
            belt[end].is_on = false; //그리고 여기에는 로봇이 없어
        second(n, start, end); //여기서 end-1부터 start까지 컨베이어벨트 작동하면서 로봇 옆으로 이동이동
        third(start); //그리고 이건 새로 로봇을 올리는 것과 관련됨! second 함수의 결과로 내구성이 0이면 못 올리고 0이 아니면 올림
        step++;//1-3이 한 스텝이니까!
        if (zero_power >= k) //k를 넘어섰다면 과정을 종료해야함
            break; //과정 종료 == 반복분 나오기
    }

    //출력
    cout << step << '\n';

    return 0;
}