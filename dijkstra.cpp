# include <bits/stdc++.h>
using namespace std;
int n,m;
vector <pair <int,int> > g[105]; /// ����� ����� (v, g[v].first) � ����� g[v].second;
int d[105];
bool solved[105];
void dijkstra()
{
    priority_queue <pair <int, int> > pq; /// .first �� � ������ �� ���� ( � ���. ����, ������ ������ �� �� ���� �����������),
                                          /// .second � �����, �� ����� � ���� ���
    pq.push({0,1}); /// ������������ �������� ���� ���� �� 1

    while( !pq.empty() )
    {
        auto [dist, v] = pq.top(); /// ������� ���� v, � ���-����� ���� �� ���� (dist) � ��������
        pq.pop();
        if( solved[v] ) continue; /// ������� ������� ���� solved[v] = 0

        solved[v] = 1;

        for( auto [u,w] : g[v] )
        {
            if ( solved[u] ) continue; /// ��� ���� � �������� ���� ���� �� �� ���������� � ����
            if ( d[u] > d[v] + w)
            {
                d[u] = d[v] + w;
                pq.push({-d[u],u}); /// � ������� ����, ������ ������ ��������� �� �� ����
            }
        }
    }
}
int main()
{
    cin>>n>>m;
    int i,u,v,w;
    for(i = 1; i <= m; i++)
    {
        cin>>u>>v>>w;
        g[v].push_back({u,w});
        g[u].push_back({v,w});
    }

    for(i = 1; i <= n; i++)
        d[i] = INT_MAX;
    d[1] = 0;
    for(i = 1; i <= n; i++)
        solved[i] = 0;

    dijkstra();

    for(i = 1; i <= n; i++)
    {
        cout<<"1 - "<<i<<" : "<<d[i]<<endl;
    }
    return 0;
}
/*
8 10
1 2 5
2 4 1
4 3 3
2 3 4
3 7 2
7 8 2
7 6 1
6 5 2
1 3 7
1 5 1
*/
