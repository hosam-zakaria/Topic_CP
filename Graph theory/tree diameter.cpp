// tree diameter
pair<int, int> dfs0(int node, int par, int cnt)
{
    pair<int, int> ret = {cnt, node};
    for(auto child : g[node]) if(child != par)
        ret = max(ret, dfs0(child, node, cnt+1));
    return ret;
}

--------------------------------------------------
// dist Node 
ll distA[N + 1], distB[N + 1];
void dfs(ll node, ll par, ll d, ll dist[])
{
    dist[node] = d;
    for(auto child : adj[node])
        if(child != par)
            dfs(child, node, d + 1, dist);
}
    
