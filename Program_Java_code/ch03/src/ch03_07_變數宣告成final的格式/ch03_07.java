package ch03_07_變數宣告成final的格式;

public class ch03_07 {

	public static void main(String[] args) {
		final int hourly_salary = 120;
		int monthly_fee = 9000;
		int annual_salary , annual_fee ,annual_savings;
		
		annual_salary = hourly_salary * 8 * 300;
		annual_fee = monthly_fee * 12;
		annual_savings =  annual_salary - annual_fee;
		
		System.out.println("一年可存" + annual_savings);
		
		
	}
	
	
	
	
	
	
	
	
	
	
	
	
	

}
