#include<bits/stdc++.h>
using namespace std;

int vc=INT_MAX-1000,kt=1;

class graph{
    public:
        int n,s,a[100][100],truoc[100],d[100];
        vector<int> T;
        
        void read(){
            cin>>n>>s;
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++) {
                    cin>>a[i][j];
                    if(a[i][j]==0) a[i][j]=vc;
                }
            }
        }
        
        int timmin(){
            int ma=INT_MAX,vt;
            for(int i=0;i<T.size();i++){
                if(d[T[i]]<ma){
                    ma=d[T[i]];
                    vt=T[i];
                }
            }
            if(ma != vc )    return vt;
            return -1;
        }
        
        void Dijkstra(int s){
            for(int i=1;i<=n;i++){
                T.push_back(i);
                if(i==s) d[i]=0;
                else d[i]=a[s][i];
                truoc[i]=s;
            }
            
            while(!T.empty()){
                int u=timmin();
                if(u == -1) {
                    for(int i=1;i<=n;i++){
                        if(i != s)    cout<<"K/c "<<s<<" -> "<<i<<" = "<<"INF;"<<endl;
                        else cout<<"K/c "<<s<<" -> "<<i<<" = "<< 0 <<"      "<<s<<" <- "<<s<<endl;
                    }
                    kt=2;
                    return;
                }
                T.erase(find(T.begin(),T.end(),u));
                
                for(int i=0;i<T.size();i++){
                    if(d[T[i]]>d[u]+a[u][T[i]]){
                        d[T[i]]=d[u]+a[u][T[i]];
                        truoc[T[i]]=u;
                    }
                }
            }
        }
        
        void in(){
            for(int i=1;i<=n;i++){
                cout<<"K/c "<<s<<" -> "<<i<<" = "<<d[i]<<";      ";
                int u=truoc[i];
                cout<<i<<" <- ";
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
    g.read();
    g.Dijkstra(g.s);
    if(kt==1) g.in();
}