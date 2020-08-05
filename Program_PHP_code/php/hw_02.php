<!DOCTYPE html>
<html lang="en">
<head>
	<meta charset="UTF-8">
	<title>Document</title>
	<style>
		table, th, td{
			border: 1px solid black;
		}
	</style>
</head>
<body>
	
		<?php	
			print("<table>");	
			for($i=1;$i<=9;$i++){
				print("<tr>");
				for($z=1;$z<=9;$z++){
					print("<td>");
					 echo  $i."x".$z."=".$i*$z."	";
					 print("</td>");
				}
				print("</tr>");
			}	
			print("</table>");	    
		?>
			
	
</body>
</html>