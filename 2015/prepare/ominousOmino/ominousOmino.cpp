#include <stdio.h>
#include <cmath>

int main() {
    int T, X, R, C;
    scanf("%d", &T);
    for (int t = 0; t < T; t++) {
        scanf("%d%d%d", &X, &R, &C);
        int size = R * C;
        if (C < R) std::swap(R, C);
        if (X == 1) 
            printf("Case #%d: GABRIEL\n", t + 1);
        else if ((X == 2) && (size % 2 == 0) )
            printf("Case #%d: GABRIEL\n", t + 1);
        else if ((X == 3) && (fmin(R,C) >= 2)  && (size % 3 == 0))
            printf("Case #%d: GABRIEL\n", t + 1);
        else if ((X == 4) && (fmin(R,C) >= 3)  && (size % 4 == 0))
            printf("Case #%d: GABRIEL\n", t + 1);
        else if ((X == 5) && (fmin(R,C) >= 3)  && (size % 5 == 0) && !(R == 3 && C == 5))
            printf("Case #%d: GABRIEL\n", t + 1);
        else if ((X == 6) && (fmin(R,C) >= 4)  && (size % 6 == 0))
            printf("Case #%d: GABRIEL\n", t + 1);
        else printf("Case #%d: RICHARD\n", t + 1);
    }
}
