package ch14_19_��k�������O;

class School{
	void college() {
		int students = 400;
		class Mis{
			public int getNum() {
				return students;
			}
		}
		Mis inner = new Mis();
		System.out.println("�ǥͤH��" + inner.getNum());
	}
}

public class ch14_19 {

	public static void main(String[] args) {
		School sc = new School();
		sc.college();

	}

}
