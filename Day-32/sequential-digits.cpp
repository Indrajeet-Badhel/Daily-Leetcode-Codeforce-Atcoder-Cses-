class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;

        string s = "123456789";
        string l = to_string(low);
        string h = to_string(high);

        for(int i = l.size(); i <= h.size(); i++) {
            for(int j = 0; j <= 9 - i; j++) {
                string n = s.substr(j, i);
                int num = stoi(n);
                if(num >= low && num <= high)
                    ans.push_back(num);
            }
        }

        return ans;
    }
};  /*class Solution:
    q = [*range(1, 10)]

    for x in q:
        d = x % 10
        if d < 9:
            q.append(x * 10 + d + 1)

    def sequentialDigits(self, l: int, h: int) -> list[int]:
        return [x for x in self.q if l <= x <= h]
        */