<?php
require_once("connMysql.php");
$sql = "SELECT * FROM `students`";


// mysqli_close($conn);
?>
<!DOCTYPE html>
<html lang="en">
<head>
	<meta charset="UTF-8">
	<title>Document</title>
</head>
<body>
	<?php
		if($result=mysqli_query($conn,$sql)){
			$toal_records=mysqli_num_rows($result);
	?>

	<h1 align="center">學生資料管理系統</h1>
	<p align="center">目前資料筆數:<?php print $toal_records ?>,<a href="add.php">新增學生資料</a></p>
	<table border="1" align="center">
		<tr>
			<td align="center">座號</td>
			<td align="center">姓名</td>
			<td align="center">性別</td>
			<td align="center">生日</td>
			<td align="center">電子郵件</td>
			<td align="center">電話</td>
			<td align="center">住址</td>
			<td align="center">功能</td>
		</tr>
	<?php
		while ($row=mysqli_fetch_assoc($result)) {
			print"<tr>";
			print "<td>".$row["cID"]."</td>";
			print "<td>".$row["cName"]."</td>";
			print "<td>".$row["cSex"]."</td>";
			print "<td>".$row["cBirthday"]."</td>";
			print "<td>".$row["cEmail"]."</td>";
			print "<td>".$row["cPhone"]."</td>";
			print "<td>".$row["cAddr"]."</td>";
			print "<td><a href='update.php?id=".$row["cID"]."'> 修改 </a>";
			print "<a href='delete.php?id=".$row["cID"]."'> 刪除 </a></td>";			

			//print "<td><a  href='update.php?id=01'>修改<a>"

			
			print"</tr>";
		}
	print "</table>";
	}
	?>
</body>
</html>
<?php
mysqli_close($conn);
?>
