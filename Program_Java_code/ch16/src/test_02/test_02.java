package test_02;



abstract class Math{
	protected int ans;
	public void show(){ 
	    System.out.println(ans=+ans); 
	} 
	public abstract void add(int a, int b); // a+b 
	public abstract void sub(int a, int b); // a-b 
	public abstract void mul(int a, int b); // a*b 
	public abstract void div(int a, int b); // a/b 	
	abstract void add(int a, int b, int c); //a+b+c 
	abstract void mul(int a, int b, int c); //a-b-c 
}

class Compute extends Math{
	
	

	@Override
	public void add(int a, int b) {
		ans=a+b;
		
	}

	@Override
	public void sub(int a, int b) {
		ans=a-b;
		
	}

	@Override
	public void mul(int a, int b) {
		 ans=a*b;	
	}

	@Override
	public void div(int a, int b) {
		ans=a/b;
		
	}
	

	@Override
	void add(int a, int b, int c) {
		ans=a+b+c;
		
	}

	@Override
	void mul(int a, int b, int c) {
		ans=a-b-c;
		
	}
	
	public void show(){ 
	    System.out.println("ans="+ans); 
	}
	
}
public class test_02 {

	public static void main(String[] args) {
		Compute cmp = new Compute(); 
	    cmp.mul(3,5);//計算 3*5 
	    cmp.show();//此行會回應”ans=15”字串 
	    cmp.add(2,3,5);
	    cmp.show();
	    cmp.mul(2,3,5);
	    cmp.show();
	    

	}

}
