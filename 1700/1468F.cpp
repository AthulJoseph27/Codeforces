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

class Vector
{
public:
    int i, j;
    Vector(const pair<int, int> a, pair<int, int> b)
    {
        i = b.first - a.first;
        j = b.second - a.second;

        if (i == 0 && j == 0)
            return;

        int gcd = __gcd(abs(i), abs(j));

        if (i == 0)
            gcd = abs(j);
        else if (j == 0)
            gcd = abs(i);

        i /= gcd;
        j /= gcd;
    }
};

void solve(int cc)
{
    int n;
    cin >> n;

    map<pair<int, int>, long long> mp;

    // vectors should be collinear and oppossite directed

    for (int i = 0; i < n; i++)
    {
        int x, y, u, v;
        cin >> x >> y >> u >> v;
        Vector temp = Vector(make_pair(x, y), make_pair(u, v));
        mp[make_pair(temp.i, temp.j)]++;
    }

    long long ans = 0;

    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        if (it->first.first == 0 && it->first.second == 0)
            continue;
        ans += it->second * mp[make_pair(it->first.first * -1, it->first.second * -1)];
    }

    cout << ans / 2 << '\n';
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