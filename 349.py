

class Solution:
    def intersection(self, nums1: list, nums2: list) -> list:
        res = [] # а это массив
        map1 ={} # это unordered_map в Питоне
        map2 ={}

        for i in range(nums1.__len__()):
            map1[nums1[i]] = 1 

        for i in range(nums2.__len__()):
            map2[nums2[i]] = 1
        
        for item in map1.keys(): # это автоматическая проход по мапе по ключам! 
            if item in map2:
                res.append(item)
        
        return res
        