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

int queryCount = 0;

int query(int l, int r)
{
    queryCount++;
    cout << "? " << (l + 1) << ' ' << (r + 1) << '\n';
    cout.flush();

    int sm;

    cin >> sm;

    assert(sm != -1);

    return sm;
}

void solve(int cc, int n)
{
    int k;
    cin >> k;

    // is sum of a given range is odd, then no of ones in that range is also odd
    // similarly if the sum of a range is even , then the no of ones in that range is also even
    // also the query result reveals the no of ones in that range

    // do binary search, ask query in one range

    int s = 0, e = n - 1;

    int total_no_of_zeros = 0, no_of_zeros = 0;

    total_no_of_zeros = n - query(0, n - 1);

    // have to get rid of total_no_of_zeros - k , zeros

    int target = total_no_of_zeros - k;

    while (target > 0)
    {
        int mid = (s + e) / 2;

        int ones = query(mid, e);
        int zeros = (e - mid + 1) - ones;

        if (zeros > target)
        {
            s = mid;
            if ((s + e) / 2 == mid)
            {
                cout << "! " << (s + 1) << '\n';

                cout.flush();
                return;
            }
        }
        else if (zeros <= target)
        {
            target -= zeros;
            e = mid - 1;
        }
    }

    while (s < e)
    {
        int mid = (s + e) / 2;

        int ones = query(mid, e);
        int zeros = (e - mid + 1) - ones;

        // debug(zeros);

        if (zeros == 0)
        {
            e = mid - 1;
        }
        else if (zeros == 1)
        {
            s = mid;
            // debug(s, e);
            if (e == (s + 1))
            {
                int ones = query(e, e);
                if (ones == 0)
                {
                    cout << "! " << (e + 1) << '\n';

                    cout.flush();
                }
                else
                {
                    cout << "! " << (s + 1) << '\n';

                    cout.flush();
                }
                return;
            }
        }
        else
        {
            s = mid + 1;
        }
    }

    assert(s == e);

    cout << "! " << (e + 1) << '\n';

    cout.flush();
}

// [1,0,1,1,0,1]

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T, n;

    cin >> n >> T;

    for (int i = 0; i < T; i++)
    {
        solve(i + 1, n);
    }

    return 0;
}