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
    int n, d;
    cin >> n >> d;

    vector<int> a(n);

    for (int &i : a)
        cin >> i;

    const int INF = 1e9 + 5;

    /*
        d = 2
        20 21 22 23 24 25 26 27 28 29

       20 + 10*2 + 2 = 32 ,... 34, 36, .......
       every even number
       21 + 10*2 + 2 = 33 .....
       every odd number

       70 71 72 73 74 75 76 77 78 79

       86,85,84,83,82,81,80
       80+7 = 87
       81+7 = 88...89....so all number greater than d*10 can be consturcted 
    */

    vector<int> pos;

    for (int i = 0; i < d; i++)
    {
        pos.push_back(d + i * 10);
    }

    vector<bool> dp(d * 10, false);
    dp[0] = true;

    for (int c : pos)
    {
        for (int i = 0; (i + c) < dp.size(); i++)
        {
            if (dp[i])
                dp[i + c] = true;
        }
    }

    for (int e : a)
    {
        if (e >= (d * 10) || dp[e])
        {
            cout << "YES" << '\n';
        }
        else
        {
            cout << "NO" << '\n';
        }
    }
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