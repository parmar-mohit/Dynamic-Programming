#include <iostream>
#include <mem.h>
#include <math.h>

using namespace std;

struct node
{
    int p;
    int w;
    float pw;
};

int solve( int N, int W, node x[] );
void quickSort( node A[], int start, int end );
int partition( node A[], int start, int end );

int main()
{
    int N;
    int W;

    cout << "Enter total no of items : ";
    cin >> N;

    node x[N];

    cout << "Enter weight of items : ";
    for( int i = 0; i < N; i++ )
    {
        cin >> x[i].w;
    }

    cout << "Enter Profit of items : ";
    for( int i =0; i < N; i++ )
    {
        cin >> x[i].p;
        x[i].pw = float( x[i].p ) / x[i].w;
    }

    cout << "Enter Maximum Weight that Knapsack Can hold : ";
    cin >> W;

    int profit = solve( N, W, x );
    cout << "Maximum Profit that can be made is : " << profit << endl;

    return 0;
}

int solve( int N, int W, node x[] )
{
    float fract[N];

    memset( fract, 0, sizeof( fract ) );

    quickSort( x, 0, N-1 );

    int i = N-1;
    while( W > 0 )
    {
        if( x[i].w < W )
        {
            fract[i] = 1;
            W -= x[i].w;
            i--;
        }else
        {
            int diff = x[i].w - W;
            fract[i] = float( x[i].w - diff ) / x[i].w;
            W = W - ( x[i].w - diff );
            i--;
        }
    }

    int profit = 0;
    for( int i = 0; i < N; i++ )
    {
        float temp = fract[i] * x[i].w * x[i].pw;

        if( int( ( temp * 10 ) ) % 10 > 5 )
        {
            profit += int ( ceil( temp ) );
        }else
        {
            profit += int( temp );
        }
    }

    return profit;
}

void quickSort( node A[], int start, int end )
{
    int pivot;
    if( start < end )
    {
        pivot = partition( A, start, end);
        quickSort( A, start, pivot - 1 );
        quickSort( A, pivot + 1, end );
    }
}

int partition( node A[], int ll, int ul )
{
    float pivot = A[ll].pw;

    int start = ll;
    int end = ul;

    while( start < end )
    {
        while( A[start].pw <= pivot )
        {
            start++;
        }
        while( A[end].pw > pivot )
        {
           end--;
        }

        if ( start < end )
        {
            node temp = A[start];
            A[start] = A[end];
            A[end] = temp;
        }
    }

    node temp = A[end];
    A[end] = A[ll];
    A[ll] = temp;

    return end;
}
