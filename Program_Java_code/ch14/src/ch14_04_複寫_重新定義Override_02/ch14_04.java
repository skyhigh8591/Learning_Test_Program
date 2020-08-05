package ch14_04_複寫_重新定義Override_02;

class Emp {
	protected int Salary;

	public int getSalary() {
		return Salary;
	}

	public void setSalary(int Salary) {
		if (Salary > 40000) {
			this.Salary = 40000;
		} else {
			this.Salary = Salary;
		}

	}

	public void ShowSal() {
		System.out.println(Salary);
	}

}

class Manager extends Emp {
	public int Bonus;

	public void setSalary(int Salary) {
		if (Salary > 60000) {
			this.Salary = 60000;
		} else {
			this.Salary = Salary;
		}

	}

	public void ShowSal() {
		System.out.println(Salary + Bonus);
	}
}

public class ch14_04 {

	public static void main(String[] args) {
		Emp John = new Emp();
		John.setSalary(45000);
		John.ShowSal();
		
		Manager Mary = new Manager();
		Mary.setSalary(65000);
		Mary.Bonus=3000;
		Mary.ShowSal();

	}

}
