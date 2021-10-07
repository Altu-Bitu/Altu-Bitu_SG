#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//숫자 두개씩 더해서 큰 순서대로 벡터에 넣는 함수
vector<int> sum_two(vector<int> l, vector<int> c, int n) {
    int s = l.size();
    for (int i = n + 1; i < s - 1; i++) {
        for (int j = i + 1; j<s; j++) {
            c.push_back(l[i] + l[j]);
        }
    }
    sort(c.begin(), c.end(), greater<int>());
    c.erase(unique(c.begin(),c.end()),c.end());

    return c;
}

//삼각형 최대 길이를 구하는 함수
int max_length(vector<int> l,vector<int> c){
    int result=0;
    for (int i = 0; i < l.size() - 2; i++) {
        c=sum_two(l,c,i);
        for (int j = 0; j < c.size(); j++) {
            if (l[i] <= c[j]) {
                result = l[i] + c[j];
                return result;
            }
            else
                continue;
        }
    }

    return -1;
}

int main() {
    int n, result = 0;

    //입력
    cin >> n;

    vector<int> l(n,0);
    vector<int> c;

    for (int i = 0; i < n; i++)
        cin >> l[i];

    int s = l.size();
    for (int i = n + 1; i < s - 1; i++) {
        for (int j = i + 1; j<s; j++) {
            c.push_back(l[i] + l[j]);
        }
    }
    sort(c.begin(), c.end(), greater<int>());
    c.erase(unique(c.begin(),c.end()),c.end());


    cout << max_length(l,c);

    return 0;
}
