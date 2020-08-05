<?php
if (isset($_GET["cID"])) {
	//print "ok";
	require_once("../11-14/connMysql.php");
	$sql = "DELETE FROM `students` WHERE `cID` =" . $_GET["cID"];
	mysqli_query($conn,$sql);
	mysqli_close($conn);
	print "OK";
}
if (isset($_POST["cID"])) {
	//print "ok";
	require_once("../11-14/connMysql.php");
	$sql = "DELETE FROM `students` WHERE `cID` =" . $_POST["cID"];
	mysqli_query($conn,$sql);
	mysqli_close($conn);
	print "OK";
}
?>