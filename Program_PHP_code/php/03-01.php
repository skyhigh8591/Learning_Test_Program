<!DOCTYPE html><!-- 宣告文件類型 -->
<html lang="zh-tw"><!-- 指定網頁使用的語言 -->
<head><!-- 文件的標頭 -->
<meta charset="utf-8"><!-- 指定網頁編碼 -->
<title></title><!-- 文件標題 -->
</head>
<body><!-- 文件主體 -->
<?php 
    $a=5;
    if($a > 0) 
        echo '$a 變數的值是正數<br>';

    $b=-5;
    if($b >= 0) {
            echo '$b 變數的值是正數<br>';
    }else{
            echo '$b 變數的值是負數<br>';
    }
    
    $score = 85;
    if($score>=60 && $score<70){
            echo '丙等<br>';
    }elseif($score>=70 && $score<80){
            echo '乙等<br>';
    }elseif($score>=80 && $score<90){
            echo '甲等<br>';		
    }elseif($score>=90 && $score<=100){
            echo '優等<br>';		
    }elseif($score<0){
            echo '輸入值有誤<br>';
    }else{
            echo '不及格<br>';
    }
    
?>

</body>
</html>



