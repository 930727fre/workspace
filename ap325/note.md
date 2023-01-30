# note: ap325
# Chap 0
## 測試資料
stdin, stdout預設使用鍵盤與螢幕輸入輸出
但可利用 .in 與 .out來取代鍵盤與螢幕

方法一：
```
./a.out <test.in test.out>
```
a.out為執行檔，test.in為輸入，test.out為輸入

方法二：
程式碼加入以下兩行
```
freopen("test.in","r",stdin);
freopen("test.out","w",stdout);
```
## complexity and big o
### rounding error of float
When a float is being stored, rounding error(捨位誤差) may occur.
e.g. 2/3=0.66666...
Thus when comparing a float,we should check whether abs(float-val) is within a specific range instead of using == operator