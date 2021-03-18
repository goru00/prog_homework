<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link href="css/style.css" type="text/css" rel="stylesheet">
    <script src="scripts/main.js"></script>
    <title>Document</title>
</head>
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

    $link = mysqli_connect($server, $user, $pass, $db)
        or die("Ошибка: " . mysqli_error($link));
    
    $query = "SELECT * FROM `Игроки`";
    $result = mysqli_query($link, $query)
        or die("Ошибка: " . mysqli_error($link));
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
    }
    mysqli_close($link);
?>
<form method="POST">
    <div class="input__form__select">
        <input type="submit" value="Получить данные" style="cursor: pointer;">
    </div>
</form>
<button onclick="Sort();" style="cursor: pointer;">Отсортировать</button>
<button onclick="window.location.reload();" style="cursor: pointer;">Сбросить</button>
<div class="container">
    <div class="input__form__added">
        <form action="src/insert.php" method="POST">
            <h2>Добавление данных: </h2>
            <p>Номер игрока: </p><input type="number" name="num_player" required>
            <p>Страна: </p><input type="text" name="country">
            <p>ФИО игрока: </p><input type="text" name="name_player">
            <p>Амплуа: </p><input type="text" name="amp"><br>
            <input type="submit" value="Отправить данные" style="cursor: pointer;">
        </form>
    </div>
    <div class="input__form__delete">
        <form action="src/delete.php" method="POST">
            <h2>Удаление данных: </h2>
            <input type="number" name="num_player">
            <input type="submit" value="Отправить данные" style="cursor: pointer;">
        </form>
    </div>
    <div class="input__form__update">
        <form action="src/update.php" method="POST">
            <h2>Обновление данных: </h2>
            <p>Номер игрока: </p><input type="number" name="num_player">
            <p>Страна: </p><input type="text" name="country">
            <p>ФИО игрока: </p><input type="text" name="name_player">
            <p>Амплуа: </p><input type="text" name="amp"><br>
            <input type="submit" value="Отправить данные" style="cursor: pointer;">
        </form>
    </div>
</div>
</main>
</body>
</html>