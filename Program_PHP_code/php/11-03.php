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
		
		if($result = mysqli_query($conn,"SELECT DATABASE()")){
			$row = mysqli_fetch_row($result);
			print("default database is " . $row[0]);
			mysqli_free_result($result);
		}


		mysqli_close($conn);


	?>
</body>
</html>