#include <string>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;
stack<int> q;

int solution(vector<vector<int>> board, vector<int> moves) {
    int top_pointer=-1; //empty 일 때
    int answer = 0;

    for(int i=0; i<moves.size(); i++){
        q.push(board[moves[i]][]);
    }

    while(!q.empty()){
        int k=q.top();

    }

    return answer;
}

/*int main(){
    int n;
    cin>>n;
    string input1;
    string input2;

    vector<vector<int>> board(n*n); //격자 선언하기
    vector<int> moves(n); //인형을 집기 위해 크레인을 작동시킨 위치

    //격자에 들어있는 인형 종류 입력 받기
    cin>>input1;


    //moves 입력받기
    cin>>input2;


    //꺾쇠 제외하고 온전히 숫자만 moves의 요소로 넣기
    for(int i=0; i<input2.size(); i++){
        if('0'<=input2[i]<='9')
            moves[i]=input2[i]-'0';
    }

    cout<<solution(board,moves)<<'\n';


}*/