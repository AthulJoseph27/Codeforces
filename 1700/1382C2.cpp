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

char get_char_at(string &a, int index, bool flipped, int l, int r)
{
    if (index == 0)
    {
        swap(l, r);
    }
    if (!flipped)
    {
        return a[r];
    }

    char ch = a[l];
    if (ch == '1')
        return '0';

    return '1';
}

void solve(int cc)
{
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;

    vi ans;

    string c = a;

    bool flipped = false;
    int len = -1;
    int l = 0, r = n - 1;

    for (int i = n - 1; i >= 0; i--)
    {
        if (get_char_at(a, i, flipped, l, r) != b[i])
        {
            if (get_char_at(a, 0, flipped, l, r) == b[i])
            {
                ans.push_back(1);
            }

            if (!flipped)
            {
                l++;
            }
            else
            {
                r--;
            }
            len = i + 1;
            flipped = !flipped;

            ans.push_back(i + 1);
        }
        else
        {
            if (flipped)
            {
                l++;
            }
            else
            {
                r--;
            }
        }
    }

    cout << ans.size() << ' ';
    for (int i : ans)
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