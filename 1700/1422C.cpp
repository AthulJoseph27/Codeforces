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

const long long mod = (long long)1e9 + 7;

long long mul(long long a, long long b)
{
    long long res = (a * b) % mod;
    return res;
}

long long add(long long a, long long b)
{
    return (a + b) % mod;
}

void solve(int cc)
{
    string s;
    cin >> s;

    long long n = s.size();

    vector<long long> prefs = {0};

    long long ten_pow = 1;

    for (int i = 1; i < n; i++)
    {
        prefs.push_back(add(prefs.back(), mul(i, ten_pow)));
        ten_pow = mul(ten_pow, 10LL);
    }

    ten_pow = 1;

    // debug(prefs);
    long long sum = 0;

    vector<long long> temp = {0};

    long long ans = 0;
    long long p = 1;

    for (long long i = n - 1; i >= 0; --i)
    {
        long long k = ((i * (i + 1)) / 2 % mod * p % mod + prefs[n - i - 1]) % mod;
        p = mul(p, 10);
        ans = add(ans, mul((long long)(s[i] - '0'), k));
    }
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;

    T = 1;

    for (int i = 0; i < T; i++)
    {
        solve(i + 1);
    }

    return 0;
}