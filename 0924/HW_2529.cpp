#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 10;

int k; //부등호 개수
bool is_find; //부등호에 만족하는 수인지 검사하기 위한 변수
vector<char> op(SIZE); //부등호
vector<int> arr(SIZE), num(SIZE); //답을 넣을 배열, 일단 그냥 수를 넣어놓을 배열
vector<bool> check(SIZE); //중복안되게 체크하는 배열

//수열을 문자열로 바꾸는 함수
string arrToString(vector<int> &arr) { //함수 안에서만 쓰이는 매개변수의 값이 아니라 실제 값을 바꿔줘야 하니까 주소값을 매개변수로 받는다
    string result;
    for (int i = 0; i <= k; i++)
        result += (arr[i] + '0'); //아스키코드 값을 더하여 문자열로 바꾸어준다다
    return result;
}

//과정에서의 답이 가능성 있는 답인지 체크하는 함수
bool promising(int idx) {
    if (op[idx] == '<' && arr[idx] > arr[idx + 1]) //부등호가 '<'인데 '>'관계일 때
        return false;
    if (op[idx] == '>' && arr[idx] < arr[idx + 1]) //부등호가 '>'인데 '<'관계일 때
        return false;
    return true; //위 if에서 다 걸리지 않으면 수가 맞게 들어간 거니까 true 리턴
}

//최댓값 or 최솟값 구하는 백트래킹 함수 (num배열을 통해 구분)
void findValue(int cnt) {
    //수가 2개 이상이 배치됐다면, 주어진 부등호 만족하는지 검사, 만족하지 않으면 바로 리턴 (가지치기)
    if (cnt >= 2 && !promising(cnt - 2))
        return;
    if (cnt == k + 1) { //부등호 만족하는 수를 찾음 (기저조건)
        is_find = true; //이미 체크까지 다 마쳤는데 수가 부등호랑 다 적합하게 들어가서 함수 나오기
        return;
    }
    for (int i = 0; i <= k; i++) { //num[i]: 최댓값이면 9 ~ (9-k), 최솟값이면 0 ~ k
        if (!check[num[i]]) {//한번도 쓰이지 않은 수
            check[num[i]] = true; // 또 쓰이지 않게 true 넣기
            arr[cnt] = num[i]; //답이 될 수 있는 수의 cnt 자릿수에 num[i]넣기
            findValue(cnt + 1); //재귀함수로 그 다음 수 찾기
            if (is_find) //k번째 부등호에 맞는 수까지 다 찾아졌다면
                return; //함수 나오기
            check[num[i]] = false;//반복할 때마다 그 전에 쓰였던 수가 또 검사될 수 있게 false로 바꾸기
            arr[cnt] = 0;
        }
    }
}

/**
 * [백트래킹 풀이] (0ms)
 * 수를 중복없이 배치함 (N과 M(1)과 동일)
 * 수를 배치할 때마다 해당 수가 그 전 수와 부등호 관계를 만족하는지 확인, 만족하지 않으면 back (가지치기)
 */

int main() {
    string max_num, min_num; //정답

    //입력
    cin >> k; //부등호 문자의 개수 입력
    for (int i = 0; i < k; i++) {
        cin >> op[i]; //부등호 입력
    }

    //최댓값 연산
    for (int i = 0; i <= k; i++) //num배열에 값 미리 저장
        num[i] = 9 - i; //최댓값은 9부터 (9-k)까지 숫자로 이루어짐
    findValue(0);
    max_num = arrToString(arr);

    //초기화 !주의! 전역변수 사용 시 초기화 빼먹기 쉬우니 잘 체크하자
    is_find = false;
    check.assign(SIZE, false);
    arr.assign(SIZE, 0);
    //윗 부분은 최솟값 연산을 또 하기 위해서 다시 다 초기화를 시켜주는 것

    //최솟값 연산
    for (int i = 0; i <= k; i++)
        num[i] = i; //최솟값은 0부터 k까지 숫자로 이루어짐
    findValue(0);
    min_num = arrToString(arr);

    //출력
    cout << max_num << '\n' << min_num;

    return 0;
}

