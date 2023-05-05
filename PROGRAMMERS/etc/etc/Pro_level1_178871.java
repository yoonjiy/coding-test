package etc.etc;

import java.util.*;

class Pro_level1_178871 {
    public String[] solution(String[] players, String[] callings) {
        String[] answer = {};
        //경주가 끝났을 때 선수들의 이름을 1등부터 등수 순서대로 배열에 담아 return
        answer = new String[players.length];
        Map<String, Integer> hm = new HashMap<>();
        for(int i=0; i<players.length; i++){
            hm.put(players[i], i);
        }
        
        for(String c:callings){
            int rank = hm.get(c);
            String temp = players[rank-1];
            //swap
            players[rank-1] = c;
            players[rank] = temp;
            
            //hm 변경
            hm.put(c, rank-1);
            hm.put(temp, rank);
        }
        
        answer = players;
        return answer;
    }
}