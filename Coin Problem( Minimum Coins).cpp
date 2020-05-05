//This program finds minimum no of coins in which change can be given in which change can be given.

#include <iostream>
#include <limits>

using namespace std;

int solve( int N, int deno[], int x );
int min( int x, int  y );

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

    cout << "Minimum no of coins required for giving change is : " << solve( N, coin, x ) << endl;

    return 0;
}

int solve( int N, int coin[], int x )
{
    int dp[x][N+1];
    int including, excluding;

    for( int i = 0; i < x; i++ )
    {
        dp[i][0] = 0;
    }

    for( int i = 0; i < x; i++ )
    {
        for( int j = 1; j <= N; j++ )
        {
            if( j < coin[i] )
            {
                dp[i][j] = dp[i-1][j];
            }else
            {
                including = 1 + dp[i][j-coin[i]];
                if( i > 0 )
                {
                    excluding = dp[i-1][j];
                }else
                {
                    excluding = numeric_limits<int>::max();
                }

                dp[i][j] = min( including, excluding );
            }
        }
    }

    return dp[x-1][N];
}

int min( int x, int y )
{
    if( x < y )
    {
        return x;
    }else
    {
        return y;
    }
}
