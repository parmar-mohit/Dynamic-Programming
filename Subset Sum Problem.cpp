#include <iostream>

using namespace std;

bool solve( int set[], int N, int sum );

int main()
{
    int N;

    cout << "Enter no of integers in set : ";
    cin >> N;

    int set[N];
    int sum;

    cout << "Enter value of integers in set in sorted order : ";
    for( int i = 0; i < N; i++ )
    {
        cin >> set[i];
    }

    cout << "Enter the subset sum which is required : ";
    cin >> sum;

    if( solve( set, N, sum ) )
    {
        cout << "Subset of given set with required sum exist" << endl;
    }else
    {
        cout << "Subset of given set with required sum does not exist" << endl;
    }

    return 0;
}

bool solve( int set[], int N, int sum )
{
    bool dp[N][sum+1];

    for( int i = 0; i < N; i++ )
    {
        dp[i][0] = true;
    }

    for( int i = 1; i <= sum; i++ )
    {
        if( i == set[0] )
        {
            dp[0][i] = true;
        }else
        {
            dp[0][i] = false;
        }
    }

    for( int i = 1; i < N; i++ )
    {
        for( int j = 1; j <= sum; j++ )
        {
            if( j < set[i] )
            {
                dp[i][j] = dp[i-1][j];
            }else if( dp[i-1][j] == true )
            {
                dp[i][j] = true;
            }else
            {
                dp[i][j] = dp[i-1][j-set[i]];
            }
        }
    }

    return dp[N-1][sum];
}