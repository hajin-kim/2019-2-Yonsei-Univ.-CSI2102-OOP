package p01;

import java.util.*;

public class P01 {

	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		
		int inp = sc.nextInt();
		
		int s = inp % 60;
		inp /= 60;
		
		int m = inp % 60;
		inp /= 60;
		
		int h = inp % 24;
		inp /= 24;
		
		System.out.println("" + inp + ' ' + h + ' ' + m + ' ' + s);
		
		// TODO Auto-generated constructor stub
	}

}
