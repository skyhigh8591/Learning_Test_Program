<!DOCTYPE html>
<html lang="en">
<head>
	<meta charset="UTF-8">
	<title>Document</title>
	<style type="text/css">
		body{
			background-color:#d1fce8; 
		}
	</style>
</head>
<body>
	<p style="text-align: center;"><img src="profile1.jpg"></p>
	<fieldset>
		<legend>個人資訊</legend>
		<form method="get" action="hw_01_02.php">
		姓&nbsp;名:<input type="text" name="username" id="username" size="40" autocomplete="off">
		<br>
		性別:
		<input type="radio" name="userage" value="age1">男
		<input type="radio" name="userage" value="age2">女
		<br>
		<br>
		<br>
		<br>
		最高學歷
		<select name="usernumber">
			<option value="高中以下" > 高中以下 </option>
			<option value="大專院校" > 大專院校 </option>
			<option value="碩士" > 碩士 </option>
			<option value="博士" > 博士 </option>
			<option value="其他" > 其他 </option>
		</select>
	</fieldset>
	<br>
	<br>
	<fieldset>
		<legend>其他資訊</legend>
		您喜歡下列哪些活動(可複選)?
		<input type="checkbox" name="userphone[]" value="閱讀">閱讀
		<input type="checkbox" name="userphone[]" value="打球">打球
		<input type="checkbox" name="userphone[]" value="聽音樂">聽音樂
		<input type="checkbox" name="userphone[]" value="水上活動">水上活動
		<input type="checkbox" name="userphone[]" value="旅行">旅行
		<br>
		<br>
		<br>
		您對於使用臉書經營社群有何看法?
		<br>
		<textarea name="usertrouble" cols="45" rows="4"></textarea>
		<br>
	</fieldset>
	<br>
	<input type="submit" value="傳送資料">
	<input type="reset" value="清除資料">
	</form>

</body>
</html>