/**
 * 
 */

/**
 * @author kimhajin
 *
 */
public final class Dropship extends AirUnit implements Repairable {

	/**
	 * @param hp
	 */
	// constructor, call parent class' constructor
	public Dropship(int hp) {
		super(hp);
		// TODO Auto-generated constructor stub
	}
	
	public String toString() {
		return "Dropship " + super.toString();
	}

	// return "Dropship repair"
	@Override
	public String selfRepair() {
		// TODO Auto-generated method stub
		this.hitPoint = this.MAX_HP;
		return "Dropship repair";
	}

}
