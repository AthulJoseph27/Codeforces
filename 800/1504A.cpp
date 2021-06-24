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
    string s;
    cin >> s;

    if (s.size() == 0)
    {
        cout << "NO" << '\n';
        return;
    }

    if (s.size() == 1)
    {
        if (s[0] == 'a')
            cout << "NO" << '\n';
        else
        {
            cout << "YES" << '\n';
            cout << s << 'a' << '\n';
        }
        return;
    }

    bool cant = true;

    for (char c : s)
        if (c != 'a')
        {
            cant = false;
            break;
        }

    if (cant)
    {
        cout << "NO" << '\n';
        return;
    }

    cout << "YES" << '\n';

    if (s[0] != 'a')
    {
        cout << s << 'a' << '\n';
        return;
    }

    if (s.back() != 'a')
    {
        cout << 'a' << s << '\n';
        return;
    }

    int fc = 0, sc = 0;
    int n = s.size();

    for (int i = 0; i < n; i++)
        if (s[i] == 'a')
            fc++;
        else
            break;

    for (int i = n - 1; i >= 0; i--)
        if (s[i] == 'a')
            sc++;
        else
            break;

    if (fc >= sc)
    {
        cout << 'a' << s << '\n';
    }
    else
    {
        cout << s << 'a' << '\n';
    }
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