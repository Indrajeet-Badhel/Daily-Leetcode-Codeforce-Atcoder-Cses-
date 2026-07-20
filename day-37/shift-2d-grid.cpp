/*mathematical mapping*/
class Solution {
public:
    
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n=size(grid);
        int m=size(grid[0]);

        vector<vector<int>>result(n, vector<int>(m));
        auto gridtoarr =[&](int r,int c){
            return r*m+c;
        };
        auto arrtogrid =[&](int pos){
            return vector<int>{pos/m,pos%m};
        };
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int val=(gridtoarr(i,j)+k)%(n*m); //we are just assuming that we made an arr but we didnt we passed the value 
                vector<int>newarrpos=arrtogrid(val);
                int r=newarrpos[0];
                int c=newarrpos[1];
                result[r][c]=grid[i][j];
            }
        }
        return result;

    }
};
/*flattening and than recversing */
/*class Solution {
public:
    // Please upvote if you like my solution :)
void reverse(vector<int> &nums,int start,int end){
        for(int i=start,j=end;i<j;i++,j--){
            swap(nums[i],nums[j]);
        }
    }
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int ro = grid.size();
        int col = grid[0].size();
        vector<int> v;
        for(auto &gri:grid){
            for(auto &val:gri){
                v.push_back(val);
            }
        }
        k = k % v.size();
        reverse(v,0,v.size()-k-1);
        reverse(v,v.size()-k,v.size()-1);
        reverse(v,0,v.size()-1);
        int vec = 0;
        for(int i=0;i<ro;i++){
            for(int j=0;j<col;j++){
                grid[i][j] = v[vec];
                vec++;
            }
        }
        return grid;
    }
// Please upvote if you like my solution :)
};*/