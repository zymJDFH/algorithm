class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(f(board,i,j,word,0)){
                    return true;
                }
            }
        }
        return false;
    }
    int f(vector<vector<char>>& board,int i,int j,string word ,int k){
        if(k==word.size()){
            return 1;
        }
        if(i<0||i==board.size()||j<0||j==board[0].size()||board[i][j]!=word[k]){
            return 0;
        }
        char temp =board[i][j];
        board[i][j] = 0;
		int ans = f(board, i - 1, j, word, k + 1) 
				|| f(board, i + 1, j, word, k + 1) 
				|| f(board, i, j - 1, word, k + 1)
				|| f(board, i, j + 1, word, k + 1);
		board[i][j] = temp;
		return ans;
    }
};