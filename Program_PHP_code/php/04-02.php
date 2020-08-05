<?php
function showdouble1($x2){
	$x2 =$x2 *2;
	print "function的值為:" .$x2."<br>";
}

function showdouble2(&$y2){
	$y2 =$y2 *2;
	print "function的值為:" .$y2."<br>";
}
?>

<!DOCTYPE html>
<html lang="en">
<head>
	<meta charset="UTF-8">
	<title>Document</title>
</head>
<body>
	<?php

	$x1=2;
	showdouble1($x1);
	print "function外的值為:" .$x1."<br>";
	print "<hr>";
	

	$y1=2;
	showdouble2($y1);
	print "function外的值為:" .$y1."<br>";
	print "<hr>";
	
	?>
	
</body>
</html>