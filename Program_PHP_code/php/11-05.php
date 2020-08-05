<!DOCTYPE html>
<html lang="en">
<head>
	<meta charset="UTF-8">
	<title>Document</title>
</head>
<body>
	<?php
		$servername = "localhost";
		$username="root";
		$password="1qaz@wsx";
		$database="class";

		//create connection
		$conn = mysqli_connect($servername,$username,$password,$database);

		//check connection
		if(mysqli_connect_error()){
			print("Failed to connect to mysql :" . mysqli_connect_error());
		}else{
			print("successful connection" . "<br>");
		}

		mysqli_query($conn,"SET NAME utf8");
		$sql = "SELECT * FROM `price` WHERE `category` = '主機板'";
		
		if($result = mysqli_query($conn,$sql)){
			print("計錄有" . mysqli_num_rows($result)."筆");
			print("包含" . mysqli_num_fields($result)."個欄位");
			mysqli_free_result($result);
		}


		mysqli_close($conn);


	?>
</body>
</html>