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
    int a, b;
    cin >> a >> b;
    string s;
    cin >> s;

    int cnt = 0;

    for (char c : s)
        if (c == '?')
            cnt++;

    if (cnt > (a + b))
    {
        cout << -1 << '\n';
        return;
    }

    int n = s.size();

    for (int i = 0; i < n / 2; i++)
    {
        if (s[i] != s[n - 1 - i] && s[i] != '?' && s[n - 1 - i] != '?')
        {
            cout << -1 << '\n';
            return;
        }
    }

    for (char c : s)
    {
        if (c == '0')
            a--;
        else if (c == '1')
            b--;
    }

    for (int i = 0; i < n / 2; i++)
    {
        if (s[i] == '?' && s[n - i - 1] != '?')
        {
            if (s[n - i - 1] == '1')
            {
                if (b == 0)
                {
                    cout << -1 << '\n';
                    return;
                }
                b--;
                s[i] = '1';
            }
            else
            {
                if (a == 0)
                {
                    cout << -1 << '\n';
                    return;
                }
                a--;
                s[i] = '0';
            }
        }
        else if (s[n - i - 1] == '?' && s[i] != '?')
        {
            if (s[i] == '1')
            {
                if (b == 0)
                {
                    cout << -1 << '\n';
                    return;
                }
                b--;
                s[n - i - 1] = '1';
            }
            else
            {
                if (a == 0)
                {
                    cout << -1 << '\n';
                    return;
                }
                a--;
                s[n - i - 1] = '0';
            }
        }
    }

    for (int i = 0; i < n / 2; i++)
    {
        if (s[i] == '?')
        {
            assert(s[n - i - 1] == '?');
            if (a >= 2)
            {
                s[n - i - 1] = '0';
                s[i] = '0';
                a -= 2;
            }
            else if (b >= 2)
            {
                s[n - i - 1] = '1';
                s[i] = '1';
                b -= 2;
            }
            else
            {
                cout << -1 << '\n';
                return;
            }
        }
    }

    if (n % 2 != 0 && s[n / 2] == '?')
    {
        if (a > 0)
        {
            s[n / 2] = '0';
            a--;
        }
        else
        {
            s[n / 2] = '1';
            b--;
        }
    }

    for (char c : s)
    {
        if (c == '?')
        {
            cout << -1 << '\n';
            return;
        }
    }

    if (a != 0 || b != 0)
    {
        cout << -1 << '\n';
        return;
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