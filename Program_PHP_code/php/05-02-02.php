<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8" />
<title></title>
</head>
<body>
	<?php
		$row0 = array(64,65);
		$row1 = array(77,81);
        $row2 = array(89,93);

        $grades = array($row0,$row1,$row2);
        $grades[1][0] = 100;
		$total= 0;

		foreach ($grades as $matrix1){
			$sum=0;
			foreach ($matrix1 as $element){
				print $element . " ";
				$sum += $element;
				$total += $element;
			}
			print "成績小計:" . $sum . "<br>";
		}
		print "總成績:" . $total . "<br>";


		// for ($i=0;$i<count($grades);$i++){
		// 	$sum=0;
		// 	for ($j=0;$j<count($grades[$i]);$j++){
		// 		print $grades[$i][$j] . " ";
		// 		$sum += $grades[$i][$j];
		// 		$total +=$grades[$i][$j];
		// 	}
		// 	print "成績小計:" . $sum . "<br>";

		// }

		// print "總成績:" . $total . "<br>";
	?>

</body>
</html>