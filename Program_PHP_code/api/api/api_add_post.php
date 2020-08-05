<?php 
if(isset($_POST["cName"]) && isset($_POST["cSex"]) && isset($_POST["cBirthday"]) && isset($_POST["cEmail"]) && isset($_POST["cPhone"]) && isset($_POST["cAddr"]) ){
    require_once "../connMysql.php";
    $sql_query = "INSERT INTO `students` (`cName` ,`cSex` ,`cBirthday` ,`cEmail` ,`cPhone` ,`cAddr`) VALUES (";
    $sql_query .= "'".$_POST["cName"]."',";
    $sql_query .= "'".$_POST["cSex"]."',";
    $sql_query .= "'".$_POST["cBirthday"]."',";
    $sql_query .= "'".$_POST["cEmail"]."',";
    $sql_query .= "'".$_POST["cPhone"]."',";
    $sql_query .= "'".$_POST["cAddr"]."')";

    mysqli_query($conn,$sql_query);
    mysqli_close($conn);//關閉資料庫連接
}	
?>