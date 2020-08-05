package test09_01;



class CBox{
	
	public static double length = 3;
	public static double width = 4;
	public static double height = 5;
	 
	 
	 double volume()
	 {
		 return length*width*height;
	 }
	 
	 double surfaceArea()
	 {
		 return length*width;
	 }
	 void showData()
	 {
		 System.out.printf("length=%.2f width=%.2f height=%.2f\n" ,length,width,height);
	 }
	 void showAll()
	 {
		 System.out.printf("體積=%.2f\n",volume());
		 System.out.printf("面積=%.2f\n",surfaceArea());
		 showData();
	 }
}

public class test09_01 {

	public static void main(String[] args) {
CBox box = new CBox();
		
		
		
		System.out.printf("體積%.2f\n",box.volume());
		System.out.println("..................................");
		System.out.printf("面積%.2f\n",box.surfaceArea());
		System.out.println("..................................");
		box.showData();
		System.out.println("..................................");
		box.showAll();
		System.out.println("..................................");

	}

}
