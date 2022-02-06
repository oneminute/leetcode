#include <iostream>
#include <vector>
#include <string>
using namespace std;
 
// 构建结构体
struct list
{
	int x, y;
	struct list *next;
};
typedef struct list node;
typedef node* link;
link push(link path, int x, int y);
link pop(link path, int *x, int *y);
int chkExit(int x, int y, int ex, int ey);
// 路径加入新点
link push(link path, int x, int y)
{
	link newnode;
	newnode = new node;
	if (!newnode)
	{
		cout << "Error:内存分配失败！" << endl;
		return NULL;
	}
	newnode->x = x;
	newnode->y = y;
	newnode->next = path;
	path = newnode;
	return path;
}
// 路径弹出不通的点
link pop(link path, int *x, int *y)
{
	link top;
	if (path != NULL)
	{
        link temp=path;
		path = path->next;
		*x = path->x;
		*y = path->y;
        delete temp;
		return path;
	}
 
	return path;
}
// 到达终点
int chkExit(int x, int y, int ex, int ey)  
{
	if ((x == ex) && (y == ey))
	{
		return 1;
	}
	return 0;
}
 
int main()
{
    int row,col;
    int kernel[5] = {0, -1, 0, 1, 0};
    while(cin>>row>>col)
    {
        int**a=new int *[row];
        for(int i=0;i<row;++i)
        {
            a[i]=new int[col];
        }
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                cin>>a[i][j];
            }
        }
        link path = NULL;
        int x=0,y=0;
        path=push(path,x,y);
        while (x<row &&y<col)
        {
            a[x][y]=2;

            bool found = false;
            for (int k = 0; k < 4; k++)
            {
                int ky = y + kernel[k];
                int kx = x + kernel[k + 1];

                if (kx < 0 || kx >= row || ky < 0 || ky >= col) // 超限就进入下一个方向
                    continue;

                if (a[kx][ky] == 0)
                {
                    x = kx;
                    y = ky;
                    path = push(path, kx, ky);
                    found = true;
                    break;
                }
            }
            if (found)
                continue;

            // 判断是否到达终点
            if(chkExit(x, y, row-1, col-1) == 1)
            {
                break;
            }
            // 倒退
            path=pop(path,&x,&y);
        }
        vector<string> result;
        while(path!=NULL)
        {
            string p="("+to_string (path->x)+","+to_string (path->y)+")";
            result.push_back(p);
            path=path->next;
        }
        for(int i=result.size()-1;i>=0;--i)
        {
            cout<<result[i]<<endl;
        }
    }
 
    return 0;
}
