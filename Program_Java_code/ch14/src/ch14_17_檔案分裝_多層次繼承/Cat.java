package ch14_17_檔案分裝_多層次繼承;


public class Cat extends Mammal{
	Cat(String name,String favorite_food){
		super(name,favorite_food);
	}
	public void jumping() {
		System.out.println(name+"正在跳");
	}
}
