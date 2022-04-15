#include<bits/stdc++.h>
using namespace std;

struct edge{
    int dau,cuoi,c;  
};

class graph{
    public:
        int n,a[100][100],ne,at[100][100],neT,check[100],dH;
        edge G[100],T[100];
        
        void read(){
            ne=0;
            cin>>n;
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++) {
                    cin>>a[i][j];
                    if(a[i][j] != 0 && i<j)  {
                        ne++;
                        G[ne].dau=i;
                        G[ne].cuoi=j;
                        G[ne].c=a[i][j];
                    }
                }
        }
        
        void init(){
            for(int i=1;i<=n;i++) check[i]=0;
        }
        
        void dfsT(int u){ // duyet tren cay voi ma tran ke at
            check[u]=1;
            for(int i=1;i<=n;i++){
                if(at[u][i]!=0 && check[i]==0) dfsT(i);
            }
        }
        
        void sortG(){
            for(int i=ne;i>=1;i--){
                for(int j=1;j<i;j++){
                    if(G[j].c>G[j+1].c) swap(G[j],G[j+1]);
                }
            }
        }
        
        void kruskal(){
            // khoi tao cay rong
            dH=0;
            neT=0;
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++) at[i][j]=0;    
                
            sortG(); // sap xep tang dan theo trong so cua danh sach canh cua do thi
            
            for(int i=1;i<=ne;i++){
                init();
                dfsT(G[i].dau);
                if(check[G[i].cuoi]==0) { // dau va cuoi ko thuoc cung cay con -> ko tao thanh chu trinh
                    neT++;
                    T[neT]=G[i];
                    dH+=G[i].c;
                    at[G[i].dau][G[i].cuoi]=at[G[i].cuoi][G[i].dau]=1;
                }
            }
            
            if(neT!=n-1) cout<<"Do thi khong lien thong";
            else {
                cout<<"dH = "<<dH<<endl;
                for(int i=1;i<=neT;i++) cout<<T[i].dau<<" "<<T[i].cuoi<<endl;
            }
        }
};

int main(){
    graph g;
    g.read();
    g.kruskal();
}