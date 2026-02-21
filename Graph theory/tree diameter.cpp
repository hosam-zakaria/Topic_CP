// tree diameter
pair<int, int> dfs0(int node, int par, int cnt)
{
    pair<int, int> ret = {cnt, node};
    for(auto child : g[node]) if(child != par)
        ret = max(ret, dfs0(child, node, cnt+1));
    return ret;
}
