#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

enum dir { leftptr, up, diag, null };

string solve( string s1, string s2 );

int main()
{
    string s1;
    string s2;

    cout << "Enter first string : ";
    cin >> s1;

    cout << "Enter second string : ";
    cin >> s2;

    cout << "Longest common subsequence is : " << solve( s1, s2 ) << endl;

    return 0;
}

string solve( string s1, string s2 )
{
    int x = s1.length();
    int y = s2.length();
    x++;
    y++;

    int dp[y][x];
    dir d[y][x];

    for( int i = 0; i < x; i++ )
    {
        dp[0][i] = 0;
        d[0][i] = null;
    }

    for( int i = 0; i < y; i++ )
    {
        dp[i][0] = 0;
        d[i][0] = null;
    }

    for( int i = 1; i < y; i++ )
    {
        for( int j = 1; j < x; j++ )
        {
            if( s2[i-1] != s1[j-1] )
            {
                if( dp[i-1][j] > dp[i][j-1] )
                {
                    dp[i][j] = dp[i-1][j];
                    d[i][j] = up;
                }else
                {
                    dp[i][j] = dp[i][j-1];
                    d[i][j] = leftptr;
                }
            }else
            {
                dp[i][j] = 1 + dp[i-1][j-1];
                d[i][j] = diag;
            }
        }
    }

    int len = dp[y-1][x-1];
    string rev;

    while( len )
    {
        if( d[y-1][x-1] == diag )
        {
            rev += s2[y-2];
            y--;
            x--;
            len--;
        }else if( d[y-1][x-1] == up )
        {
            y--;
        }else
        {
            x--;
        }
    }

    int start = 0;
    int end = rev.length() - 1;

    while( start < end )
    {
        char temp = rev[start];
        rev[start] = rev[end];
        rev[end] = temp;
        start++;
        end--;
    }

    return rev;
}
