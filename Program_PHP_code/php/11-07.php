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
		$database="product";

		//create connection
		$conn = mysqli_connect($servername,$username,$password,$database);

		//check connection
		if(mysqli_connect_error()){
			print("Failed to connect to mysql :" . mysqli_connect_error());
		}else{
			print("successful connection" . "<br>");
		}

		mysqli_query($conn,"SET NAMES utf8");
		$sql = "SELECT * FROM `price` WHERE `category` = '主機板'";
		
		if($result = mysqli_query($conn,$sql)){
			print "<table width = '400' border='1'><tr align='center'>";
			print "<th>欄位名稱</th><th>長度</th></tr>";
			$i=0;
			while($i<mysqli_num_fields($result)) {
				$meta = mysqli_fetch_field_direct($result,$i);
				print "<tr>";
				print "<td>$meta->name</td>";
				print "<td>$meta->length</td>";
				print "</tr>";
				$i++;
			}
			print "</table>";
			mysqli_free_result($result);
		}
		mysqli_close($conn);
	?>
</body>
</html>