<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8" />
<title></title>
</head>
<body>
<?php
// 指定陣列元素
$grades = array(78, 55, 89, 93);
// 計算成績總分
$grades[2] = 65;  // 更改陣列值
$total = 0;
for ( $i = 0; $i < count($grades); $i++ ) {
   echo "$i=>$grades[$i]";
   $total += $grades[$i];
}
echo "<br>成績總分: ".$total."<br>";

echo "////////////////////////////<br>";
$weekArray[] = 'Sunday';//同$weekArray[0] 
$weekArray[] = 'Monday';//同$weekArray[1] 
$weekArray[] = 'Tuesday';//同$weekArray[2] 
$weekArray[] = 'Wednesday';//同$weekArray[3] 
$weekArray[] = 'Thursday';//同$weekArray[4] 
$weekArray[] = 'Friday';//同$weekArray[5] 
$weekArray[] = 'Saturday';//同$weekArray[6] 
$weekArray[2] = 'Tue'; 

foreach ($weekArray as $element) {
	print "$element<br>";
}



?>

</body>
</html>