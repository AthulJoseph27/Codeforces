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
#define rall(v) v.rbegin(), v.rend()

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
    ll x, y, k;
    cin >> x >> y >> k;

    /*
        need y*k + 1 + k stick
        1 -> x
        x -> 2x-1
        2x-1 ->3x-2
        n*x - (n-1) >= yk  + k
        nx -n >= yk + k - 1

        n(x-1) >= yk + k - 1
        n >= (yk+k-1)/(x-1)

        2 1 5

        10 sticks

        1 -> 2
        2 -> 3
        3 -> 4
        4 -> 5
        5 -> 6
        6 -> 7
        7 -> 8
        8 -> 9
        9 -> 10

        10 -> 5 + 5 coal
    */

    ll n;

    if ((y * k + k - 1LL) % (x - 1LL) == 0)
    {
        n = (y * k + k - 1LL) / (x - 1LL);
    }
    else
    {
        n = (y * k + k - 1LL) / (x - 1LL) + 1LL;
    }

    cout << (n + k) << '\n';
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