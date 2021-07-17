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
    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> b(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());

    int k = n - n / 4;

    int as = 0, bs = 0;

    for (int i = 0; i < k; i++)
    {
        as += a[i];
        bs += b[i];
    }

    if (as >= bs)
    {
        cout << 0 << '\n';
        return;
    }

    vector<int> prefs = {0};
    vector<int> prefs_b = {0};
    for (int i : a)
    {
        prefs.push_back(prefs.back() + i);
    }

    for (int i : b)
    {
        prefs_b.push_back(prefs_b.back() + i);
    }

    int N = 4 * n + 10;

    for (int i = 1; i < N; i++)
    {
        int newN = n + i;
        int kn = newN - newN / 4;
        int nas = i * 100LL;
        int nbs = bs;
        if (kn > i)
        {
            nas += prefs[kn - i];
        }

        if (kn <= n)
        {
            nbs = prefs_b[kn];
        }
        else
        {
            nbs = prefs_b[n];
        }

        if (nas >= nbs)
        {
            cout << i << '\n';
            return;
        }

        // debug(kn, nas, nbs);
    }
    cout << N << '\n';
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