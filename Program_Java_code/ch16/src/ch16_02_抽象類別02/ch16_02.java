package ch16_02_��H���O02;

abstract class Cal{
	public int x;
	public int y;
	
	Cal(int x ,int y){
		this.x = x;
		this.y = y;
		System.out.println("�w��l��");
	}
	
	double multiply() {
		return x*y;
	}
	
	abstract double Answer();
}

class CalPlus extends Cal{
	CalPlus(int x, int y){
		super(x,y);
	}

	@Override
	double Answer() {
		return x+y;
	}

	
}

class CalMinus  extends Cal{
	CalMinus(int x, int y){
		super(x,y);
	}

	@Override
	double Answer() {
		return x-y;
	}

	
}

public class ch16_02 {

	public static void main(String[] args) {
		//Cal c = new Cal(); false
		CalPlus myPlus = new CalPlus(10,20);
		System.out.println(myPlus.multiply());
		System.out.println(myPlus.Answer());
		
		CalMinus myMinus = new CalMinus(50,100);
		System.out.println(myMinus.multiply());
		System.out.println(myMinus.Answer());	
	}

}
