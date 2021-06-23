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
    require_once 'src/select.php';
?>
<button onclick="Sort();" style="cursor: pointer;">Отсортировать</button>
<button onclick="window.location.reload();" style="cursor: pointer;">Сбросить</button>
<div class="container">
    <div class="input__form__added">
        <form action="src/insert.php" method="POST">
            <h2>Добавление данных: </h2>
            <p>Номер игрока: </p><input type="number" min="1" max="99" name="num_player" required>
            <p>Страна: </p><input type="text" name="country" required>
            <p>ФИО игрока: </p><input type="text" name="name_player">
            <p>Амплуа: </p><input type="text" name="amp"><br>
            <input type="submit" value="Отправить данные" style="cursor: pointer;">
        </form>
    </div>
    <div class="input__form__delete">
        <form action="src/delete.php" method="POST">
            <h2>Удаление данных: </h2>
            <p>Номер игрока: </p><input type="number" min="1" max="99" name="num_player" required>
            <p>Страна: </p><input type="text" name="country" required>
            <input type="submit" value="Отправить данные" style="cursor: pointer;">
        </form>
    </div>
    <div class="input__form__update">
        <form action="src/update.php" method="POST">
            <h2>Обновление данных: </h2>
            <p>Номер игрока: </p><input type="number" min="1" max="99" name="num_player" required>
            <p>Страна: </p><input type="text" name="country" required>
            <p>ФИО игрока: </p><input type="text" name="name_player">
            <p>Амплуа: </p><input type="text" name="amp"><br>
            <input type="submit" value="Отправить данные" style="cursor: pointer;">
        </form>
    </div>
</div>
</main>
</body>
</html>