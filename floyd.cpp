// code by TheodoreBui
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int vc=9000;

class graph{
    public:
        int n,a[100][100],next[100][100]={0},d[100][100]={0};

        void nhap(){

            cin>>n;
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    cin>>a[i][j];
                    if(i != j && a[i][j]==0 ) a[i][j]=vc;
                }
            }

        }

        void floyd(){

            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    d[i][j]=a[i][j];
                    if(a[i][j] != vc) next[i][j]=j;
                    else next[i][j]=-1;
                }
            }

            for(int k=1;k<=n;k++){
                for(int i=1;i<=n;i++){
                    for(int j=1;j<=n;j++){
                        if(d[i][j]>d[i][k]+d[k][j]){
                            d[i][j]=d[i][k]+d[k][j];
                            next[i][j]=next[i][k];
                        }
                    }
                }
            }
        }

        void in(int u,int v){
            if(next[u][v]==-1) cout<<"Khong co duong di tu "<<u<<" den "<<v<<endl;
            else {
                cout<<"K/c "<<u<<" -> "<<v<<" = "<<d[u][v]<<";    ";
                while(u!=v){
                    cout<<u<<" --> ";
                    u=next[u][v];
                }
                cout<<v<<endl;
            }
        }

        void kq(){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    in(i,j);
                }
            cout<<endl;
            }
        }
};

int main(){
    graph g;
    g.nhap();
    g.floyd();
    g.kq();
}
/* Bùi Tuấn Nhật

▄▄▄█████▓ ██░ ██ ▓█████  ▒█████  ▓█████▄  ▒█████   ██▀███  ▓█████     ▄▄▄▄    █    ██  ██▓
▓  ██▒ ▓▒▓██░ ██▒▓█   ▀ ▒██▒  ██▒▒██▀ ██▌▒██▒  ██▒▓██ ▒ ██▒▓█   ▀    ▓█████▄  ██  ▓██▒▓██▒
▒ ▓██░ ▒░▒██▀▀██░▒███   ▒██░  ██▒░██   █▌▒██░  ██▒▓██ ░▄█ ▒▒███      ▒██▒ ▄██▓██  ▒██░▒██▒
░ ▓██▓ ░ ░▓█ ░██ ▒▓█  ▄ ▒██   ██░░▓█▄   ▌▒██   ██░▒██▀▀█▄  ▒▓█  ▄    ▒██░█▀  ▓▓█  ░██░░██░
  ▒██▒ ░ ░▓█▒░██▓░▒████▒░ ████▓▒░░▒████▓ ░ ████▓▒░░██▓ ▒██▒░▒████▒   ░▓█  ▀█▓▒▒█████▓ ░██░
  ▒ ░░    ▒ ░░▒░▒░░ ▒░ ░░ ▒░▒░▒░  ▒▒▓  ▒ ░ ▒░▒░▒░ ░ ▒▓ ░▒▓░░░ ▒░ ░   ░▒▓███▀▒░▒▓▒ ▒ ▒ ░▓  
    ░     ▒ ░▒░ ░ ░ ░  ░  ░ ▒ ▒░  ░ ▒  ▒   ░ ▒ ▒░   ░▒ ░ ▒░ ░ ░  ░   ▒░▒   ░ ░░▒░ ░ ░  ▒ ░
  ░       ░  ░░ ░   ░   ░ ░ ░ ▒   ░ ░  ░ ░ ░ ░ ▒    ░░   ░    ░       ░    ░  ░░░ ░ ░  ▒ ░
          ░  ░  ░   ░  ░    ░ ░     ░        ░ ░     ░        ░  ░    ░         ░      ░  
                                  ░                                        ░              
*/