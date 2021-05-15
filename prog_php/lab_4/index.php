<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Третьяков</title>
    <link rel="stylesheet" href="style/style.css">
    <script src="scripts/ajax.js"></script>
    <link rel="stylesheet" href="style/bootstrap.min.css">
    <link rel="stylesheet" href="style/bootstrap.css">
</head>
<style>
sub
{
    color: red;
    font-size: 18px;
}
</style>
<body>
    <header>
        <h1>
        Третьяков Дмитрий
        <br>
        Вариант 17 ИВТ-31
        </h1>
    </header>
    <nav class="navbar navbar-expand-lg navbar-light bg-light">
        <?php
            require_once 'src/login.php';
            $link = mysqli_connect($server, $user, $pass, $db) or die("Ошибка: " . mysqli_error($link));
            $link->set_charset('utf8');
            $query = "show tables";
            $result = mysqli_query($link, $query) or die("Ошибка: " . mysqli_error($link));
        ?>
            <ul id="list" class="nav justify-content-center nav-tabs">
            <?php
                $i = 0;
                while($row = mysqli_fetch_array($result))
                {
                    if ($i == 0) echo "<li class='active nav-item nav-link'>" . $row[0] . "</li>";
                    else echo "<li class='nav-item nav-link'>" . $row[0] . "</li>";
                    $i++;
                }
            ?>
            </ul>
            </nav>
            <main>
        <div class="container">
            <div class="result"></div>
            <div class="table col-md"></div>
            <div class="form_table form-group">
                <p class="text-md-left" style="color: red;">Поле с «*» обязательно к заполнению.</p>
                <div class="input_form">
                    <form action="" name="taxi"></form>
                </div>
                <div class="button_confirm">
                    <button class="btn btn-primary" id="insert">Добавить запись</button>
                    <button class="btn btn-primary" id="delete">Удалить запись</button>
                    <button class="btn btn-primary" id="update">Изменить запись</button>
                    <button class="btn btn-danger" onclick="window.location.reload();">Сбросить</button>
                </div>
            </div>
        </div>
    </main>
    <script src="scripts/main.js"></script>
</body>
</html>