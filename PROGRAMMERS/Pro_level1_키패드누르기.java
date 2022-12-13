class Pro_level1_키패드누르기 {
    public String solution(int[] numbers, String hand) {
        String answer = "";
        int leftIndex = 10;
        int rightIndex = 12;
    
        for(int num : numbers){
            if(num==1 || num==4 || num==7){
                answer += "L";
                leftIndex = num;
            }else if(num==3 || num==6 || num==9){
                answer += "R";
                rightIndex = num;
            }else{
                int leftDis = getLength(leftIndex, num);
                int rightDis = getLength(rightIndex, num);
                
                if(leftDis < rightDis){
                    answer += "L";
                    leftIndex = num;
                }
                else if(leftDis > rightDis){
                    answer += "R";
                    rightIndex = num;
                }
                else{
                    if(hand.equals("left")){
                        answer += "L";
                        leftIndex = num;
                    }
                    else {
                        answer += "R";
                        rightIndex = num;
                    }
                }
            }
        }
        
        return answer;
    }
    
    public int getLength(int index, int num){
        //0 -> 11로 치환
        index = (index==0) ? 11 : index;
        num = (num==0) ? 11 : num;
        
        //좌표 구하기
        int r = (index-1)/3;
        int c = (index-1)%3;
        int numR = (num-1)/3;
        int numC = (num-1)%3;
        
        return Math.abs(r-numR) + Math.abs(c-numC);
    }
}