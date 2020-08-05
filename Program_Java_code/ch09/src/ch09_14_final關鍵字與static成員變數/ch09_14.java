package ch09_14_final關鍵字與static成員變數;

class IcCard{
	final static int valueadd=1000;
	
}

public class ch09_14 {

	public static void main(String[] args) {
		IcCard A = new IcCard();
		
		System.out.println(A.valueadd);

	}

}
