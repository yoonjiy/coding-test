// Created by strit on 2022-06-24. gold2 1300 k번째 수 - 이분 탐색
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>

using namespace::std;

long long n, k;
long long low, high, mid;
long long cnt;

long long count(long long mid)
{
    long long count = 0;
    for (int i = 1; i <= n; i++)
    {
        count += min(mid / i, n);
    }
    return count;
}

int main()
{
    cin >> n >> k;

    k = min((long long)1000000000, k);

    low = 1;
    high = n * n;

    while (low <= high)
    {
        mid = (low + high) / 2;

        cnt = count(mid); // Mid보다 작거나 같은 수들의 개수

        if (cnt >= k)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    cout << low;
}

