#include<bits/stdc++.h>
using namespace std;

class graph{
    public:
        int n,a[100][100],check[100]={0};
        
        void read(){
            cin>>n;
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++) cin>>a[i][j];
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
    cout<<"Enter the number of vertices n, and adjaciency matrix: ";
    graph g;
    g.read();
    g.DFS(3);
    
}