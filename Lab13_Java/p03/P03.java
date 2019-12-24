/**
 * 
 */
package p03;

import java.util.*;

/**
 * @author kimhajin
 *
 */
public class P03 {

	/**
	 * @param args
	 */
	

	static void swap(int a[]) {
		int t = a[0];
		a[0] = a[1];
		a[1] = t;
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Scanner sc = new Scanner(System.in);
		
		int a[] = new int[2];
		
		a[0] = sc.nextInt();
		a[1] = sc.nextInt();
		
		swap(a);
		
		System.out.println(a[0] + " " + a[1]);
	}

}
