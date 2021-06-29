#define pb push_back
#define ff first
#define ss second
int Solution::snakeLadder(vector<vector<int>> &A, vector<vector<int>> &B)
{
    vector<int> graph[101];
    for (int i = 1; i <= 100; i++)
    {
        for (int j = i + 1; j <= 100 && j <= i + 6; j++)
            graph[i].pb(j);
    }
    set<int> ladder;
    for (int i = 0; i < A.size(); i++)
    {
        graph[A[i][0]].clear();
        graph[A[i][0]].pb(A[i][1]);
        ladder.insert(A[i][0]);
    }
    set<int> snake;
    for (int i = 0; i < B.size(); i++)
    {
        graph[B[i][0]].clear();
        graph[B[i][0]].pb(B[i][1]);
        snake.insert(B[i][0]);
    }
    queue<pair<int, int>> q;
    vector<int> moves(101, INT_MAX);
    q.push({1, 0});
    moves[1] = 0;
    while (q.size())
    {
        pair<int, int> pr = q.front();
        q.pop();
        int node = pr.ff;
        int moves_ = pr.ss;
        int newMoves = moves_ + 1;
        if (ladder.find(node) != ladder.end() || snake.find(node) != snake.end())
            newMoves--;
        for (int i = 0; i < graph[node].size(); i++)
        {
            int x = graph[node][i];
            if (moves[x] > newMoves)
            {
                q.push({x, newMoves});
                moves[x] = newMoves;
            }
        }
    }
    if (moves[100] == INT_MAX)
        return -1;
    return moves[100];
}
