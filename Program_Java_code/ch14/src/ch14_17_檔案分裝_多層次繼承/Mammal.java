package ch14_17_�ɮפ���_�h�h���~��;

public class Mammal extends Animail {
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
