package test_01;

abstract class Math{
	protected int ans;
	public void show(){ 
	    System.out.println(ans=+ans); 
	} 
	public abstract void add(int a, int b); // a+b 
	public abstract void sub(int a, int b); // a-b 
	public abstract void mul(int a, int b); // a*b 
	public abstract void div(int a, int b); // a/b 	
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
	public void show(){ 
	    System.out.println("ans="+ans); 
	}
	
}

public class test_01 {

	public static void main(String[] args) {
		Compute cmp = new Compute(); 
	    cmp.mul(3,5);//計算 3*5 
	    cmp.show();//此行會回應”ans=15”字串 

	}

}
