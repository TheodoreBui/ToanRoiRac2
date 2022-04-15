#include<bits/stdc++.h>
using namespace std;

class graph{
    public:
        int n,a[100][100],check[100],m;
        vector< vector<int> > kq;
        
        void read(){
            cin>>n>>m;
            for(int i=1;i<=n;i++) {
                for(int j=1;j<=n;j++) cin>>a[i][j];
            }
        }
        
        void ghinhan(int x,int y){
            vector<int> vt;
            vt.push_back(x);
            vt.push_back(y);
            sort(vt.begin(),vt.end());
            kq.push_back(vt);
        }
        
        void in(vector<int> vt){
            for(auto x:vt) cout<<x<<" ";
            cout<<endl;
        }
        
        void dfs(int k){
            check[k]=1;
            for(int i=1;i<=n;i++){
                if(a[k][i]==1 && check[i]==0){
                    ghinhan(k,i);
                    dfs(i);
                }
            }
        }
        
        void TreegraphDFS(int m){
            kq.clear();
            for(int i=1;i<=n;i++) check[i]=0;
            dfs(m);
            if(kq.size()<n-1) cout<<"Khong co khung \n";
            else {
                cout<<"DFS tree\n";
                for(auto x:kq) in(x);
            }
        }
};

int main(){
    graph g;
    g.read();
    g.TreegraphDFS(g.m);
}