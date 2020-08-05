package ch17_04_基本介面的繼承;

interface Animal{
	void showMe();
}

interface Bird extends Animal{
	void flying();
}

class Eagle implements Bird{

	@Override
	public void showMe() {
		System.out.println("我是動物");
		
	}

	@Override
	public void flying() {
		System.out.println("我是雄鷹我會飛");	
	}
	
}

public class ch17_04 {

	public static void main(String[] args) {
		Eagle e = new Eagle();
		e.showMe();
		e.flying();
	

	}

}
