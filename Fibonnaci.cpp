// This program prints Nth Fibonnaci term using Dynamic Programming

#include <iostream>
#include <mem.h>

using namespace std;

int fib( int x, int memo[] );

int main()
{
    int N;

    cout << "Enter a Number : ";
    cin >> N;

    int memo[N+1];
    memset( memo, -1, sizeof( memo ) );

    cout << N << "th Fibonnaci Number is : " << fib( N, memo ) << endl;

    return 0;
}

int fib( int x, int memo[] )
{
   int temp;

   if( memo[x] != -1 )
   {
       return memo[x];
   }else if( x == 0 || x == 1 )
   {
       temp = x;
   }else
   {
       temp = fib( x-1, memo) + fib( x-2, memo );
   }

   memo[x] = temp;
   return temp;
}
