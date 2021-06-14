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
        no of matches
        nC2 = n*(n-1)/2
        
        each team will have (n-1) matches

        if (n-1) is even, then a team can lose (n-1)/2 matches and win (n-1)/2 matches
        else 1 tie and (n-2)/2 wins and loses

        4       

        1 and 2 1          
        1 and 3 0
        1 and 4 -1

        2 and 3 1
        2 and 4 0

        3 and 4 1

        6

        1 - 2 , 2 - 2, 3 - 2, 4 - 2, 5 - 2, 6 - 2

        1 and 2  1
        1 and 3  1
        1 and 4  0
        1 and 5  -1
        1 and 6  -1

        2 and 3  1
        2 and 4  1
        2 and 5  0
        2 and 6  -1

        3 and 4  1
        3 and 5  1
        3 and 6  0

        4 and 5  1
        4 and 6  1

        5 and 6  1


    */

    if (n % 2 == 0)
    {
        // 1 tie and (n-2)/2 wins and loses for each team

        int t_wins = (n - 2) / 2;

        map<int, int> wins;
        map<int, int> draws;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (wins[i] < t_wins)
                {
                    wins[i]++;
                    cout << 1 << ' ';
                }
                else if (draws[i] == 0)
                {
                    draws[i]++;
                    cout << 0 << ' ';
                }
                else
                {
                    cout << -1 << ' ';
                }
            }
        }
    }
    else
    {
        map<int, int> points;
        // (n-1)/2 wins and (n-1)/2 loses
        for (int i = 0; i < n; i++)
        {
            int wins = (n - 1) / 2;
            int index = i + 1;

            while (points[i] < wins && index < n)
            {
                cout << 1 << ' ';
                points[i]++;
                points[index];
                index++;
            }

            while (points[i] > 0 && index < n)
            {
                cout << -1 << ' ';
                points[i]--;
                points[index]++;
                index++;
            }

            // assert(points[i] == 0);
        }
    }

    cout << '\n';
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