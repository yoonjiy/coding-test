package two_pointer;
import java.util.*;

class Pro_level3_67258 {
    public int[] solution(String[] gems) {
        int[] answer = new int[2];
        //모든 보석을 하나 이상 포함하는 가장 짧은 구간
        
        //보석 종류의 총 개수를 저장하기 위한 set
        Set<String> gemSet = new HashSet<>();
        Collections.addAll(gemSet, gems);
        
        //보석의 종류, 개수를 저장하기 위한 map
        Map<String, Integer> gemMap = new HashMap<>();
        
        int gemCnt = gemSet.size();
        int len = gems.length;
        
        int distance = Integer.MAX_VALUE; //right-left 저장
        int left = 0, right = 0; //투 포인터
        int start = 0, end = 0; //정답
        
        while(true){
            if(gemCnt == gemMap.size()){ //left 이동
                String leftGem = gems[left];
                gemMap.put(leftGem, gemMap.get(leftGem)-1);
                if(gemMap.get(leftGem)==0){
                    gemMap.remove(leftGem);
                }
                left++;
            }
            else if(right==len) break;
            else{ //right 이동
                String rightGem = gems[right];
                gemMap.put(rightGem, gemMap.getOrDefault(rightGem, 0)+1);
                right++;
            }
            
            if(gemCnt == gemMap.size()){
                //answer 갱신
                if(right-left < distance){
                    distance = right-left;
                    start = left+1;
                    end = right;
                }
            }
        }
        
        answer[0] = start;
        answer[1] = end;
        
        return answer;
    }
}