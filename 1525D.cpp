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

    // Every one can be moved to the left or right , so it has 2 states at everypoint

    vector<int> ones;

    for (int i = 0; i < n; i++)
    {
        if (a[i] == 1)
            ones.push_back(i);
    }

    vector<vector<int>> dp(5001, vector<int>(5001, INT_MAX));

    dp[0][0] = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= ones.size(); j++)
        {
            if (dp[i][j] == INT_MAX)
                continue;

            // we need to choose at most ones.size() zeros
            // initially we have an empty array with no zeros
            // when the array is of size 1, then no of zeros is 1

            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);

            // when we choose same number of final positions for the next array also,i.e size increases by 1

            if (j < ones.size() && a[i] == 0)
            {
                dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + abs(ones[j] - i));
            }
        }
    }

    cout << dp[n][ones.size()] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve(1);

    return 0;
}