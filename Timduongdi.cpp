#include<bits/stdc++.h>
using namespace std;
int ktDFS=0,ktBFS=0;

class graph{
    public:
        int a[100][100],n,check[100],truoc[100],s,t;
        stack<int> st;
        queue<int> qe;
        
        void read(){
            cin>>n>>s>>t;
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++) cin>>a[i][j];
            }
        }
        
        void dfs(int k){
            st.push(k);
            check[k]=1;
            while(!st.empty()){
                int u=st.top();
                st.pop();
                for(int i=1;i<=n;i++){
                    if(a[u][i]==1 && check[i]==0){
                        check[i]=1;
                        st.push(u);
                        st.push(i);
                        truoc[i]=u;
                        break;
                    }
                }
            }
        }
        
        void bfs(int k){
            qe.push(k);
            check[k]=1;
            while(!qe.empty()){
                int u=qe.front();
                qe.pop();
                for(int i=1;i<=n;i++){
                    if(a[u][i]==1 && check[i]==0){
                        qe.push(i);
                        check[i]=1;
                        truoc[i]=u;
                    }
                }
            }
        }
        
        void in(int s,int t){
            cout<<t<<" ";
            int u=truoc[t];
            while(u!=s){
                cout<<u<<" ";
                u=truoc[u];
            }
            cout<<s<<endl;
        }
        
        void init(){
            for(int i=1;i<=n;i++){
                check[i]=0;
                truoc[i]=0;
            }
        }
};

int main(){
    graph g;
    g.read();
    g.init();
    g.dfs(g.s);
    if(g.truoc[g.t]){
        cout<<"DFS path: ";
        g.in(g.s,g.t);
        ktDFS=1;
    }
    g.init();
    g.bfs(g.s);
    if(g.truoc[g.t]){
        cout<<"BFS path: ";
        g.in(g.s,g.t);
        ktBFS=1;
    }
    if(ktDFS==0 && ktBFS==0) cout<<"no path";
}