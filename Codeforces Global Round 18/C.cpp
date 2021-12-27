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

int fun[4][4] = {
    {2, 3, 0, 1},
    {2, 3, 0, 1},
    {2, 3, 2, 1},
    {2, 3, 0, 3},
};

int ans = 1e9;

void solve(int a, int b, int c, int d, int k, int u) {
    if(k == 10) return;
    if(b == 0 && c == 0) {
        ans = min(ans, k);
        return;
    }else{
        int x[] = {a, b, c, d};
        rep(i, 0, 4) {
            if(i == 1 || i == u) continue;
            int y[] = {0, 0, 0 ,0};
            rep(j, 0, 4) {
                y[fun[i][j]] += x[j];
                solve(y[0], y[1], y[2], y[3], k+1, i);
            }
        }
    }
}

int q[8];

void f(int a, int b, int c, int d, int k) {
    if(k == 8) {
        return;
    }
    if(b == 0 && c == 0) {
        cout4(a, b, c, d);
        rep(i, 0, k) cout << q[k] << ' ';
        cout << '\n';
        ans = min(ans, k);
        return;
    }
    if(c != 0) {
        q[k] = 1;
        f(0, d, a + c, b, k + 1);
    }
    if(d != 0) {
        q[k] = 2;
        f(c, 0, a, b + d, k + 1);
    }
}

int main(){
    fastIO();

    TC {
        ans = 1e9;

        int n;
        cin >> n;

        string a, b;
        cin >> a >> b;

        // 00 01 10 11
        int cnt[4] = {0, };
        rep(i, 0, n) {
            int aa = (a[i]-'0')*2;
            int bb = (b[i]-'0');
            cnt[aa+bb]++;
        }

        int ans = 1e9;
        if(cnt[3] - cnt[0] == 1) {
            ans = min(ans, cnt[3] + cnt[0]);
        }

        if(cnt[1] == cnt[2]) {
            ans = min(ans, cnt[1] + cnt[2]);
        }
        
        if(ans == 1e9) cout << "-1\n";
        else cout << ans << '\n';
    }
}