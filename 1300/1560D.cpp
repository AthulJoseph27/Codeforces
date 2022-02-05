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

int optimize(string s, ll p2)
{
    int moves = 0;

    string p2s = to_string(p2);
    stack<char> ssk, p2sk;

    for (int i = s.size() - 1; i >= 0; i--)
        ssk.push(s[i]);

    for (int i = p2s.size() - 1; i >= 0; i--)
        p2sk.push(p2s[i]);

    // debug(p2sk.top(), ssk.top());
    // debug(p2s);
    while (ssk.size() > 0 && p2sk.size() > 0)
    {
        if (ssk.top() != p2sk.top())
        {
            ssk.pop();
            moves++;
            continue;
        }

        ssk.pop();
        p2sk.pop();
    }

    // debug(ssk.size(), p2sk.size());

    // vi tmp;
    // while (!ssk.empty())
    // {
    //     tmp.push_back(ssk.top());
    //     ssk.pop();
    // }
    // // debug("ssk", tmp);
    // tmp.clear();
    // while (!ssk.empty())
    // {
    //     tmp.push_back(ssk.top());
    //     ssk.pop();
    // }
    // debug("p2sk", tmp);
    return moves + max(p2sk.size(), ssk.size());
}

void solve(int cc)
{
    string s;
    cin >> s;

    vl p2;

    /*
        9
        18
    */

    for (ll i = 0; i < 63; i++)
    {
        p2.push_back(1ll << i);
    }

    int ans = s.size() + 1;

    for (int i = 0; i < p2.size(); i++)
    {
        ans = min(ans, optimize(s, p2[i]));
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