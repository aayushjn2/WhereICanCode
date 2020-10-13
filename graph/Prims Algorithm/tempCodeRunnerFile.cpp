int n,d;cin>>n>>d;
    vector<vector<pair<int,int>>> g(n);
    vector<vector<int>> points(n, vector<int>(d));
    for(int i = 0; i<n;i++){
        for(int j = 0;j<d;j++){
            cin>>points[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j = 0; j<n; j++){
            int w = cal(points[i], points[j], d);
            addEdge(g, i, j, w);
        }
    }
    primsMST(g, n);