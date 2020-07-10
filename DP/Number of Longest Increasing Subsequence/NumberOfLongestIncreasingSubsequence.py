def findNumberOfLIS(self, nums: List[int]) -> int:
    if not nums:
        return 0
    n = len(nums)
    lis = [0]*n
    count = [1]*n
    for i in range(n):
        for j in range(i):
            if nums[j]<nums[i]:
                if lis[i]<=lis[j]:
                    lis[i] = 1+lis[j]
                    count[i] = count[j]
                elif lis[j]+1 == lis[i]:
                    count[i] += count[j]
    max_ = max(lis)
    return sum(count[i] for i in range(n) if lis[i]==max_)