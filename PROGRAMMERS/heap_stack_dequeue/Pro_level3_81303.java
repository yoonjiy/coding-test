package heap_stack_dequeue;

import java.util.*;

class Pro_level3_81303 {
    public String solution(int n, int k, String[] cmd) {
        String answer = "";
        
        //삭제 정보 스택에 관리
        Stack<Integer> s = new Stack<Integer>();
        
        int size = n;
        
        for(int i=0; i<cmd.length; i++){
            char c = cmd[i].charAt(0);
            
            if(c=='U'){ //X칸 위에 있는 행 선택
                k -= Integer.parseInt(cmd[i].substring(2));
            }
            else if(c=='D'){ //X칸 아래 있는 행 선택
                k += Integer.parseInt(cmd[i].substring(2));
            }
            else if(c=='C'){ //현재 선택 행 삭제
                s.add(k);
                size--;
                if(k==size){ //마지막 행을 가리키고 있었다면
                    k--;
                }
            }
            else if(c=='Z'){ //이전 삭제 행 복구
                if(s.pop()<=k){
                    k++;
                }
                size++;
            }
        }
        
        StringBuilder sb = new StringBuilder();
        for(int i=0; i<size; i++){
            sb.append("O");
        }
        
        while(!s.isEmpty()){
            sb.insert(s.pop(), "X");
        }
        
        answer = sb.toString();
        
        return answer;
        
    }
}
