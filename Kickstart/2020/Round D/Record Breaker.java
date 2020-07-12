// "Hakino-Matata: DEVANG SHARMA, GDG SINGAPORE"

import java.util.*;
import java.io.*;

public class Solution {

    private static final Scanner _in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));

    private static int solve() {
        final int N = _in.nextInt();
        _in.nextLine();
        int[] V = new int[N+2];
        V[0] = -1;
        for (int i = 0; i < N; i++) {
            V[i+1] = _in.nextInt();
        }
        V[N+1] = -1;

        int max = -1;
        int solution = 0;
        int prev = -1, curr;
        boolean asc = true;
        for (int i = 0; i < N+2; i++) {
            curr = V[i];
            if (asc && curr < prev && max < prev) {
                solution++;
                max = prev;
            }
            asc = curr > prev;
            prev = curr;
        }

        return solution;
    }

    public static void main(String[] args) {
        int T = _in.nextInt();
        for (int i = 1; i <= T; ++i) {
            System.out.println("Case #" + i + ": " + solve());
        }
    }
} 