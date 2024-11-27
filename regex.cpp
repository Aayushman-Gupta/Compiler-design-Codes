#include<bits/stdc++.h>
using namespace std;

int main(){
    regex demo("[a-zA-Z0-9_][a-zA-Z0-9_!@#$%^&*()|?><]*");
    string s;
    cin>>s;
    if(regex_match(s,demo)){
        cout<<"String matches "<<endl;
        return 1;
    }
    cout<<"String doesnot match "<<endl;
    return 0;
}