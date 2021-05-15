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

void solve(int cc)
{
    int n, m, k;
    cin >> n >> m >> k;

    if (k % 2 != 0)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cout << -1 << ' ';
            cout << '\n';
        }

        return;
    }

    vector<vector<int>> rightCost(n, vector<int>(m - 1));
    vector<vector<int>> downCost(n - 1, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < (m - 1); j++)
        {
            cin >> rightCost[i][j];
        }
    }

    for (int i = 0; i < (n - 1); i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> downCost[i][j];
        }
    }

    vector<vector<long long>> dp(n, vector<long long>(m, 0));
    vector<vector<long long>> dpNext(n, vector<long long>(m, 0));
    k = k / 2;

    for (int steps = 1; steps <= k; steps++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                long long ans = LLONG_MAX;
                if (i != 0)
                    ans = min(ans, dp[i - 1][j] + downCost[i - 1][j]);
                if (j != 0)
                    ans = min(ans, dp[i][j - 1] + rightCost[i][j - 1]);
                if (i != (n - 1))
                    ans = min(ans, dp[i + 1][j] + downCost[i][j]);
                if (j != (m - 1))
                    ans = min(ans, dp[i][j + 1] + rightCost[i][j]);

                dpNext[i][j] = ans; // take k steps and retrace that path, so at the end of k*2 steps
                                    // we will be back where we started
            }
        }
        dp = dpNext;
        dpNext = vector<vector<long long>>(n, vector<long long>(m, 0));
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << dp[i][j] * 2 << ' ';
        }
        cout << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve(1);

    return 0;
}

long long min(long long a, long long b)
{
    if (a < b)
        return a;
    return b;
}