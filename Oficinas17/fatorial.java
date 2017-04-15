/*
 * Leonardo Deliyannis Constantin
 * Fatorial em Vetor
 */

import java.io.IOException;
import java.util.Locale;
import java.util.Scanner;

class Main{
	public static final int MAX = 21;
	public static void main(String args[]) throws IOException{
		Locale.setDefault(new Locale("en", "US"));
		Scanner sc = new Scanner(System.in);
		int N, i;
		long fat[] = new long[MAX];
		N = sc.nextInt();
		fat[0] = 1;
		for(i = 1; i <= N; i++){
			fat[i] = fat[i-1] * i;
			System.out.println(fat[i]);
		}
	}
}
