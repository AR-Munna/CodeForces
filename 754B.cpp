#include<bits/stdc++.h>
using namespace std;

char s[5][5];

int flag = 0;

int isPossible()
{

    for(int i=1; i<=4; i++)
    {
        for(int j=1; j<=4; j++)
        {
            if(s[i][j]=='.')
            {
                if(s[i][j+1]=='x' && s[i][j+2]=='x') flag=1;

				else if(s[i][j-1]=='x' && s[i][j+1]=='x') flag=2;

				else if(s[i][j-1]=='x' && s[i][j-2]=='x') flag=3;

				else if(s[i+1][j]=='x' && s[i+2][j]=='x') flag=4;

				else if(s[i-1][j]=='x' && s[i+1][j]=='x') flag=5;

				else if(s[i-1][j]=='x' && s[i-2][j]=='x') flag=6;

				else if(s[i+1][j-1]=='x' && s[i+2][j-2]=='x') flag=7;

				else if(s[i+1][j-1]=='x' && s[i-1][j+1]=='x') flag=8;

				else if(s[i-1][j+1]=='x' && s[i-2][j+2]=='x') flag=9;

				else if(s[i+1][j+1]=='x' && s[i+2][j+2]=='x') flag=10;

				else if(s[i-1][j-1]=='x' && s[i+1][j+1]=='x') flag=11;

				else if(s[i-1][j-1]=='x' && s[i-2][j-2]=='x') flag=12;
            }
        }
    }

    return flag;
}

main()
{
    for(int i=1; i<=4; i++)
    {
        for(int j=1; j<=4; j++) cin>>s[i][j];
    }

    if(isPossible()) cout<<"YES"<<endl;

    else cout<<"NO"<<endl;

    return 0;
}
