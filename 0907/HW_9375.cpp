#include<iostream>
#include<map>
#include<string>
using namespace std;

int main()
{
    int N, T;
    int ans;
    string s1, s2;

    cin >> T; // 테스트케이스 수

    while (T--)
    {
        map<string, int> m; // Map<의상종류,의상수>

        ans = 1;
        cin >> N; // 의상 수

        for (int i = 0; i < N; i++)
        {
            cin >> s1 >> s2;

            // key값이 존재하지 않으면 find 함수가 end() 리턴한다
            if (m.find(s2) == m.end())
            {
                m[s2] = 1;
            }
            else // 해당 key값이 존재할 경우
            {
                m[s2]++;
            }

        }

        for (auto iter : m)
            ans *= (iter.second + 1); // (의상수+1) 씩 곱하기

        cout << ans - 1 << "\n";
    }
}