<?php
    require_once 'login.php';
    $link = mysqli_connect($server, $user, $pass, $db) or die("Ошибка: " . mysqli_error($link));
    $tab = "<table border=1 cellpadding=2>";
    $thead = "<thead><tr>";
    /* опционально. этот момент с select я поправлю в курсовой */
    $query = "select COLUMN_NAME from information_schema.columns where table_name='Игроки' order by COLUMN_NAME DESC";
    $result = mysqli_query($link, $query) or die("Ошибка: " . mysqli_error($link));
    while($row = mysqli_fetch_array($result))
    {
        $thead .= "<td>" . $row[0] . "</td>";
    }
    $thead .= "</tr></thead>";
    $query = "select * from `Игроки`";
    $result = mysqli_query($link, $query) or die("Ошибка: " . mysqli_error($link));
    $rows = mysqli_num_rows($result);
    if ($rows == 0) echo "<p>Таблица пуста</p>";
    else {
        $tab .= $thead;
        $tab .= "<tbody>";
        for ($rows_num = 0; $rows_num < $rows; $rows_num++)
        {
            $row = mysqli_fetch_row($result);
            $tab .= "<tr>";
            for ($cell_num = 0; $cell_num < 4; $cell_num++) $tab .= "<td>$row[$cell_num]</td>";
            $tab .= "</tr>";
        }
        $tab .= "</tbody></table>";
        echo $tab;
    }
?>