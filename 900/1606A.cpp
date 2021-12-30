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
    // claim, count |AB(s) - BA(s)|<=1

    string s;
    cin >> s;

    int ab = 0, ba = 0;
    int n = s.size();

    for (int i = 1; i < n; i++)
    {
        if (s[i - 1] == 'a' && s[i] == 'b')
        {
            ab++;
        }
        else if (s[i - 1] == 'b' && s[i] == 'a')
        {
            ba++;
        }
    }

    if (ab == ba)
    {
        cout << s << '\n';
        return;
    }

    assert(abs(ab - ba) <= 1);

    if (ab > ba)
    {
        if (s[0] == 'a')
        {
            s[0] = 'b';
        }
        else if (s.back() == 'b')
        {
            s[n - 1] = 'a';
        }
        else
        {
            assert(false);
        }
    }
    else
    {
        if (s[0] == 'b')
        {
            s[0] = 'a';
        }
        else if (s.back() == 'a')
        {
            s[n - 1] = 'b';
        }
        else
        {
            assert(false);
        }
    }

    cout << s << '\n';
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