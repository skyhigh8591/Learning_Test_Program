<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8" />
<title></title>
</head>
<body>
<?php
    $msg = "這是全域變數<br>";
    function showMsg(){
            //$msg = "這是區域變數<br>";
            global $msg;		 
            echo $msg;
    }
    echo $msg;
    showMsg();
    echo $msg;


    print "<hr>";

    $GLOBALS["msg2"]="bbbbbbbbb<br>";

    function showMsg2(){
    	print $GLOBALS["msg2"];
    }
    showMsg2();

    ///////////////////////////

    function showMsg3(){
    	global $ms1;
    	$ms1 = "dddddddddd<br>";
    	print $ms1;
    }
    showMsg3();
    print $ms1;
    
?>
</body>
</html>