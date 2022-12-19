package etc;

import java.util.*;

class Pro_level2_138476 {
    public int solution(int k, int[] tangerine) {
        int answer = 0;
        // 귤 k개를 고를 때 크기가 서로 다른 종류의 수의 최솟값을 return
        
        HashMap<Integer, Integer> hm = new HashMap<>();
        for(int t:tangerine){
            hm.put(t, hm.getOrDefault(t, 0)+1);
        }
        
        List<Integer> valueList = new ArrayList<>(hm.values());
        Collections.sort(valueList, Collections.reverseOrder());
        
        for(int v:valueList){
            k -= v;
            answer++;
            if(k<=0){
                break;
            }
        }
        
        return answer;
    }
}