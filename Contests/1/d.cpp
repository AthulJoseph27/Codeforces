#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;

#define push push_back
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

long long cur_min = 1e14;

void search(int i, int j, int s, long long cost, int k, vector<vector<vector<long long>>> &dp, vector<vector<int>> &rightW, vector<vector<int>> &downW)
{
    if (s > k)
        return;

    dp[s][i][j] = min(dp[s][i][j], cost);

    if (s == k)
    {
        cur_min = min(cur_min, dp[s][i][j]);
    }

    if (i != 0)
    {
        search(i - 1, j, s + 1, dp[s][i][j] + downW[j][i - 1], k, dp, rightW, downW);
    }

    if (j != 0)
    {
        search(i, j - 1, s + 1, dp[s][i][j] + rightW[i][j - 1], k, dp, rightW, downW);
    }

    if (i != downW[0].size())
    {
        search(i + 1, j, s + 1, dp[s][i][j] + downW[j][i], k, dp, rightW, downW);
    }

    if (j != rightW[0].size())
    {
        search(i, j + 1, s + 1, dp[s][i][j] + rightW[i][j], k, dp, rightW, downW);
    }
}

void solve(int cc)
{
    // from a point you can go up , down , left or right

    int n, m, k;

    cin >> n >> m >> k;

    vector<vector<int>> rightW(n, vector<int>(m - 1));
    vector<vector<int>> downW(m, vector<int>(n - 1));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m - 1; j++)
        {
            cin >> rightW[i][j];
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            cin >> downW[i][j];
        }
    }

    if (k % 2 != 0)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << -1 << ' ';
            }
            cout << '\n';
        }
        return;
    }

    // debug(rightW);
    // debug(downW);

    // find a path of len k/2 of minimum cost, take it and return using the same path
    // let dp[k][i][j] be the minimum cost to reach i j with k steps
    // then dp[k+1][i+1][j] = dp[k][i][j] + cx
    //

    k = k / 2;

    // debug(rightW);
    // debug(downW);

    vector<vector<long long>> ans(n, vector<long long>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            vector<vector<vector<long long>>> dp(k + 2, vector<vector<long long>>(n, vector<long long>(m, 1e14)));

            dp[0][i][j] = 0;

            cur_min = 1e14;

            search(i, j, 0, 0, k, dp, rightW, downW);

            assert(cur_min != 1e14);

            ans[i][j] = cur_min;

            ans[i][j] *= 2;
        }
    }

    // debug(ans);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;

    solve(1);

    return 0;
}

long long min(long long a, long long b)
{
    if (a < b)
        return a;
    return b;
}