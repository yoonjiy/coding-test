package simulation;

class Pro_level2_77485 {
    int[][] map;
    public int[] solution(int rows, int columns, int[][] queries) {
        int[] answer = {};
        answer = new int[queries.length];
        //회전에 의해 위치가 바뀐 숫자들 중 가장 작은 숫자들을 순서대로 배열에 담아 return 
        map = new int[110][110];
        int idx = 1;
        map[0][0] = 0;
        for(int i=1; i<=rows; i++){
            for(int j=1; j<=columns; j++){
                map[i][j] = idx++; 
            }
        }
        
        for(int i=0; i<queries.length; i++){
            int num = turnRight(queries[i][0], queries[i][1], queries[i][2], queries[i][3]);
            answer[i] = num;
        }
        
        return answer;
    }
    
    public int turnRight(int r1, int c1, int r2, int c2){
        int temp = map[r1][c1];
        int minNum = temp;
    
        //위로 이동
        for(int i=r1; i<r2; i++){
            minNum = Math.min(minNum, map[i][c1]);
            map[i][c1] = map[i+1][c1];      
        }
        //왼쪽으로 이동
        for(int i=c1; i<c2; i++){
            minNum = Math.min(minNum, map[r2][i]);
            map[r2][i] = map[r2][i+1];
        }
        //아래로 이동
        for(int i=r2; i>r1; i--){
            minNum = Math.min(minNum, map[i][c2]);
            map[i][c2] = map[i-1][c2];
        }
        //오른쪽으로 이동
        for(int i=c2; i>c1; i--){
            minNum = Math.min(minNum, map[r1][i]);
            map[r1][i] = map[r1][i-1];
        }
        
        map[r1][c1+1] = temp;
        
        return minNum;
    }
}
