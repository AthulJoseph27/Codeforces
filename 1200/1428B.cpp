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
    int n;
    cin >> n;

    string s;
    cin >> s;

    // pick any node and try to travel back to it, if its not possible just count the no of '-'
    // through a cycle

    bool cycle = true;

    bool left = true;
    bool right = true;

    for (int i = 1; i <= n; i++)
    {
        if (s[i % n] == '-' || s[i % n] == '>')
            continue;
        else
        {
            left = false;
            break;
        }
    }

    for (int i = n - 2; i >= -1; i--)
    {
        int index = i;
        if (i < 0)
            index = i + n;

        if (s[index] == '-' || s[index] == '<')
            continue;
        else
        {
            right = false;
            break;
        }
    }

    cycle = right || left;
    int count = 0;

    if (cycle)
    {
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '>' || s[i] == '-')
                count++;
            else
            {
                int index = i - 1;
                if (index < 0)
                    index += n;

                if (s[index] == '<' || s[index] == '-')
                    count++;
            }
        }
        cout << count << '\n';
    }
    else
    {
        for (int i = 0; i < n; i++)
            if (s[i] == '-')
                count++;
            else
            {
                int index = i - 1;
                if (index < 0)
                    index += n;
                if (s[index] == '-')
                    count++;
            }

        cout << count << '\n';
    }
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