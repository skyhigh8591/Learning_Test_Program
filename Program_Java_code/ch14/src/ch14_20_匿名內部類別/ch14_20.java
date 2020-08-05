package ch14_20_匿名內部類別;

class Animal{
	public void moving() {
		System.out.println("aaaaaaa");
	}
	
}

//class Test extends Animal{
//	public void moving() {
//		System.out.println("bbbbbb");
//	}
//}

public class ch14_20 {

	public static void main(String[] args) {
//		Test t = new Test();
//		t.moving();
		
		Animal inner = new Animal() {
			@Override
			public void moving() {
				System.out.println("ccccccccc");
			}
		};		
		inner.moving();
	}

}
