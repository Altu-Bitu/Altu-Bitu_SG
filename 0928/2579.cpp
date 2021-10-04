#include <iostream>
#include <vector>

using namespace std;

int maxScore(int n, vector<int> &score) {
    vector<int> dp(n + 1, 0); //계단마다의 최대 점수를 담기 위한 벡터

    //점화식을 이용해서 구할 수 없는 수에 대해서는 먼저 써주기
    dp[1] = score[1]; //계단 1개만 있으면 그거 밟는 게 최대
    dp[2] = score[1] + score[2]; //계단 2개라면 1개 밟고 또 밟는 게 최대

    //3부터는 점화식 적용할 수 있다
    for (int i = 3; i <= n; i++)
        dp[i] = max(dp[i - 2], dp[i - 3] + score[i - 1]) + score[i];
    //2개 전 계단을 한 번에 오르거나, 3개 전 계단에서 2개를 오르고 또 1개를 오르는 경우

    //마지막 계단까지 올라갔을 때의 최대
    return dp[n];
}

int main() {

    int n;//계단 갯수

    //입력
    cin >> n;
    vector<int> score(n + 1, 0); //각 계단을 오를 때의 점수를 담을 벡터
    for (int i = 1; i <= n; i++)
        cin >> score[i];//계단 당 점수 입력받기

    cout<<maxScore(n,score)<<'\n';

    return 0;
}

