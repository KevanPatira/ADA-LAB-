#include <stdio.h>

#define LEFT -1
#define RIGHT 1

int mobile(int p[], int d[], int n) {
    int maxMobile = 0,i;

    for ( i = 0; i < n; i++) {

        if (d[i] == LEFT &&
            i > 0 &&
            p[i] > p[i - 1] &&
            p[i] > maxMobile) {

            maxMobile = p[i];
        }

        if (d[i] == RIGHT &&
            i < n - 1 &&
            p[i] > p[i + 1] &&
            p[i] > maxMobile) {

            maxMobile = p[i];
        }
    }

    return maxMobile;
}

int main() {

    int i,n;

    printf("Enter value of n: ");
    scanf("%d", &n);

    int p[10], d[10];

    for (i = 0; i < n; i++) {
        p[i] = i + 1;
        d[i] = LEFT;
    }

    while (1) {
	
        for ( i = 0; i < n; i++) {
            printf("%d ", p[i]);
        }
        printf("\n");

        int m = mobile(p, d, n);

        if (m == 0)
            break;

        int pos = -1;

        for ( i = 0; i < n; i++) {
            if (p[i] == m) {
                pos = i;
                break;
            }
        }

        int next = pos + d[pos];

        int temp = p[pos];
        p[pos] = p[next];
        p[next] = temp;

        temp = d[pos];
        d[pos] = d[next];
        d[next] = temp;

        for (i = 0; i < n; i++) {
            if (p[i] > m) {
                d[i] = -d[i];
            }
        }
    }

    return 0;
}
