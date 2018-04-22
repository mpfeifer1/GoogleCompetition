// Michael Pfeifer
// Version 04, 2018/02/17

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;

const ld  pi   = 4.0*atanl(1.0);
const int iinf = 1e9 + 10;
const ll  inf  = 1e18 + 10;
const int mod  = 1000000007;
const ld  prec = .000001;

#define enld endl
#define endl '\n'
#define pb push_back
#define debug(x) cout<<#x<<" -> "<<x<<'\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define uni(x) (x).erase(unique(all(x)), (x).end())
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define rep1(i, n) for (ll i = 1; i <= (ll)(n); ++i)
#define umap unordered_map
#define uset unordered_set

template<class TIn>
using indexed_set = tree<
        TIn, null_type, less<TIn>,
        rb_tree_tag, tree_order_statistics_node_update>;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

void file() {
    auto a = freopen("a.in",  "r", stdin);
    auto b = freopen("a.out", "w", stdout);
    if(!a || !b) cout << "uh oh" << endl;
}





map<ull,ull> m;

ull val(ull n) {
    ull v = 1;
    while(v < n) {
        v *= 10;
    }

    ull count = 0;
    ull timesadded = 0;
    bool done = false;
    while(n > 0 && !done) {
        for(ull i = 9; i >= 1; i--) {
            if(n >= (v*i)) {
                count += m[v*i];
                n -= v*i;
                timesadded++;

                if(i == 9) {
                    done = true;
                }
                break;
            }
        }
        v /= 10;
    }

    return count;
}

void solve() {
    ull a, b;
    cin >> a >> b;

    cout << val(b) - val(a-1) << endl;
}

void gen() {
    for(int i = 1; i <= 8; i++) {
        m[i] = i;
    }
    m[9] = 8;

    ull last = 9;
    for(ull shift = 10; shift <= 1000000000000000000; shift *= 10) {
        for(ull mul = 1; mul <= 9; mul++) {
            m[mul*shift] = 1 + mul*m[last];
            if(mul == 9) {
                m[mul*shift] -= 1;
            }
        }
        last *= 10;
    }
}

int main() {
    //file();
    //fast();

    gen();

    int cases;
    cin >> cases;
    for(int i = 1; i <= cases; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}
