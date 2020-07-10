def wordBreak(self, s, wordDict):
    mem = [False for i in range(len(s)+1)]
    mem[0] = True
    for i in range(1,len(s)+1):
        for j in range(i-1,-1,-1):
            if mem[j] and s[j:i] in wordDict:
                mem[i] = True
    return mem[len(s)]