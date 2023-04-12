package two_pointer;
import java.util.*;

class Pro_level2_42885 {
    public int solution(int[] people, int limit) {
        int answer = 0;
        //모든 사람을 구출하기 위해 필요한 구명보트 개수의 최솟값을 return
        
        //사람 정렬
        Arrays.sort(people);
        
        int idx = 0; //가장 가벼운 사람
        int i = people.length-1;
        while(idx <= i){
            if(people[i] + people[idx] <= limit){
                answer++; 
                idx++;
                i--;
            }
            else{
                //무거운 사람 혼자 타야 함
                answer++;
                i--;
            }
        }
        
        return answer;
    }
}