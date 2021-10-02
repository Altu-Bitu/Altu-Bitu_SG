//
// Created by 류수한 on 2021-09-30.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<vector<int>> cost(10,vector<int>(10,0));
vector<vector<bool>> check; //가로를 기준으로 분석할거야
vector<int> possible; //가능한 비용을 다 이 벡터에 넣은 후에 여기서 min 값을 찾으면 되지 않을까?

int result=0;

void pickRoute(int start,vector<vector<int>> v,vector<vector<bool>> c){
    int s=sizeof(v[0])/sizeof(int);

    if(start==s)
        possible.push_back(result);

    for(int j=0; j<s; j++) //하 근데 뭔가 꼭 도시 1에서부터 출발하는 건 아니잖아 아아아악...
        if(v[start][j]){
            result+=v[start][j];
            c[j][start]=false;
            for (int i=0; i<s; i++)
                c[i][j]=false;
            pickRoute(start+1,v,c);
        }
}

int main(){
    int n,min=0;//start는 출발한 도시가 어디인지
    //입력
    cin>>n;

    //2차원 벡터의 크기를 할당해준다
    cost.assign(n,vector<int> (n,0));
    check.assign(n,vector<bool> (n,true));

    for(int i=0; i<n; i++)
        check[i][i]=false;

    //도시 간의 비용을 입력받는다
    for(int j=0; j<n; j++){
        for(int i=0; i<n; i++){
            cin>>cost[i][j];
        }
    }

    pickRoute(0,cost,check);
    min=*min_element(possible.begin(),possible.end());

    cout<<min<<'\n';

    return 0;
}