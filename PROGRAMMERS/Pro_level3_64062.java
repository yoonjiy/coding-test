class Pro_level3_64062 {
    public int solution(int[] stones, int k) {
        int answer = 0;
        
        //최대 몇 명까지 징검다리를 건널 수 있는지 - 이분탐색
        int left = 1; //건널 수 있는 친구들의 수
        int right = 200000000; 
        
        while(left<=right){
            int mid = (left+right)/2;
            
            //건널 수 없다면 친구들의 수 감소
            if(!check(stones, k, mid)){
                right = mid - 1;
            } else{ //건널 수 있다면 
                left = mid + 1;
                answer = Math.max(answer, mid);
            }
        }
        
        return answer;
    }
    
    //friends명의 친구들이 건널 수 있는지
    boolean check(int[] stones, int k, int friends){
        int skip = 0;
        for(int stone : stones){
            if(stone < friends){
                skip++; //건널 수 없음
            }
            else{
                skip = 0; //건널 수 있음
            }
            
            if(skip==k){
                return false;
            }
        }

        return true;
    }
}