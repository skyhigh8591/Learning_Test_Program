package ch14_21_�ΦW���O��Ѽƶǰe;


class Animal{
	public String moving() {
		return "�ʪ��i�H����";
	}
}

class myCat{
	public void showMsg(Animal obj) {
		System.out.println("�ΦW���O��Ѽƶǰe " + obj.moving());
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
