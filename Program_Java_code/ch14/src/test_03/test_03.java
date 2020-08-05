package test_03;


class Caaa{
	public int num1;
	public int num2;
	Caaa(){
		this.num1 = 1;
		this.num2 = 1;
	}
	Caaa(int a, int b){
		this.num1 = a;
		this.num2 = b;
	}
}

class Cbbb extends Caaa{
	public void set_num(int x , int y) {
		this.num1 = x; 
		this.num2 = y;				
	}
	public void show() {
		System.out.println("num1 = " + this.num1);
		System.out.println("num2 = " + this.num2);
	}	
	Cbbb(int x , int y){
			super(x,y);
	}
}

public class test_03 {

	public static void main(String[] args) {
		Caaa aa1 = new Caaa();
		Caaa aa2 = new Caaa(6,7);
		Cbbb bb = new Cbbb(5,10);
		bb.set_num(8, 9);
		bb.show();
	}

}
