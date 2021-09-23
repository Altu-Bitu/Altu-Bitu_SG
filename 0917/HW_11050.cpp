//
// Created by 류수한 on 2021-09-22.
//

#include <iostream>

using namespace std;

int main(){
    int n,k;
    int r=1,t=1;

    //입력
    cin>>n>>k;

    for(int i=0; i<k; i++){
        r*=n-i;
        t*=k-i;
    }
    int result=r/t;

    cout<<result<<'\n';
}