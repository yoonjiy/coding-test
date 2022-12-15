package greedy;

import java.util.*;

class Pro_level2_118667 {
    public int solution(int[] queue1, int[] queue2) {
        int answer = 0;
        // 각 큐의 원소 합을 같게 만들기 위해 필요한 작업의 최소 횟수
        Queue<Integer> q1 = new LinkedList<>();
        Queue<Integer> q2 = new LinkedList<>();
        
        long sum = 0;
        long q1_sum = 0;
        for(int i=0; i<queue1.length; i++){
            sum += queue1[i];
            sum += queue2[i];
            q1_sum += queue1[i];
            q1.add(queue1[i]);
            q2.add(queue2[i]);
        }
        
        long mid = sum/2;
        int cnt = queue1.length*3;
        
        while(q1_sum!=mid){
            if(cnt==0){
                return -1;
            }
            if(q1_sum > mid){
                int num = q1.poll();
                q1_sum -= num;
                q2.add(num);
                answer++;
            }
            else if(q1_sum < mid){
                int num = q2.poll();
                q1_sum += num;
                q1.add(num);
                answer++;
            }
            cnt--;
        }
        
        return answer;
    }
    
}
