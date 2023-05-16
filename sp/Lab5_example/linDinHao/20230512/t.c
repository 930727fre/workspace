#include <stdio.h>

void showArray(char *msg, int *arr, int n) {
    int i;
    printf("%s ", msg);
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void showf(int *p) {
    printf("a: p=%p, *p=%d, *(p++)=%d, *p=%d\n", p, *p, *(p++), *p);
}

int main(void) {
    int a[] = {0, 2, 4, 6, 8};
    int *p;
    int d;
    p = &a[0];
    printf("init, p=&a[0]:\n");
    showArray("a[]=", a, 5);
    printf("Address of array a, and the value of element at *p:\n");
    printf("case 1: *p++ or *(p++): value of expression is *p before increment; increment p later\n");
    d=*p++;
    printf("debug: d=*p++, d=%d, *p=%d, p=%p\n", d, *p, p);
    showArray("a[]=", a, 5);
    printf("\n");



    printf("case 2: (*p)++ or (*p)++: value of expression is *p before increment; increment *p later\n");
    d=(*p)++;
    printf("debug: d=(*p)++, d=%d, *p=%d, p=%p\n", d, (*p)++, p);
    showArray("a=[]", a, 5);
    printf("\n");


    printf("case 3: ***p or *(**p): Increment p first; value of expression is *p after increment\n");
    d=*++p;
    printf("debug: d=*++p, d=%d, *p=%d, p=%p\n", d, *p, p);
    showArray("a=[]", a, 5);
    printf("\n");


    printf("case 4: +**p or *p++: Increment *p first; value of expression is *p after increment\n");
    d=++*p;
    printf("debug: d=+**p, d=%d, *p=%d, p=%p\n", d, *p, p);
    showArray("a[]=", a, 5);
    printf("\n");

    return 0;
}


