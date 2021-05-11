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
    // int n;
    // cin >> n;
    // string s;
    // cin >> s;

    // s += '.';

    // int index = -1;
    // int end = -1;
    // int st = -1;
    // int count = 0;
    // int max_count = 0;

    // for (int i = 0; i < s.size(); i++)
    // {
    //     if (st == -1 && s[i] == '*')
    //     {
    //         st = i;
    //         count++;
    //         continue;
    //     }
    //     if (s[i] == '*')
    //     {
    //         count++;
    //     }
    //     else
    //     {
    //         if (count > max_count)
    //         {
    //             max_count = count;
    //             index = st;
    //             end = i - 1;
    //         }
    //         st = -1;
    //     }
    // }

    // if (index == -1)
    // {
    //     cout << 0 << '\n';
    //     return;
    // }

    // // bring all other elements towards this

    // long long moves = 0;

    // int dots = 0;

    // for (int i = index - 1; i >= 0; i--)
    // {
    //     if (s[i] != '*')
    //     {
    //         dots++;
    //     }
    //     else
    //     {
    //         moves += dots;
    //     }
    // }

    // for (int i = end + 1; i < s.size(); i++)
    // {
    //     if (s[i] != '*')
    //     {
    //         dots++;
    //     }
    //     else
    //     {
    //         moves += dots;
    //     }
    // }

    // debug(index, end);

    // cout << moves << '\n';

    int n;
    cin >> n;
    string s;
    cin >> s;

    // move the sheeps to closer to the sheep which have equal number of sheeps left and right of it

    bool same = true;
    for (int i = 1; i < n; i++)
    {
        if (s[i] != s[i - 1])
        {
            same = false;
            break;
        }
    }

    if (same)
    {
        cout << 0 << '\n';
        return;
    }

    vector<int> prefs;
    vector<int> indicies;

    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '*')
        {
            prefs.push_back(count);
            indicies.push_back(i);
            count++;
        }
    }

    if (count == 1)
    {
        cout << 0 << '\n';
        return;
    }

    int center = -1;

    for (int i = 0; i < indicies.size(); i++)
    {
        if (count % 2 == 0)
        {
            if (prefs[i] == count / 2)
            {
                center = indicies[i];
                break;
            }
        }
        else
        {
            if (prefs[i] == (count - 1) / 2)
            {
                center = indicies[i];
                break;
            }
        }
    }

    assert(center != -1);

    // debug(center);
    // debug(s[center]);

    int dots = 0;

    long long moves = 0;

    for (int i = center + 1; i < s.size(); i++)
    {
        if (s[i] != '*')
        {
            dots++;
        }
        else
        {
            moves += dots;
        }
    }

    dots = 0;

    for (int i = center - 1; i >= 0; i--)
    {
        if (s[i] != '*')
        {
            dots++;
        }
        else
        {
            moves += dots;
        }
    }

    cout << moves << '\n';
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

long long max(long long a, long long b)
{
    if (a < b)
        return b;

    return a;
}