<?php 
if(isset($_GET["cName"]) && isset($_GET["cSex"]) && isset($_GET["cBirthday"]) && isset($_GET["cEmail"]) && isset($_GET["cPhone"]) && isset($_GET["cAddr"]) ){
    require_once "../connMysql.php";
    $sql_query = "INSERT INTO `students` (`cName` ,`cSex` ,`cBirthday` ,`cEmail` ,`cPhone` ,`cAddr`) VALUES (";
    $sql_query .= "'".$_GET["cName"]."',";
    $sql_query .= "'".$_GET["cSex"]."',";
    $sql_query .= "'".$_GET["cBirthday"]."',";
    $sql_query .= "'".$_GET["cEmail"]."',";
    $sql_query .= "'".$_GET["cPhone"]."',";
    $sql_query .= "'".$_GET["cAddr"]."')";

    mysqli_query($conn,$sql_query);
    mysqli_close($conn);//關閉資料庫連接
}	
?>