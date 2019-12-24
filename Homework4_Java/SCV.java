/**
 * 
 */

/**
 * @author kimhajin
 *
 */
public final class SCV extends GroundUnit implements Repairable {

	/**
	 * @param hp
	 */
	// constructor, call parent class' constructor
	public SCV(int hp) {
		super(hp);
		// TODO Auto-generated constructor stub
	}

	// return "SCV repair"
	@Override
	public String selfRepair() {
		// TODO Auto-generated method stub
		this.hitPoint = this.MAX_HP;
		return "SCV repair";
	}
	
	public String toString() {
		return "SCV " + super.toString();
	}
	
	// set back r's hitPoint to MAX_HP
	// and print the message r.selfRepair() + " completed"
	public void repair(Repairable r) {
		System.out.println(r.selfRepair() + " completed");
	}

}
