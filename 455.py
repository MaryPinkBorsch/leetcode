

class Solution:
    def findContentChildren(self, g: list, s: list) -> int:
        g.sort()
        s.sort()
        p1 = 0
        p2 = 0
        res = 0
        while p1 < g.__len__():
            while p2 < s.__len__() and s[p2] < g[p1]:
                p2 += 1

            if p2 == s.__len__():
                return res
            else:
                res += 1
                p1 += 1
                p2 += 1

        return res
