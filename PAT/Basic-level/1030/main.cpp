#include <iostream>
#include <algorithm>
using namespace std;

#define MAXSIZE 100005

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, imin, imax, maxcnt, array[MAXSIZE] = { 0 };
    long long p, mp;
    cin >> n >> p;
    for (int i = 0; i < n; ++i)
    {
        cin >> array[i];
    }
    sort(array, array + n);//默认从小到大排序
    mp = array[0] * p;
    imax = n - 1;
    for (int i = 0; i < n; i++) { //如果imax在之前的循环中没有得到更新，说明没有进入if语句，数组中的数都<=mp;
        if (array[i] > mp) {
            imax = i - 1;
            maxcnt = imax + 1;
            break;
        }
    }

    if (imax == n - 1) {
        maxcnt = n;
    }
    else {
        bool isupdate;  //进入if语句的标志，如果之后的数都<=mp,退出循环没有办法更新imax
        imin = 1;
        for (int i = imax + 1; i < n && imin < n; i++) {
            mp = array[imin] * p;
            isupdate = false;
            if (array[i] > mp) {
                imax = i - 1;
                maxcnt = maxcnt > (imax - imin + 1) ? maxcnt : (imax - imin + 1);
                imin++;
                isupdate = true;
            }
        }
        if (isupdate == false) {   //没有更新的话，说明imax=n-1
            maxcnt = n - 1 - imin + 1;
        }

    }
    cout << maxcnt;

    return 0;
} 