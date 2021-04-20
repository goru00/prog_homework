<?php
    require_once 'login.php';
    if (isset($_POST['status']))
    {
        $link = mysqli_connect($server, $user, $pass, $db) or die("Ошибка: " . mysqli_error($link));
        $status = htmlentities(mysqli_real_escape_string($link, $_POST['status']));
        $result;
        switch($status)
        {
            case 'select':
                if (isset($_POST['tab']))
                {
                    $val = htmlentities(mysqli_real_escape_string($link, $_POST['tab']));
                    $tab = "<table border=1 cellpadding=2>";
                    $thead = "<thead><tr>";
                    $query = "select COLUMN_NAME from information_schema.columns where table_name='$val'";
                    $result = mysqli_query($link, $query) or die("Ошибка: " . mysqli_error($link));
                    $count = 0;
                    while($row = mysqli_fetch_array($result))
                    {
                        $thead .= "<td>" . $row[0] . "</td>";
                        $count += 1;
                    }
                    $query = "select * from $val";
                    $result = mysqli_query($link, $query) or die("Ошибка: " . mysqli_error($link));
                    $thead .= "</tr></thead>";
                    $tab .= $thead;
                    $tab .= "<tbody>";
                    $rows = mysqli_num_rows($result);
                    if ($rows == 0) echo "<p>Таблица пуста</p>";
                    else {
                        for ($rows_num = 0; $rows_num < $rows; $rows_num++)
                        {
                            $row = mysqli_fetch_row($result);
                            $tab .= "<tr>";
                            for ($cell_num = 0; $cell_num < $count; $cell_num++) $tab .= "<td>$row[$cell_num]</td>";
                            $tab .= "</tr>";
                        }
                        $tab .= "</tbody></table>";
                    }
                    echo $tab;
                }
                break;
            case 'type':
                if (isset($_POST['tab']))
                {
                    $val = htmlentities(mysqli_real_escape_string($link, $_POST['tab']));
                    $query = "select column_type from information_schema.columns where table_name='$val'";
                    $result = mysqli_query($link, $query) or die("Ошибка: " . mysqli_error($link));
                    $tab;
                    while ($row = mysqli_fetch_array($result))
                    {
                        $tab .= $row[0] . ";";
                    }
                    echo $tab;
                }
                break;
        }
    }
?>