package 이분탐색;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

public class sof_1204_java {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] str = br.readLine().split(" ");
        int N = Integer.parseInt(str[0]);
        long B = Long.parseLong(str[1]);

        str = br.readLine().split(" ");
        int[] capacity = new int[N];
        for (int i = 0; i < N; i++) {
            capacity[i] = Integer.parseInt(str[i]);
        }

        Arrays.sort(capacity);

        long low = capacity[0]; 
        long high = capacity[N - 1] + (long)Math.sqrt(B);
        long answer = 0;
        while (low <= high) {
            long mid = (low + high) / 2;

            if (calculate(mid, capacity, B)) {
                low = mid + 1;
                answer = mid;
            } else {
                high = mid - 1;
            }
        }
        System.out.println(answer);
    }

    public static boolean calculate(long mid, int[] capacity, long B) {
        long total = 0;
        for (int c : capacity) {
            if (c < mid) {
                total += (mid - c) * (mid - c);
                if (total > B) return false;
            }
        }
        return true;
    }
}
