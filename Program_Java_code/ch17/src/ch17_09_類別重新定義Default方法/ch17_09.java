package ch17_09_���O���s�w�qDefault��k;

interface Dog{
	int x = 10;
	default void running() {
		System.out.println("dog running");
	}
	default void running1() {
		System.out.println("dog running1");
	}
}

interface Cat{
	default void running() {
		System.out.println("Cat running");
	}
}

class Pet implements Dog,Cat{

	@Override
	public void running() {
		System.out.println("Pet running");
		Dog.super.running();
		Cat.super.running();
	}
	
}
public class ch17_09 {

	public static void main(String[] args) {
		Pet p = new Pet();
		p.running();
		p.running1();

	}

}
