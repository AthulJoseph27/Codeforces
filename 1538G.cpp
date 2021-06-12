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
    int x, y, a, b;
    cin >> x >> y >> a >> b;

    if (a == b)
    {
        cout << (min(x, y) / a) << '\n';
        return;
    }

    if (a > b)
        swap(a, b);

    if (x > y)
        swap(x, y);

    /*
        no of gifts = n

        k of type 1 and n-k of type 2

        k*a + (n-k)*b <= x
        k*b + (n-k)*a <= y

        k >= (nb - x)/(b-a)

        k <= (y - na)/(b-a)

        0<=k<=n

        k >= lb
        k <= hb

        lb<=k<=hb

        lb <= n, but hb may or may not be less than n

    */

    int low = 0, high = (x + y) / (a + b);

    // binary search for n

    int ans = 0;

    while (low <= high)
    {
        int n = low + (high - low) / 2;

        int lb = ceil((double)(n * b - x) / ((double)(b - a)));
        int hb = floor(((double)(y - n * a)) / ((double)(b - a)));

        if (lb <= hb && hb >= 0 && lb <= n)
        {
            // then n is a possible solution
            low = n + 1;
            ans = max(ans, n);
        }
        else
        {
            high = n - 1;
        }
    }

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