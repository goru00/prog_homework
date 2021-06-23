<?php
    require_once 'login.php';
    if (isset($_POST['country']) && isset($_POST['num_player']) 
    && isset($_POST['amp']) 
    && isset($_POST['name_player']))
    {
        $link = mysqli_connect($server, $user, $pass, $db)
            or die("Ошибка: " . mysqli_error($link));
        $country = htmlentities(mysqli_real_escape_string($link, $_POST['country']));
        $num_player = htmlentities(mysqli_real_escape_string($link, $_POST['num_player']));
        $amp = htmlentities(mysqli_real_escape_string($link, $_POST['amp']));
        $name_player = htmlentities(mysqli_real_escape_string($link, $_POST['name_player']));
        $query = "UPDATE `Игроки` SET `№ игрока`='$num_player', `Страна`='$country', `ФИО игрока`='$name_player', `Амплуа`='$amp' ";
        $query .= "WHERE `№ игрока`='$num_player' AND `Страна`='$country'";
        $result = mysqli_query($link, $query)
            or die("Ошибка" . mysqli_error($link));
        mysqli_close($link);
        header('../index.php');
    }
?>
