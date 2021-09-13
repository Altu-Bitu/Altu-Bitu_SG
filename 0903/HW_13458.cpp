#include <iostream>
#include <vector>
using namespace std;

int main(){
    long long N,B,C,count=0;
    vector<long long> A;

    cin>>N;
    A.assign(N,0);
    for (long long i=0; i<N; i++)
        cin>>A[i];

    cin>>B>>C;

    for (long long j=0; j<N; j++){
        long long n=A[j]-B; //총감독관이 볼 수 있는 인원을 총 인원에서 빼고
        count++; //감독관 총 수에 +1
        if(n>0) {
            if (n % C == 0)
                count += n / C;
            else
                count += n / C + 1;
        }
    }

    cout<<count;
}

//교훈: 에러가 난다면 최대로 나올 수 있는 값의 범위도 고려를 해보자
