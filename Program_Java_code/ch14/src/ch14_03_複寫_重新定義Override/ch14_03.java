package ch14_03_�Ƽg_���s�w�qOverride;

class Emp{
	public int salary;
	public void ShowSal() {
		System.out.println(salary);
	}
}

class Manager extends Emp{
	public int Bonus;
	public void ShowSal() {
		System.out.println(salary + Bonus);
	}
}
public class ch14_03 {

	public static void main(String[] args) {
		Emp John = new Emp();
		John.salary=30000;
		John.ShowSal();
		
		Manager Mary = new Manager();
		Mary.salary = 40000;
		Mary.Bonus = 1000;
		Mary.ShowSal();
			

	}

}
