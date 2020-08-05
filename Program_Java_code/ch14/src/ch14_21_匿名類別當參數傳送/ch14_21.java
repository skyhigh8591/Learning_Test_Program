package ch14_21_匿名類別當參數傳送;


class Animal{
	public String moving() {
		return "動物可以活動";
	}
}

class myCat{
	public void showMsg(Animal obj) {
		System.out.println("匿名類別當參數傳送 " + obj.moving());
	}
}

//class Test extends Animal{
//	public String moving() {
//	return "tttttttt";
//	}
//}

public class ch14_21 {

	public static void main(String[] args) {
//		myCat obj1 = new myCat();
//		Animal t = new Animal();
//		obj1.showMsg(t);
		
		
		myCat obj2 = new myCat();
		obj2.showMsg(new Animal() {
			
			public String moving() {
				return "ttttttttt";
			}
			
		});

	}

}
