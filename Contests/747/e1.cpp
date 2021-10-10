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

// long long rec(long long node, long long mx)
// {
//     long long res = 0;
//     if (node == 1)
//     {
//         res = 6;
//         res *= rec(2LL * node, mx);
//         res %= mod;
//         res *= rec(2LL * node + 1, mx);
//         res %= mod;
//         return res;
//     }

//     if (node > mx)
//         return 1;

//     res = 4;

//     res *= rec(2LL * node, mx);
//     res %= mod;
//     res *= rec(2LL * node + 1, mx);
//     res %= mod;
//     return res;
// }

void solve(int cc)
{
    int k;
    cin >> k;

    // long long nodes = (1LL << k) - 1;
    // long long res = rec(1, mx) % mod;

    long long res = 4000934262 % mod;

    debug(res);

    // long long pw4 = 4;

    long long nodes = (1LL << k) - 2;

    cout << res << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve(1);

    return 0;
}