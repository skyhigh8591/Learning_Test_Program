package ch14_16_01_�ɮפ���;

public class  Employee {							// ���uEmployee���O
	int id;										// ���u�s��
	int age;									// ���u�~��
	char gender;								// �ʧO
	String name;								// �W�r
	HomeTown hometown;							// Aggregation�a�m����
	Employee(int id, int age, char gender, String name, HomeTown hometown) {
		this.id = id;
		this.age = age;
		this.gender = gender;
		this.name = name;
		this.hometown = hometown;
	}
	public void printInfo() {					// �C�L���u��T
		System.out.println("���u�s��:" + id + "\t" + 
						   "���u�~��:" + age + "\t" +
						   "���u�ʧO:" + gender + "\t" +
						   "���u�m�W:" + name);							
		System.out.println("����:" + hometown.city + "\t" + 
						   "�٥�:" + hometown.state + "\t" + 
						   "��O:" + hometown.country);	
	}
}

