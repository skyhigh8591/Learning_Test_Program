package ch14_19_方法內部類別;

class School{
	void college() {
		int students = 400;
		class Mis{
			public int getNum() {
				return students;
			}
		}
		Mis inner = new Mis();
		System.out.println("學生人數" + inner.getNum());
	}
}

public class ch14_19 {

	public static void main(String[] args) {
		School sc = new School();
		sc.college();

	}

}
