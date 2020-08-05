package test08_3_02;

class Caaa{	
	int a;
	int b;
	int c;		
}





public class test08_3_02 {

	public static void main(String[] args) {
		Caaa obj = new Caaa();
		obj.a = 5 ;
		obj.b = 3 ;
		obj.c = obj.a * obj.b ;
		
		System.out.println("a的值等於" + obj.a);

		System.out.println("b的值等於" + obj.b);

		System.out.println("c的值等於" + obj.c);

	}

}
