#include<bits/stdc++.h>
using namespace std;


class graph{
    public:
        int n,m,a[100][100],check[100];
        stack<int> st;
        queue<int> qe;
        vector< vector<int> > kq;
        
        void read(){
            cin>>n>>m;
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++) cin>>a[i][j];
            }
        }
        
        void in(vector<int> vt){
            for(auto x:vt) cout<<x<<" "; 
            cout<<endl;
        }
        
        void ghinhan(int x,int y){
            vector<int> vt;
            vt.push_back(x);
            vt.push_back(y);
            sort(vt.begin(),vt.end());
            kq.push_back(vt);
        }
        
        void dfs(int k){
            st.push(k);
            check[k]=1;
            while(!st.empty()){
                int s=st.top();
                st.pop();
                for(int i=1;i<=n;i++){
                    if(a[s][i]==1 && check[i]==0){
                        ghinhan(s,i);
                        check[i]=1;
                        st.push(s);
                        st.push(i);
                        break;
                    }
                }
            }
        }
        
        void bfs(int k){
            qe.push(k);
            check[k]=1;
            while(!qe.empty()){
                int s=qe.front();
                qe.pop();
                for(int i=1;i<=n;i++){
                    if(a[s][i]==1 && check[i]==0){
                        ghinhan(s,i);
                        qe.push(i);
                        check[i]=1;
                    }
                }
            }
        }
        
        void TreegraphDFS(int m){
            for(int i=1;i<=n;i++) check[i]=0;
            kq.clear();
            dfs(m);
            if(kq.size()<n-1) cout<<"khong co khung\n";
            else {
                cout<<"DFS tree: \n";
                for(int i=0;i<kq.size();i++) in(kq[i]);
            }
        }
        
        void TreegraphBFS(int m){
            for(int i=1;i<=n;i++) check[i]=0;
            kq.clear();
            bfs(m);
            if(kq.size()<n-1) cout<<"khong co khung\n";
            else {
                cout<<"BFS tree: \n";
                for(int i=0;i<kq.size();i++) in(kq[i]);
            }
        }
};

int main(){
    graph g;
    g.read();
    g.TreegraphDFS(g.m);
    g.TreegraphBFS(g.m);
}
