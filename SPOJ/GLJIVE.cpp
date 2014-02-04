#include <iostream>
#include <iomanip>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sstream>
#include <math.h>
#include <limits.h>
#include <time.h>
#include <vector>
#include <utility>
#include <list>
#include <stack>
#include <queue>
#include <map>
#include <set>
using namespace std;

#define LIM_UI UINT_MAX
#define LIM_UL ULLONG_MAX

//iterations
#define repi(i,a,b) for(int i=a;i<=b;++i)
#define repd(i,a,b) for(int i=a;i>=b;--i)

int main(){
    int array[10], sum = 0;
    for (int i = 0; i < 10; ++i) {
        scanf("%d", &array[i]);
        sum += array[i];
        if (sum >= 100) {
            if (sum - 100 <= 100 - (sum-array[i])) printf("%d\n", sum);
            else printf("%d\n", sum-array[i]);
            return 0;
        }
    }
    printf("%d\n", sum);
    return 0;
}