package ch17_04_�򥻤������~��;

interface Animal{
	void showMe();
}

interface Bird extends Animal{
	void flying();
}

class Eagle implements Bird{

	@Override
	public void showMe() {
		System.out.println("�ڬO�ʪ�");
		
	}

	@Override
	public void flying() {
		System.out.println("�ڬO���N�ڷ|��");	
	}
	
}

public class ch17_04 {

	public static void main(String[] args) {
		Eagle e = new Eagle();
		e.showMe();
		e.flying();
	

	}

}
