#include <iostream>
#include <vector>

using namespace std;

//최소 비용을 계산하는 함수
long long min_cost(int n, vector<long long> d, vector<long long> c) {
    long long min_cost = 0;//리턴할 최소비용

    for (int i = 0; i < n - 1;) {
        if ((i <= n - 2) && (c[i] < c[i + 1])) {
            c[i+1]=c[i]; //만약 앞 도시의 기름값이 더 싸면 앞 도시에서 기름을 더 살 거니까 다음 도시 기름값을 아예 바꿔주기
            min_cost+=c[i]*d[i]; //그리고 기름값이 앞 도시랑 뒷 도시랑 같아졌으니까 이제 그냥 곱해서 비용 계산
            i++;
        }
        else {
            min_cost += d[i] * c[i]; //만약에 앞 도시가 더 비싸면 걍 일단은 한 도시 갈 양만 사고, 그 다음 도시 기름값 알아보기
            i++;
        }
    }

    return min_cost;
}

int main() {
    int n; //도시 수
    //입력
    cin >> n;

    vector<long long> distance(n - 1, 0);
    vector<long long> cost(n, 0);


    for (int i = 0; i < n - 1; i++)
        cin >> distance[i];
    for (int i = 0; i < n; i++)
        cin >> cost[i];

    cout << min_cost(n, distance, cost);

    return 0;
}
