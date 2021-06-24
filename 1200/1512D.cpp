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

    vector<long long> b(n + 2);

    for (long long &i : b)
        cin >> i;

    sort(all(b));

    // the sum could be b[-1] or b[-2]

    long long sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += (long long)b[i];
    }

    // debug(b);

    if (sum == b[n] || sum == b[n + 1])
    {
        // x is b[n+1] or b[n]
        for (int i = 0; i < n; i++)
        {
            cout << b[i] << ' ';
        }
        cout << '\n';
        return;
    }

    // if sum is b[n] or b[n+1]
    // then whole sum is b[n+1] and b[n] is a element of a

    // debug(sum, b[n], b[n + 1]);

    sum += b[n];
    long long x = sum - b[n + 1];

    // debug(x);

    vector<long long> a;
    bool flag = true;

    for (int i = 0; i < n; i++)
    {
        if (flag && b[i] == x)
        {
            flag = false;
            continue;
        }
        else
        {
            a.push_back(b[i]);
        }
    }

    if (a.size() == n)
    {
        cout << -1 << '\n';
        return;
    }

    for (long long i : a)
        cout << i << ' ';

    cout << b[n] << '\n';
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