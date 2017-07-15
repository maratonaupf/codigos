/*
https://www.urionlinejudge.com.br/judge/pt/problems/view/1248
URI Problem 1248 - Diet Plan

"Premature optimization is the root of all evil." -- Donald Knuth

*/

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.lang.Character;
import java.lang.StringBuilder;
import java.util.Arrays;

class Main {
	private static String dietValidation(String diet, String meal){
		char[] dietArray = diet.toCharArray();
		int tam = meal.length(), target;
		
		for(int i = 0; i < tam; i++){
			target = Arrays.binarySearch(dietArray, meal.charAt(i));
			if(target < 0){
				return String.valueOf("CHEATER");
			}
			else{
				StringBuilder temp = new StringBuilder(diet);
				temp.deleteCharAt(target);
				diet = temp.toString();
				dietArray = diet.toCharArray();
			}
		}
		return diet;
	}
    
    public static void main(String[] args) throws IOException {
        InputStreamReader ir = new InputStreamReader(System.in);
        BufferedReader in = new BufferedReader(ir);
        
        int testCases;
		
        String diet = new String();
        String bFast = new String();
        String lunch = new String();

        testCases = Integer.parseInt(in.readLine());
        
        while(testCases != 0){
            testCases--;
            
            diet = in.readLine();
            bFast = in.readLine();
            lunch = in.readLine();
			
			// 1st step: sorting
			char[] sortedDiet = diet.toCharArray();
			Arrays.sort(sortedDiet);
			diet = String.valueOf(sortedDiet);
			// DONE
			
            diet = dietValidation(diet, bFast);
			if(diet.equals("CHEATER") == false){
				diet = dietValidation(diet, lunch);
			}
			System.out.println(diet);
			
        }
    }
}
