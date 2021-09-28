/*#include <iostream>
#include <stack>

using namespace std;
stack<int> s; //스택으로 하는 게 맞나...?

int main(){
    int count=0;
    int n,p;
    cin>>n>>p;

    for(int i=0; i<n; i++){
        cin>>c[i].first>>c[i].second;

    }
}*/

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

/**
 * 각 줄마다 외계인이 누르고 있는 프렛을 스택에 저장하기
 * 매 입력에 대해 이번에 누를 프렛이 해당 줄에서 가장 높은 프렛이어야 함
 *
 * 1. 이번에 눌러야 할 프렛보다 높은 프렛에서 손가락을 전부 떼기
 * 2. 만약 이번에 눌러야 할 프렛을 누르고 있지 않다면 누르기
 */

int main() {
    int n, p, guitar_string, fret, ans = 0;

    cin >> n >> p; //멜로디에 포함되어 있는 음의 수 / 한 줄 당 프렛 몇 개인지 입력받기

    //제일 위에 있는 프렛에서 손을 떼는 조치가 필요하니까 스택을 쓰는 게 가장 적합하겠네.
    vector<stack<int>> guitar(7); //1번 줄부터 6번줄 까지
    //스택은 생각을 했는데 그걸 다시 벡터에 넣는 생각을 못했음,,
    //생각해보니까 벡터에 스택을 넣으면 진짜 딱 기타 줄(가로)+프렛(세로)가 구현이 되는 군,,,
    //기 ! 억 ! 하 ! 자 !
    while (n--) {
        //입력
        cin >> guitar_string >> fret; //몇 번 줄의 몇 번 프렛 누를 것인가 ex.3번 줄의 5번 프렛

        //연산
        while (!guitar[guitar_string].empty() && guitar[guitar_string].top() > fret) {
            //이미 그 줄의 프렛 어딘가는 누르고 있는 상태이고, 그리고 이제 눌러야 되는 프렛보다 지금 누르고 있는 프렛이 더 클 때
            //ex. 지금 3번 줄의 5번 프렛 누르고 있는데 3번 줄의 3번 프렛을 눌러야 한다면?
            //프렛에서 손가락 떼기
            ans++;
            guitar[guitar_string].pop(); //제일 위에 있는 손가락에서 손을 뗄거야
        }
        if (guitar[guitar_string].empty() || guitar[guitar_string].top() != fret) {
            //지금 프렛이 비어 있거나, 아니면 눌러야 되는 프렛을 안누르고 있다면
            //프렛 누르기
            //while문에서 이미 제일 위의 프렛은 손을 떼도록 처리했으니 여기서는 그냥 누르면 됨
            ans++;
            guitar[guitar_string].push(fret);
        }
    }

    //출력
    cout << ans; //줄에서 손을 뗀 횟수, 줄에 손을 댄 횟수 모두 더한 값 출력합니다.
}


