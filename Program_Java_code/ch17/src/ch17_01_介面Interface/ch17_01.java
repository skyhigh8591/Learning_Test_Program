package ch17_01_¤¶­±Interface;

interface Fly{
	void flying();
}

class Bird implements Fly{
	@Override
	public void flying() {
		System.out.println("Bird flying....");		
	}
}

class Airplane implements Fly{
	@Override
	public void flying() {
		System.out.println("Airplane flying....");		
	}
}
public class ch17_01 {

	public static void main(String[] args) {
		Bird bird = new Bird();
		bird.flying();
		
		Airplane Air = new Airplane();
		Air.flying();

	}

}
