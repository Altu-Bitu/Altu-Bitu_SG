#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string number, int k) {
    int s=number.size();
    int n=s-k;
    char w;

    vector<int> c;

    for(int i=0; i<s; i++)
        c.push_back(number[i]-'0');

    sort(c.begin(),c.end(),greater<int>());

    string answer="\0";

    for(int i=0; i<n; i++){
        w=c[i]+'0';
        answer+=w;
    }


    return answer;
}
