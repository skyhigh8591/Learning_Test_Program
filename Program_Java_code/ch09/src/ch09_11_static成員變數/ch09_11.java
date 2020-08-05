package ch09_11_static成員變數;

class NBAtemp{
	public static int counter;//所有物件共享
	public int id;
	public String name;
	static { //static的初始區域
		counter=0;		
	}
	public NBAtemp() {
		id = ++counter;
	}
	public void output() {
		System.out.println("id:" + id + "Name" + name);
		System.out.println("共有" + counter + "成員");
	}
	
}




public class ch09_11 {

	public static void main(String[] args) {
		
		NBAtemp t1 = new NBAtemp();
		t1.name = "Durant";
		t1.output();
		
		NBAtemp t2 = new NBAtemp();
		t2.name = "Curry";
		t2.output();
		
		
		
		
		
	}

}
