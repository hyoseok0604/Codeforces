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
        lli n, k, x;
        cin >> n >> k >> x;

        string s;
        cin >> s;

        string s2 = "";
        
        vector<lli> v;

        rep(i, 0, s.length()) {
            if(s[i] == '*') {
                int c = 0;
                while(i + c < n && s[i + c] == '*') c++;

                v.push_back(c * k + 1);

                i += c - 1;
                s2.push_back('*');
            } else {
                s2.push_back('a');
            }
        }

        vector<lli> a;
        int cur = v.size() - 1;
        x--;
        while(x > 0) {
            a.push_back(x % v[cur]);
            x /= v[cur];
            cur--;
        }

        while(v.size() != a.size()) a.push_back(0);

        int cur2 = a.size() - 1;
        rep(i, 0, s2.length()) {
            if(s2[i] == 'a') cout << 'a';
            else {
                rep(j, 0, a[cur2]) {
                    cout << 'b';
                }
                cur2--;
            }
        }
        cout << '\n';
    }
}