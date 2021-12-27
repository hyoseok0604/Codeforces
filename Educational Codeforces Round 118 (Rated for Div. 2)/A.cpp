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
        string x1, x2;
        int p1, p2;
        cin >> x1 >> p1 >> x2 >> p2;

        if(x1.length() + p1 > x2.length() + p2) cout << ">\n";
        else if(x1.length() + p1 < x2.length() + p2) cout << "<\n";
        else {
            int n = max(x1.length(), x2.length());
            char ans = '=';
            for(int i = 0 ; i < n ; i++){
                int k1 = (i < x1.length()) ? x1[i] - '0' : 0;
                int k2 = (i < x2.length()) ? x2[i] - '0' : 0;

                if(k1 > k2) ans = '>';
                else if(k1 < k2) ans = '<';

                if(ans != '=') break;
            }

            cout << ans << '\n';
        }
    }
}