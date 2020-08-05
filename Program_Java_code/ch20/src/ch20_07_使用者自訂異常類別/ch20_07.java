package ch20_07_使用者自訂異常類別;

class MyException extends Exception{
	String str;
	MyException(String msg){
		str = msg;
	}
	public String toSyring() {
		return("我定義的MyException發生了" + str);
	}
}

public class ch20_07 {

	public static void main(String[] args) {
		try {
			System.out.println("try區塊");
			throw new MyException("異常訊息");
		}catch(MyException e) {
			System.out.println("catch區塊");
			System.out.println("MyException:" + e);
		}

	}

}
