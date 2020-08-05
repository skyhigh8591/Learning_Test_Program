<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Document</title>
</head>
<body>
    <?php
    function showMe(){
    static $msg;
    $msg +=2;
    echo $msg . "<br>";
}

showMe();
showMe();
showMe();
showMe();
showMe();

?>
    
</body>
</html>