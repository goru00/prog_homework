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
    <main>
        <?php
            require_once 'src/login.php';
            $link = mysqli_connect($server, $user, $pass, $db) or die("Ошибка: " . mysqli_error($link));
            $query = "show tables";
            $result = mysqli_query($link, $query) or die("Ошибка: " . mysqli_error($link));
        ?>
        <form action="" name="taxi">
            <select name="Taxi[]" onchange="Selection(this.value)">
                <?php
                    while($row = mysqli_fetch_array($result))
                    {
                        echo "<option value=" . $row[0] . ">" . $row[0];
                        echo "</option>";
                    }
                ?>
            </select>
        </form>
        <div class="content">
            Тут Орлов получает плюшки
        </div>
    </main>
</body>
</html>