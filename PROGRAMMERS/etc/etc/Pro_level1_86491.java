package etc.etc;

import java.util.*;

class Pro_level1_86491 {
    static List<int[]> temp;
    public int solution(int[][] sizes) {
        int answer = 0;
        //모든 명함을 수납할 수 있는 가장 작은 지갑을 만들 때, 지갑의 크기를 return 
        temp = new ArrayList<>();
        for(int[] s:sizes){
            int a = s[0];
            int b = s[1];
            if(a >= b){
                temp.add(new int[]{a, b});
            }
            else temp.add(new int[]{b, a});
        }
        
        Collections.sort(temp, (o1, o2)->(o2[0]-o1[0]));
        int a = temp.get(0)[0];
        
        Collections.sort(temp, (o1, o2)->(o2[1]-o1[1]));
        int b = temp.get(0)[1];   
        
        answer = a*b;
        return answer;
    }
}