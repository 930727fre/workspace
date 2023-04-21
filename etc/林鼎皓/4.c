//1.3
int idx=0;
while(str[idx]!=0){
    idx++;
}
return idx-1;

//2.3
int temp=k+xStrlen(s);
while(temp!=k-1){
    s[temp]=s[temp-k];
}
while(k>=0){
    s[k]='*';
}

//3.3
int temp=k+xStrlen(s);
while(temp!=k-1){
    s[temp]=s[temp-k];
}
while(k>=0){
    s[k]='0';
}

//4.3
return c-'0'

//5.5
int charDigitSubtraction(char *s, const char a, const char b, const int barrow) {
    int result = (int)(a - '0') - (int)(b - '0') - barrow;
    if (result < 0) {
        result += 10;
        *s = (char)(result + '0');
        return 1;
    } else {
        *s = (char)(result + '0');
        return 0;
    }
}


//6.5
int isLess(const char a[], const char b[]) {
    int len_a = strlen(a);
    int len_b = strlen(b);
    
    // If a has fewer digits than b, a is less than b
    if (len_a < len_b) {
        return 1;
    }
    // If a has more digits than b, a is greater than b
    else if (len_a > len_b) {
        return 0;
    }
    // If a and b have the same number of digits, compare digit by digit
    else {
        for (int i = 0; i < len_a; i++) {
            if (a[i] < b[i]) {
                return 1;
            }
            else if (a[i] > b[i]) {
                return 0;
            }
        }
        // If all digits are equal, a is not less than b
        return 0;
    }
}
