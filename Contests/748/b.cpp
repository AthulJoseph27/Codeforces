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
    long long n;
    cin >> n;

    string s = to_string(n);

    if (n % 25 == 0)
    {
        cout << 0 << '\n';
        return;
    }

    int ln = s.size() - 1;

    int ans = ln;

    int count = 0;

    while (ln >= 0 && s[ln] != '0')
    {
        ln--;
        count++;
    }

    if (ln >= 0 && s[ln] == '0')
    {

        int aln = ln;
        int nc = count;
        ln--;
        // debug(ln, s[ln], count);
        while (ln >= 0 && s[ln] != '0' && s[ln] != '5')
        {
            ln--;
            nc++;
        }

        // debug(ln, nc);
        if (ln >= 0 && (s[ln] == '0' || s[ln] == '5'))
        {
            ans = min(ans, nc);
        }

        ln = aln;
    }

    ln = s.size() - 1;
    count = 0;

    while (ln >= 0 && s[ln] != '5')
    {
        ln--;
        count++;
    }

    // debug(ln, count);

    if (ln >= 0 && s[ln] == '5')
    {

        int aln = ln;
        int nc = count;
        // debug(ln, s[ln], count, s);
        ln--;
        while (ln >= 0 && s[ln] != '2' && s[ln] != '7')
        {
            ln--;
            nc++;
        }

        // debug(ln, s[ln], nc, s);

        if (ln >= 0 && (s[ln] == '2' || s[ln] == '7'))
        {
            ans = min(ans, nc);
        }
    }

    cout << ans << '\n';
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
