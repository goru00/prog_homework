<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Третьяков</title>
    <link rel="stylesheet" href="style/style.css">
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
    <nav>
        <?php
            require_once 'src/login.php';
            $link = mysqli_connect($server, $user, $pass, $db) or die("Ошибка: " . mysqli_error($link));
            $query = "show tables";
            $result = mysqli_query($link, $query) or die("Ошибка: " . mysqli_error($link));
        ?>
            <ul id="list" class="list_table">
            <?php
                $i = 0;
                while($row = mysqli_fetch_array($result))
                {
                    if ($i == 0) echo "<li class='active'>" . $row[0] . "</li>";
                    else echo "<li>" . $row[0] . "</li>";
                    $i++;
                }
            ?>
            </ul>
            </nav>
            <main>
        <div class="result"></div>
        <div class="content">
            <div class="table"></div>
            <div class="form_table">
                <div class="input_form">
                    <form action="" name="taxi"></form>
                </div>
                <button>Добавить запись</button>
                <button>Удалить запись</button>
                <button>Изменить запись</button>
            </div>
        </div>
    </main>
    <script src="scripts/main.js"></script>
</body>
</html>