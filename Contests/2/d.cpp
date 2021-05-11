#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;

#define push push_back
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
    int n;

    cin >> n;

    vector<long long> a(n);
    vector<long long> b(n);

    for (long long &i : a)
    {
        cin >> i;
    }

    for (long long &i : b)
    {
        cin >> i;
    }

    vector<long long> prefs = {0};
    vector<long long> suffx = {0};

    for (int i = 0; i < n; i++)
    {
        prefs.push_back(prefs.back() + b[i] * a[i]);
    }

    for (int i = n - 1; i >= 0; i--)
    {
        suffx.push_back(suffx.back() + b[i] * a[i]);
    }

    long long ans = prefs.back();

    for (int center = 0; center < n; center++)
    {
        long long cur = a[center] * b[center];

        for (int l = center - 1, r = center + 1; l >= 0 && r < n; l--, r++)
        {
            cur += (a[l] * b[r]);
            cur += (a[r] * b[l]);
            ans = max(ans, cur + prefs[l] + suffx[n - r - 1]);
        }

        cur = 0;

        for (int l = center, r = center + 1; l >= 0 && r < n; l--, r++)
        {
            cur += (a[l] * b[r]);
            cur += (a[r] * b[l]);
            ans = max(ans, cur + prefs[l] + suffx[n - r - 1]);
        }
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

long long max(long long a, long long b)
{
    if (a > b)
        return a;
    return b;
}