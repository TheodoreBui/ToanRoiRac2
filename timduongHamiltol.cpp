#include<bits/stdc++.h>
using namespace std;

vector< vector<int> > kq;

class graph{
    public:
        int n,a[100][100],check[100],x[100],v;
        
        void read(){
            cin>>n>>v;
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++) cin>>a[i][j];
            }
        }
        
        void ghinhan(){
            vector<int> vt;
            for(int i=1;i<=n;i++) vt.push_back(x[i]);
            vt.push_back(x[1]);
            kq.push_back(vt);
        }
        
        void hmt(int k){
            for(int i=1;i<=n;i++){
                if(a[x[k-1]][i]==1){
                    if(k==n+1 && i==v) ghinhan();
                    else if(check[i]==0){
                        x[k]=i;
                        check[i]=1;
                        hmt(k+1);
                        check[i]=0;
                    }
                }
            }    
        }
        
        void hamiltoncycle(int m){
            for(int i=1;i<=n;i++) check[i]=0;
            x[1]=m;
            check[1]=1;
            hmt(2);
        }
};

void in(vector<int> vt){
    for(int i=0;i<vt.size();i++) cout<<vt[i]<<" ";
    cout<<endl;
}

int main(){
    graph g;
    g.read();
    g.hamiltoncycle(g.v);
    for(int i=0;i<kq.size();i++) in(kq[i]);
}