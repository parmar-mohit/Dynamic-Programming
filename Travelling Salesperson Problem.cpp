#include <iostream>
#include <limits>
#include <vector>
#define INF 100

using namespace std;

int graph[INF][INF];

int solve( int N, int home, vector<int> set, int current = -1 )
{
    if( set.size() == 0 )
    {
        return graph[current][home];
    }

    if( current == -1 )
    {
        current = home;
    }

    int distance[set.size()];

    for( int i = 0; i < set.size(); i++ )
    {
        vector<int> set_new;
        for( int j = 0; j < set.size(); j++ )
        {
            if( j != i )
            {
                set_new.push_back( set[j] );
            }
        }
        distance[i] = graph[current][set[i]] + solve( N-1, home, set_new, set[i] );
    }


    int min_distance = distance[0];

    for( int i = 1; i < set.size(); i++ )
    {
        if( min_distance > distance[i] )
        {
            min_distance = distance[i];
        }
    }

    return min_distance;
}

int main()
{
    int N;

    cout << "Enter No of Cities to vist : ";
    cin >> N;

    int home;

    cout << "Enter Cost Of Edges in Matrix" << endl;
    for( int i = 1; i <= N; i++ )
    {
        for( int j = 1; j <= N; j++ )
        {
            cin >> graph[i][j];
        }
    }

    cout << "Enter Home city : ";
    cin >> home;

    vector<int> set;
    for( int i = 1; i <= N; i++ )
    {
        if( i != home )
        {
            set.push_back( i );
        }
    }

    cout << "The Minimum cost required to travel all cities would be " << solve( N, home, set ) << endl;

    return 0;
}
