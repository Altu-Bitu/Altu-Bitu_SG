#include <iostream>
#include <string>

using namespace std;

int main(void){
    string s;
    cin >> s; //자바 형식인지 C++ 형식인지

    bool c = false, java = false, err = false;
    string result;

    for (int i = 0; i < s.length(); i++)
    {
        if ('A' <= s[i] && s[i] <= 'Z') //대문자 알파벳이 들어오면 자바의 2번째 단어 이상
        {
            if (!i || c)
            //첫번째 문자로 대문자가 오거나, c++로 인식했는데 대문자가 나오는 경우
            {
                err = true;
                break;
            }
            //에러에 안 걸렀다면, 자바형식으로 들어온 거니까 c++형태로 바꿔준다
            result += '_';
            result += s[i] - 'A' + 'a'; //알파벳을 소문자로 바꿔주기
            java = true;

        }
        else if (s[i] == '_')
        {
            if (!i || java || i == s.length() - 1 || s[i + 1] == '_' || ('A' <= s[i + 1] && s[i + 1] <= 'Z'))
            //예외들: 첫번째 문자로 _가 오거나, java라고 인식했는데 _가 들어오거나
            //맨 마지막 문자로 _가 들어오거나, __으로 나오는 경우나, c++인데 다음 문자로 대문자가 오는 경우
            {
                err = true;
                break;
            }

            //에러 안 걸렸다면 c++ 형식으로 들어온 것 그래서 자바 형식으로 바꿔줘야 함
            result += s[i + 1] - 'a' + 'A'; //언더바 건너뛰고 뒤 알파벳을 소문자로 바꾸기
            i++;
            c = true;
        }
        else
            result += s[i]; //자바와 c++의 첫번째 문자
    }

    if (err)
        cout << "Error!\n";
    else
        cout << result << "\n";

}

