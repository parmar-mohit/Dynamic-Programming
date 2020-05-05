//This program finds no of unique ways in which change can be given.

#include <iostream>

using namespace std;

int solve( int N, int deno[], int x );

int main()
{
    int N;
    int x;

    cout << "Enter the amount whoose change is required : ";
    cin >> N;

    cout << "Enter no of distinct value  of coins : ";
    cin >> x;

    int coin[x];

    cout << "Enter value of coins : ";
    for( int i = 0; i < x; i++ )
    {
        cin >> coin[i];
    }

    cout << "No of Unique ways of Giving Change is : " << solve( N, coin, x ) << endl;

    return 0;
}

int solve( int N, int coin[], int x )
{
    int dp[x][N+1];
    int including, excluding;

    for( int i = 0; i < x; i++ )
    {
        dp[i][0] = 1;
    }

    for( int i = 0; i < x; i++ )
    {
        for( int j = 1; j <= N; j++ )
        {
            if( j < coin[i] )
            {
                including = 0;
            }else
            {
                including = dp[i][j-coin[i]];
            }

            if( i > 0 )
            {
                excluding = dp[i-1][j];
            }else
            {
                excluding = 0;
            }

            dp[i][j] = including + excluding;
        }
    }

    return dp[x-1][N];
}