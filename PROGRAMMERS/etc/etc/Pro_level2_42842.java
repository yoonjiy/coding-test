package etc.etc;

class Pro_level2_42842 {
    public int[] solution(int brown, int yellow) {
        int[] answer = {};
        int total = brown+yellow;
        for(int i=3; i<=Math.sqrt(total); i++){
            int c = i;
            if(total%c!=0) continue;
            int r = total/c;
            
            if(brown==(2*r + 2*c - 4)){
                answer = new int[2];
                answer[0] = r;
                answer[1] = c;
                break;
            }
            
        }
        return answer;
    }
}