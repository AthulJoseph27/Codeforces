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
    int n;
    cin >> n;

    vi a(n);

    for (int &i : a)
        cin >> i;

    int last = a.back();

    string s = "a";

    for (int i = 0; i < n; i++)
    {
        // current and next string shd have first a[i] elements same
        // if a[i] = 2 and a[i+1] = 5, current length cannot be 2

        if (a[i] == 0)
        {
            if (s[0] == 'a')
            {
                cout << s << '\n';
                s = "b";
            }
            else
            {
                cout << s << '\n';
                s = "a";
            }

            continue;
        }

        int x = a[i];

        if (x >= s.size())
        {
            x -= s.size();
            while (x > 0)
            {
                x--;
                s += s.back();
            }
            cout << s << '\n';
        }
        else
        {
            // length cannot be less
            cout << s << '\n';
            if (s[x] == 'a')
            {
                s[x] = 'b';
            }
            else
            {
                s[x] = 'a';
            }
        }
    }

    if (a.back() == 0)
    {
        cout << "c\n";
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