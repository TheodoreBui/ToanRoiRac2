#include<bits/stdc++.h>
using namespace std;

class graph{
    public:
        int n,a[100][100],check[100]={0};
        stack<int> st;
        void read(){
            cin>>n;
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++) cin>>a[i][j];
            }
        }
        void DFS(int k){
            st.push(k);
            check[k]=1;
            cout<<k<<" ";
            while(!st.empty()){
                int s=st.top();
                st.pop();
                for(int i=1;i<=n;i++){
                    if(a[s][i]==1 && check[i]==0){
                        cout<<i<<" ";
                        check[i]=1;
                        st.push(s);
                        st.push(i);
                        break;
                    }
                }
            }
        }
};
int main(){
    graph g;
    g.read();
    g.DFS(4);
}