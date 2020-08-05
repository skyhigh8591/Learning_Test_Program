<?php
	if (isset($_GET["cName"]) && isset($_GET["cSex"]) && isset($_GET["cBirthday"]) && isset($_GET["cEmail"]) && isset($_GET["cPhone"]) && isset($_GET["cAddr"])) {
		//print "ok";
		require_once("../11-14/connMysql.php");
		$sql = "INSERT INTO `students`(`cName`,`cSex`,`cBirthday`,`cEmail`,`cPhone`,`cAddr`)VALUES(";
		$sql.="'".$_GET["cName"]."',";
		$sql.="'".$_GET["cSex"]."',";
		$sql.="'".$_GET["cBirthday"]."',";
		$sql.="'".$_GET["cEmail"]."',";
		$sql.="'".$_GET["cPhone"]."',";
		$sql.="'".$_GET["cAddr"]."')";
		//print($sql);
		mysqli_query($conn,$sql);
		mysqli_close($conn);
		print "OK";
	}

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