// "Maroon Beret"- DEVANG SHARMA, GDG SINGAPORE

import java.util.Scanner;

public class Solution {

    public static void findRuleBreak(int[] arr, int testNum) {
        int n = arr.length, ans = Integer.MAX_VALUE;
        int[][] dp = new int[n][4];
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < 4; ++j) {
                dp[i][j] = Integer.MAX_VALUE;
            }
            if (arr[i] == arr[i-1]) {
                for (int j = 0; j < 4; ++j) {
                    dp[i][j] = Math.min(dp[i-1][j], dp[i][j]);
                    for (int k = j+1; k%4 != j; ++k) {
                        dp[i][k%4] = Math.min(dp[i][k%4], dp[i-1][j] + 1);
                    }
                }
            }
            else if (arr[i] > arr[i - 1]) {
                for (int j = 3; j >= 0; --j) {
                    for (int k = 0; k <= j; ++k) {
                        dp[i][k] = Math.min(dp[i][k], dp[i - 1][j] + 1);
                    }
                    for (int k = j + 1; k < 4; ++k) {
                        dp[i][k] = Math.min(dp[i][k], dp[i - 1][j]);
                    }
                }
            } else if (arr[i] < arr[i - 1]) {
                for (int j = 0; j < 4; ++j) {
                    for (int k = j; k < 4; ++k) {
                        dp[i][k] = Math.min(dp[i][k], dp[i - 1][j]+1);
                    }
                    for (int k = 0; k < j; ++k) {
                        dp[i][k] = Math.min(dp[i][k], dp[i - 1][j]);
                    }

                }
            }
        }
        for (int i = 0; i < 4; ++i) {
            ans = Math.min(ans, dp[n-1][i]);
        }

        System.out.println(String.format("Case #%s: %s", testNum, ans));
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = Integer.parseInt(scanner.nextLine());
        for (int i = 0 ; i < n; ++i) {
            int l = Integer.parseInt(scanner.nextLine());
            int[] arr = new int[l];
            String[] strs = scanner.nextLine().split(" ");
            for (int j = 0; j < l; ++j) {
                arr[j] = Integer.parseInt(strs[j]);
            }
            findRuleBreak(arr, i+1);
        }
    }
}