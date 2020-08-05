package ex_07;

class Vehicle{
	String type = "4W";
	int maxSpeed = 100;
	Vehicle(String type, int maxSpeed ){
		this.type = type;
		this.maxSpeed = maxSpeed;
	}
}

class Car extends Vehicle{
	String trans;
	Car(String trans,int maxSpeed){
		super(trans,maxSpeed);
		this.trans = trans;		
	}
	Car(String type , int maxSpeed , String trans){
		super(type,maxSpeed);
		//this.trans = trans;
	}
}

public class ex_07 {

	public static void main(String[] args) {
		Car c1 = new Car("auto",150);
		System.out.println(c1.type +" "+ c1.maxSpeed + " " + c1.trans);

	}

}
