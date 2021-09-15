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
    int n;
    cin >> n;

    vector<int> a(n);

    for (int &i : a)
        cin >> i;

    if (n < 3)
    {
        cout << (a[0] == 1) << '\n';
        return;
    }

    // you can make one jump or two jump, if you encounter 1, then ur score is added
    // minimize the score

    const int INF = 1e9 + 7;

    vector<vector<int>> dp(2, vector<int>(n, INF));

    dp[0][0] = (a[0] == 1);
    dp[1][1] = (a[0] == 1) + (a[1] == 1);

    for (int i = 2; i < n; i++)
    {
        // dp[0][i] -> ith fight is fought
        // dp[1][i] -> i-1 and ith fight is fought

        dp[0][i] = min(dp[0][i - 2], dp[1][i - 2]) + (a[i] == 1); // gap of 1

        if (i > 2)
        {
            dp[0][i] = min({dp[0][i], dp[0][i - 3] + (a[i] == 1), dp[1][i - 3] + (a[i] == 1)}); // gap of 2
            dp[1][i] = min(dp[1][i - 3], dp[0][i - 3]) + (a[i - 1] == 1) + (a[i] == 1);         // gap of 1
        }

        if (i > 3)
        {
            dp[1][i] = min(dp[1][i], min(dp[1][i - 4], dp[0][i - 4]) + (a[i - 1] == 1) + (a[i] == 1)); // gap of 2
        }
    }

    cout << min({dp[0][n - 1], dp[1][n - 1], dp[0][n - 2], dp[1][n - 2], dp[0][n - 3], dp[1][n - 3]}) << '\n';
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