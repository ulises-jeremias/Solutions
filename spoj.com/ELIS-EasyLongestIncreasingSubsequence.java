/*
 * By: ulises-jeremias
 * From: http://www.spoj.com/problems/ELIS/
 * Name: ELIS - Easy Longest Increasing Subsequence
 * Date: 25/09/2017
 */

import java.io.*;
import java.math.*;
import java.util.*;

public class Main {

static int n;
static int[] inputs = new int[25];
static int[] dp = new int[25];

static int lis () {
        int i, j, max = -1;
        for (i = 0; i < n; i++) {
                dp[i] = 1;
                for (j = 0; j < i; j++) {
                        if ((inputs[j] < inputs[i]) && (dp[j]+1 > dp[i])) {
                                dp[i] = dp[j]+1;
                        }
                }
                if (max < dp[i]) {
                        max = dp[i];
                }
        }
        return max;
}

public static void main (String[] args) throws IOException {
        int i, j;
        Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        n = in.nextInt();
        for (i = 0; i < n; i++) {
                inputs[i] = in.nextInt();
        }
        System.out.println(lis());
}

}
