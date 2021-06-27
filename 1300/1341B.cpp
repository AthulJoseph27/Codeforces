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
    int n, k;
    cin >> n >> k;

    vector<int> a(n);

    for (int &i : a)
        cin >> i;

    vector<int> prefs = {0};

    for (int i = 1; i < (n - 1); i++)
    {
        if (a[i] > max(a[i - 1], a[i + 1]))
        {
            prefs.push_back(prefs.back() + 1);
        }
        else
        {
            prefs.push_back(prefs.back());
        }
    }

    prefs.push_back(0);

    int p = 0;
    int index = -1;

    for (int i = 0; (i + k - 1) < n; i++)
    {
        // [i .... i+k-1]

        int nps = prefs[i + k - 2] - prefs[i];

        if (nps > p)
        {
            index = i;
            p = nps;
        }
    }

    if (p == 0)
    {
        cout << 1 << ' ' << (1) << '\n';
        return;
    }

    cout << (p + 1) << ' ' << (index + 1) << '\n';
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