/*
DFS
*/
#include <iostream>
using namespace std;

const int MAXN = 110;
const int dx[5] = {0, 0, 0, 1, -1};
const int dy[5] = {0, 1, -1, 0, 0};

struct node
{
	int x, y;
};

int n = 4, min1;
node path[MAXN], pass[MAXN];
bool mark[MAXN][MAXN], vis[MAXN][MAXN];

void dfs(node v, int step)
{
	if(v.x == n && v.y == n)
	{
		if(step < min1)
		{
			min1 = step;
			for(int i=0; i<min1; i++)
			{
				path[i] = pass[i];
			}
		}
		return ;
	}
	for(int i=1; i<=4; i++)
	{
		int x = v.x + dx[i], y = v.y + dy[i];
		if(x >= 0 && y >= 0 && x <= n && y <= n && !vis[x][y] && !mark[x][y])
		{
			vis[x][y] = 1;
			pass[step] = (node){x, y};
			dfs((node){x, y}, step+1);
			vis[x][y] = 0;		
		}
	}
}

int main()
{
	for(int i=0; i<=n; i++)
	{
		for(int j=0; j<=n; j++)
		{
			cin >> mark[i][j];
		} 
	}
	vis[0][0] = pass[1].x = pass[1].y = 1;
	min1 = 0x3fff;
	dfs((node){0, 0}, 1);
	for(int i=0; i<min1; i++)
	{
		cout << '(' << path[i].x << ", " << path[i].y << ')' << endl;
	}
	return 0;
}
