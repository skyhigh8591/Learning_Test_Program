package ch17_02_介面的成員變數;

interface Shape{
	double PI=3.141596;
	double ares();
}
class Rectangel implements Shape{	
	protected double height,width;
	Rectangel(double height,double width){
		this.height = height;
		this.width = width;
	}
	@Override
	public double ares() {		
		return height*width;
	}
}
class Circle implements Shape{
	public double r;
	Circle(double r){
		this.r = r;
	}
	@Override
	public double ares() {
		return r*r*PI;
	}
}
public class ch17_02 {
	public static void main(String[] args) {
		Rectangel r = new Rectangel(2,3);	
		System.out.println(r.ares());
		System.out.println(r.PI);
		System.out.println(r.height);
		System.out.println(r.width);
		System.out.println("....................................");
		Circle c = new Circle(5);
		System.out.println(c.ares());
		System.out.println(c.PI);
		System.out.println(c.r);
	}
}
