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
    int n, k;
    cin >> n >> k;
    /*
        1 2 3 4 5               1 2 3 4
        A   B                   A     B
        5   1                   4     1
        4   2                   3     2
        3   4                   2     3
        2   5                   1     4
        1   2                   

        5   3
        4   5
        3   1
        2   3
        1   4
        
        5   1
        4   2
        3   4
        2   5
        1   2

        1 2 3 4 5 6 7

        A      B
        7      1
        6      2
        5      3
        4      5
        3      6
        2      7
        1      2

        7      3
        6      4
        5      6
        4      7
        3      1
        2      3
        1      4

        first collision at (n+1)/2 th position
        second collision at n
        third collision at n+ n//2
        fourth collision at 2*n - 1

        diff between collision , (n+1)/2 , (n-1)/2 , (n+1)/2 , (n-1)/2

        no of collision : 0 0 1 1 2 2 3 3 4  4  5  5  6  6  7  7  8  8  9  9 (5)  
        no of collision : 0 0 0 1 1 1 2 2 2 3  3  3  4  4  4  5  5  5  6  6 (7) 
        index no        : 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19

        After certain number, it will start repeating the pattern

        Cannot simulate the process.....

        if n is even, then the will be no collision


    */

    k--;

    if (n % 2 == 0)
    {
        cout << (k % n) + 1 << '\n';
    }
    else
    {
        int fr = n / 2;
        int no_of_collisions = k / fr;
        k += no_of_collisions;

        cout << (k % n) + 1 << '\n';
        return;
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