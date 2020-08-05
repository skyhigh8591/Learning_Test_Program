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
$intSum = 0;

// 迴圈敘述
//sum(1+2+3+4+5+6)
for ($i = 1; $i <= $X; $i++){//i=1:初始值、i<=5:結束條件、i++:每次遞增1
    echo "整數: " . $i . "<br>";
    $intSum += $i;//intSum = intSum + i
}
echo "總和: " . $intSum . "<br><hr>";
    

$X = 4;
$intSum = 0;//故意拿掉
// 迴圈敘述
//1+3+5+7
for ($i = 1; $i <= $X; $i+=2){//i=1:初始值、i<=5:結束條件、i++:每次遞增1
    echo "整數: " . $i . "<br>";
    $intSum += $i;//intSum = intSum + i
}
echo "總和: " . $intSum . "<br><hr>";


?>

</body>
</html>



