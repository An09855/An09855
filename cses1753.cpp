#include <bits/stdc++.h>
using namespace std;
using ll=int;

const ll N = 1e6 * 5  + 100;

ll n,a[N],i,x,y,d,q,m,j,val,sum,t;
string s, key;
int lenKey,lenS;
int pi[N + 1] = {};

void buildKMP(){
    pi[1] = 0;
    for (int i = 2; i <= lenKey; i++){
        int k = pi[i - 1];
        while (true){
            if (key[k + 1] == key[i]){
                pi[i] = k + 1;
                break;
            } else {
                if (k == 0) break;
                k = pi[k];
            }
        }
    }
}

vector<ll> match(string s){
    vector<ll> positions;
    ll k = 0;
    for (ll i = 1; i <= lenS; i++){
        while (k > 0 and key[k + 1] != s[i])
            k = pi[k];
        if (key[k+1] == s[i]) k++;
        if (k == lenKey){
            positions.push_back(i - lenKey + 1);
            k = pi[k];
        }
    }
    return positions;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("test.inp","r",stdin);
    //freopen("test.out","w",stdout);
    cin >> s >> key;
    lenS = s.length();
    s = ' ' + s;
    lenKey = key.length();
    key = ' ' + key;
    buildKMP();
    cout << match(s).size();
}
