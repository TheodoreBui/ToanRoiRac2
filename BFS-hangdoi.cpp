#include<bits/stdc++.h>
using namespace std;

class graph{
    public:
        int n,a[100][100],check[100]={0};
        queue<int> qe;
        
        void read(){
            cin>>n;
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++) cin>>a[i][j];
            }
        }
        
        void bfs(int k){
            qe.push(k);
            check[k]=1;
            while(!qe.empty()){
                int s=qe.front();
                qe.pop();
                cout<<s<<" ";
                for(int i=1;i<=n;i++){
                    if(a[s][i]==1 && check[i]==0) {
                        qe.push(i);
                        check[i]=1;
                    }
                }
            }
        }
};

int main(){
    graph g;
    g.read();
    g.bfs(6);
}