vector<string> allPalindromeSubstring(string S){
    int n = S.size();
    if(n == 0 ) return vector<string>();
    if(n == 1) return {S};
    bool mem[n][n];
    memset(mem,false, sizeof(mem));
    vector<string> res;

    for(int i = 0; i< n;i++){
        mem[i][i] = true;
        res.push_back(S[i]);
    }
    for(int i = 0;i<n-1;i++){
        if(S[i] == S[i+1]){
            mem[i][i+1] = true;
            res.push_back(S.substr(i,i+1));
        }
    }

    for(int length = 3;length<=n;length++){
        for(int i = 0; i < n-length+1;i++){
            int j = i + length - 1;
            if(mem[i+1][j-1] && S[i] == S[j]){
                mem[i][j] = true;
                res.push_back(S.substr(i,j));
            }
        }
    }
    return res;
}