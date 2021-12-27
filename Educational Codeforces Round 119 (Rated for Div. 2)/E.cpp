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

int to[500005];

int main(){
    fastIO();

    rep(i, 0, 500005) to[i] = i;

    int n;
    cin >> n;

    vector<int> v;
    vector<pair<int, pair<int, int>>> c;

    rep(i, 0, n){
        int q;
        cin >> q;

        if(q == 1) {
            int a;
            cin >> a;

            v.push_back(a);
        } else {
            int a, b;
            cin >> a >> b;

            c.push_back({v.size(), {a, b}}); // 이 지점 이전의 값은 a를 b로 변환
        }
    }

    int cur = c.size() - 1;
    rep2(i, v.size() - 1, 0) {
        while(cur >= 0 && i <= c[cur].first - 1) {
            to[c[cur].second.first] = to[c[cur].second.second];
            cur--;
        }

        v[i] = to[v[i]];
    }

    rep(i, 0, v.size()) cout << v[i] << ' ';
}