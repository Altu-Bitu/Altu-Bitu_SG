#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int SIZE=10001;

int front_pointer=0, back_pointer=0;
vector<int> d(SIZE);

//empty
int empty(){
    if(back_pointer==front_pointer) return 1;
    return 0;
}

//full
bool full(){
    if(back_pointer>=SIZE)
        return false;
    return true;
}

//push_back
void push_back(int x){
    if(full()!=false){
        d[back_pointer++]=x;
    }
}

//push_front
void push_front(int x){
    if(empty()==1) {
        push_back(x); //비어있을 때는 앞으로 넣나 뒤로 넣나 똑같으니까
    }
    else{
        vector<int> N(back_pointer-front_pointer); //벡터를 새로 하나 만들고
        for(int i=0; i<back_pointer-front_pointer; i++){ //원래 벡터에 들어있었던 요소들을 새 벡터에 복사한다
            N[i]=d[i];
        }
        d[front_pointer]=x; //그리고 맨 앞에 요소를 넣고
        for(int i=0; i<N.size(); i++){ //그 뒤 인덱스부터 차례대로 복사한 요소들을 뒤로 집어 넣는다
            push_back(N[i]);
        }
    }

}

//pop_front
int pop_front(){
    if(empty()==1) return -1;
    else
    {
        int tmp=d[front_pointer]; //일단 임시로 pop 할 요소를 저장하고
        back_pointer--; //하나 뺐으니까 포인터 이동
        vector<int> N(back_pointer-front_pointer);
        for(int i=1; i<=N.size(); i++){
            N[i-1]=d[i];//남은 요소들을 다른 벡터에 저장하고
        }
        for(int i=0; i<N.size(); i++){
            d[i]=N[i];//그 요소들을 다시 인덱스 0부터 차례대로 저장한다
        }
        return tmp;

    }
}
//pop_back
int pop_back(){
    if(empty()==1) return -1;
    return d[--back_pointer];
}
//size
int size(){
    return back_pointer-front_pointer;
}

//front
int front(){
    if(empty()==1) return -1;
    return d[front_pointer];
}

//back
int back(){
    if(empty()==1) return -1;
    return d[back_pointer-1];
}

int main(){
    int n,x;
    cin>>n;

    string input;

    while(n--){
        cin>>input;
        if(input=="push_front"){
            cin>>x;
            push_front(x);
            continue;
        }
        if(input=="push_back"){
            cin>>x;
            push_back(x);
            continue;
        }
        if(input=="pop_front"){
            cout<<pop_front()<<'\n';
            continue;
        }
        if(input=="pop_back"){
            cout<<pop_back()<<'\n';
            continue;
        }
        if(input=="size"){
            cout<<size()<<'\n';
            continue;
        }
        if(input=="empty"){
            cout<<empty()<<'\n';
            continue;
        }
        if(input=="front"){
            cout<<front()<<'\n';
            continue;
        }
        if(input=="back"){
            cout<<back()<<'\n';
            continue;
        }

    }
}
