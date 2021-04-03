#include <bits/stdc++.h>
using namespace std;

int rand(long long a, long long b)
{
    return a + rand() % (b - a + 1);
}

int main(int argc, char *argv[])
{
    srand(atoi(argv[1]));
    int n = rand(1, 1e12 + 5);
    int k = rand(1, n);
    printf("%d %d\n", n, k);
    // set<int> used;
    // for (int i = 0; i < n; ++i)
    // {
    //     int x;
    //     do
    //     {
    //         x = rand(1, 10);
    //     } while (used.count(x));
    //     printf("%d ", x);
    //     used.insert(x);
    // }
    puts("");
}