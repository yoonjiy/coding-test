package etc.etc;

import java.util.*;

class Pro_level2_87946 {
    public int solution(int k, int[][] dungeons) {
        int answer = -1;
        // 유저가 탐험할수 있는 최대 던전 수를 return 
        
        int n = dungeons.length;
        //던전을 탐험하는 순열
        List<String> list = new ArrayList<>();
        dfs("", n, list);
        
        for(String s:list){
            int hp = k;
            int cnt = 0;
            for(int i=0; i<s.length(); i++){
                int d = s.charAt(i)-'0';
                if(hp < dungeons[d][0]) break;
                else{
                    hp -= dungeons[d][1];
                    cnt++;
                }
            }
            
            answer = Math.max(answer, cnt);
        }
        return answer;
    }
    
    public static void dfs(String s, int n, List<String> list){
        if(s.length()==n) {
            list.add(s);
            return;
        }
        
        for(int i=0; i<n; i++){
            if(!s.contains(String.valueOf(i))){
                dfs(s+String.valueOf(i), n, list);
            }
        }
    }
}