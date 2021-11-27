// 给出一个矩阵，要求每行只能选一个节点，每列选的节点不能超过所有选的节点的一半，不能不选，
// 给出每个节点的选择方案数，求总方案数

int n, m;
int a[103][2003];
int use[103][2003];
void dfs (int x) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= a[x][i]; j++)
            use[x][i] = j; 
        use[]
    }
}

int main () {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &a[i][j]);
    
    return 0;
}