#include <iostream>
#include <algorithm>

using namespace std;


int main(){
    int N,count=0;

    cin>>N;

    for (int i=0; i<N; i++){
        string word;
        cin>>word;

        if (word.length()==1) {
            count++;
            continue;
        }

        int alphabet[26]={0,};
        alphabet[word[0]-'a']+=1; //word의 첫번째 알파벳 인덱스에 +1
        //'a'의 아스키코드가 97이니까 만약에 b가 나오면 98-97=1로 alpahbet[1]에 접근할 수 있음
        for (int j=1; j<word.length(); j++){
            if(word[j]==word[j-1]) continue;  //연속해서 나오는 문자가 같을 때
            if(alphabet[word[j]-'a']>0){ //연속해서 나오지 않았는데 이미 한 번 나왔을 때
                count--;
                break;
            }
            alphabet[word[j]-'a']+=1;
        }
        count++;
    }
    cout<<count;
}
