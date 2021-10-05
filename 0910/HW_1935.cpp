#include <iostream>
#include <stack>
#include <vector>
#include <map>

using namespace std;
stack<char> s;
vector<int> v;

int main(){
    int n;
    string input;

    cin>>n;
    v.assign(n,0);
    cin>>input;
    map<char,int> num;

    for(int i=0; i<n; i++){
        int k;
        cin>>k;
        v[i]=k;
    }

    for(int i=0; i<input.size(); i++){
        for(int j=0; j<n; j++){
            if('A'<=input[i]<='Z')
                num[input[i]]=v[j];
            else
                s.push(input[i]);
                    if(s.size()==2)

        }
    }
//힌트를 봐도 감이 안와효,,,
//뭔가 *- *+ /- /+ 이런식으로 곱하기,나누기 / 덧셈,나눗셈이 연달아 같이 나오면
//거기서 스택을 비우고 다시 시작해야되는 것 같은 느낌은 드는데..그게 맞는지..
//그리고 그걸 어떻게 구현할지,,,
//힌트 받고 다시 짜볼게요!!ㅠㅜ







}

