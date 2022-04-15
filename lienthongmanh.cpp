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

        int DFS(int k){
            set<int> stt;
            st.push(k);
            check[k]=1;
            stt.insert(k);
            while(!st.empty()){
                int s=st.top();
                st.pop();
                for(int i=1;i<=n;i++){
                    if(a[s][i]==1 && check[i]==0){
                        stt.insert(i);
                        check[i]=1;
                        st.push(s);
                        st.push(i);
                        break;
                    }
                }
            }
            if(stt.size()!=n) return 0;
            return 1;
        }

        void reinit(){
            for(int i=1;i<=n;i++) check[i]=0;
        }

        bool strongly_connected(){
            reinit();
            for(int u=1;u<=n;u++){
                if(!DFS(u)) return false;
                else reinit();
            }
            return true;
        }
};

int main(){
    graph g;
    g.read();
    if(g.strongly_connected()) cout<<"strongly connected";
    else cout<<"not strongly connected";
}