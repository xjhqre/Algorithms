#include<bits/stdc++.h>
using namespace std;

int xh = 1;        // 条块序号
int board[128][128]; // 地板大小

void floorBoard(int tr, int tc, int dr, int dc, int size)
{
    if (size == 1)
        return;
    int s = size / 2;
    int t = xh++;   //t记录当前条块序号

    // 判断黑砖是否在左上地板
    if (dr < tr + s && dc < tc + s)
    {
        floorBoard(tr, tc, dr, dc, s); //黑砖在左上地板的递归处理方法
    }
    else
    {
        board[tr + s - 1][tc + s - 1] = t;             // 用序号为t的条块覆盖右下角
        floorBoard(tr, tc, tr + s - 1, tc + s - 1, s); // 递归覆盖其余地板
    }

    // 判断黑砖是否在右上地板
    if (dr < tr + s && dc >= tc + s)
    {
        floorBoard(tr, tc + s, dr, dc, s);
    }
    else
    {
        board[tr + s - 1][tc + s] = t;
        floorBoard(tr, tc + s, tr + s - 1, tc + s, s);
    }

    // 判断黑砖是否在左下地板
    if (dr >= tr + s && dc < tc + s)
    {
        floorBoard(tr + s, tc, dr, dc, s);
    }
    else
    {
        board[tr + s][tc + s - 1] = t;
        floorBoard(tr + s, tc, tr + s, tc + s - 1, s);
    }

    // 判断黑砖是否在右下地板
    if (dr >= tr + s && dc >= tc + s)
    {
        floorBoard(tr + s, tc + s, dr, dc, s);
    }
    else
    {
        board[tr + s][tc + s] = t;
        floorBoard(tr + s, tc + s, tr + s, tc + s, s);
    }
}

int main()
{
    int boardSize;                 // 地板边长
    int n, m;                      //黑砖位置
    cout << "输入地板边长：" << endl;
    cin >> boardSize;
    cout << "输入黑砖位置：" << endl;
    cin >> n >> m;
    floorBoard(0, 0, n, m, boardSize); 

    // 打印地板
    printf("输出地板：\n");
    for (int i = 0; i < boardSize; i++)
    { 
        for (int j = 0; j < boardSize; j++)
        {
            printf("%d\t", board[i][j]);
        }
        printf("\n\n\n");
    }
    getchar();
    getchar();
    return 0;
}