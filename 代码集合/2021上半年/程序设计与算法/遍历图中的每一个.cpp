void DFS(V)
{
    if(V 是旧点)
        return;
    将V标记为旧点；
    for(遍历V的每个邻接点U){
        DFS(U);
    }
}
int main()
{
    将所有点都标记为新点
    for(遍历图中所有结点)
        if(如果该节点V没有访问)
            DFS(V);
    return 0;
}