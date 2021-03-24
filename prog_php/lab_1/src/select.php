<?php
    require_once 'login.php';

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
    header('../index.php');
?>