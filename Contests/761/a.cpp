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

void solve(int ccc)
{
    string s, t;

    cin >> s >> t;

    sort(all(s));

    if (s[0] != 'a' || t[0] != 'a' || t[1] != 'b')
    {
        cout << s << '\n';
        return;
    }

    int cb = 0, cc = 0;

    for (char c : s)
        if (c == 'b')
            cb++;
        else if (c == 'c')
            cc++;

    string res = "";

    bool fixedb = false, fixedc = false;

    if (cc > 0 && cb > 0)
    {
        for (char c : s)
        {
            if (!fixedb && c == 'b')
            {
                for (int i = 0; i < cc; i++)
                    res += 'c';
                fixedb = true;
            }
            else if (!fixedc && c == 'c')
            {
                for (int i = 0; i < cb; i++)
                    res += 'b';
                fixedc = true;
            }
            else if (c != 'c' && c != 'b')
            {
                res += c;
            }
        }
    }
    else
    {
        cout << s << '\n';
        return;
    }

    cout << res << '\n';
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