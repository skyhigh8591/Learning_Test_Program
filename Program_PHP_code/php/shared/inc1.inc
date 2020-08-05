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