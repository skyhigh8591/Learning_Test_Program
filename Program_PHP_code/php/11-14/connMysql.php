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
			// print("successful connection" . "<br>");
		}

		mysqli_query($conn,"SET NAMES utf8");
?>