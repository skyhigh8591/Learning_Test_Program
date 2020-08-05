<!DOCTYPE html><!-- 宣告文件類型 -->
<html lang="zh-tw"><!-- 指定網頁使用的語言 -->
<head><!-- 文件的標頭 -->
<meta charset="utf-8"><!-- 指定網頁編碼 -->
<title></title><!-- 文件標題 -->
</head>
<body><!-- 文件主體 -->
<?php 
$total = 0;  // 指定變數值
$i = 1;
do { // 無窮迴圈
   echo "|" . $i;
   $total += $i;
   $i++;
   if ( $i > 15 ) break;  // break指令
} while ( true );
echo " ->從1加到15=" . $total . "<br>";
echo "<hr>";


$total = 0;  // 重設變數值
for ( $i = 1; $i <= 15; $i++ ) {
   if ( ($i % 2) == 1 ) continue;  // continue指令
   echo "|" .  $i;
   $total += $i;
}
echo " ->從1到15的偶數總和=" . $total . "<br>";
?>

</body>
</html>



