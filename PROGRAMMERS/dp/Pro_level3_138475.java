package dp;

import java.util.*;

class Pro_level3_138475 {
    Point[] dp;
    public int[] solution(int e, int[] starts) {
        int[] answer = {};
        
        dp = new Point[e+1];
        
        for(int i=0; i<=e; i++){
            dp[i] = new Point(i, 0);
        }
        
        //배수 세기
        for(int i=1; i<=e; i++){ 
            for(int j=i; j<=e; j+=i){
                dp[j].c++;
            }
        }
        
        //약수의 개수가 큰 순서대로 정렬
        Arrays.sort(dp, new Comparator<Point>(){
            @Override
            public int compare(Point o1, Point o2){
                if(o1.c < o2.c) return 1;
                else if(o1.c > o2.c){
                    return -1;
                }
                else {
                //작은 숫자 반환
                    if(o1.num > o2.num) return 1;
                    else if(o1.num < o2.num) return -1;
                    else return 0;
                }
            }
        });          
        
        answer = new int[starts.length];
        for(int i=0; i<starts.length; i++){
            for(int j=0; j<=e; j++){
                if(starts[i] <= dp[j].num){
                    answer[i] = dp[j].num;
                    break;
                }
            }
        }
        
        return answer;
    }
    
    static class Point{
        int num, c;
        Point(int num, int c){
            this.num = num;
            this.c = c;
        }
    }
}
