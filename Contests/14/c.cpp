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
    string s;
    cin >> s;

    int n = s.size();

    int team1 = 0, team2 = 0, q1 = 0, q2 = 0;
    int m1 = 0, m2 = 0;

    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            m1++;
            if (s[i] == '1')
            {
                team1++;
            }
            else if (s[i] == '?')
            {
                q1++;
            }
        }
        else
        {
            m2++;
            if (s[i] == '1')
            {
                team2++;
            }
            else if (s[i] == '?')
            {
                q2++;
            }
        }

        int left1 = n / 2 - m1;
        int left2 = n / 2 - m2;

        // debug(team2, team1 + left1 + q1);
        // debug(team1, team2 + left2 + q2);
        // debug(i + 1, "_____________________");

        if ((team2 + q2) > (team1 + left1))
        {
            cout << (i + 1) << '\n';
            return;
        }

        if ((team1 + q1) > (team2 + left2))
        {
            cout << (i + 1) << '\n';
            return;
        }
    }

    cout << 10 << '\n';
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