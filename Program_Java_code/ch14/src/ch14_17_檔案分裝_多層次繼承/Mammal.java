package ch14_17_檔案分裝_多層次繼承;

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
		System.out.println(name + "喜歡吃" + favorite_food);
	}
}
