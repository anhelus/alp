base

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        i_1 = 0
        while i_1 < len(nums):
            for i_2 in range(i_1+1, len(nums)):
                if nums[i_1] + nums[i_2] == target:
                    return [i_1, i_2]
            i_1 = i_1 + 1

intermedio
