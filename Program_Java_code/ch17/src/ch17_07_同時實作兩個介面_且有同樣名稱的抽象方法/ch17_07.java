package ch17_07_�P�ɹ�@��Ӥ���_�B���P�˦W�٪���H��k;

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
