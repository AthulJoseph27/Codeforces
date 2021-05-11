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

long long dfs(int i, int j, vector<vector<int>> &rightWeight, vector<vector<int>> &downWeight, int k, vector<vector<long long>> dp)
{
    if (k == 0)
        return 0;

    long long cost = 1e18;
    if (i != 0)
    {
        // going from (i,j) to (i-1,j)
        // if there is above node can be reached with shorted distance neglect that
        if (dp[i - 1][j] > dp[i][j] + downWeight[i - 1][j])
        {
            dp[i - 1][j] = dp[i][j] + downWeight[i - 1][j];
            cost = min(cost, dp[i - 1][j] + dfs(i - 1, j, rightWeight, downWeight, k - 1, dp));
        }
    }
    if (j != 0)
    {
        if (dp[i][j - 1] > dp[i][j] + rightWeight[i][j - 1])
        {
            dp[i][j - 1] = dp[i][j] + rightWeight[i][j - 1];
            cost = min(cost, dp[i][j - 1] + dfs(i, j - 1, rightWeight, downWeight, k - 1, dp));
        }
    }
    if (i != downWeight.size())
    {
        if (dp[i + 1][j] > dp[i][j] + downWeight[i][j])
        {
            dp[i + 1][j] = dp[i][j] + downWeight[i][j];
            cost = min(cost, dp[i + 1][j] + dfs(i + 1, j, rightWeight, downWeight, k - 1, dp));
        }
    }
    if (j != rightWeight.size())
    {
        if (dp[i][j + 1] > dp[i][j] + rightWeight[i][j])
        {
            dp[i][j + 1] = dp[i][j] + rightWeight[i][j];
            cost = min(cost, dp[i][j + 1] + dfs(i, j + 1, rightWeight, downWeight, k - 1, dp));
        }
    }

    return cost;
}

void solve(int cc)
{
    int n, m, k;

    cin >> n >> m >> k;

    vector<vector<int>> rightWeight(n, vector<int>(m - 1));
    vector<vector<int>> downWeight(n - 1, vector<int>(m));

    // from a point (i,j) one can move up, down, left or right

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m - 1; j++)
        {
            int d;
            cin >> d;
            rightWeight[i][j] = d;
        }
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int d;
            cin >> d;
            downWeight[i][j] = d;
        }
    }

    // debug(rightWeight);
    // debug(downWeight);

    if (k % 2 != 0)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << -1 << " ";
            }
            cout << '\n';
        }
        return;
    }

    // assert(false);

    // take the minimum path of k/2 steps and then go back in using this path
    // so path len k should be even

    // do dfs search for solution
    vector<vector<long long>> ans(n, vector<long long>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            vector<vector<long long>> dp(n, vector<long long>(m, 1e18));
            dp[i][j] = 0;
            ans[i][j] = 2 * dfs(i, j, rightWeight, downWeight, k / 2, dp);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j : ans[i])
        {
            cout << j << " ";
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