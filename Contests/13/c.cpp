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
    vector<vector<int>> a(2, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        cin >> a[0][i];
        a[0][i]--;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> a[1][i];
        a[1][i]--;
    }

    vector<vector<int>> g(n);

    for (int i = 0; i < n; i++)
    {
        g[a[0][i]].push_back(a[1][i]);
    }

    vector<bool> visited(n, false);

    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            count++;
            int cur = i;
            do
            {
                visited[cur] = true;
                cur = g[cur].back();
            } while (cur != i);
        }
    }

    long long ans = 1;
    const int mod = int(1e9 + 7);

    for (int i = 0; i < count; i++)
    {
        ans *= 2LL;
        ans %= mod;
    }

    // ans is 2^no of cycles

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