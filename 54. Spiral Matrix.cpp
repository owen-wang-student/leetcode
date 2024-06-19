class Solution {
    public:
        vector<int> spiralOrder(vector<vector<int>>& matrix) {
            vector<int> result;
            int rows = matrix.size();
            int cols = matrix[0].size();
            int sr = 0;
            int sc = 0;
            int er = rows - 1;
            int ec = cols - 1;

            while(result.size() < rows * cols){
                // l -> r
                for(int c = sc; c <= ec; c++){
                    result.push_back(matrix[sr][c]);
                }
                // u -> d
                for(int r = sr + 1; r <= er; r++){
                    result.push_back(matrix[r][ec]);
                }
                // r -> l
                if(sr != er){
                    for(int c = ec - 1; c >= sc; c--){
                        result.push_back(matrix[er][c]);
                    }
                }
                // d -> u
                if(sc != ec){
                    for(int r = er-1 ; r > sr; r--){
                        result.push_back(matrix[r][sc]);
                    }
                }
                sc++;
                sr++;
                ec--;
                er--;
            }

            return result; 
        }
};