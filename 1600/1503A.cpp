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

/*
    101101
*/
void solve(int cc)
{
    int n;

    cin >> n;

    string s;

    cin >> s;

    if (n % 2 != 0 || s[0] == '0' || s.back() == '0')
    {
        cout << "NO" << '\n';
        return;
    }

    vector<char> a(n);
    vector<char> b(n);

    int ones = 0;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
            ones++;
    }

    if (ones % 2 != 0)
    {
        cout << "NO" << '\n';
        return;
    }

    int k = ones / 2;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1' && k > 0)
        {
            a[i] = '(';
            b[i] = '(';
            k--;
        }
        else
        {
            a[i] = ')';
            b[i] = ')';
        }
    }

    bool alt = true;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            if (alt)
            {
                a[i] = '(';
                b[i] = ')';
            }
            else
            {
                a[i] = ')';
                b[i] = '(';
            }

            alt = !alt;
        }
    }

    cout << "YES" << '\n';
    for (char c : a)
        cout << c;
    cout << '\n';
    for (char c : b)
        cout << c;
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