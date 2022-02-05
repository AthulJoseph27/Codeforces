#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<int, int> pi;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

void __print(int x)
{
    cerr << x;
}
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template <typename T, typename V>
void __print(const pair<T, V> &x)
{
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template <typename T>
void __print(const T &x)
{
    int f = 0;
    cerr << '{';
    for (auto &i : x)
        cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v)
{
    __print(t);
    if (sizeof...(v))
        cerr << ", ";
    _print(v...);
}
#ifndef ONLINE_JUDGE
#define debug(x...)               \
    cerr << "[" << #x << "] = ["; \
    _print(x)
#else
#define debug(x...)
#endif

void solve(int cc)
{
    int n;
    cin >> n;

    vvl a(n);

    for (auto &v : a)
    {
        int k;
        cin >> k;
        v = vl(k);
        for (ll &i : v)
            cin >> i;
    }

    vector<pair<ll, ll>> mn(n);

    ll l = 0, r = LLONG_MAX;

    for (int i = 0; i < n; i++)
    {
        ll cur = a[i][0] + 1ll;
        ll initial = a[i][0] + 1ll;
        for (int j = 1; j < a[i].size(); j++)
        {
            cur = cur + 1ll;
            if (cur <= a[i][j])
            {
                cur = a[i][j] + 1ll;
                initial = (cur - j);
            }
        }
        mn[i] = {initial, a[i].size()};
        // r = min(initial, r);
    }

    sort(all(mn));

    ll ans = LLONG_MAX;

    // debug(l, r);
    // debug(mn);

    while (l <= r)
    {
        ll mid = l + (r - l) / 2ll;

        // check if this is possible
        bool possible = true;

        ll h = mid;
        for (int i = 0; i < n; i++)
        {
            if (h < mn[i].first)
            {
                possible = false;
                break;
            }
            h += mn[i].second;
        }

        // debug(l, r, mid, possible);

        if (possible)
        {
            ans = min(ans, mid);
            r = mid - 1ll;
        }
        else
        {
            l = mid + 1ll;
        }
    }

    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;

    cin >> T;

    for (int i = 0; i < T; i++)
    {
        solve(i + 1);
    }

    return 0;
}