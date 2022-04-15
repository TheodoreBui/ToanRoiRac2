#include<bits/stdc++.h>
using namespace std;

struct edge{
    int dau,cuoi,c;
};

class graph{
    public:
        int n,a[100][100],check[100],s,dH;
        vector<edge> G,T;
        vector<int> Vh,V;
        
        void read(){
            cin>>n>>s;
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    cin>>a[i][j];
                }
            }
        }
        
        void init(){
            for(int i=1;i<=n;i++) check[i]=0;
        }
        
        edge timmin(){
            int k=-1;
            edge tmp{0,0,1000};
            for(int i=0;i<Vh.size();i++){
                for(int j=0;j<V.size();j++){
                    if(a[Vh[i]][V[j]] < tmp.c && a[Vh[i]][V[j]]!=0){
                        tmp.dau=Vh[i];
                        tmp.cuoi=V[j];
                        k=j;
                        tmp.c=a[Vh[i]][V[j]];
                    }
                }
            }
            
            if(tmp.c==1000) return {0,0,0};
            
            Vh.push_back(tmp.cuoi);
            swap(V[k],V[V.size()-1]);
            V.pop_back();
            
            sort(Vh.begin(),Vh.end());
            sort(V.begin(),V.end());
            
            if(tmp.dau>tmp.cuoi) swap(tmp.dau,tmp.cuoi);
            return tmp;
        }
        
        void prim(int s){
            dH=0;
            Vh.push_back(s);
            for(int i=1;i<=n;i++){
                if(i!=s) V.push_back(i);
            }
            
            while(!V.empty()){
                edge tmp=timmin();
                if(tmp.c==0){
                    cout<<"No spanning tree";
                    return ;
                }
                T.push_back(tmp);
                dH+=tmp.c;
            }
            cout<<"dH = "<<dH<<endl;
            for(int i=0;i<T.size();i++){
                cout<<T[i].dau<<" "<<T[i].cuoi<<endl;
            }
        }
};

int main(){
    graph g;
    g.read();
    g.prim(g.s);
    return 0;
}