#include <stdio.h>
#include <string.h>
#define and &&
#define or ||
#define Pos(x, y) (pos){(x), (y)}
#define m_len 5005
#define q_len 200005
int a[m_len][m_len], walked[m_len][m_len], paths[m_len][m_len], p[q_len], ans[q_len],
dir[][3]= {{3, 0, 2}, [2]={[2]=1}}, idx, mx_idx = q_len;
typedef struct{
    int x, y;
} pos;
pos dir_rev[] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void find_path(pos src, pos now){  // 找路
    int x = now.x, y = now.y, d = paths[x][y], dx = dir_rev[d].x, dy = dir_rev[d].y;
    if(x == src.x and y == src.y) return;
    find_path(src, Pos(x - dx, y - dy));
    p[idx++] = d;
}

void bfs(pos src, pos dst){  // bfs
    printf("%d %d %d %d\n",src.x, src.y, dst.x, dst.y);
    pos q[q_len] = {src};
    int start = 0, end = 1;
    while (end > start){
        int x = q[start].x, y = q[start].y;
        if (x == dst.x and y == dst.y) return find_path(src, dst);
        for (int dx = -1; dx < 2; dx += 2) for (int dy = -1; dy < 2; dy += 2){
            int nx = x + (dx + dy) / 2, ny = y + (dx - dy) / 2;
            if (a[nx][ny] == walked[nx][ny]) {
                q[end++] = Pos(nx, ny);
                paths[nx][ny] = dir[dx + 1][dy + 1];
                walked[nx][ny] = 1;
            }
        }
        start++;
    }
    idx = 200005;
}

pos follow(pos src, pos dst, const int* path){  // 跟隨
    int x = src.x, y = src.y;
    for (int i = 0; i < idx; ++i) {
        int dx = dir_rev[path[i]].x, dy = dir_rev[path[i]].y, move = !a[x + dx][y + dy];
        x += dx * move, y += dy * move;
        if(x == dst.x and y == dst.y) return Pos(-1, i + 1);
    }
    return Pos(x, y);
}

pos unfollow(pos src, int idx_to, const int* path){
    int x = src.x, y = src.y;
    for (int i = idx - 1; i >= (idx = idx_to); --i) x -= dir_rev[path[i]].x, y -= dir_rev[path[i]].y;
    return Pos(x, y);
}

int main(){  // 主函式
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) scanf("%d", &a[j][n - i - 1]);
    pos src[2], dst[2], new0, new1;
    scanf("%d%d%d%d%d%d%d%d", &src[0].x, &src[0].y, &src[1].x, &src[1].y, &dst[0].x, &dst[0].y, &dst[1].x, &dst[1].y);
    for (int s = 0; s < 2; ++s) for (int d = 0; d < 2; ++d) {
        idx = 0;
        for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) walked[i][j] = 0;
        bfs(src[s], dst[d]);
        new0 = follow(src[!s], dst[d], p), new1 = follow(src[!s], dst[!d], p);
        if (new0.x != -1 and new1.x != -1) bfs(new0, dst[!d]);
        else if (new0.x == -1 and (new1.x != -1 or new0.y < new1.y)) bfs(unfollow(dst[d], new0.y, p), dst[!d]);
        if (idx < mx_idx) memcpy(ans, p, sizeof(int) * (mx_idx = idx));
    }

//    idx = 0;
//    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) walked[i][j] = 0;
//    bfs(src[0], dst[0]);
//    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) walked[i][j] = 0;
//    new0 = follow(src[1], dst[0], p), new1 = follow(src[1], dst[1], p);
//    if (new0.x != -1 and new1.x != -1) bfs(new0, dst[1]);
//    else if (new0.x == -1 and (new1.x != -1 or new0.y < new1.y)) bfs(unfollow(dst[0], new0.y, p), dst[1]);
//    memcpy(ans, p, sizeof(int) * (mx_idx = idx));
    for (int i = 0; i < mx_idx; ++i) printf("%d", ans[i]);
}