#include<bits/stdc++.h>
using namespace std;

class euler{
    public:
        int n,m,a[100][100];
        stack<int> st;
        vector<int> vt;
        
        void read(){
            cin>>n>>m;
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++) cin>>a[i][j];
            }
        }
        
        int check(int i){
            for(int j=1;j<=n;j++){
                if(a[i][j]) return j;
            }
            return 0;
        }
        
        void timduong(int u){
            st.push(u);
            while(!st.empty()){
                int k=st.top();
                int kt=1;
                for(int i=1;i<=n;i++){
                    if(a[k][i]){
                        kt=0;
                        st.push(i);
                        a[k][i]=a[i][k]=0;
                        break;
                    }
                }
                if(kt){
                    vt.push_back(k);
                    st.pop();
                }
            }
        }
        
        void in(){
            for(int i=vt.size()-1;i>=0;i--) cout<<vt[i]<<" ";
        }
};

int main(){
    euler g;
    g.read();
    g.timduong(g.m);
    g.in();
}