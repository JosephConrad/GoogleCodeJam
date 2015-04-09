#include "stdio.h"
#include "stdlib.h"
#include <vector>
#include <limits.h>
#include <queue>
#include <map>

std::map<int, int> cards; 

void count() {
    int m;
    scanf("%d", &m);
    int a;
    for (int j = 0; j < 4; j++) {
        for (int k = 0; k < 4; k++) {
            scanf("%d", &a);
            if (j == m-1)
                cards[a]++;
        }
    } 
}



int main() {
    int n;
    scanf("%d", &n);

    double C, F, X, lastTime, currentTime, factoryTime, cookieCount;


    for (int i = 0; i < n; i++) {
        scanf("%lf%lf%lf", &C, &F, &X);
           
        cookieCount = 2.0;
        factoryTime = 0.0;
        lastTime = currentTime = X/cookieCount;

        while (lastTime >= currentTime) {
            lastTime = currentTime; 
            factoryTime += C/cookieCount;
            cookieCount += F;
            currentTime = factoryTime + X/cookieCount;
        }
        printf("Case #%d: %lf \n", i+1, lastTime);
    }
}


