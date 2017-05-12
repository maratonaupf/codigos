/*
 * Leonardo Deliyannis Constantin
 * OBI2016 - Lâmpadas do hotel
*/

import java.io.IOException;
import java.util.Locale;
import java.util.Scanner;

class Main{
	public static void main(String args[]) throws IOException{
		Locale.setDefault(new Locale("en", "US"));
		Scanner sc = new Scanner(System.in);
		int ia, ib, fa, fb;
		while(sc.hasNext()){
			ia = sc.nextInt();
			ib = sc.nextInt();
			fa = sc.nextInt();
			fb = sc.nextInt();
			if(ia == fa && ib == fb) System.out.println(0);
			if(ia != fa) System.out.println(1);
			if(ia == fa && ib != fb) System.out.println(2);
		}
	}
}
