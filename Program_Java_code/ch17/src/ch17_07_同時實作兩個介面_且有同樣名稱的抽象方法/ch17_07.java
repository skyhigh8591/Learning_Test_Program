package ch17_07_同時實作兩個介面_且有同樣名稱的抽象方法;

interface Bird{
	void flying();
}

interface Airplane{
	void flying();
	
}

class InfoFly implements Bird , Airplane{


	@Override
	public void flying() {
		System.out.printf("flying...................");
		
	}

	
}

public class ch17_07 {

	public static void main(String[] args) {
		InfoFly i = new InfoFly();
		i.flying();

	}

}
