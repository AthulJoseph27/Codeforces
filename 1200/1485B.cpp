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
    int n, q, k;

    cin >> n >> q >> k;

    vector<long long> a(n);

    for (long long &i : a)
        cin >> i;

    /*
        [a,b,c,......]
        at index 0 => {1,2,...b-1} - {a} => b-2
        at index 1 => {a+1,a+2....c-1} - {b} => c-a-2
        at index i => a(i+1) - a(i-1) - 2
    */

    vector<long long> possib = {a[1] - 2};

    for (int i = 1; i < n; i++)
    {
        if (i != (n - 1))
            possib.push_back(a[i + 1] - a[i - 1] - 2);
        else
            possib.push_back(k - a[i - 1] - 1);
    }

    vector<long long> pref = {0};

    for (int i = 0; i < n; i++)
    {
        pref.push_back(pref.back() + possib[i]);
    }

    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;

        if (l == r)
        {
            cout << (k - 1) << '\n';
            continue;
        }

        l--;
        r--;

        // sum from l+1 to r-1

        long long ans = pref[r] - pref[l + 1] + (a[l + 1] - 2) + (k - a[r - 1] - 1);

        cout << ans << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve(1);

    return 0;
}