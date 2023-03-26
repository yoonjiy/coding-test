package shortest_path;

class Pro_level3_72413 {
    static int[][] cost;
    public int solution(int n, int s, int a, int b, int[][] fares) {
        int answer = Integer.MAX_VALUE;
        
        cost = new int[n+1][n+1];
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                cost[i][j] = 20000000; //200*100000
            }
            cost[i][i] = 0;
        }
        
        for(int[] f:fares){
            cost[f[0]][f[1]] = f[2];
            cost[f[1]][f[0]] = f[2];
        }
        
        //플로이드 워셜
        for(int k=1; k<=n; k++){
            for(int i=1; i<=n; i++){
                for(int j=1; j<=n; j++){
                    if(cost[i][j] > cost[i][k]+cost[k][j]){
                        cost[i][j] = cost[i][k]+cost[k][j];
                    }
                }
            }
        }
        
        for(int i=1; i<=n; i++){
            answer = Math.min(answer, cost[s][i]+cost[i][a]+cost[i][b]);
        }
        
        return answer;
    }
}