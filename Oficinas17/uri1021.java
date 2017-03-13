import java.io.IOException;
import java.util.Scanner;
import java.util.Locale;

class Main{
	public static final boolean DEBUG = false;
	
	public static void main(String args[]) throws IOException {
		Locale.setDefault(new Locale("en", "US"));
		Scanner sc = new Scanner(System.in);
		double N, resto;
		int notas, moedas;
		
		N = sc.nextDouble();
		System.out.println("NOTAS:");
		resto = N;
		
		notas = (int)resto / 100;
		resto = resto - (notas * 100.0);
		System.out.println(notas + " nota(s) de R$ 100.00");
		
		notas = (int)resto / 50;
		resto = resto - (notas * 50.0);
		System.out.println(notas + " nota(s) de R$ 50.00");
				
		notas = (int)resto / 20;
		resto = resto - (notas * 20.0);
		System.out.println(notas + " nota(s) de R$ 20.00");
		
		notas = (int)resto / 10;
		resto = resto - (notas * 10.0);
		System.out.println(notas + " nota(s) de R$ 10.00");
		
		notas = (int)resto / 5;
		resto = resto - (notas * 5.0);
		System.out.println(notas + " nota(s) de R$ 5.00");
		
		notas = (int)resto / 2;
		resto = resto - (notas * 2.0);
		System.out.println(notas + " nota(s) de R$ 2.00");
		
		System.out.println("MOEDAS:");
		
		moedas = (int)(resto * 100) / 100;
		resto = resto - (moedas * 1.0);
		System.out.println(moedas + " moeda(s) de R$ 1.00");
		
		moedas = (int)(resto * 100) / 50;
		resto = resto - (moedas * 0.5);
		System.out.println(moedas + " moeda(s) de R$ 0.50");
		
		moedas = (int)(resto * 100) / 25;
		resto = resto - (moedas * 0.25);
		System.out.println(moedas + " moeda(s) de R$ 0.25");
		
		moedas = (int)(resto * 100) / 10;
		resto = resto - (moedas * 0.10);
		System.out.println(moedas + " moeda(s) de R$ 0.10");
		
		moedas = (int)(resto * 100) / 5;
		resto = resto - (moedas * 0.05);
		System.out.println(moedas + " moeda(s) de R$ 0.05");
		
		moedas = (int)(resto * 100);
		resto = resto - (moedas * 0.01);
		System.out.println(moedas + " moeda(s) de R$ 0.01");
	}
}
