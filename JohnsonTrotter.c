#include <stdio.h>
// -1 means left
int mobile(int p[], int d[], int n){
    int m = 0;
    for (int i = 0; i < n; i++) {
        if (d[i] == -1 && i > 0 && p[i] > p[i - 1] && p[i] > m)
            m = p[i];
        if (d[i] == 1 && i < n - 1 && p[i] > p[i + 1] && p[i] > m)
            m = p[i];
    }
    return m;
}

int main(){
    int n;
    int p[10], d[10];
    int i, m, pos, next, temp;
    scanf("%d", &n);
    for (i = 0; i < n; i++){
        p[i] = i + 1;
        d[i] = -1; 
    }

    while (1)
    {
        for (i = 0; i < n; i++){
            printf("%d ", p[i]);
        }

        printf("\n");
        m = mobile(p, d, n);
        if (m == 0)
            break;
        for (i = 0; i < n; i++)
            if (p[i] == m)
                pos = i;
        next = pos + d[pos];
        temp = p[pos];
        p[pos] = p[next];
        p[next] = temp;

        temp = d[pos];
        d[pos] = d[next];
        d[next] = temp;

        for (i = 0; i < n; i++)
            if (p[i] > m)
                d[i] = -d[i];
    }
    return 0;
}