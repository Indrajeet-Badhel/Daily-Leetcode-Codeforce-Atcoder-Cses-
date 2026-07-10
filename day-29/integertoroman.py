class Solution:
    def intToRoman(self, num: int) -> str:
        thousands = ["", "M", "MM", "MMM"]
        hundreds = ["", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"]
        tens = ["", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"]
        ones = ["", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"]

        return (
            thousands[num // 1000] +
            hundreds[(num % 1000) // 100] +
            tens[(num % 100) // 10] +
            ones[num % 10]
        )


        """class Solution:
    def intToRoman(self, num: int) -> str:
        # List of Roman symbols with their values
        symList = [
            ("I", 1), ("IV", 4), ("V", 5), ("IX", 9),
            ("X", 10), ("XL", 40), ("L", 50), ("XC", 90),
            ("C", 100), ("CD", 400), ("D", 500), ("CM", 900),
            ("M", 1000)
        ]

        res = ""
        # Iterate from largest to smallest value
        for sym, val in reversed(symList):
            if num >= val:
                count = num // val
                res += sym * count
                num %= val
        return res


# Example usage:
sol = Solution()
print(sol.intToRoman(13))   # Output: XIII
print(sol.intToRoman(1994)) # Output: MCMXCIV
"""
class solution {
    public:

    string intToRoman(int num) {
        vector<pair<string,int>>val={
            {"M",1000},
            {"CM",900},
            {"D",500},
            {"CD",400},
            {"C",100},
            {"XC",90},
            {"L",50},
            {"XL",40},
            {"X",10},
            {"IX",9},
            {"V",5},
            {"IV",4},
            {"I",1}
        }
        string ans="";
        for(auto& it:val){
            int count=num/it.second;
            num%=it.second;
            while(count--){
                ans+=it.first;
            }
        }
        return ans;
    }
}