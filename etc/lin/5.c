//A
call reverse s=[1]
call reverse s=[2]
call reverse s=[3]
call reverse s=[4]
call reverse s=[5]
call reverse s=[6]


//B
void reverseNonRec(const char* const sPtr) {
    int len = strlen(sPtr);
    for (int i = 0; i < len / 2; i++) {
        char temp = sPtr[i];
        sPtr[i] = sPtr[len - i - 1];
        sPtr[len - i - 1] = temp;
    }
    printf("%s", sPtr);
}
