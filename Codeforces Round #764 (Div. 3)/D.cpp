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
        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        int cnt[26];
        mset(0, cnt);

        rep(i, 0, n) {
            cnt[s[i]-'a']++;
        }

        sort(cnt, cnt+26);
        
        int ans[k];
        mset(0, ans);

        int cntcur = 25;
        int anscur = 0;
        while(cntcur >= 0) {
            while(cnt[cntcur] > 1) {
                cnt[cntcur] -= 2;
                ans[anscur] += 2;
                anscur++;
                anscur %= k;
            }
            cntcur--;
        }

        sort(ans, ans + k);
        int ones = 0;
        rep(i, 0, 26) {
            if(cnt[i] == 1) ones++;
        }

        // rep(i, 0, k) cout << ans[i] << ' ';
        // cout << '\n';

        rep(i, 0, min(ones, k)) ans[i]++;

        sort(ans, ans + k);
        rep(i, 0, k) {
            if(ans[i] % 2 == 0 && ans[k-1-i] - ans[i] == 2) ans[i] = ans[k-1-i] = ans[i] + 1;
        }

        int an = 1e9;
        rep(i, 0, k) an = min(an, ans[i]);
        cout << an << '\n';
    }
}