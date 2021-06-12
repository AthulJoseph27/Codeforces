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

long long dp[1001][1001][2];
const int modulo = int(1e9 + 7);

int simulate(int cur, int dir, int n, int k)
{
    if (k == 1)
        return 1;

    if (dp[cur][k][dir] != -1)
        return dp[cur][k][dir];

    int ans = 2;

    if (dir == 0)
    {
        if (cur < n)
            ans = (ans + simulate(cur + 1, 0, n, k) - 1) % modulo;

        if (cur > 1)
            ans = (ans + simulate(cur - 1, 1, n, k - 1) - 1) % modulo;
    }
    else
    {
        if (cur < n)
            ans = (ans + simulate(cur + 1, 0, n, k - 1) - 1) % modulo;

        if (cur > 1)
            ans = (ans + simulate(cur - 1, 1, n, k) - 1) % modulo;
    }

    dp[cur][k][dir] = ans;

    return ans;
}

void solve(int cc)
{
    int n, k;

    cin >> n >> k;

    memset(dp, -1, sizeof(dp));

    int ans = simulate(1, 0, n, k);

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