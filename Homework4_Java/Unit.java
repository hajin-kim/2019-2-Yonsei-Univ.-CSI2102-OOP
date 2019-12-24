

/**
 * @author kimhajin
 *
 */
public abstract class Unit {
	protected int hitPoint;
	protected final int MAX_HP;
	
	// constructor, initialize hitPoint and MAX_HP as hp
	public Unit(int hp) {
		this.MAX_HP = hp;
		this.hitPoint = this.MAX_HP;
	}
	
	// decrease hitPoint by howmuch,
	// but hitPoint should not be negative
	public void reduceHitPoint(int howmuch) {
		if (howmuch > this.hitPoint) {
			this.hitPoint = 0;
		}
		else {
			this.hitPoint -= howmuch;
		}
	}
	
	// make the information string and return
	public String toString() {
		return "unit hp(" + this.hitPoint + ") maxhp(" + this.MAX_HP + ")";
	}
}
