package ch17_06_¤¶­±¦h­«Ä~©Ó;

interface Bird{
	void birdFly();
}

interface Airplane{
	void ariplanefly();
}

interface Fly extends Bird , Airplane{
	void pediaFly();
}

class InfoFly implements Fly{

	@Override
	public void birdFly() {
		System.out.println("birdFly");
		
	}

	@Override
	public void ariplanefly() {
		System.out.println("ariplanefly");
		
	}

	@Override
	public void pediaFly() {
		System.out.println("pediaFly");
		
	}
	
}
public class ch17_06 {
	public static void main(String[] args) {
		InfoFly i = new InfoFly();
		i.birdFly();
		i.ariplanefly();
		i.pediaFly();
	}

}
