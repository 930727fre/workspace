#include <stdio.h>
#include <string.h>

char *strrev(char *str){ // reverse the string
    char c, *front, *back;

    if(!str || !*str)
        return str;
    for(front=str,back=str+strlen(str)-1;front < back;front++,back--){
        c=*front;*front=*back;*back=c;
    }
    return str;
}

void addLargeIntegers(char a[], char b[]) {
    char ans[1000];
    int n = strlen(a);
    int m = strlen(b);

    // Reverse the strings
    strrev(a);
    strrev(b);

    int length = n > m ? n : m;
    int carry = 0;

    for (int i = 0; i < length; i++) {
        int num1 = (i < n) ? (a[i] - '0') : 0;
        int num2 = (i < m) ? (b[i] - '0') : 0;

        int sum = num1 + num2 + carry;

        ans[i] = (sum % 10) + '0';
        carry = sum / 10;
    }

    // If there is a carry after the last addition
    if (carry)
        ans[length++] = carry + '0';

    ans[length] = '\0';

    // Reverse the result to get the correct order
    strrev(ans);

    printf("%s\n", ans);
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        char a[1000], b[1000];
        scanf("%s %s", a, b);
        addLargeIntegers(a, b);
    }

    return 0;
}
