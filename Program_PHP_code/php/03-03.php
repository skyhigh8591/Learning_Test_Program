<!DOCTYPE html><!-- 宣告文件類型 -->
<html lang="zh-tw"><!-- 指定網頁使用的語言 -->
<head><!-- 文件的標頭 -->
<meta charset="utf-8"><!-- 指定網頁編碼 -->
<title></title><!-- 文件標題 -->
</head>
<body><!-- 文件主體 -->
<?php 
$a = 100;
$b = "100";

$result1 = ($a == $b) ? "the same" : "different";

$result2 = ($a === $b) ? "the same" : "different";

echo "第一種:" . $result1 . "<br>";
echo "第二種:" . $result2 . "<br>";
   
?>

</body>
</html>



