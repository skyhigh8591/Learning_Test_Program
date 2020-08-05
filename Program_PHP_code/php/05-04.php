<!DOCTYPE html><!-- 宣告文件類型 -->
<html lang="zh-tw"><!-- 指定網頁使用的語言 -->
<head><!-- 文件的標頭 -->
<meta charset="utf-8"><!-- 指定網頁編碼 -->
<title>網頁標題文字</title><!-- 文件標題 -->
</head>
<body><!-- 文件主體 -->
<?php
$season = array('春', '夏', '秋', '冬'); 

echo "每年的四季分別為：";

	foreach ($season as $element){
		print $element;
	}

?>
</body>
</html>

