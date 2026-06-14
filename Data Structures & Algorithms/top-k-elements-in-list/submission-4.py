class Solution:
    def isPresent(p,dic,n):
        for i in range(1,n+1):
            if p in dic[i]:
                return i
        return 0
        
    def promote(p,i,dic):
        dic[i].remove(p)
        dic[i+1].append(p)
        return dic

        
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        dic = {}
        for i in range(1,n+1):
            dic[i] = []
        for i in range(n):
            j = Solution.isPresent(nums[i],dic,n)
            if j:
                dic = Solution.promote(nums[i],j,dic)
            else:
                dic[1].append(nums[i])
        
        sol = []
        counter = 0
        for i in range(n,0,-1):
            for j in range(len(dic[i])):
                if counter == k:
                    return sol
                sol.append(dic[i][j])
                counter+=1
        return sol


        