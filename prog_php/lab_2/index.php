<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="UTF-8">
<meta http-equiv="X-UA-Compatible" content="IE=edge">
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<title>Третьяков</title>
<style>
    tbody > tr
    {
        cursor: pointer;
    }
    thead
    {
        font-weight: bold;
    }
</style>
</head>
<!-- решает проблему с повторной отправки формы -->
<script>
    if (window.history.replaceState)
    {
        window.history.replaceState(null, null, window.location.href);
    }
</script>
<body>
    <header>
    <h1>
    Третьяков Дмитрий
    <br>
    Вариант 17 ИВТ-31
    </h1>
    </header>
    <main>
    <?php
        require_once 'src/login.php';
        $link = mysqli_connect($server, $user, $pass, $db) or die("Ошибка: " . mysqli_error($link));
    if ($link)
    {
        if (isset($_POST['country']) && isset($_POST['num_player']) && isset($_POST['amp']) && isset($_POST['name_player']) && isset($_POST['Ok'])) {
            $country = htmlentities(mysqli_real_escape_string($link, $_POST['country']));
            $num_player = htmlentities(mysqli_real_escape_string($link, $_POST['num_player']));
            $amp = htmlentities(mysqli_real_escape_string($link, $_POST['amp']));
            $name_player = htmlentities(mysqli_real_escape_string($link, $_POST['name_player']));
            $Ok = htmlentities(mysqli_real_escape_string($link, $_POST['Ok']));
            switch($Ok)
            {
                case "insert":
                    $query = "INSERT INTO `Игроки` VALUES ('$num_player', '$country', '$name_player', '$amp');";
                    $result = mysqli_query($link, $query);
                    if (!$result) echo "<h1>Невозможно добавить запись: </h1>" . mysqli_error($link);
                    break;
                case "update":
                    if (isset($_POST['country_old']) && isset($_POST['num_player_old']) && isset($_POST['name_player_old']) && isset($_POST['amp_old']))
                    {
                        $country_old = htmlentities(mysqli_real_escape_string($link, $_POST['country_old']));
                        $num_player_old = htmlentities(mysqli_real_escape_string($link, $_POST['num_player_old']));
                        $amp_old = htmlentities(mysqli_real_escape_string($link, $_POST['amp_old']));
                        $name_player_old = htmlentities(mysqli_real_escape_string($link, $_POST['name_player_old']));
                        $query = "UPDATE `Игроки` SET `№ игрока`='$num_player', `Страна`='$country', `ФИО игрока`='$name_player', `Амплуа`='$amp' ";
                        $query .= "WHERE `№ игрока`='$num_player_old' AND `Страна`='$country_old' AND `ФИО игрока`='$name_player_old' AND `Амплуа`='$amp_old'";
                        $result = mysqli_query($link, $query);
                        if (!$result) echo "<h1>Невозможно обновить запись: </h1>" . mysqli_error($link);
                        break;
                    }
                case "delete":
                    $query = "select exists(select * from `Игроки` WHERE `№ игрока`='$num_player'  AND `Страна`='$country' AND `ФИО игрока`='$name_player' AND `Амплуа`='$amp')";
                    $result = mysqli_query($link, $query);
                    $row = mysqli_fetch_row($result);
                    if ($row[0] > 0)
                    {
                        $query = "DELETE FROM `Игроки` WHERE `№ игрока` = '$num_player' AND `Страна` = '$country'";
                        $result = mysqli_query($link, $query);
                        if (!$result) echo "<h1>Невозможно удалить запись: </h1>" . mysqli_error($link);
                    } else echo "<p>Запись с такими полями № игрока = $num_player, Страна = $country, ФИО игрока = $name_player, Амплуа = $amp не существует!</p>";
                    break;
                default:
                    break;
            }
        }
        $query = "SELECT * FROM `Игроки`";
        $result = mysqli_query($link, $query);
        if ($result)
        {
            $rows = mysqli_num_rows($result);
            if ($rows == 0) echo "<p>Таблица пуста</p>";
            else {
                echo "<table border='2' cellpadding='30' cellspacing='5' align='center'><thead><tr><td>№ игрока</td><td>Страна</td><td>ФИО игрока</td><td>Амплуа</td></thead><tbody>";
                for ($rows_num = 0; $rows_num < $rows; ++$rows_num)
                {
                    $row = mysqli_fetch_row($result);
                    echo "<tr>";
                    for ($cell_num = 0; $cell_num < 4; ++$cell_num) echo "<td>$row[$cell_num]</td>";
                    echo "</tr>";
                }
                echo "</tbody></table>";
            }
            mysqli_free_result($result);
        } else {
            $query = "CREATE TABLE `Игроки` (
            `№ игрока` INT NOT NULL,
            `Страна` VARCHAR(24) NOT NULL,
            `ФИО игрока` VARCHAR(48) NOT NULL,
            `Амплуа` VARCHAR(24) NOT NULL,
            PRIMARY KEY(`№ игрока`,`Страна`)
            )";
            $result = mysqli_query($link, $query) or die("Ошибка: " .mysqli_error($link));
            echo $result;
        }
    }
    mysqli_close($link);

    ?>
        <button onclick="Sort();" style="cursor: pointer;">Отсортировать</button>
        <button onclick="window.location.reload();" style="cursor: pointer;">Сбросить</button>
        <div class="container">
            <div class="input__form__added">
                <form action="" method="POST">
                    <input type="hidden" id="num_player_old">
                    <input type="hidden" id="country_old">
                    <input type="hidden" id="name_player_old">
                    <input type="hidden" id="amp_old">
                    <h2>Работа с БД: </h2>
                    <p>Номер игрока: </p><input type="number" id="num_player" min="1" max="99" name="num_player" required>
                    <p>Страна: </p><input type="text" id="country" name="country" required>
                    <p>ФИО игрока: </p><input type="text" id="name_player" name="name_player">
                    <p>Амплуа: </p><input type="text" id="amp" name="amp"><br>
                    <button type="submit" name="Ok" id="insert" value="insert" style="cursor: pointer;">Добавить данные</button>
                    <button type="submit" name="Ok" id="delete" value="delete" style="cursor: pointer;">Удалить запись</button>
                    <button type="submit" name="Ok" id="update" value="update" style="cursor: pointer;">Изменить данные</button>
                </form>
            </div>
        </div>
    </main>
<script src="scripts/main.js"></script>
</body>
</html>