<?php
if (isset($_POST["cID"])) {
    include("../connMysql.php");
    $sql_query = "DELETE FROM `students` WHERE `cID`=" . $_POST["cID"];
    mysqli_query($conn, $sql_query);
    mysqli_close($conn); //關閉資料庫連接
}
?>