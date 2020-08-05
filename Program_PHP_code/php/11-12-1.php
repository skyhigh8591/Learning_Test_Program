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
			print "<table border = '1' align = 'center'><tr align = 'center'>";
			while ($meta=mysqli_fetch_field($result)) {
				print "<td>".$meta->name."</td>";

			}
			print "</tr>";

			mysqli_data_seek($result,2); //指引到想要的行數
			while ($row=mysqli_fetch_array($result,MYSQLI_NUM)) {
				print "<tr>";
				for ($i=0; $i<mysqli_num_fields($result) ; $i++) { 						print("<td>").$row[$i]."</td>";
				}
				// print_r($row);
				// print("<hr>");
			}

			print "</tr>";
			print "</table>";
			mysqli_free_result($result);
		}
		mysqli_close($conn);
	?>
</body>
</html>