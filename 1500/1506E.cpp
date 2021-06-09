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

    for (int &i : a)
        cin >> i;

    if (n == 1)
    {
        cout << a[0] << '\n';
        cout << a[0] << '\n';
        return;
    }

    vector<int> mn(n, 0);
    vector<int> mx(n, 0);

    map<int, int> used;

    mn[0] = a[0];
    mx[0] = a[0];
    used[a[0]]++;

    for (int i = 1; i < n; i++)
    {
        if (a[i] != a[i - 1])
        {
            mn[i] = a[i];
            mx[i] = a[i];
            used[a[i]]++;
        }
    }

    int fr = 1;

    for (int i = 1; i < n; i++)
    {
        if (mn[i] == 0)
        {
            while (fr < n && used[fr] > 0)
                fr++;
            mn[i] = fr;
            used[fr]++;
        }
    }

    for (int i : mn)
        cout << i << ' ';
    cout << '\n';

    used.clear();

    mx[0] = a[0];

    for (int i : mx)
        used[i]++;

    fr = a[0] - 1;

    set<int> mlt;

    for (int i = 1; i <= n; i++)
    {
        mlt.insert(i);
    }

    // auto ptr = mlt.find(a[0]);

    int cb = a[0];

    for (int i = 1; i < n; i++)
    {
        if (mx[i] == 0)
        {
            fr = *(prev(mlt.find(cb)));
            mx[i] = fr;
            mlt.erase(mlt.find(fr));
            used[fr]++;
        }
        else
        {
            mlt.erase(mlt.find(cb));
            cb = a[i];
        }
    }

    for (int i : mx)
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