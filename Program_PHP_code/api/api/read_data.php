<?php
require_once("../connMysql.php");
$sql = "SELECT * FROM `students` ORDER BY `cID`";

if ($result = mysqli_query($conn, $sql)) { 
    //echo "ok";
    while($row=mysqli_fetch_array($result, MYSQLI_ASSOC)){
        $json_arr[]=$row;
    }
    $json_result = json_encode($json_arr,JSON_UNESCAPED_UNICODE);
    echo $json_result; 
}else{
    echo "false";
}

mysqli_close($conn);//關閉資料庫連接
?>
