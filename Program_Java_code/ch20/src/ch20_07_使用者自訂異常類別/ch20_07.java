package ch20_07_�ϥΪ̦ۭq���`���O;

class MyException extends Exception{
	String str;
	MyException(String msg){
		str = msg;
	}
	public String toSyring() {
		return("�کw�q��MyException�o�ͤF" + str);
	}
}

public class ch20_07 {

	public static void main(String[] args) {
		try {
			System.out.println("try�϶�");
			throw new MyException("���`�T��");
		}catch(MyException e) {
			System.out.println("catch�϶�");
			System.out.println("MyException:" + e);
		}

	}

}
