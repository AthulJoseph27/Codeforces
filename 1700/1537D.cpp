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

    /*
        1) n is odd
        2) n is even and not power of 2
        3) n is even and power of 2

        1)
            we can substract only odd divisor, so n will be even in the next move which is not a
            power of 2
            n = 3^p1 * 5^p2 * .....
            D = 3^p1
            n-D = 3^p1 * (5^p2...... - 1) , so n will still be divisible by D
        
        2) the person who gets the odd number loses, coz, one can substract the even divisor and
            give the other person the odd number which will either be prime or the other person
            makes a move and give u even again
        
        3) if n is power of two , then
            2^1 => Bob
            2^2 => Alice
            2^3 => Bob .... so if power is odd, Bob wins

    */

    if (n % 2 != 0)
    {
        cout << "Bob\n";
        return;
    }

    if (n % 2 == 0)
    {
        int N = n;
        int p = 0;

        while (N % 2 == 0)
        {
            N /= 2;
            p++;
        }

        if (N == 1)
        {
            // power of two
            if (p % 2 != 0)
            {
                cout << "Bob\n";
            }
            else
            {
                cout << "Alice\n";
            }
        }
        else
        {
            cout << "Alice\n";
        }
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