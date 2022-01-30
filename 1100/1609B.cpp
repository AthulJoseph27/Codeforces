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
    int n, q;
    cin >> n >> q;

    string s;

    cin >> s;

    int cnt = 0;

    for (int i = 0; i < (n - 2); i++)
    {
        if (s.substr(i, 3) == "abc")
        {
            cnt++;
        }
    }

    for (int _ = 0; _ < q; _++)
    {
        int pos;
        char ch;
        cin >> pos >> ch;

        pos--;

        if (s[pos] == ch)
        {
            cout << cnt << '\n';
            continue;
        }

        // check if it reduces count
        for (int i = max(0, pos - 2); i < min(n - 2, pos + 1); i++)
        {
            if (s.substr(i, 3) == "abc")
            {
                cnt--;
                break;
            }
        }

        s[pos] = ch;

        for (int i = max(0, pos - 2); i < min(n - 2, pos + 1); i++)
        {
            if (s.substr(i, 3) == "abc")
            {
                cnt++;
                break;
            }
        }

        cout << cnt << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;

    T = 1;

    for (int i = 0; i < T; i++)
    {
        solve(i + 1);
    }

    return 0;
}