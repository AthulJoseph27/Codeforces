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

class SegTree
{

public:
    int leftmost, rightmost;
    int setTo;
    SegTree *lChild, *rChild, *parent;

    SegTree(int leftmost, int rightmost, SegTree *parent, vector<SegTree *> &knights)
    {
        this->leftmost = leftmost;
        this->rightmost = rightmost;
        this->setTo = 0;
        this->parent = parent;

        if (leftmost == rightmost)
        {
            lChild = NULL;
            rChild = NULL;

            knights.push_back(this);
        }
        else
        {
            int mid = (leftmost + rightmost) / 2;

            lChild = new SegTree(leftmost, mid, this, knights);
            rChild = new SegTree(mid + 1, rightmost, this, knights);
        }
    }

    void rangeUpdate(int l, int r, int val)
    {
        if (l > r)
            return;

        if (l == leftmost && r == rightmost)
        {
            if (l == val || setTo != 0)
                return;

            setTo = val;
            return;
        }

        if (l >= leftmost && r <= rightmost)
        {

            if (setTo != 0)
                return;

            int mid = (leftmost + rightmost) / 2;

            if (l > mid)
            {
                rChild->rangeUpdate(l, r, val);
            }
            else if (r <= mid)
            {
                lChild->rangeUpdate(l, r, val);
            }
            else
            {
                lChild->rangeUpdate(l, mid, val);
                rChild->rangeUpdate(mid + 1, r, val);
            }
            return;
        }
    }

    void deleteChild()
    {
        if (lChild != NULL)
        {
            lChild->deleteChild();
            delete lChild;
        }
        if (rChild != NULL)
        {
            rChild->deleteChild();
            delete rChild;
        }
    }
};

vector<SegTree *> knights;

void solve(int cc)
{
    int n, m;

    cin >> n >> m;

    SegTree *T = new SegTree(1, n, NULL, knights);

    vector<int> ans(n + 1, 0);
    vector<int> winners;

    for (int i = 0; i < m; i++)
    {
        int l, r, x;
        cin >> l >> r >> x;
        T->rangeUpdate(l, x - 1, x);
        T->rangeUpdate(x + 1, r, x);
        winners.push_back(x);
    }

    ans[winners.back()] = 0;

    for (int i = 1; i <= n; i++)
    {
        if (i == winners.back())
            continue;

        if (ans[i] == 0)
        {
            SegTree *x = knights[i - 1];
            while (x != NULL && x->setTo == 0)
            {
                x = x->parent;
            }
            assert(x != NULL);
            ans[i] = x->setTo;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << ' ';
    }

    cout << '\n';

    T->deleteChild();

    delete T;

    /*
        8 4
        3 5 4
        3 7 6 -> set the range 3-5 and 7-7 with 6 ... if not set
        2 8 8
        1 8 1
        
        1 2 3 4 5 6 7 8
        0 8 4 6 4 8 6 1

        // given a range, set all those who r not yet set to the given number
    */
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve(1);

    return 0;
}