package ch14_01_梯形面積_繼承的範例;

class Tshape{
	public double Tx = 0;
	private double upline = 0;
	private double downline = 0;
	private double height = 0;
	
	public double getUpline() {
		return upline;
	}
	public void setUpline(double upline) {
		this.upline = upline;
	}
	public double getDownline() {
		return downline;
	}
	public void setDownline(double downline) {
		this.downline = downline;
	}
	public double getHeight() {
		return height;
	}
	public void setHeight(double height) {
		this.height = height;
	}		
}


class TshapeArea extends Tshape{
	public double x = 1.4;
	public double Area() {
		Tx=200;
		System.out.println(Tx);
		return(((getUpline()+getDownline())*getHeight())/2);
		
	}
}



public class ch14_01 {

	public static void main(String[] args) {
		TshapeArea T = new TshapeArea();
		T.setDownline(20);
		T.setHeight(33);
		T.setUpline(40);	
		System.out.println("面積" + T.Area());
		T.x=50;
		System.out.println(T.x);
		
	}

}
