<!DOCTYPE html>
<html lang="en">
<head>
	<meta charset="UTF-8">
	<title>Document</title>
	<style type="text/css">
		body{
			background-color:#d1fce8; 
		}
	</style>
</head>
<body>
	<?php
		print("<h2>");
		print($_GET["username"]);

		if($_GET["userage"] == ["age1"]){
			print("先生你好!"."<br>");
		}else{
			print("小姐你好!"."<br>");
		}
		print("</h2>");

		print("你的學歷為:".$_GET["usernumber"]."<br>");
		print("你喜歡那些活動如下:"."<br>");
		print("<ul>");
		foreach ($_GET["userphone"] as $value) {
			print("<li>".$value."</li>");
		}
		print("</ul>");

		print("您對於使用臉書經營社群有何看法為:"."<br>");
		print($_GET["usertrouble"]);


	?>
</body>
</html>