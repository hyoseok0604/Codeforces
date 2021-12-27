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

    // TC {
        lli x, y;
        cin >> x >> y;

        bitset<64> xb(x);
        bitset<64> yb(y);

        string xbs = xb.to_string();
        string ybs = yb.to_string();

        // cout << xbs << ' ' << ybs <<  '\n';

        int xs = -1, ys = -1;
        rep(i, 0, 64) {
            if(xs == -1 && xbs[i] == '1') xs = i;
            if(ys == -1 && ybs[i] == '1') ys = i;
        }

        xbs = xbs.substr(xs);
        ybs = ybs.substr(ys);
        
        if(xbs == ybs) {
            return cout << "YES\n", 0;
        }

        bool ans = false;

        // add 1 tail 0 remain
        xbs.append("1");
        // cout << xbs;
        int sz = ybs.size() - xbs.size() + 1;
        rep(i, 0, sz) {
            if(ybs.substr(i, xbs.size()) == xbs) {
                bool tmp = true;
                rep(j, 0, ybs.size()) {
                    if(j >= i && j < i + xbs.size()) continue;
                    if(ybs[j] == '0') tmp = false;
                }
                ans |= tmp;
            }
        }

        reverse(xbs.begin(), xbs.end());

        rep(i, 0, sz) {
            if(ybs.substr(i, xbs.size()) == xbs) {
                bool tmp = true;
                rep(j, 0, ybs.size()) {
                    if(j >= i && j < i + xbs.size()) continue;
                    if(ybs[j] == '0') tmp = false;
                }
                ans |= tmp;
            }
        }

        reverse(xbs.begin(), xbs.end());

        xbs.pop_back();

        // cout << xbs;

        while(xbs[xbs.size() - 1] == '0') xbs.pop_back();

        // add 0 tail 0 remove

    // }
    sz = ybs.size() - xbs.size() + 1;
    rep(i, 0, sz) {
            if(ybs.substr(i, xbs.size()) == xbs) {
                bool tmp = true;
                rep(j, 0, ybs.size()) {
                    if(j >= i && j < i + xbs.size()) continue;
                    if(ybs[j] == '0') tmp = false;
                }
                ans |= tmp;
            }
        }

        reverse(xbs.begin(), xbs.end());

        rep(i, 0, sz) {
            if(ybs.substr(i, xbs.size()) == xbs) {
                bool tmp = true;
                rep(j, 0, ybs.size()) {
                    if(j >= i && j < i + xbs.size()) continue;
                    if(ybs[j] == '0') tmp = false;
                }
                ans |= tmp;
            }
        }

    if(ans) cout << "YES";
    else cout << "NO";
}