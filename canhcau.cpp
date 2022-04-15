#include<bits/stdc++.h>
using namespace std;

class graph{
    public:
        int n,check[100],a[50][50];
        
        void read(){
            cin>>n;
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++) cin>>a[i][j];
            }
        }
        
        void reinit(){
            for(int i=1;i<=n;i++) check[i]=0;
        }
        
        void DFS(int k){
            check[k]=1;
            for(int i=1;i<=n;i++){
                if(a[k][i]==1 && check[i]==0) {
                    DFS(i);
                }
            }
        }
        
        void bridge(){
            reinit();
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(a[i][j] && j>i){
                        a[i][j]=a[j][i]=0;
                        DFS(1);
                        for(int k=1;k<=n;k++){
                            if(check[k]==0){
                                cout<<i<<" "<<j<<endl;
                                break;
                            }
                        }
                        a[i][j]=a[j][i]=1;
                        reinit();
                    }
                }
            }
        }
};

int main(){
    graph g;
    g.read();
    g.bridge();
}