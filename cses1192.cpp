#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const ll MOD = 1e9 + 7;
const ll N = 1e6+9;
const ll base = 311;

ll n,m,i,j,x,dem;
char a[1009][1009];
ll moveX[4]={0,0,1,-1};
ll moveY[4]={1,-1,0,0};
void dfs(ll n,ll m,ll i,ll j){
    a[i][j]='#';
    for(int x=0;x<4;x++){
        ll ni=i+moveX[x];
        ll nj=j+moveY[x];
        if(ni>=0&&nj>=0&&ni<n&&nj<m&&a[ni][nj]=='.') dfs(n,m,ni,nj);
    }
}
int main() {
    faster
    cin>>n>>m;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(a[i][j]=='.'){
                dem++;
                dfs(n,m,i,j);
            }
        }
    }
    cout<<dem;
}
