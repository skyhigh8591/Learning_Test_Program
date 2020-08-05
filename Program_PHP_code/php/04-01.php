<!DOCTYPE html>
<html>

<head>
    <meta charset="utf-8" />
    <title>sample</title>
    <?php 
// 無輸入無輸出
    function showHeader(){
      echo "<hr>";
      print "<h3>PHP的自訂函數</h3>";

    }

// 輸入2變數，輸出1變數
// 函數計算N加到M
    function sumN2N($begin, $end) {
      $sum = 0;
      for ($i = $begin; $i <= $end; $i++) 
      { 
        $sum +=$i; 
      } 
      return $sum; 
    }

// 輸入2變數，輸出2變數
// 函數計算相加相減
    function test($num1, $num2) {
      $sumnum = $num1 + $num2;
      $cutnum = $num1 - $num2;
      return array($sumnum,$cutnum);
    }
    ?>
</head>

<body>
<?php
showHeader();
/////////////////////////////////////////////////////
$sum1 = sumN2N(1, 100); // 呼叫函數
$sum2 = sumN2N(1, 10);
print "<p>從1加到100為:" . $sum1 . "</p>";
print "<p>從1加到10為:" . $sum2 . "</p>";
/////////////////////////////////////////////////////
$return_value = test(50,10);// 呼叫函數
$return_value_count = count($return_value);//回傳數量
print "<p>相加等於" . $return_value[0] . "</p>";
print "<p>相減等於" . $return_value[1] . "</p>";
print "<p>陣列數量等於" . $return_value_count;

print "<hr>";

for($i=0;$i<$return_value_count;$i++){
  print "<p>列印:".$return_value[$i]."<p>";
}


?>
</body>

</html>