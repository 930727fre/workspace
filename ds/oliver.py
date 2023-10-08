n = int(input())
a = [["⬛" if i == "1" else "⬜" for i in input().split()] for j in range(n)]
src0x, src0y, src1x, src1y = [int(i) for i in input().split()]
dst0x, dst0y, dst1x, dst1y = [int(i) for i in input().split()]
a[n - src0y - 1][src0x] = a[n - src1y - 1][src1x] = "🟩"
a[n - dst0y - 1][dst0x] = a[n - dst1y - 1][dst1x] = "🟥"
print("\n".join(["".join(i) for i in a]))