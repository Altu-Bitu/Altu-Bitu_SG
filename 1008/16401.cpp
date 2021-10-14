#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int M, N; //조카의 수, 과자의 수
vector<int> l; //과자 조각을 넣을 벡터

//이분 탐색하는 함수
int binary_search(int start, int stop, vector<int> v){
    int result=0;

    while (start <= stop) {
        int mid = (start + stop) / 2;
        int cnt=0;

        for(int i=0; i<N; i++){ //현재 mid가 최대길이
            cnt+=l[i]/mid; //그리고 과자를 최대 길이로 나눠서 조각 수를 구한다
        }

        if(cnt>=M){ //과자 조각이 조카 수보다 많으면
            result=mid; //일단 그
            start=mid+1; //탐색 시작하는 범위를 mid+1로 지정하여 다시 탐색한다
        }

        else
            stop=mid-1;
    }

    return result;
}

int main() {
    int length; //과자의 길이
    int max_length = 0; //과자 최대 길이
    int start = 1, stop = 0; //탐색 시작, 끝
    int result = 0;


    //입력
    cin >> M >> N;
    l.assign(N, 0); //과자를 넣을 벡터 크기 지정
    for (int i = 0; i < N; i++) {
        cin >> length; //각 과자의 길이
        l[i] = length;
        stop = max(stop, length); //가장 길이가 긴 과자를 stop으로 설정한다
    }

    //정답 출력
    cout << binary_search(start,stop,l);

}

// 참고 링크: https://peanut2016.tistory.com/268
