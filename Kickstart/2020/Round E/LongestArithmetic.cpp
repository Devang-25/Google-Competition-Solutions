// "Maroon Beret"-Devang Sharma


import java.io.*;
import java.util.*;

 public class Solution
 {

	public static void main(String[] args) throws IOException 
    {
		Scanner scanner = new Scanner(System.in);
        {
			int testCases = scanner.nextInt();
			scanner.nextLine();
			for (int testcase = 1; testcase <= testCases; testcase++) {
				int len = scanner.nextInt();
				int array[] = new int[len];
				for (int x = 0; x < len; x++)
					array[x] = scanner.nextInt();
				System.out.println("Case #" + testcase + ": " + longestArthematic(array));
			}
		}
	}

	private static int longestArthematic(int[] array) {
		int len = 1, currLen = 1;
		int diff = array[0] - array[1];
		for (int x = 1; x < array.length - 1; x++) {
			int currDiff = array[x] - array[x + 1];
			if (diff != currDiff) {
				diff = currDiff;
				currLen = 1;
			} else
				len = Math.max(len, ++currLen);
		}
		return len + 1;
	}
}