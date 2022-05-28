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

    int lc = 0;

    for (char c : s)
    {
        if (c == 'L')
            lc++;
    }

    if (k >= lc)
    {
        cout << ((n - 1) * 2 + 1) << '\n';
        return;
    }

    vector<pi> gaps;

    int st = 0;

    while (st < n && s[st] == 'L')
    {
        st++;
    }

    int en = n - 1;

    while (en >= 0 && s[en] == 'L')
    {
        en--;
    }

    for (int i = st; i <= en; i++)
    {
        if (s[i] == 'L')
        {
            int b = i;
            while (i <= en && s[i] == 'L')
            {
                i++;
            }
            gaps.push_back({b, i});
        }
    }

    sort(all(gaps), [&](const pi aa, const pi bb)
         { return (aa.second - aa.first) < (bb.second - bb.first); });

    for (auto p : gaps)
    {
        for (int i = p.first; i < p.second && k > 0; i++)
        {
            s[i] = 'W';
            k--;
        }
    }

    for (int i = en; i < n && k > 0; i++)
    {
        if (s[i] == 'L')
        {
            k--;
            s[i] = 'W';
        }
    }

    for (int i = st - 1; i >= 0 && k > 0; i--)
    {
        s[i] = 'W';
        k--;
    }

    int score = 0;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'W')
        {
            score++;
            if (i != 0 && s[i - 1] == 'W')
                score++;
        }
    }
    cout << score << '\n';
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

/*
    In a fully connected K-ary Tree
    parent of nth node is
    p = (n+k-2)/k
*/