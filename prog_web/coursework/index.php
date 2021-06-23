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
    <nav class="navbar navbar-expand-lg navbar-light bg-light">
        <?php
            require_once 'src/login.php';
            $link = mysqli_connect($server, $user, $pass, $db) or die("Ошибка: " . mysqli_error($link));
            $link->set_charset('utf8');
            $query = "SHOW FULL TABLES WHERE TABLE_TYPE LIKE 'BASE TABLE';";
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
                if ($i != 0) echo "<li class='nav-item nav-link'>Сводная таблица</li>";
            ?>
            </ul>
            </nav>
            <main>
        <div class="container justify-content-center">
            <div class="result"></div>
            <div class="row ">
                <div class="col">
                    <div class="table"></div>
                </div>
                <div class="col">
                    <div class="form_table form-group"></div>
                </div>
            </div>
        </div>
    </main>
    <script src="scripts/main.js"></script>
</body>
</html>