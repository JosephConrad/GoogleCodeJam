#include "stdio.h"
#include "stdlib.h"
#include <vector>
#include <limits.h>
#include <queue>
#include <map>
#include <string>
#include <iostream>
#include <algorithm> 
#include <cmath>

int main() {
    int T, pancakesNo, pan;
    scanf("%d", &T);
    std::vector<int> v;

    for (int t = 0; t < T; t++) {
        scanf("%d", &pancakesNo);
        
        for (int i = 0; i < pancakesNo; i++) {
            scanf("%d", &pan);
            v.push_back(pan); 
        } 
        int best = 1000; 
        for (int i = 1; i <=1000; i++) {
            int current = i; 
            for (int j = 0; j < pancakesNo; j++) {
                current += (v[j] - 1) / i; 
            }
            best = std::min(best, current);
        }
        
        printf("Case #%d: %d\n", t+1, best);
        v.clear();
    }
}
