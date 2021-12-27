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
        
        lli a[n];
        rep(i, 0, n) cin >> a[i];

        lli ans = 0;

        for(int i = 0 ; i < n ; i += 2) {
            lli k = __gcd(a[0], a[i]);
            bool can = true;
            for(int j = 0 ; j < n ; j++) {
                if(j % 2 == 0 && a[j] % k != 0) can = false;
                if(j % 2 == 1 && a[j] % k == 0) can = false;
            }

            if(can) {
                ans = k;
                break;
            }
        }

        for(int i = 1 ; i < n ; i += 2) {
            lli k = __gcd(a[1], a[i]);
            bool can = true;
            for(int j = 0 ; j < n ; j++) {
                if(j % 2 == 1 && a[j] % k != 0) can = false;
                if(j % 2 == 0 && a[j] % k == 0) can = false;
            }

            if(can) {
                ans = k;
                break;
            }
        }

        cout << ans << '\n';
    }
}