<?php
if (isset($_GET["cName"]) && isset($_GET["cSex"]) && isset($_GET["cBirthday"]) && isset($_GET["cEmail"]) && isset($_GET["cPhone"]) && isset($_GET["cAddr"]) && isset($_GET["cID"])) {
	//print "ok";
	require_once("../11-14/connMysql.php");
	$sql = "UPDATE `students` SET ";
	$sql.="`cName`='".$_GET["cName"]."',";
	$sql.="`cSex`='".$_GET["cSex"]."',";
	$sql.="`cBirthday`='".$_GET["cBirthday"]."',";
	$sql.="`cEmail`='".$_GET["cEmail"]."',";
	$sql.="`cPhone`='".$_GET["cPhone"]."',";
	$sql.="`cAddr`='".$_GET["cAddr"]."'";
	$sql.=" WHERE `cID` =" . $_GET["cID"];
	//print $sql;
	mysqli_query($conn,$sql);
	mysqli_close($conn);
	print "OK";
}

if (isset($_POST["cName"]) && isset($_POST["cSex"]) && isset($_POST["cBirthday"]) && isset($_POST["cEmail"]) && isset($_POST["cPhone"]) && isset($_POST["cAddr"]) && isset($_POST["cID"])) {
	//print "ok";
	require_once("../11-14/connMysql.php");
	$sql = "UPDATE `students` SET ";
	$sql.="`cName`='".$_POST["cName"]."',";
	$sql.="`cSex`='".$_POST["cSex"]."',";
	$sql.="`cBirthday`='".$_POST["cBirthday"]."',";
	$sql.="`cEmail`='".$_POST["cEmail"]."',";
	$sql.="`cPhone`='".$_POST["cPhone"]."',";
	$sql.="`cAddr`='".$_POST["cAddr"]."'";
	$sql.=" WHERE `cID` =" . $_POST["cID"];
	//print $sql;
	mysqli_query($conn,$sql);
	mysqli_close($conn);
	print "OK";
}
?>