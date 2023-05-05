package etc.etc;
class Pro_level2_181187 {
    public long solution(int r1, int r2) {
        long answer = 0;
        //두 원 사이의 공간에 x좌표와 y좌표가 모두 정수인 점의 개수를 return
        
        for(int i=1; i<=r2; i++){
            //r2 안에 있는 점의 개수
            int max = (int)Math.floor(Math.sqrt((long)r2*r2 - Math.pow((long)i, 2)));
            int min = (int)Math.ceil(Math.sqrt((long)r1*r1 - Math.pow((long)i, 2)));
            
            answer += max-min+1;
        }
        
        answer *= 4;

        return answer;
    }
}