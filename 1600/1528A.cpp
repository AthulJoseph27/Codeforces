#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;

#define all(v) v.begin(), v.end()

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

pair<long long, long long> dfs(vector<pair<int, int>> &lr, vector<vector<int>> &con, int cur, int parent)
{
    long long a = 0, b = 0;

    for (int e : con[cur])
    {
        if (e == parent)
            continue;
        pair<long long, long long> p = dfs(lr, con, e, cur);
        a += max(llabs(lr[cur].first - lr[e].first) + p.first, llabs(lr[cur].first - lr[e].second) + p.second);
        b += max(llabs(lr[cur].second - lr[e].first) + p.first, llabs(lr[cur].second - lr[e].second) + p.second);
    }

    return {a, b};
}

void solve(int cc)
{
    int n;
    cin >> n;

    vector<pair<int, int>> lr(n);

    for (int i = 0; i < n; i++)
        cin >> lr[i].first >> lr[i].second;

    vector<vector<int>> con(n);

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        con[v].push_back(u);
        con[u].push_back(v);
    }

    // debug(lr);
    // debug(con);
    // exit(0);

    pair<long long, long long> ans = dfs(lr, con, 0, -1);
    cout << max(ans.first, ans.second) << '\n';
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

long long max(pair<long long, long long> &p)
{
    if (p.first > p.second)
        return p.first;
    return p.second;
}