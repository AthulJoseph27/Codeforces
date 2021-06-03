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

    string s;
    cin >> s;

    int count = 0;

    int last = -1, last_free = -1;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '*')
        {
            s[i] = 'x';
            last = i;
            count++;
            break;
        }
    }

    int end = -1;

    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == '*')
        {
            end = i;
            s[i] = 'x';
            count++;
            break;
        }
    }

    for (int i = last + 1; i < end; i++)
    {
        if (s[i] == '*')
        {
            if ((i - last) > k)
            {
                assert(last_free != -1);
                s[last_free] = 'x';
                count++;

                if ((i - last_free) > k)
                {
                    s[last_free] = 'x';
                    count++;
                    last = last_free;
                    last_free = -1;
                }
                else
                {
                    last = last_free;
                    last_free = i;
                }
            }
            if ((i - last) == k)
            {
                s[i] = 'x';
                last = i;
                count++;
            }
            else
            {
                last_free = i;
            }
        }
    }

    if ((end - last) > k)
        count++;

    cout << count << '\n';
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