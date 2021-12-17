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

long long gcd(long long a, long long b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

void solve(int cc)
{
    int n;
    cin >> n;

    vector<long long> a(n);

    for (long long &i : a)
        cin >> i;

    long long o = a[1], e = a[0];

    for (int i = 2; i < n; i += 2)
    {
        e = gcd(e, a[i]);
    }

    for (int i = 3; i < n; i += 2)
    {
        o = gcd(o, a[i]);
    }

    // debug(o, e);

    if (o == 1 and e == 1)
    {
        cout << "0\n";
        return;
    }

    if (o == 1)
    {
        for (int i = 1; i < n; i += 2)
        {
            if (a[i] % e == 0)
            {
                cout << "0\n";
                return;
            }
        }
        cout << e << '\n';
        return;
    }
    else if (e == 1)
    {
        for (int i = 0; i < n; i += 2)
        {
            if (a[i] % o == 0)
            {
                cout << "0\n";
                return;
            }
        }

        cout << o << '\n';
        return;
    }

    bool is_ans = true;

    for (int i = 0; i < n; i += 2)
    {
        if (a[i] % o == 0)
        {
            is_ans = false;
            break;
        }
    }

    if (is_ans)
    {
        cout << o << '\n';
        return;
    }

    is_ans = true;

    for (int i = 1; i < n; i += 2)
    {
        if (a[i] % e == 0)
        {
            is_ans = false;
            break;
        }
    }

    if (is_ans)
    {
        cout << e << '\n';
        return;
    }

    cout << 0 << '\n';
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