/**
 * 
 */
package p04;

/**
 * @author kimhajin
 *
 */

// Car
class Car {
	
	private String name;
	private String color;
	private String gearType;
	private int door;

	public Car(String name, String color, String gearType, int door) {
		this.name = name;
		this.color = color;
		this.gearType = gearType;
		this.door = door;
	}
	
	public String toString() {
		return "name=" + name + ", " + "color=" + color + ", " + "gearType=" + gearType + ", " + "door=" + door;
	}
}


public class Lab13_4 {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

        Car c1 = new Car("Car1", "white", "auto", 4);
        Car c2 = new Car("Car2", "gray", "manual", 2);

        System.out.println(c1);
        System.out.println(c2);
	}

}
