import java.io.IOException;
import java.util.Scanner;
import java.util.Locale;

class Main{
	public static void main(String args[]) throws IOException {
		Locale.setDefault(new Locale("en", "US"));
		Scanner sc = new Scanner(System.in);
		int a, b;
		a = sc.nextInt();
		b = sc.nextInt();
		System.out.println("SOMA = " + (a+b));
	}
}
