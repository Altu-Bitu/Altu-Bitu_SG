#include <iostream>
#include <vector>

using namespace std;

vector<int> v;

//소수 판별하기
vector<bool> prime(int n){
    vector<bool> prime_list(n+1,true);

    for(int i=2; i*i<n; i++){
        if(prime_list[i]){
            for(int j=i*i; j<=n; j+=i){
                if(!prime_list[j])
                    continue;
                prime_list[j]=false;
            }

        }
    }

    for(int i=2; i<prime_list.size(); i++){
        if(!prime_list[i]) prime_list.erase(prime_list.begin()+i);
    } //벡터에 소수인 요소들만 있을 수 있도록 소수아닌 것은 요소에서 제외

    return prime_list;
}

int main(){
    int n;

    while(n!=0){
        cin>>n;
        v.push_back(n);
    }
    v.pop_back(); //맨뒤에 들어간 0 지우기

    for(int i=0; i<v.size(); i++){
        for(int j=1; j<=prime(v[i]).size(); j++) //소수만 있는 벡터 순회하면서 답 찾기

    }


    return 0;
}
