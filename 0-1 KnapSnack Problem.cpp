#include <iostream>

using namespace std;

struct node
{
    int w;
    int p;
};

int solve( int N, int W, node x[] );
int max( int x, int y);

int main()
{
    int N;
    int W;

    cout << "Enter total no of Items : ";
    cin >> N;

    node x[N+1];

    cout << "Enter Weight of item in ascending order : ";
    for( int i = 1; i <= N; i++ )
    {
        cin >> x[i].w;
    }

    cout << "Enter profits of item in respective order : ";
    for( int i = 1; i <= N; i++ )
    {
        cin >> x[i].p;
    }

    cout << "Enter Maximum Weight that Knapsnack can hold : ";
    cin >> W;

    cout << "Maximum Profit that can be made is : " << solve( N, W, x ) << endl;

    return 0;
}

int solve( int N, int W, node x[] )
{
    int dp[N+1][W+1];
    int including, excluding;

    for( int i = 0; i <= W ; i++ )
    {
        dp[0][i] = 0;
    }

    for( int i = 0; i <= N; i++ )
    {
        dp[i][0] = 0;
    }

    for( int i = 1; i <=N; i++ )
    {
        for( int j = 1; j <= W; j++ )
        {
            if( j < x[i].w )
            {
                including = 0;
            }else
            {
                including = x[i].p + dp[i-1][j-x[i].w];
            }

            excluding = dp[i-1][j];

            dp[i][j] = max( including, excluding );
        }
    }

    return dp[N][W];
}

int max( int x, int y )
{
    if( x > y )
    {
        return x;
    }else
    {
        return y;
    }

}
