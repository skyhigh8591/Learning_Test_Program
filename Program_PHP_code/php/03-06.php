<!DOCTYPE html><!-- 宣告文件類型 -->
<html lang="zh-tw"><!-- 指定網頁使用的語言 -->
<head><!-- 文件的標頭 -->
<meta charset="utf-8"><!-- 指定網頁編碼 -->
<title></title><!-- 文件標題 -->
</head>
<body><!-- 文件主體 -->
<?php 
// 變數宣告
$X = 4;

//sum(1+2+3+4+5+6)
$intSum = 0;
$i = 1;
while($i<=$X){//結束條件
    echo "整數: " . $i . "<br>";
    $intSum += $i;//intSum = intSum + i
    $i++;
}
echo "總和: " . $intSum . "<br><hr>";

//sum(1+3+5+7+9)
$intSum = 0;
$i = 1;
while($i<=$X){//結束條件
    echo "整數: " . $i . "<br>";
    $intSum += $i;//intSum = intSum + i
    $i+=2;
}
echo "總和: " . $intSum . "<br><hr>";

?>

</body>
</html>



