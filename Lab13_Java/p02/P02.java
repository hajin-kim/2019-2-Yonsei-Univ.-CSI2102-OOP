package p02;

import java.util.*;

public class P02 {

	static void sortArray(int a[]) {
		for(int i = 0; i < a.length; ++i) {
			for(int j = i + 1; j < a.length; ++j) {
				if (a[i] > a[j]) {
					int temp = a[j];
					a[j] = a[i];
					a[i] = temp;
				}
			}
		}
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		
		int arr[] = new int[5];
		
		for(int i = 0; i < 5; ++i) {
			arr[i] = sc.nextInt();
		}
		
		sortArray(arr);

		System.out.print("" + arr[0]);
		System.out.print(" " + arr[1]);
		System.out.print(" " + arr[2]);
		System.out.print(" " + arr[3]);
		System.out.println(" " + arr[4]);
	}

}
