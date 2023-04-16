package etc.etc;

import java.util.*;

class Pro_level1_42840 {
    static int[] aa = {1, 2, 3, 4, 5};
    static int[] bb = {2, 1, 2, 3, 2, 4, 2, 5};
    static int[] cc = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    public int[] solution(int[] answers) {
        int[] answer = {};
        //가장 많은 문제를 맞힌 사람이 누구인지 배열에 담아 return 
        int[] cnt = new int[3];
        int aidx = 0, bidx = 0, cidx = 0;
        for(int ans:answers){
            if(ans==aa[aidx]) cnt[0]++;
            if(ans==bb[bidx]) cnt[1]++;
            if(ans==cc[cidx]) cnt[2]++;
            aidx = (aidx+1)%5;
            bidx = (bidx+1)%8;
            cidx = (cidx+1)%10;
        }

        int max = Math.max(cnt[0], Math.max(cnt[1], cnt[2]));
        
        List<Integer> list = new ArrayList<>();
        for(int i=0; i<3; i++){
            if(max==cnt[i]){
                list.add(i);
            }
        }
        
        answer = list.stream().mapToInt(i -> i+1).toArray();
        
        return answer;
    }
}
