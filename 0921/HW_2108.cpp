#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> v;

const int SIZE = 4000;

//산술평균
int avg(vector<int> v) {
    int result = 0, s = v.size();

    for (int i = 0; i < s; i++) {
        result += v[i];
    }
    if (result % s > s / 2) //소수점 첫째자리 수에서 반올림하기 위한 코드
        return (result / s) + 1;
    else
        return result / s;
}

//중앙값
int mid(vector<int> v) {
    int num = v.size() / 2;
    sort(v.begin(), v.end());
    return v[num];
}

//최빈값(여러 개 있을 때에는 최빈값 중 두 번째로 작은 값을 출력한다.)
int frq(vector<int> v) {
    vector<int> cnt(SIZE * 2 + 1, 0); //수가 -4000부터 4000까지 들어올 수 있으니까 8001개의 인덱스가 있는 벡터 하나 만들기
    vector<int> w;

    for (int i = 0; i < v.size(); i++) {
        cnt[v[i]+4000]++; //v[i]가 6이면 4006번째 인덱스에 +1하기
    }

    auto m = max_element(cnt.begin(), cnt.end()); //cnt에서 가장 요소가 큰 인덱스의 주소 반환
    w.push_back(m-cnt.begin()-4000);
    for (int i = 0; i < SIZE * 2 + 1; i++) {//여기서 여러개의 최빈값을 w리스트에 다 넣어주는 것
        if (cnt[i] == *m && (i != m - cnt.begin())) //근데 m에서 하나를 이미 넣었으니까 그건 빼고
            w.push_back(i-4000);
    }

    if(w.size()==1) return w[0];
    else{
        sort(w.begin(),w.end()); //오름차순으로 정렬해서 두번째 값 출력하도록 하기
        return w[1];
    }
}

//범위(최댓값과 최솟값의 차이)
int range(vector<int> v) {
    int max = v[0], min = v[0];
    int s = v.size();

    for (int j = 1; j < s; j++) {
        if (v[j] > max)
            max = v[j];
        if (v[j] < min)
            min = v[j];
    }

    return max - min;
}

int main() {
    int n, k;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> k;
        v.push_back(k);
    }

    cout << avg(v) << '\n';
    cout << mid(v) << '\n';
    cout << frq(v) << '\n';
    cout << range(v) << '\n';

    return 0;
}
