package ch14_16_01_檔案分裝;

public class  Employee {							// 員工Employee類別
	int id;										// 員工編號
	int age;									// 員工年齡
	char gender;								// 性別
	String name;								// 名字
	HomeTown hometown;							// Aggregation家鄉城市
	Employee(int id, int age, char gender, String name, HomeTown hometown) {
		this.id = id;
		this.age = age;
		this.gender = gender;
		this.name = name;
		this.hometown = hometown;
	}
	public void printInfo() {					// 列印員工資訊
		System.out.println("員工編號:" + id + "\t" + 
						   "員工年齡:" + age + "\t" +
						   "員工性別:" + gender + "\t" +
						   "員工姓名:" + name);							
		System.out.println("城市:" + hometown.city + "\t" + 
						   "省份:" + hometown.state + "\t" + 
						   "國別:" + hometown.country);	
	}
}

