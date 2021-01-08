//该深度所对应的节点
Node path[MAX_LEN];//MAX_LEN取节点总数即可
int depth;//记录深度即每一次的深度
bool DFS(V)
{
    if(V 为终点)
    { 
        path[depth] = V;
        return true;
    }
    if(V 为旧点或已经访问过的点)
        return false;
    将V标记为旧点
    path[depth] = V;//该深度depth对应的结点V
    ++depth;//下一个邻接点的深度
    对V的每个邻接点U{
        if(DFS(U) == true)
            return true;
    }
    --depth;//上面的V走不到终点所有要把它排除（相当于回退）
    return false;
}
int main()
{
    将所有点都标记为新点
    depth = 0;
    if(DFS(起点))
    {//遍历每一步走的结点
        for(int i = 0;i <= depth;++i)
            cout<<path[i]<<endl;
    }
    return 0;
}