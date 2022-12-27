package bfs_or_dfs;

import java.util.*;

class Pro_level3_64046 {
    HashSet<HashSet<String>> ans = new HashSet<>();
    
    public int solution(String[] user_id, String[] banned_id) {
        int answer = 0;
        
        dfs(new LinkedHashSet<>(), user_id, banned_id);
        
        answer = ans.size();
        return answer;
    }
    
    public void dfs(HashSet<String> hs, String[] user_id, String[] banned_id){
        //조합 구하기
        if(hs.size()==banned_id.length){
            if(isBanned(hs, banned_id)){
                ans.add(new HashSet<>(hs));//ans.add(hs); -> 틀림
            }
            return;
        }
        for(String user:user_id){
            if(!hs.contains(user)){ 
                hs.add(user);
                dfs(hs, user_id, banned_id);
                hs.remove(user);
            }
        }
    }
    
    public boolean isBanned(HashSet<String> hs, String[] banned_id){
        //문자열 확인
        boolean check;
        int idx = 0;
        for(String user:hs){
            String bannedUser = banned_id[idx++];
            if(user.length()!=bannedUser.length()) return false;
            for(int i=0; i<bannedUser.length(); i++){
                if(bannedUser.charAt(i)=='*') continue;
                if(user.charAt(i)!=bannedUser.charAt(i)) return false;
            }
        }
        return true;
    }
}