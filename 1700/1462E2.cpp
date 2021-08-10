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

const int mod = 1e9 + 7;

long long fast_pow(long long a, long long p)
{
    long long res = 1;
    while (p)
    {
        if (p % 2 == 0)
        {
            a = (a * a) % mod;
            p /= 2;
        }
        else
        {
            res = (res * a) % mod;
            p--;
        }
    }
    return res;
}

pair<vector<long long>, vector<long long>> fact_and_inv(int N)
{
    vector<long long> fact(N + 1);

    vector<long long> inv(N + 1);

    fact[0] = 1;
    inv[0] = 1;

    for (int i = 1; i <= N; i++)
    {
        fact[i] = (fact[i - 1] * i) % mod;
        inv[i] = fast_pow(fact[i], mod - 2);
    }

    return {fact, inv};
}

vector<long long> fact;
vector<long long> inv;

int nCk(int n, int k)
{
    if (k > n)
    {
        return 0;
    }

    return fact[n] * inv[k] % mod * inv[n - k] % mod;
}

void solve(int cc)
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n);

    for (int &i : a)
        cin >> i;

    sort(all(a));

    long long count = 0;

    for (int i = 0; i < n; i++)
    {
        int l = i + 1;
        int r = upper_bound(all(a), a[i] + k) - a.begin();
        // chose m-1 elements from the range (l,r)
        count = (count + nCk(r - l, m - 1)) % mod;
    }
    cout << count << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;

    pair<vector<long long>, vector<long long>> p = fact_and_inv(2 * 100000);

    fact = p.first;
    inv = p.second;

    cin >> T;

    for (int i = 0; i < T; i++)
    {
        solve(i + 1);
    }

    return 0;
}