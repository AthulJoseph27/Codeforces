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

    vl a(n);

    for (ll &i : a)
        cin >> i;

    if (n == 2)
    {
        cout << 0 << '\n';
        return;
    }

    // vl prefs = {0}, suffx = {0};

    // for (int i = 1; i < n; i++)
    // {
    //     prefs.push_back(prefs.back() + llabs(a[i] - a[i - 1]));
    // }

    // for (int i = n - 2; i >= 0; i--)
    // {
    //     suffx.push_back(suffx.back() + llabs(a[i] - a[i + 1]));
    // }

    ll total = 0;

    for (int i = n - 2; i >= 0; i--)
    {
        total += llabs(a[i] - a[i + 1]);
    }

    ll ans = LLONG_MAX;

    for (int i = 0; i < n; i++)
    {
        // skip this index
        //
        if (i == 0)
        {
            ans = min(ans, total - llabs(a[0] - a[1]));
        }
        else if (i == (n - 1))
        {
            ans = min(ans, total - llabs(a[n - 1] - a[n - 2]));
        }
        else
        {
            ans = min(ans, total - (llabs(a[i] - a[i - 1]) + llabs(a[i] - a[i + 1])) + llabs(a[i - 1] - a[i + 1]));
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

/*
    In a fully connected K-ary Tree
    parent of nth node is
    p = (n+k-2)/k
*/