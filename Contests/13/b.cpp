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

long long Ugliness(vector<int> &a)
{
    long long ugly = a[0] + a.back();
    int n = a.size();
    for (int i = 1; i < n; i++)
    {
        ugly += llabs(a[i] - a[i - 1]);
    }

    return ugly;
}

void solve(int cc)
{
    int n;
    cin >> n;

    vector<int> a(n);

    for (int &i : a)
        cin >> i;

    if (n == 1)
    {
        cout << a[0] << '\n';
        return;
    }

    long long ugly = Ugliness(a);

    for (int i = 1; i < n - 1; i++)
    {
        if (a[i] > max(a[i - 1], a[i + 1]))
        {
            ugly -= (a[i] - max(a[i - 1], a[i + 1]));
            a[i] = max(a[i - 1], a[i + 1]);
        }
    }

    if (a[0] > a[1])
    {
        ugly -= (a[0] - a[1]);
    }

    if (a[n - 1] > a[n - 2])
    {
        ugly -= (a[n - 1] - a[n - 2]);
    }

    cout << ugly << '\n';
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
