package bfs_or_dfs.bfs_or_dfs;

import java.util.*;

class Pro_level2_84512 {
    static List<String> words;
    static char[] alpha = {'A', 'E', 'I', 'O','U'};
    public int solution(String word) {
        int answer = 0;
        words = new ArrayList<>();
        //사전에서 몇 번째 단어인지 return
        dfs("");
        
        Collections.sort(words);
        
        answer = words.indexOf(word)+1;
        
        return answer;
    }
    
    static void dfs(String w){
        if(w.length()==5){
            return;
        }
        
        for(int i=0; i<5; i++){
            words.add(w+alpha[i]);
            dfs(w+alpha[i]);
        }
         
    }
}
