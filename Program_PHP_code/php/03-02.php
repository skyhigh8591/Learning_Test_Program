<!DOCTYPE html><!-- 宣告文件類型 -->
<html lang="zh-tw"><!-- 指定網頁使用的語言 -->
<head><!-- 文件的標頭 -->
<meta charset="utf-8"><!-- 指定網頁編碼 -->
<title></title><!-- 文件標題 -->
</head>
<body><!-- 文件主體 -->
<?php 
// switdh條件敘述
$grade = 'B';  // 指定變數值
switch ( $grade ) {
   case 'A':
      print "學生成績超過80";
      break;
   case 'B':
      print "學生成績超過70,低於80";
      break;
   case 'C':
      print "學生成績超過60,低於70";
      break;
   default:
      print "學生成績不及格";
}
    
?>

</body>
</html>



