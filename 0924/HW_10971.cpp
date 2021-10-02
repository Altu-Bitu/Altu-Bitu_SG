#include <iostream>
#include <vector>

using namespace std;
const int INF = 1e9;

vector<bool> visited; //해당 도시 방문했는지 체크하는 벡터
vector<vector<int>> matrix; //이동 비용을 요소로 가지고 있는 n*n 격자
int ans = INF; //이게 이 문제에서 될 수 있는 최소 비용인 것은 알겠는데 왜 딱 10^9인지 이해가 안돼서...일단 질문했는데 더 생각해보고 해결되면 이 부분 다시 수정하겠습니다!

/**
 * 모든 도시를 방문한 뒤 돌아올 수 있는 모든 경우 탐색
 * !생각해보기! 함수의 각 인자는 각각 어떤 역할을 하고 있나요?
 */

 //방문하고 돌아오는 모든 경우를 탐색하는 함수
 //n개의 도시를 모두 방문해야하고, start_city는 출발한 도시, cur_city는 현재 위치, cnt는 방문한 도시의 수, cost는 비용
void backtracking(int n, int start_city, int cur_city, int cnt, int cost) {
    if (cost >= ans) //생각해보기 : 이 조건문이 없으면 어떻게 될까요?
        return;
    if (cnt == n) { //종료 조건 : n개의 도시를 순회했음
        //출발 도시로 다시 돌아올 수 있는지 확인
        if (matrix[cur_city][start_city] != 0) //도시 1에서 도시 1로 돌아가는 경우가 아니라면!
            ans = min(ans, cost + matrix[cur_city][start_city]); //지금까지의 cost에 돌아오는 비용을 더해서 ans
        return;
    }
    for (int i = 0; i < n; i++) { //cur_city에서 도시 i로 이동
        if (matrix[cur_city][i] && !visited[i]) { //길이 있고, 아직 방문하지 않은 도시
            visited[i] = true; //방문 처리
            backtracking(n, start_city, i, cnt + 1, cost + matrix[cur_city][i]);
            //현재도시에서 갈 수 있는 모든 도시들 중에 하나 방문, 거기서 갈 수 있는 도시 중에 하나 방문
            //이러한 모든 경우를 재귀함수로 구현한다
            //재귀함수니까 계속 cost가 더해지면서 결국에는 마지막에 최소 비용이 나오게 됨
            visited[i] = false; //미방문 처리
        }
    }
}


//n=4
//backtracking(n, i, i, 1, 0);

/**
 * 백트래킹 풀이 (4ms)
 *
 * !주의! 모든 도시를 방문 후 시작 도시로 돌아와야 하기 때문에 어떤 도시에서 출발했는지 알고 있어야 함.
 */
int main() {
    int n;

    //입력
    cin >> n;
    visited.assign(n, false); //n개의 도시 다녀왔는지 여부 체크하도록 크기 할당
    matrix.assign(n, vector<int>(n, 0)); //n*n 격자 크기 할 당
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j]; //해당 격자에 각 도시마다 이동비용 입력하기
    }

    //연산
    //i번째 도시를 시작으로 순회
    for (int i = 0; i < n; i++) {
        visited[i] = true; //방문 처리
        backtracking(n, i, i, 1, 0); //도시 1에서 처음 출발했을 때, 2에서 처음 출발했을 때...쭉 다 해보기
        visited[i] = false; //미방문 처리
        //그래야 다음 반복문에서 다시 방문할 수 있으니까!
    }

    //출력
    cout << ans;
}