def maxEnvelopes(self, envelopes: List[List[int]]) -> int:
    if not envelopes:
        return 0
    envelopes = sorted(envelopes,key=lambda envelop:(envelop[0],-1*envelop[1]))
    return self.LIS(envelopes)

def LIS(self,envelopes):
    lis = [1]*len(envelopes)
    res = 1
    for i in range(1,len(envelopes)):
        for j in range(0,i):
            if(envelopes[j][1] < envelopes[i][1] and lis[i]<lis[j]+1):
                lis[i] = lis[j]+1
        if res < lis[i]:
            res = lis[i]
    return res
