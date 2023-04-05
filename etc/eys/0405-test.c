#include<stdio.h>
int toLower(char a) {
  return 'A'<=a&&a<='Z'?a-'A'+'a':a;
}
int isOneChar(char a1){ // a
  return toLower(a1)=='a';
}
int isTwoChars(char a1, char a2){ // an, at, by, in, of, on, or, to
  return toLower(a1)=='a'&&toLower(a2)=='n' ||
    toLower(a1)=='a'&&toLower(a2)=='t' ||
    toLower(a1)=='b'&&toLower(a2)=='y' ||
    toLower(a1)=='i'&&toLower(a2)=='n' ||
    toLower(a1)=='o'&&toLower(a2)=='f' ||
    toLower(a1)=='o'&&toLower(a2)=='n' ||
    toLower(a1)=='o'&&toLower(a2)=='r' ||
    toLower(a1)=='t'&&toLower(a2)=='o';
}
int isThreeChars(char a1, char a2, char a3){ // and, but, for, nor, off
  return toLower(a1)=='a'&&toLower(a2)=='n'&&toLower(a3)=='d' ||
    toLower(a1)=='b'&&toLower(a2)=='u'&&toLower(a3)=='t' ||
    toLower(a1)=='f'&&toLower(a2)=='o'&&toLower(a3)=='r' ||
    toLower(a1)=='n'&&toLower(a2)=='o'&&toLower(a3)=='r' ||
    toLower(a1)=='o'&&toLower(a2)=='f'&&toLower(a3)=='f' ||
    toLower(a1)=='t'&&toLower(a2)=='h'&&toLower(a3)=='e';
}
int isLowerToken(char token[], int len){ // is a lower token or not?
  return len==1 && isOneChar(token[0]) ||
    len==2 && isTwoChars(token[0], token[1]) ||
    len==3 && isThreeChars(token[0], token[1], token[2]);
}
void putCapital(char token[], int len){ // print out a captial word
  int i, c;
  c = token[0];
  putchar('a'<=c&&c<='z' ? c-'a'+'A' : c);
  for(i=1; i<len; ++i){
    c=token[i];
    putchar('A'<=c&&c<='Z' ? c-'A'+'a' : c);
  }
}
void putNormal(char token[], int len){
  int i, c;
  for(i=0; i<len; ++i){
    c=token[i];
    putchar('A'<=c&&c<='Z' ? c-'A'+'a' : c);
  }
}

int main() {
    char token[64];
    int c, len=0;

    int flag=1;

    while((c=getchar())!=EOF){
        if('a'<=c&&c<='z' || 'A'<=c&&c<='Z') {
            token[len++]=c;
        }else{
            if(flag){
                putCapital(token,len);
                flag=0;
            }
            else if(len<=3){
                putNormal(token,len);
            }
            else{
                putCapital(token,len);
            }
            printf(" ");
            len=0;



            }
        }
}