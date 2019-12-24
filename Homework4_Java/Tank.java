/**
 * 
 */

/**
 * @author kimhajin
 *
 */
public final class Tank extends GroundUnit implements Repairable {

	/**
	 * @param hp
	 */
	// constructor, call parent class' constructor
	public Tank(int hp) {
		super(hp);
		// TODO Auto-generated constructor stub
	}
	
	public String toString() {
		return "Tank " + super.toString();
	}

	// return "Tank repair"
	@Override
	public String selfRepair() {
		// TODO Auto-generated method stub
		this.hitPoint = this.MAX_HP;
		return "Tank repair";
	}

}
