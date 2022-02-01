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

    vector<vector<char>> a(n, vector<char>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    if (a[n - 1][n - 2] == a[n - 2][n - 1])
    {
        char ch = a[n - 1][n - 2];

        vector<pi> ans;

        if (a[0][1] == ch)
        {
            ans.push_back({1, 2});
        }

        if (a[1][0] == ch)
        {
            ans.push_back({2, 1});
        }

        cout << ans.size() << '\n';
        for (auto p : ans)
        {
            cout << p.first << ' ' << p.second << '\n';
        }
        return;
    }

    if (a[0][1] == a[1][0])
    {
        char ch = a[0][1];

        vector<pi> ans;

        if (a[n - 1][n - 2] == ch)
        {
            ans.push_back({n, n - 1});
        }

        if (a[n - 2][n - 1] == ch)
        {
            ans.push_back({n - 1, n});
        }

        cout << ans.size() << '\n';
        for (auto p : ans)
        {
            cout << p.first << ' ' << p.second << '\n';
        }
        return;
    }

    char ch = a[0][1];
    vector<pi> ans;
    ans.push_back({2, 1});

    if (a[n - 1][n - 2] == ch)
    {
        ans.push_back({n, n - 1});
    }

    if (a[n - 2][n - 1] == ch)
    {
        ans.push_back({n - 1, n});
    }

    cout << ans.size() << '\n';
    for (auto p : ans)
    {
        cout << p.first << " " << p.second << '\n';
    }
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