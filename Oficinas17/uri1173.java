/*
 * Leonardo Deliyannis Constantin
 * URI 1173 - Preenchimento de Vetor I
 */

import java.io.IOException;
import java.util.Locale;
import java.util.Scanner;

class Main{
	public static void main(String args[]) throws IOException{
		Locale.setDefault(new Locale("en", "US"));
		Scanner sc = new Scanner(System.in);
		int i;
		int N[] = new int[10];
		N[0] = sc.nextInt();
		System.out.println("N[0] = " + N[0]);
		for(i = 1; i < 10; i++){
			N[i] = N[i-1] * 2;
			System.out.println("N[" + i + "] = " + N[i]);
		}
	}
}