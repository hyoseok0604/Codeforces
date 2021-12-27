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
    TC {
        int n, a, b;
        cin >> n >> a >> b;

        // n - 2
        int ans[n];
        rep(i, 0, n) ans[i] = i + 1;
        if(a + b > n - 2 || abs(a - b) > 1) cout << "-1\n";
        else {
            if(a > b) {
                rep(i, 0, max(a, b)){
                    swap(ans[n-1-i*2], ans[n-1-i*2-1]);
                }
            }else if(a < b) {
                rep(i, 0, max(a, b)){
                    swap(ans[i*2], ans[i*2+1]);
                }
            }else{
                rep(i, 0, a) {
                    swap(ans[i*2+1], ans[i*2+2]);
                }
            }
            rep(i, 0, n) cout << ans[i] << ' ';
            cout << '\n';
        }
    }
}