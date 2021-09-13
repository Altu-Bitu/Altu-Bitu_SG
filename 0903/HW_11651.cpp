#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct point{
    int xpos;
    int ypos;
};


bool cmp(const point &p1,const point &p2){
    if(p1.ypos!=p2.ypos)
        return p1.ypos<p2.ypos;
    return p1.xpos<p2.xpos;
}

int main(){
    int num;
    vector<point> ppoint;

    cin>>num;
    ppoint.assign(num,{});

    for (int i=0; i<num; i++){
        cin>>ppoint[i].xpos>>ppoint[i].ypos;
    }

    sort(ppoint.begin(),ppoint.end(),cmp);

    for (int i=0; i<num; i++){
        cout<<ppoint[i].xpos<<' '<<ppoint[i].ypos<<'\n';

    }
}