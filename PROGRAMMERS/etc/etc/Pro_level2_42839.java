package etc.etc;

import java.util.*;

class Pro_level2_42839 {
    static int[] nums;
    static boolean[] visited;
    static Set<Integer> set;
    public int solution(String numbers) {
        int answer = 0;
        nums = new int[numbers.length()];
        // 종이 조각으로 만들 수 있는 소수가 몇 개인지 return 
        for(int i=0; i<numbers.length(); i++){
            nums[i] = numbers.charAt(i)-'0';
        }
        
        set = new HashSet<>();
        visited = new boolean[nums.length];
        dfs(nums, "");
        
        for(Integer s:set){
            if(isPrime(s)){
                answer++;
            }
        }
        return answer;
    }
    
    public static boolean isPrime(int p){
        if(p<2) return false;
        for(int i=2; i<=Math.sqrt(p); i++){
            if(p%i==0) return false;
        }
        return true;
    }
    
    public static void dfs(int[] nums, String num){
        
        if(num!="")
            set.add(Integer.parseInt(num));
        
        for(int i=0; i<nums.length; i++){
            if(visited[i]) continue;
            visited[i] = true;
            dfs(nums, num+nums[i]);
            visited[i] = false;
        }
    }
}