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
#define rall(v) v.rbegin(), v.rend()

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
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    int cnt = 0;
    for (char c : s)
    {
        if (c == '1')
            cnt++;
    }

    vector<int> left(n, 1), right(n, 1);

    int upto = -1;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            upto = i + k;
        }
        else if (i <= upto)
        {
            left[i] = 0;
        }
    }

    upto = n;
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == '1')
        {
            upto = i - k;
        }
        else if (i >= upto)
        {
            right[i] = 0;
        }
        else
        {
            if (left[i] && right[i])
            {
                s[i] = '1';
                upto = i - k;
            }
        }
    }

    int initial = cnt;
    cnt = 0;

    for (char c : s)
    {
        if (c == '1')
            cnt++;
    }

    cout << (cnt - initial) << '\n';
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