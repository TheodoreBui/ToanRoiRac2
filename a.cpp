#include<bits/stdc++.h>
using namespace std;

class graph{
    public:
        int n,m,s,check[1000]={0};
        vector< vector<int> > a;

        void read(){
            cin>>n>>m>>s;
          for(int i=0;i<=n;i++){
             vector<int> b;
            for(int j=0;j<=n;j++){
                b.push_back(0);
            }
            a.push_back(b);
          }
            for(int i=1;i<=m;i++){
                int x,y;
                cin>>x>>y;
                a[x][y]=1;
                a[y][x]=1;
            }
        }
        
        void init(){}
        
        void DFS(int k){
            cout<<k<<" ";
            check[k]=1;
            for(int i=1;i<=n;i++){
                if(a[k][i]==1 && check[i]==0) DFS(i);
            }
        }
};

int main(){
    int t;
    cin>>t;
    while(t--){
      graph g;
      g.read();
      g.DFS(g.s);   
      cout<<endl; 
    }
}