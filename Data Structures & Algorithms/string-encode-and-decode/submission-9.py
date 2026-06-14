class Solution:

    def encode(self, strs: List[str]) -> str:
        if not strs:
            return "!@#$%"
        str1 = ""
        str1 = str1 + strs[0]
        for i in range(1,len(strs)):
            str1 = str1 + "~" + strs[i]
        return str1
    def decode(self, s: str) -> List[str]:
        if s == "!@#$%":
            return []
        strs = [""]
        i = 0
        for char in s:
            if char != "~":
                strs[i] += char
            else:
                i+=1
                strs.append("")
        return strs