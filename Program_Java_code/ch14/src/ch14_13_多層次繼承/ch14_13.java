package ch14_13_�h�h���~��;

class Animail {
	protected String name;

	Animail(String name) {
		this.name = name;
	}

	public void eat() {
		System.out.println(name + "���b�Y");
	}
}

class Mammal extends Animail {
	protected String favorite_food;

//	Mammal(String name){
//		super(name);
//	}	
	Mammal(String name, String favorite_food) {
		super(name);
		this.favorite_food = favorite_food;
	}
	public void favoritefood() {
		System.out.println(name + "���w�Y" + favorite_food);
	}
}

class Cat extends Mammal{
	Cat(String name,String favorite_food){
		super(name,favorite_food);
	}
	public void jumping() {
		System.out.println(name+"���b��");
	}
}

public class ch14_13 {

	public static void main(String[] args) {
		//Animail a = new Animail("aaa");
		Cat c = new Cat("bill","fish");
		c.eat();
		c.favoritefood();
		c.jumping();
		System.out.println(c.name);
		System.out.println(c.favorite_food);
		
		
		

	}
}
