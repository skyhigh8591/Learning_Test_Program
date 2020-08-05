package ch17_08_同時實作兩個介面_且有同樣名稱的成員變數;

interface Dog{
	int y = 20;
	int age=5;//static final
	void running();
}

interface Cat{
	int x = 1;
	int age = 5;
	void running();
}

class Pet implements Dog,Cat{
	@Override
	public void running() {
		System.out.println(Dog.age);
		System.out.println(Cat.age);
		
		System.out.println(x);
		System.out.println(Cat.x);
		
		System.out.println(y);
		System.out.println(Dog.y);
	}	
}
public class ch17_08 {
	public static void main(String[] args) {
		Pet p = new Pet();
		p.running();
	}
}
