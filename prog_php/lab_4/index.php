<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Третьяков</title>
    <link rel="stylesheet" href="css/style.css">
    <script>
    if (window.history.replaceState)
    {
        window.history.replaceState(null, null, window.location.href);
    }
    </script>
    <script src="scripts/ajax.js"></script>
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
        <div class="result"></div>
        <div class="content">
            <?php
                require_once 'src/select.php';
            ?>
        </div>
        <form action="" name="players">
            <input type="hidden" id="num_player_old">
            <input type="hidden" id="country_old">
            <input type="hidden" id="name_player_old">
            <input type="hidden" id="amp_old">
            <label for="num_player">№ игрока: </label>
            <input type="range" id="num_player" name="num_player" min="1" max="25" step="1" value="1" onchange="document.getElementById('num_player_range').innerHTML = this.value">
            <span id="num_player_range">1</span>
            <br>
            <label for="name_player">ФИО игрока: </label>
            <input type="text" id="name_player" name="name_player" placeholder="Введите фамилию и имя хоккеиста" onfocus="this.placeholder = ''" onblur="this.placeholder = 'Введите фамилию и имя хоккеиста'">
            <br>
            <label for="country">Страна: </label>
            <label for="country">
            <input type="radio" id="country" value="Россия" name="country">Р
            </label>
            <label for="country">
            <input type="radio" id="country" value="Чехия" name="country" checked>Ч
            </label>
            <br>
            <label for="amp[]">Амплуа: </label>
            <select name="amp" id="amp">
                <option value="Нападающий">Нападающий</option>
                <option value="Защитник">Защитник</option>
                <option value="Вратарь">Вратарь</option>
            </select>
            <br>
            <input type="button" id="insert" value="Добавить данные" style="cursor: pointer;">
            <input type="button" id="delete" value="Удалить запись" style="cursor: pointer;">
            <input type="button" id="update" value="Изменить данные" style="cursor: pointer;">
            <button type="reset">Сбросить</button>
        </form>
    </main>
    <script src="scripts/main.js"></script>
</body>
</html>