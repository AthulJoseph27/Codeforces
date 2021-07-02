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

const int modulo = 1e9 + 7;

pair<int, long long> binarySearch(int n, int x, int index)
{
    int l = 0, r = n, mid;

    int lesser = x - 1, larger = n - x;

    long long ans = 1;

    while (l < r)
    {
        mid = (l + r) / 2;
        debug(mid);
        if (mid == index)
        {
            l = mid + 1;
        }
        else if (mid < index)
        {
            ans *= (lesser);
            ans %= modulo;
            lesser--;
            l = mid + 1;
        }
        else
        {
            ans *= (larger);
            ans %= modulo;
            larger--;
            r = mid;
        }
    }

    assert(l > 0 && l - 1 == index);

    if (lesser < 0 || larger < 0)
        ans = 0;
    return {lesser + larger, ans};
}

void solve(int cc)
{
    int n, x, index;
    cin >> n >> x >> index;

    pair<int, long long> result = binarySearch(n, x, index);

    debug(result);
    long long ans = result.second;
    ;

    for (int i = result.first; i > 0; i--)
    {
        ans *= i;
        ans %= modulo;
    }

    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve(1);

    return 0;
}