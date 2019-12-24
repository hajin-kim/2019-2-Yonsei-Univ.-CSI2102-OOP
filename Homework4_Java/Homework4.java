

/**
 * @author kimhajin
 *
 */

public class Homework4 {

	public static void main(String[] args) {

		Tank tank = new Tank(120);
		Dropship dropship = new Dropship(150);
		Marine marine = new Marine(50);
		SCV	scv = new SCV(40);
		
		tank.reduceHitPoint(10);
		dropship.reduceHitPoint(30);
		marine.reduceHitPoint(20);
		scv.reduceHitPoint(5);
		
		System.out.println(tank);
		System.out.println(dropship);
		System.out.println(marine);
		System.out.println(scv); 

		System.out.println(); 
		scv.repair(tank);
		scv.repair(dropship);
		scv.repair(scv);
		//scv.repair(marine);	
		System.out.println(); 
		
		System.out.println(tank);
		System.out.println(dropship);
		System.out.println(marine);
		System.out.println(scv); 
	}
}
