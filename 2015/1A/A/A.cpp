#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAX = 1000;

int tab[MAX];

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            int temp;
            scanf("%d", &temp);
            tab[i] = temp;
        }
        int diff;
        int biggestDrop = -1;
        int sum = 0;
        for (int i = 1; i < n; i++) {
            diff = tab[i-1] - tab[i]; 
            if (diff > biggestDrop) biggestDrop = diff;
            if (tab[i] < tab[i-1]) sum += diff;
        }
        int sum2 = 0;
        for (int i = 0; i < n-1; i++) {
            int diff = tab[i] - tab[i-1];
            sum2 += min(tab[i], biggestDrop);
        }
        printf("Case #%d: %d %d\n", t, sum, sum2);
    }

}
