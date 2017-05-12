/*
 * Leonardo Deliyannis Constantin
 * Programa que diz se uma string é palíndromo
 */

import java.io.IOException;
import java.util.Locale;
import java.util.Scanner;

class Main{
	public static boolean ehPalindromo(String s){
		int i, N = s.length();
		for(i = 0; i < N/2; i++){
			if(s.charAt(i) != s.charAt(N-1-i)) 
				return false;
		}
		return true;
	}

	public static void main(String args[]) throws IOException{
		Locale.setDefault(new Locale("en", "US"));
		Scanner sc = new Scanner(System.in);
		String s;
		while(sc.hasNext()){
			s = sc.nextLine();
			System.out.print("A string " + s);
			System.out.print(ehPalindromo(s.toLowerCase()) ? "" : " nao");
			System.out.println(" eh um palindromo");
		}
	}
}
