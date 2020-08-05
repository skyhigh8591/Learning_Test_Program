<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8" />
<title>Ch7_1_2.php</title>
<?php 
// 函數計算體積
function volume($length, $width=2, $height=3) {
   print $length."x".$width."x".$height."= ";
   return $length * $width * $height; 
}
?>
</head>
<body>
<?php
// 指定變數值
$l = 10;   $w = 12;   $h = 15; 
// 計算盒子體積 
print "盒子體積: ".volume($l, $w, $h)."<br/>";
print "盒子體積: ".volume($l, $w)."<br/>";
print "盒子體積: ".volume($l)."<br/>";
?>
</body>
</html>