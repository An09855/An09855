#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pp pair<long long, long long>
const ll MOD = 1e9 + 7;
const ll N = 1e6+9;
const ll base = 311;

char a[1009][1009];
ll n,m,i,j,ex,ey,sx,sy;
bool vis[1009][1009];
ll moveX[]={0,0,1,-1};
ll moveY[]={1,-1,0,0};
char moveChar[]={'R','L','D','U'};
bool isValid(ll x,ll y){
    if(x<1 || x>n || y<1 || y>m) return false;
    if(a[x][y]!='.'&&a[x][y]!='B') return false;
    return true;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n>>m;
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            cin>>a[i][j];
            if(a[i][j]=='#') vis[i][j]=true;
            else if(a[i][j]=='A'){
                sx=i,sy=j;
            }
            else if(a[i][j]=='B'){
                ex=i,ey=j;
            }
        }
    }
    queue<pp> bfs;
    bfs.push({sx,sy});
    bool check=false;
    while(!check&&!bfs.empty()){
        pp top=bfs.front();
        bfs.pop();
        for(i=0;i<4;i++){
            ll nX=top.first+moveX[i];
            ll nY=top.second+moveY[i];
            if(isValid(nX,nY)){
                bfs.push({nX,nY});
                a[nX][nY]=moveChar[i];
                if(nX==ex&&nY==ey) check=true;
            }
        }
    }
    if(check==false){
        cout<<"NO";
        return 0;
    }
    cout<<"YES"<<"\n";
    string ans="";
    ll c=ex,currj=ey;
    while(!(c==sx&&currj==sy)){
        ans+=a[c][currj];
        switch(a[c][currj]){
			case 'D':
				c--;
				break;
			case 'U':
				c++;
				break;
			case 'R':
				currj--;
				break;
			case 'L':
				currj++;
				break;
		}
    }
    reverse(ans.begin(),ans.end());
    cout<<ans.size()<<"\n"<<ans;
}
