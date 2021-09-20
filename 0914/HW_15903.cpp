#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, m; //카드 개수, 몇번 합체하는 지
    cin >> n >> m;

    long long arr[1000]; //카드를 넣을 배열
    long long smallest = 0;


    for (int i = 0; i < n; i++)  //맨 처음 카드 상태 입력받기
        cin >> arr[i];

    for (int i = 0; i < m; i++) {
        sort(arr, arr + n); //점점 커지게 정렬하기
        long long tmp = arr[1] + arr[0]; //작은 수끼리 더하고
        arr[0] = tmp;
        arr[1] = tmp; //이 수를 두 카드에 덮어쓰기
    }

    for (int i = 0; i < n; i++)
        smallest += arr[i];

    cout << smallest;
}

