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

        int a[n];
        int mx = 0;
        vector<int> pos, neg;
        rep(i, 0, n){
            cin >> a[i];
            mx = max(mx, abs(a[i]));
            if(a[i] >= 0) pos.push_back(a[i]);
            else neg.push_back(a[i]);
        }

        sort(pos.begin(), pos.end());
        sort(neg.begin(), neg.end());
        
        int posIdx = pos.size() - 1;
        int negIdx = 0;

        int posMaxCount = 0;
        int negMaxCount = 0;
        while(posIdx - posMaxCount >= 0 && pos[posIdx - posMaxCount] == mx) posMaxCount++;
        while(negIdx + negMaxCount < neg.size() && neg[negIdx + negMaxCount] == -mx) negMaxCount++;

        // cout2(posMaxCount, negMaxCount);

        if(posMaxCount > negMaxCount) posIdx -= k;
        else negIdx += k;

        lli ans = mx;
        while(posIdx >= 0) {
            ans += pos[posIdx] * 2;
            posIdx -= k;
        }

        while(negIdx < neg.size()) {
            ans -= neg[negIdx] * 2;
            negIdx += k;
        }

        cout << ans << '\n';
    }
}