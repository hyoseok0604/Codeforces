#include<bits/stdc++.h>
 
using namespace std;
 
#define lli long long
#define TC int TC;cin>>TC;while(TC--)
#define fastIO() ios_base::sync_with_stdio(0),cin.tie(0)
#define uMin(a, b) a = min(a, b)
#define uMax(a, b) a = max(a, b)
#define mset(a, arr) memset(arr, a, sizeof(arr))
#define piii pair<lli, pair<lli, lli>>
#define piiii pair<pair<lli, lli>, pair<lli, lli>>
#define ff first
#define ss second
 
#define rep(i, a, b) for(int i = (a) ; i < (b) ; i++)
#define rep1(i, a, b) for(int i = (a) ; i <= (b) ; i++)
#define rep2(i, a, b) for(int i = (a) ; i >= (b) ; i--)
 
#define cout1(a) cout << a << '\n'
#define cout2(a, b) cout << a << ' ' << b << '\n'
#define cout3(a, b, c) cout << a << ' ' << b << ' ' << c << '\n'
#define cout4(a, b, c, d) cout << a << ' ' << b << ' ' << c << ' ' << d << '\n'

#define unq(v) v.erase(unique(v.begin(), v.end()), v.end())
#define srt(v) sort(v.begin(), v.end())

lli powerMod(int x, lli y, lli m)
{
    if (y == 0)
        return 1;
    lli p = powerMod(x, y / 2, m) % m;
    p = (p * p) % m;
 
    return (y % 2 == 0) ? p : (x * p) % m;
}

int main(){
    fastIO();
    
    TC {
        int n;
        cin >> n;

        int in[n+1];
        mset(0, in);
        vector<pair<int, int>> g[n+1];
        rep(i, 0, n - 1) {
            int u, v;
            cin >> u >> v;

            in[u]++;
            in[v]++;

            g[u].push_back({v, i});
            g[v].push_back({u, i});
        }

        bool can = true;
        int root = 0;
        rep1(i, 1, n) {
            if(in[i] > 2) can = false;
            if(in[i] == 1) root = i;
        }

        if(!can) {
            cout << "-1\n";
            continue;
        }

        int ans[n+1];
        int now = root;
        bool vis[n+1];
        mset(0, vis);
        int c = 0;
        while(c < n - 1) {
            vis[now] = true;
            
            if(!vis[g[now][0].first]){
                ans[g[now][0].second] = 2 + c % 2;
                now = g[now][0].first;
            } else {
                ans[g[now][1].second] = 2 + c % 2;
                now = g[now][1].first;
            }
            c++;
        }

        rep(i, 0, n - 1) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }
}