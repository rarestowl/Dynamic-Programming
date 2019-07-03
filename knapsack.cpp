void knapsack(){
    int n, w;
    cin>>n>>w;
    int a[n+1][w+1]={0};
    int wt[n], val[n];
    for(int i=0; i<n; i++)
        cin>>val[i];
    for(int i=0; i<n; i++)
        cin>>wt[i];
    for(int i=0; i<=n; i++){
        for(int j=0; j<=w; j++){
            if(i==0 || j==0)
                a[i][j]=0;
            else if(wt[i-1]>j)
                a[i][j]=a[i-1][j];
            else
                a[i][j]=max(a[i-1][j], val[i-1]+a[i-1][j-wt[i-1]]);
        }
    }
    cout<<a[n][w]<<endl;
}
