#include<bits/stdc++.h>
using namespace std;

int vc= 10000;

class graph{
    public:
        int n,s,a[100][100],truoc[100],d[100];
        
        void nhap(){
            cin>>n>>s;
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    cin>>a[i][j];
                    if(a[i][j] == 0 && i!=j ) a[i][j]=vc;
                }
            }
        }
        
        void bellman_ford(int s){
            for(int i=1;i<=n;i++){
                d[i]=a[s][i];
                truoc[i]=s;
            }
            
            for(int i=1;i<=n-2;i++){
                for(int v=1;v<=n;v++){
                    if(v!=s){
                        for(int u=1;u<=n;u++){
                            if(d[v] > d[u]+a[u][v]) {
                                d[v] = d[u]+a[u][v];
                                truoc[v]=u;
                            }
                        }
                    }
                }
            }

        }
        
        void in(int s){
            for(int i=1;i<=n;i++){
                cout<<"K/c "<<s<<" -> "<<i<<" = "<<d[i]<<";      ";
                cout<<i<<" <- ";
                int u=truoc[i];
                while(u!=s){
                    cout<<u<<" <- ";
                    u=truoc[u];
                }
                cout<<s<<endl;
            }
        }
};

int main(){
    graph g;
    g.nhap();
    g.bellman_ford(g.s);
    g.in(g.s);
}