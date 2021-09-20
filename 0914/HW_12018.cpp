#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n,m; //과목수와 마일리지
std::priority_queue<int,vector<int>,greater<int>> pq1;
//우선순위는 내림차순으로

int main(){
    cin>>n>>m; //과목수와 마일리지 입력받고

    while(n--){
        int p,l; //해당 과목에 신청한 사람수, 수강인원
        cin>>p>>l;

        vector<int> v(p); //신청한 사람 수만큼의 크기의 벡터 만들기

        for(int i=0; i<p; i++){
            cin>>v[i];
        } //각 사람이 마일리지를 얼마나 넣었는지

        sort(v.begin(),v.end()); //적은 마일리지부터 정렬

        if(v.size()<l) //신청한 사람이 수강인원보다 적으면 다 들어가겠지
            pq1.push(1);
        else
            pq1.push(v[p-l]); //수강인원 넘치면 높은 마일리지 배팅한 애들 중에 제일 적은 거 넣기
    }

    int sum=0;
    int ans=0;
    while(!pq1.empty() && sum + pq1.top()<=m){
        sum+=pq1.top(); //마일리지 높게 배팅한 애들부터 넣고
        ++ans;
        pq1.pop(); //이미 들어간 건 빼자
   }

    cout<<ans;
}

