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
    
    for (int i = 0; i < n; i++) {
        cards.clear();
        count();
        count();
        int result = 0; 
        for (auto& kv : cards) {
            if ((kv.second > 1) && (result == 0)) result = kv.first;
            else if ((kv.second > 1) && (result != 0)) {
                 result = -1;
                 break;
            }
        }
        printf("Case #%d: ", i+1);
        if (result > 0) 
            printf("%d\n", result);
        else if (result == 0)
            printf("Volunteer cheated!\n");
        else
            printf("Bad magician!\n");
    }
}


