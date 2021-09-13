#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


bool cmp(string &a1,string &b1){
    int a1_size=a1.size(),b1_size=b1.size();
    int A=0,B=0;
    //문자열의 길이가 다를 때 짧은 게 먼저 온다
    if(a1_size != b1_size) return a1_size<b1_size;

    //문자열의 길이가 같을 때 숫자 합이 작은 게 먼저
    for (int i=0; i<a1_size; i++){
        if('0'<=a1[i] && a1[i]<='9')
            A+=a1[i]-30;
        if('0'<=b1[i] && b1[i]<='9')
            B+=b1[i]-30;
    } //'0'<=a1[i]<='9' 이렇게 쓰면 못 알아들음
    //B+=(int)b1[i]; 이렇게 하면 b1[1]=='7'이면 (int)b1[i]==7이 아니라 55로 나옴
    //즉 문자 7의 아스키코드가 나온당 
    if(A != B) return A<B;

    return a1<b1; //사전순
}

int main(){
    int n;

    cin>>n;
    string serial[n];

    for(int i=0; i<n; i++)
        cin>>serial[i];
    sort(serial,serial+n,cmp);

    for(int i=0; i<n; i++)
        cout<<serial[i]<<'\n';

    return 0;
}

