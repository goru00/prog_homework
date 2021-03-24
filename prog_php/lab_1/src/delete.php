<?php
    require_once 'login.php';
    if (isset($_POST['num_player']))
    {
        $link = mysqli_connect($server, $user, $pass, $db)
            or die("Ошибка: " . mysqli_error($link));
        $num_player = mysqli_real_escape_string($link, $_POST['num_player']);

        $query = "DELETE FROM `Игроки` WHERE `№ игрока` = '$num_player'";
        $result = mysqli_query($link, $query)
            or die("Ошибка: " . mysqli_error($link));
        mysqli_close($link);
        header('Location: ../index.php');
    }
?>