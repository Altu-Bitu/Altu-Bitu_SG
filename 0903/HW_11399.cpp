#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    int total=0;
    vector<int> time;

    cin>>n;
    time.assign(n,0);

    for (int i=0; i<n; i++)
        cin>>time[i];

    sort(time.begin(),time.end());

    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            total+=time[j];
        }
    }

    cout<<total;
}