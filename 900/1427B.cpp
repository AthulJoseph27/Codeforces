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

    vi a(n);

    for (int &i : a)
        cin >> i;

    int sm = 0;

    for (int i : a)
        sm += i;

    if (sm == 0)
    {
        cout << "NO\n";
        return;
    }

    bool has_zero = false;

    for (int i : a)
        if (i == 0)
        {
            has_zero = true;
            break;
        }

    cout << "YES\n";

    sort(all(a));

    if (a[0] >= 0)
    {
        sort(a.rbegin(), a.rend());
        for (int i : a)
            cout << i << ' ';
        cout << '\n';
        return;
    }

    int neg_sm = 0, ps_sm = 0;

    for (int i : a)
    {
        if (i < 0)
            neg_sm += abs(i);
        else
            ps_sm += i;
    }

    if (ps_sm > neg_sm)
    {
        sort(a.rbegin(), a.rend());
    }

    if (ps_sm == neg_sm)
    {
        swap(a[0], a[n - 1]);
    }

    for (int i : a)
        cout << i << ' ';
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