#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pp pair<long long, long long>
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const ll MOD = 1e9 + 7;
const ll N = 1e6+9;
const ll base = 311;
const ll moveX4[]={0,0,1,-1};
const ll moveY4[]={1,-1,0,0};
const char moveChar4[]={'R','L','D','U'};

ll n,m,u,v,ans,i,kq[N],k;
bool vis[N];
vector< vector<ll> >trie(N);
void dfs(ll i){
    for(int j=0;j<trie[i].size();j++){
        if(vis[trie[i][j]]==false){
            vis[trie[i][j]] = true;
            dfs(trie[i][j]);
        }
    }
}
int main() {
    faster
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>u>>v;
        trie[u].push_back(v);
        trie[v].push_back(u);
    }
    for(i=1;i<=n;i++){
        if(vis[i]==false){
            ans++;
            dfs(i);
            vis[i]=true;
            kq[++k]=i;
        }
    }
    cout<<ans-1<<"\n";
    for(i=1;i<k;i++){
        cout<<kq[i]<<" "<<kq[i+1]<<"\n";
    }
}
