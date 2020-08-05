<?php
require_once("connMysql.php");
//預設每頁筆數
$pageRow_records=3;
//預設頁
$num_pages=2;

if (isset($_GET["page"])) {
	$num_pages=$_GET["page"];
}

//1 (1-1)*3=0
//2 (2-1)*3=3
//3 (3-1)*3=6
$startRow_records=($num_pages-1)*$pageRow_records;
$sql="SELECT * FROM `students` ";
$sql_limit = $sql . "LIMIT " . $startRow_records . "," . $pageRow_records;

$result=mysqli_query($conn,$sql_limit);
$all_result = mysqli_query($conn,$sql);

$toal_records = mysqli_num_rows($all_result);//計算總筆數
$total_pages=ceil($toal_records/$pageRow_records);//計算總頁數
//print $total_pages;
//print $sql_limit;
// mysqli_close($conn);
?>
<!DOCTYPE html>
<html lang="en">
<head>
	<meta charset="UTF-8">
	<title>Document</title>
</head>
<body>
 <!-- 	<?php
		 //if($result=mysqli_query($conn,$sql)){
		 	//$toal_records=mysqli_num_rows($result);
	?> -->

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
	print "<table border = '0' align = 'center'>";
	print "<tr>";

	if($num_pages>1){
		print "<td> <a href='data_page.php?page=1'>第一頁</a> </td>";
		print "<td> <a href='data_page.php?page=".($num_pages-1)."'>上一頁</a></td>";
	}
	if($num_pages<$total_pages){
		print "<td> <a href='data_page.php?page=".($num_pages+1)."'>下一頁</a></td>";
		print "<td> <a href='data_page.php?page=$total_pages'>最後一頁</a></td>";
	}

	print "</tr>";
	print "</table>";

	print "</table>";
	print "<table border = '0' align = 'center'>";
	print "<tr>";
	print "<td>頁數</td>";
	for ($i=1; $i<=$total_pages ; $i++) { 
		print "<td>";
		if ($i==$num_pages) {
			print $i;
		}else{
			print "<a href='data_page.php?page=$i'>$i</a>";
		}
		print "</td.";
	}
	print "</tr>";
	print "</table>";
	 // }
	?>
</body>
</html>
<?php
mysqli_close($conn);
?>
