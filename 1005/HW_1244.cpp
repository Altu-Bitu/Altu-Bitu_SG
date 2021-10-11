#include <iostream>
#include <vector>

using namespace std;

int sn; //스위치 개수 //스위치 최대 100개
vector<int> s(sn+1, 0);

//
void print_light(int n){
    for (int i = 1; i <= sn; i++) {
        cout << s[i] << ' ';
        if (i % 20 == 0) //20 넘어가면 한 줄 밑에서 출력
            cout << '\n';
    }
    cout << '\n';
}

void girl(int n) {
    int left = n - 1;
    int right = n + 1;

    if (s[n] == 0) s[n] = 1; //일단 양쪽 검사하기 전에 해당 칸의 상태 바꿔주기
    else s[n] = 0;

    while (left >= 1 && right <= sn) {
        if (s[left] != s[right])
            break; //양쪽이 다르면 그냥 바로 break

        else {
            if (s[left] == 0) {
                s[left] = 1;
                s[right] = 1;
            }
            else{
                s[left] = 0;
                s[right] = 0;
            }

        }
        left--;
        right++;
    }

}

void boy(int n, int size) {
    int num;
    for (int i = 1;; i++) {
        num = n * i;
        if (num >= size) break;
        if (s[num] == 0) s[num] = 1;
        else s[num] = 0;
    }

    return ;
}

int main() {
    int studentNum;
    //스위치 개수 입력
    cin >> sn;

    for (int i = 1; i <= sn; i++)
        cin >> s[i];

    //학생수 입력
    cin >> studentNum;

    for (int i = 0; i < studentNum; i++) {
        int sex, num;
        cin >> sex >> num;

        if (sex == 1) {
            boy(num, sn);
            print_light(sn);
        }//남자면

        else //여자면
        {
            girl(num);
            print_light(sn);
        }
    }

    print_light(sn);

    return 0;
}

//참고 링크: https://velog.io/@woga1999/BOJ-1244%EB%B2%88-%EC%8A%A4%EC%9C%84%ED%82%A4-%EC%BC%9C%EA%B3%A0-%EB%81%84%EA%B8%B0-C