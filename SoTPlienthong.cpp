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
        
        void dfs(int k){
            st.push(k);
            check[k]=1;
            while(!st.empty()){
                int s=st.top();
                st.pop();
                for(int i=1;i<=n;i++){
                    if(a[s][i]==1 && check[i]==0){
                        check[i]=1;
                        st.push(s);
                        st.push(i);
                        break;
                    }
                }
            }
        }
        void soTP(){
            int dem=0;
            for(int i=1;i<=n;i++){
                if(check[i]==0){
                    dem++;
                    dfs(i);
                }
            }
            cout<<dem;
        }
};

int main(){
    graph g;
    g.read();
    g.soTP();
    
}