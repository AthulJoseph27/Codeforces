/*
Recently a new building with a new layout was constructed in Monocarp's hometown. According to this new layout, the building consists of three types of apartments: three-room, five-room, and seven-room apartments. It's also known that each room of each apartment has exactly one window. In other words, a three-room apartment has three windows, a five-room — five windows, and a seven-room — seven windows.

Monocarp went around the building and counted n

windows. Now he is wondering, how many apartments of each type the building may have.

Unfortunately, Monocarp only recently has learned to count, so he is asking you to help him to calculate the possible quantities of three-room, five-room, and seven-room apartments in the building that has n

windows. If there are multiple answers, you can print any of them.

Here are some examples:

    if Monocarp has counted 30

windows, there could have been 2 three-room apartments, 2 five-room apartments and 2 seven-room apartments, since 2⋅3+2⋅5+2⋅7=30
;
if Monocarp has counted 67
windows, there could have been 7 three-room apartments, 5 five-room apartments and 3 seven-room apartments, since 7⋅3+5⋅5+3⋅7=67
;
if Monocarp has counted 4
windows, he should have mistaken since no building with the aforementioned layout can have 4 windows. 

Th first line contains one integer t (1≤t≤1000

) — the number of test cases.

The only line of each test case contains one integer n
(1≤n≤1000) — the number of windows in the building

For each test case, if a building with the new layout and the given number of windows just can't exist, print −1

.

Otherwise, print three non-negative integers — the possible number of three-room, five-room, and seven-room apartments. If there are multiple answers, print any of them.

*/
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

    for (int s = 0; s <= 143; s++)
    {
        for (int f = 0; f <= 201; f++)
        {
            for (int t = 0; t <= 334; t++)
            {
                int ans = t * 3 + f * 5 + s * 7;
                if (ans > n)
                    break;
                if (ans == n)
                {
                    cout << t << " " << f << " " << s << '\n';
                    return;
                }
            }
        }
    }
    cout << -1 << '\n';
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