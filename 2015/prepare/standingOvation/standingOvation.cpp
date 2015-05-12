#include "stdio.h"
#include "stdlib.h"
#include <vector>
#include <limits.h>
#include <queue>
#include <map>
#include <string>
#include <iostream>


void printVector(std::vector<int> shynessLevel, int maxShyness) {
    for (int i = 0; i <= maxShyness; i++) 
        std::cout << shynessLevel[i] << "\t";
    std::cout << std::endl;
}

int main() {
    int T;
    scanf("%d", &T);
    std::vector<int> shynessLevel;
    
    int result, maxShyness;
    for (int t = 0; t < T; t++) {
        result = 0;
        scanf("%d",&maxShyness);
        char c;
        getchar();

        for (int i = maxShyness; i >= 0; i--) {
            c = getchar();
            shynessLevel.push_back(int(c) - 48);
        }
        
        if (shynessLevel[0] == 0) {
            shynessLevel[0] = 1;
            result++; 
        }       
        for (int i = 1; i <= maxShyness; i++) {
            shynessLevel[i] += shynessLevel[i-1];
            if (shynessLevel[i] < i + 1) {
                shynessLevel[i] = i+1;
                result++; 
            }
        }
        
        printf("Case #%d: %d\n", t+1, result);
        shynessLevel.clear();
    }
}
