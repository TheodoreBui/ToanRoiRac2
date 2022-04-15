#include<bits/stdc++.h>
using namespace std;

struct edge{
    int dau,cuoi,c;
};

class graph{
    public:
        int n,a[100][100],check[100],s,dH;
        vector<edge> G,T; // G ds cạnh, T kq cây khung
        vector<int> Vh,V; // Vh chứa tập đỉnh đang của khung, V ngược lại Vh
        
        void nhap(){
            cin>>n>>s;
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    cin>>a[i][j];
                    if(a[i][j]!=0 && i<j){
                        edge tmp;
                        tmp.dau=i;
                        tmp.cuoi=j;
                        tmp.c=a[i][j];
                        G.push_back(tmp);
                    }   
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
                    if(a[Vh[i]][V[j]]<tmp.c && a[Vh[i]][V[j]]!=0){
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
            
            if(tmp.cuoi<tmp.dau) swap(tmp.dau,tmp.cuoi);
            return tmp;
        }
        
        void prim(int s){
            dH=0;
            Vh.push_back(s);
            for(int i=1;i<=n;i++){
                if(i!=s) V.push_back(i);
            }
            check[s]=1;
            while(!V.empty()){
                edge tmp=timmin();
                if(tmp.c==0) {
                    cout<<"Do thi khong lien thong\n";
                    return;
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
    g.nhap();
    g.prim(g.s);
}