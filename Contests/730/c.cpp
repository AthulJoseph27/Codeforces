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

long double dfs(int c, int m, int p, int v, int scale)
{

    if (p >= scale)
        return 1;

    long double e = 0;

    if (c > 0)
    {
        if (m > 0)
        {
            if (v > c)
                e += (((long double)c / (long double)scale) * (1.0 + dfs(0, m + c / 2, p + c / 2, v, scale)));
            else
                e += (((long double)c / (long double)scale) * (1.0 + dfs(c - v, m + v / 2, p + v / 2, v, scale)));
        }
        else
        {
            if (v > c)
                e += (((long double)c / (long double)scale) * (1.0 + dfs(0, 0, p + c, v, scale)));
            else
                e += (((long double)c / (long double)scale) * (1.0 + dfs(c - v, 0, p + v, v, scale)));
        }
    }

    if (m > 0)
    {
        if (c > 0)
        {
            if (v > m)
                e += (((long double)m / (long double)scale) * (dfs(c + m / 2, 0, p + m / 2, v, scale) + 1.0));
            else
                e += (((long double)m / (long double)scale) * (dfs(c + v / 2, m - v, p + v / 2, v, scale) + 1.0));
        }
        else
        {
            if (v > m)
                e += (((long double)m / (long double)scale) * (dfs(0, 0, p + m, v, scale) + 1.0));
            else
                e += (((long double)m / (long double)scale) * (dfs(0, m - v, p + v, v, scale) + 1.0));
        }
    }
    e += ((long double)p / (long double)scale);
    return e;
}

void solve(int cc)
{
    long double c, m, p, v;
    cin >> c >> m >> p >> v;

    long double scale = 1e7;

    long double e = dfs(round(scale * c), round(scale * m), round(scale * p), round(scale * v), scale);

    cout << setprecision(15) << e << '\n';
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