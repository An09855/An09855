#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const ll MOD = 1e9 + 7;
const ll N = 1e6+9;
const ll base = 311;

ll n,m,u,v,i,vis[N],parent[N];
vector< vector<ll> > trie(N);
queue<ll> dd;
int main() {
    faster
    cin>>n>>m;
    ll p=n;
    for(i=1;i<=m;i++){
        cin>>u>>v;
        trie[u].push_back(v);
        trie[v].push_back(u);
    }
    bool check=false;
    dd.push(1);
    while(!check&&!dd.empty()){
        ll top = dd.front();
        dd.pop();
        for(i=0;i<trie[top].size();i++){
            if(vis[trie[top][i]]==false){
                parent[trie[top][i]]=top;
                if(trie[top][i]==n){
                    check=true;
                } 
                dd.push(trie[top][i]);
                vis[trie[top][i]]=true;
            }
        }
    }
    if(!check){
        cout<<"IMPOSSIBLE";
        return 0;
    }
    ll k=0,ans[N];
    while(parent[n]!=1){
        ans[++k]=parent[n];
        n=parent[n];
    }
    cout<<k+2<<"\n";
    cout<<1<<" ";
    for(i=k;i>=1;i--) cout<<ans[i]<<" "; 
    cout<<p;
}
