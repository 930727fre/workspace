#include <bits/stdc++.h>
int eval()
{
    int val, x, y, z;
    char token;
    scanf("%d", &token);
    if (token == 'f')
    {
        x = eval();
        return 2 * x - 1;
    }
    else if (token == 'g')
    {
        x = eval();
        y = eval();
        return x + 2 * y - 3;
    }
    else
    {
        return atoi(token);
    }
}
int main()
{
    printf("%d\n", eval());
    return 0;
}