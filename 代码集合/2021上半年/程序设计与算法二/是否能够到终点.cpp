bool DFS(V)
{
    if(V 为终点)
        return true;
    if(V 为旧点或者已访问过的点)
        return false;
    将V标记为旧点或者已访问过的点
    V的每个邻接点U进行判断{
        //如果邻接点可以到达终点返回true
        if(DFS(U) == true)
            return true;
    }
    //如果操作执行结束还没有返回正确那么就说明找不到终点
    return false;
}
int main()
{
    将所有点都标记为新点
    起点 = 1；
    终点 = 8；
    cout<<DFS(起点);
    return 0;
}