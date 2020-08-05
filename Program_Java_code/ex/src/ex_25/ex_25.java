package ex_25;

public class ex_25{
	String name;
	boolean contract;
	double salary;
	
	ex_25(String name,boolean contract,double salary){
		this.name=name;
		this.contract=contract;
		this.salary=salary;
	}
	
	ex_25(){
		this("joe",true,100);
	}
	
	public String toString() {
		return name + ":" + contract + ":" + salary + "......";
	}
	
	public static void main(String[] args) {
		ex_25 e = new ex_25();
		e.name="joe";
		e.contract=true;
		e.salary=100;
		System.out.print(e);

	}

}
