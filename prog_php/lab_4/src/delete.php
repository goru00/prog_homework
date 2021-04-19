<?php
    require_once 'login.php';
    if (isset($_POST['num_player']) && isset($_POST['country']) && isset($_POST['name_player']) && isset($_POST['amp']))
    {
        $link = mysqli_connect($server, $user, $pass, $db) or die("Ошибка: " . mysqli_error($link));
        $query = "select exists(select * from `Игроки` WHERE `№ игрока`='$num_player'  AND `Страна`='$country' AND `ФИО игрока`='$name_player' AND `Амплуа`='$amp')";
        $result = mysqli_query($link, $query);
        $row = mysqli_fetch_row($result);
        if ($row[0] > 0)
        {
            $query = "DELETE FROM `Игроки` WHERE `№ игрока` = '$num_player' AND `Страна` = '$country'";
            $result = mysqli_query($link, $query);
            if (!$result) echo "<h1>Невозможно удалить запись: </h1>" . mysqli_error($link);
        } else echo "<p>Запись с такими полями № игрока = $num_player, Страна = $country, ФИО игрока = $name_player, Амплуа = $amp не существует!</p>";
        mysqli_close($link);
    }
?>