package ch09_11_static�����ܼ�;

class NBAtemp{
	public static int counter;//�Ҧ�����@��
	public int id;
	public String name;
	static { //static����l�ϰ�
		counter=0;		
	}
	public NBAtemp() {
		id = ++counter;
	}
	public void output() {
		System.out.println("id:" + id + "Name" + name);
		System.out.println("�@��" + counter + "����");
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
