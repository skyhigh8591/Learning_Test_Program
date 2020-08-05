package ch14_18_±_ª¬°j°é;

class School{
	public class Motto{
		int num = 400;
		public void printInfo() {
			System.out.println("print motto");
		}
	}
	void display() {
		Motto m = new Motto();
		m.printInfo();
	}
}

public class ch14_18 {

	public static void main(String[] args) {
		School sc = new School();
		sc.display();
		
		School sc1 = new School();
		School.Motto inner = sc1.new Motto();
		inner.printInfo();
		System.out.println(inner.num);
	}

}
