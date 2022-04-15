#include<bits/stdc++.h>
using namespace std;

class graph{
    public:
        int n,check[100],a[100][100];
        stack<int> st;
        
        void read(){
            cin>>n;
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++) cin>>a[i][j];
            }
        }
        
        void init(){
            for(int i=1;i<=n;i++) check[i]=0;
        }
        
        int dfs(int k){
            st.push(k);
            check[k]=1;
            while(!st.empty()){
                int u=st.top();
                st.pop();
                for(int i=1;i<=n;i++){
                    if(a[u][i] && check[i]==0){
                        check[i]=1;
                        st.push(u);
                        st.push(i);
                    }
                }
            }
            for(int i=1;i<=n;i++){
                if(check[i]==0) return 1;
            }
            return 0;
        }
        void dinhtru(){
            init();
            for(int i=1;i<=n;i++){
                check[i]=1;
                if(dfs(1)) cout<<i<<" ";
                init();
            }
        }
};

int main(){
    graph g;
    g.read();
    g.dinhtru();
}