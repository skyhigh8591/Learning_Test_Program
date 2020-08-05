<?php
	if (isset($_POST["cName"])&&isset($_POST["cSex"])&&isset($_POST["cBirthday"])&&isset($_POST["cEmail"])&&isset($_POST["cPhone"])&&isset($_POST["cAddr"])) {
		//print "ok";
		require_once("../11-14/connMysql.php");
		$sql = "INSERT INTO `students`(`cName`,`cSex`,`cBirthday`,`cEmail`,`cPhone`,`cAddr`)VALUES(";
		$sql.="'".$_POST["cName"]."',";
		$sql.="'".$_POST["cSex"]."',";
		$sql.="'".$_POST["cBirthday"]."',";
		$sql.="'".$_POST["cEmail"]."',";
		$sql.="'".$_POST["cPhone"]."',";
		$sql.="'".$_POST["cAddr"]."')";
		//print($sql);
		mysqli_query($conn,$sql);
		mysqli_close($conn);
		print "OK";
	}
?>