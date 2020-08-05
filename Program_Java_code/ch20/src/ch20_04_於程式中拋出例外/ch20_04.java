package ch20_04_於程式中拋出例外;

public class ch20_04 {

	public static void pwdCheck(String pwdStr) {

		if (pwdStr.length() >= 5 && pwdStr.length() <= 8) {
			System.out.println("密碼格式正確" + pwdStr);
		} else {
			System.out.println("密碼格式錯誤" + pwdStr);
			throw new StringIndexOutOfBoundsException("密碼長度不符合");
		}
	}

	public static void main(String[] args) {
		String[] pwd = { "123456", "3456766", "2212434" };
		for (int i = 0; i < pwd.length; i++) {
			try {
				pwdCheck(pwd[i]);
			} catch (StringIndexOutOfBoundsException e) {
				System.out.println("密碼長度不符合");
			}
		}
	}

}
