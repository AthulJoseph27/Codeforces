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
    ll n, W;
    cin >> n >> W;

    vl w(n);

    for (ll &i : w)
        cin >> i;

    ll C = (W + 1ll) / 2;

    ll tw = 0;

    for (ll i : w)
        tw += i;

    if (tw < C)
    {
        cout << -1 << '\n';
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (w[i] >= C && w[i] <= W)
        {
            cout << 1 << '\n'
                 << (i + 1) << '\n';
            return;
        }
    }

    ll sm = 0;
    vi ans;
    for (int i = 0; i < n; i++)
    {
        if (w[i] < W)
        {
            sm += w[i];
            ans.push_back(i);
        }

        if (sm >= C && sm <= W)
        {
            cout << ans.size() << '\n';
            for (int j : ans)
                cout << (j + 1) << ' ';
            cout << '\n';
            return;
        }
    }

    cout << -1 << '\n';

    /*
        wi < C or wi > W
        wi > W are useless

        ignore all wi>W

        w1+w2+....wk >= C




    */
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