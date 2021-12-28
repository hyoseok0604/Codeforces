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
        lli n, k;
        cin >> n >> k;

        lli a[n];
        rep(i, 0, n) cin >> a[i];

        if(n == 1) {
            cout << max(0LL, a[0] - k) << '\n';
            continue;
        }

        sort(a, a + n);

        lli s = 0;
        rep(i, 0, n) {
            s += a[i];
        }

        int cur = n - 1;
        lli c = 0;
        lli ans = 0;
        while(cur > 0 && s > k) {
            if(cur > 0 && a[cur] - a[0] >= c + 1) {
                s -= a[cur] - a[0];
                cur--;
                c++;
                ans++;
            }else{
                if((s - k + c) / (c + 1) <= c + 1 - a[cur] + a[0]){
                    ans += (s - k + c) / (c + 1);
                    s -= (s - k + c) / (c + 1) * (c + 1);
                } else {
                    ans += c + 1 - a[cur] + a[0];
                    s -= (c + 1 - a[cur] + a[0]) * (c + 1);
                    a[0] -= c + 1 - a[cur] + a[0];
                }
            }
        }

        if(s > k) {
            ans += (s - k + c) / (c + 1);
        }

        cout << ans << '\n';
    }
}