#include <stdio.h>

#define MAX 15

struct item {
    char name;
    int profit;
    int wt;
    float ratio;
} a[MAX];

void swap(struct item *a, int i, int j) {

    struct item temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

int partition(struct item *a, int st, int end) {

    float pivot = a[st].ratio;
    int i = st + 1;
    int j = end;

    while (1) {

        while (i <= end && a[i].ratio >= pivot)
            i++;

        while (j >= st && a[j].ratio < pivot)
            j--;

        if (i >= j)
            break;

        swap(a, i, j);
    }

    swap(a, st, j);

    return j;
}

void quickSort(struct item *a, int st, int end) {

    if (st >= end)
        return;

    int mid = partition(a, st, end);

    quickSort(a, st, mid - 1);
    quickSort(a, mid + 1, end);
}

void fillUp(struct item *a, int cap, int n) {
	int i;
    quickSort(a, 0, n - 1);

    float profit = 0.0;

    printf("\nSelected items: ");

    for ( i = 0; i < n && cap > 0; i++) {

        if (cap >= a[i].wt) {

            cap -= a[i].wt;
            profit += a[i].profit;

            printf("%c ", a[i].name);
        }
        else {

            float fraction = (float)cap / a[i].wt;

            profit += fraction * a[i].profit;

            printf("%c(%.2f%%) ", a[i].name, fraction * 100);

            cap = 0;
        }
    }

    printf("\nMaximum Profit = %.2f\n", profit);
}

int main() {

    int n,i, cap;

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter weight, profit and name respectively:\n");

    for (i = 0; i < n; i++) {

        scanf("%d", &a[i].wt);
        scanf("%d", &a[i].profit);
        scanf(" %c", &a[i].name);

        a[i].ratio =
            (float)a[i].profit / a[i].wt;
    }

    printf("Enter capacity: ");
    scanf("%d", &cap);

    fillUp(a, cap, n);

    return 0;
}
