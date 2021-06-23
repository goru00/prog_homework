<?php
    require_once 'login.php';
    $link = mysqli_connect($server, $user, $pass, $db)
        or die("Ошибка: " . mysqli_error($link));
    $query = "CREATE TABLE `Игроки` (";
    $query .= "`№ игрока` INT NOT NULL,";
    $query .= "`Страна` VARCHAR(24) NOT NULL,";
    $query .= "`ФИО игрока` VARCHAR(40) NOT NULL,";
    $query .= "`Амплуа` VARCHAR(24) NOT NULL,";
    $query .= "PRIMARY KEY(`№ игрока`, `Страна`)";
    $query .= ");";

    $result = mysqli_query($link, $query)
        or die("Ошибка: " .mysqli_error($link));
    mysqli_close($link);
    header('../index.php');
?>