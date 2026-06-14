class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        output = []
        for i in range(len(nums)):
            output.append(1)
        for i in range(len(nums)):
            j=0
            while j < len(nums):
                if i == j:
                    j+=1
                    if j == len(nums):
                        break 
                output[i] *= nums[j]
                j+=1
        return output
