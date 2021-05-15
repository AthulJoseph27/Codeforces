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

void getNextPermutation(vector<int> &c)
{
    int temp = c[0];

    // [ 1, 2, 3, 4 ]

    for (int i = 0; i < 3; i++)
        c[i] = c[i + 1];

    c[3] = temp;
}

void solve(int cc)
{
    int n;
    vector<int> c(4, 0);
    cin >> n;

    for (int i = 0; i < 4; i++)
        cin >> c[i];

    bool can = true; // can color up to n-2 colors independently

    for (int i = 0; i < 4; i++)
    {
        if (c[i] > n - 2)
        {
            can = false;
            break;
        }
    }

    if (can)
    {
        cout << "YES" << '\n';
        return;
    }

    int s = 0;

    // debug(c);
    vector<int> temp(4);

    for (int i = 0; i < 4; i++)
        temp[i] = c[i];

    do
    {
        can = true;
        for (int i = 0; i < 4; i++)
        {
            if (c[i] == 0)
                continue;

            int prev = i - 1;

            if (prev < 0)
                prev += 4;

            if (c[prev] > 0)
            {
                c[prev]--;
                c[i]--;
            }
        }

        for (int i : c)
            if (i > (n - 2))
            {
                can = false;
                break;
            }

        if (can)
        {
            cout << "YES" << '\n';
            return;
        }

        for (int i = 0; i < 4; i++)
            c[i] = temp[i];

        getNextPermutation(c);

        for (int i = 0; i < 4; i++)
            temp[i] = c[i];

        // debug(c);

        s++;

    } while (s <= 4);

    cout << "NO" << '\n';
    return;
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