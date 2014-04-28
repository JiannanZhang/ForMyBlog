/*Google Code Jam
  2013
  Round 1A
  Problem C. Good Luck
  Source: https://code.google.com/codejam/contest/2418487/dashboard#s=p2&a=2
  
  Written by: Annie Kim
  Solutions: ...
*/
#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <math.h>
using namespace std;
using namespace std::tr1;

int ri() { int a; scanf( "%d", &a ); return a; }
long long rll() { long long a; scanf( "%lld" , &a ); return a ; }

int main()
{
    freopen("C:\\Users\\Administrator\\Desktop\\C-small-practice-2.in","rt",stdin);
    freopen("C:\\Users\\Administrator\\Desktop\\C-small-practice-2.out","wt",stdout);

    int T = ri(), R = ri(), N = ri(), M = ri(), K = ri();
    printf("Case #1:\n");
    // pre-computation
    // all possible combinations
    vector<vector<int>> digits;
    vector<int> dig(N, 2);
    while (dig != vector<int>(N, M))
    {
        digits.push_back(dig);
        int i = N-1;
        while (dig[i] == M) i--;
        dig[i]++;
        for (int j = i + 1; j < N; j++)
            dig[j] = dig[i];
    }
    digits.push_back(dig);
    int total = digits.size();
    // possibilities of the combinations
    // 1. construct C
    double C[13][13];
    memset(C, 0, sizeof(C));
    C[0][0] = 1;
    for (int i = 1; i < 13; ++i)
    {
        C[i][0] = 1;
        for (int j = 1; j <= i; ++j)
            C[i][j] = C[i-1][j-1] + C[i-1][j];
    }
    // 2. prob
    vector<double> prob(total, 0);
    for (int i = 0; i < total; ++i)
    {
        vector<int> count(M+1, 0);
        for (int j = 0; j < N; ++j)
            count[digits[i][j]]++;
        double p = 0;
        int size = N;
        for (int j = 2; j <= M; ++j)
        {
            p += log(C[size][count[j]]);
            size -= count[j];
        }
        prob[i] = p;
    }
    // 3. products
    vector<unordered_map<long long, int>> products(total);
    for (int i = 0; i < total; ++i)
    {
        for (int mask = 1; mask < (1<<N); ++mask)
        {
            long long prod = 1;
            for (int j = 0; j < N; ++j)
                if (mask & (1<<j))
                    prod *= digits[i][j];
            products[i][prod] += 1;
        }
    }
    // test
    while (R--)
    {
        vector<int> test_products;
        for (int i = 0; i < K; ++i)
            test_products.push_back(rll());
        int res_i = 0;
        double resProb = INT_MIN;
        for (int i = 0; i < total; ++i)
        {
            double p = prob[i];
            for (int k = 0; k < K; ++k)
            {
                if (test_products[k] == 1) break;
                unordered_map<long long, int>::iterator it = products[i].find(test_products[k]);
                if (it != products[i].end())
                {
                    p += log((double)it->second);
                }
                else
                {
                    p = INT_MIN;
                    break;
                }
            }
            if (resProb < p)
            {
                res_i = i;
                resProb = p;
            }
        }
        for (int i = 0; i < digits[res_i].size(); ++i)
            printf("%d", digits[res_i][i]);
        printf("\n");
    }
    return 0;
}
