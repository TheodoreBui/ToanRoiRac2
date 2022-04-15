#include <bits/stdc++.h>
using namespace std;
 int main() {
    int t ;
    cin>>t ;
    while(t--){
        scanf("\n");
        string str ;
        cin>>str;
        set<char> s;
        for(int i=0;i<str.size();i++) s.insert(str[i]);
        cout<<s.size()<<endl;
   }
 }