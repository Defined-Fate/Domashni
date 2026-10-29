# N-Queens problem

## N-Queens проблемот звучи вака:
  Даден број $n$, стави $n$ кралици во $n \times n$ хаковска табла така да нема да се напаѓаат

## Како работи алгоритамот
  Користиме backtracking за да ја решиме задачава.
   Главниот дел е функцијата `placeQueen` каде во неа се проверува дали може да се стави кралица ако може ставија, ако не продолжи на следното и ако ги има сите кралици ставено зачувај го решението.
   ```c++
     
     void placeQueens(int row, vector<vector<int>>& mat, vector<vector<int>>&result) {
        int n = mat.size();

        // base case: If all queens are placed
        if(row == n) {
        
            // store current solution
            vector<int> ans;
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(mat[i][j]){
                        ans.push_back(j + 1); //n^2
                    }
                }
            }
            result.push_back(ans);
            return;
        }

        // Consider the row and try placing
        // queen in all columns one by one
        for(int i = 0; i < n; i++){
        
            // Check if the queen can be placed
            if(isSafe(mat, row, i)){ //n
                mat[row][i] = 1; 
                placeQueens(row + 1, mat, result); //n
            
                // backtrack
                mat[row][i] = 0; 
            }
        }
    }
 ```
## Временска комплексност
   Нека $T(n)$ е временска комплексност на даден алгоритам таа се дефинира со рекурзивната равенка $T(n)=n\times T(n-1) + O(n)$. За алгоритамот `isSafe` добиваме временска комплексност од $O(n)$ што е објаснето во кодот. 
   Сега за `placeQueens` фукцијата првоит дел е $n^2$, а за рекурзивниот дел (ова е за ако имаме r кралици ставени на r колони тогаш имам r-n колони останато)

   |Длабочина | Максимални повици на placeQueens|
   |----------+---------------------------------|
   |         0|1                                |
   |         1|$n$                              |
   |         2|$n(n-1)$                         |
   |         3|$n(n-1)(n-2)$                    |
   |       ...|...                              |
   |         n|$n!$                             |
    
   Од што тотално е $n+n(n-1)+...+n! = n! \times (1/n! + 1/(n-1)! + ... + 1) \approx e \times n!$ кое може да го запишеме како $O(n!)$

   И сега по формулата $T(r) = (n-r) \times T(r+1)+n^2$ -> 
