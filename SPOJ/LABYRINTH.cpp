#include <iostream>
#include <stdio.h>
#include <stack>

using namespace std;

char board[1000][1005];
int maxi, posx, posy, n, m, vis[1000][1005];

void dfs(int i, int j, int k)
{
    vis[i][j] = 1;
    //cout<<"dfs "<<i<<" "<<j<<" "<<k<<endl;
    if(k>maxi)
    {
        posx = i;
        posy = j;
        maxi = k;
    }

    if(j+1<m && board[i][j+1]=='.' && vis[i][j+1]==0)
        dfs(i, j+1, k+1);

    if(j-1>=0 && board[i][j-1]=='.' && vis[i][j-1]==0)
        dfs(i, j-1, k+1);

    if(i-1>=0 && board[i-1][j]=='.' && vis[i-1][j]==0)
        dfs(i-1, j, k+1);

    if(i+1<n && board[i+1][j]=='.' && vis[i+1][j]==0)
        dfs(i+1, j, k+1);
}

int main()
{
    int t, i, j, ctr;
    cin>>t;
    while(t--)
    {
        cin>>m>>n;
        for(i=0; i<n; i++)
            scanf("%s", board[i]);

        for(i=0; i<n; i++)
            for(j=0; j<m; j++)
                vis[i][j] = 0;

        ctr = maxi = 0;
        for(i=0; i<n; i++)
        {
            for(j=0; j<m; j++)
            {
                if(board[i][j]=='.')
                {
                    posx = i;
                    posy = j;
                    dfs(i, j, 0);
                    ctr = 1;
                    break;
                }
            }
            if(ctr==1)
                break;
        }

        for(i=0; i<n; i++)
            for(j=0; j<m; j++)
                vis[i][j] = 0;
        dfs(posx, posy, 0);
        cout<<"Maximum rope length is "<<maxi<<".\n";
    }
    return 0;
}