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
    int n;
    cin >> n;

    vl a(n);

    for (ll &i : a)
        cin >> i;

    ll sm = 0;

    for (ll i : a)
        sm += i;

    vl b1(n), b2(n);

    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            b1[i] = 1;
            b2[i] = a[i];
        }
        else
        {
            b1[i] = a[i];
            b2[i] = 1;
        }
    }

    ll sm1 = 0, sm2 = 0;

    for (int i = 0; i < n; i++)
    {
        sm1 += llabs(a[i] - b1[i]);
    }

    for (int i = 0; i < n; i++)
    {
        sm2 += llabs(a[i] - b2[i]);
    }

    if (sm1 < sm2)
    {
        for (ll i : b1)
        {
            cout << i << ' ';
        }
    }
    else
    {
        for (ll i : b2)
        {
            cout << i << ' ';
        }
    }

    cout << '\n';
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