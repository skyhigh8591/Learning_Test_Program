<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8" />
<title></title>
</head>
<body>
	<?php
	$arr=array("color"=>"black","name"=>"marry","shape"=>"circle",200);
	if (!isset($arr["type"])){
		$arr["type"]="php";
		print "新增成功, ";
	}
	$arr["color"]="green";
	foreach($arr as $key=>$value){
		print "$key=>$value ";
	}
	print "<br>";

	?>

</body>
</html>