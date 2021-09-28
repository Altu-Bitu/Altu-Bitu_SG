#include <iostream>
#include <vector>

using namespace std;

vector<int> v;

//재귀함수를 이용해서 최대공약수 구하기
int gcdRecursion(int a, int b) {
    if (b == 0) return a;
    return gcdRecursion(b, a % b);
}

//gcd 모든 쌍을 구하는 함수
long long every_gcd(int n){
    long long result=0;

    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            result+=gcdRecursion(max(v[i],v[j]),min(v[i],v[j]));
        }
    }
    return result;
}

int main() {
    int t,n;
    long long result=0;
    //테스트 케이스의 개수 입력
    cin >> t;


    for (int i = 0; i < t; i++) {
        cin >> n; //수의 개수 입력
        v.resize(n);
        for (int j = 0; j < n; j++) {
            cin >> v[j];
        } //n개만큼의 수 입력받기

        result = every_gcd(n);
        cout << result << '\n';
    }

}