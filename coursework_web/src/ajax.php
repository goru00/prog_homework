<?php
    require_once 'login.php';
    $link = mysqli_connect($server, $user, $pass, $db) or die("Ошибка: " . mysqli_error($link));
    $result;
    if (isset($_POST['tab']))
    {
        $val = htmlentities(mysqli_real_escape_string($link, $_POST['tab']));
        if (isset($_POST['status']))
        {
            $status = htmlentities(mysqli_real_escape_string($link, $_POST['status']));
            switch($status)
            {
                case 'insert':
                    break;
                case 'update':
                    break;
                case 'delete':
                    break;
            }
        }
        $query = "select COLUMN_NAME from information_schema.columns where table_name='$val'";
        $result = mysqli_query($link, $query) or die("Ошибка: " . mysqli_error($link));
        $rows = array();
        $count = 0;
        while($row = mysqli_fetch_array($result))
        {
            array_push($rows, $row[0]);
            $count++;
        }
        $thead = array($rows);
        $rows = array();
        $query = "select COLUMN_TYPE from information_schema.columns where table_name='$val'";
        $result = mysqli_query($link, $query) or die("Ошибка: " . mysqli_error($link));
        while($row = mysqli_fetch_array($result))
        {
            array_push($rows, $row[0]);
        }
        $type = array($rows);
        $rows = array();
        $query = "select COLUMN_KEY from information_schema.columns where table_name='$val'";
        $result = mysqli_query($link, $query) or die("Ошибка: " . mysqli_error($link));
        while($row = mysqli_fetch_array($result))
        {
            array_push($rows, $row[0]);
        }
        $key = array($rows);
        $rows = array();
        $query = "select * from $val";
        $result = mysqli_query($link, $query) or die("Ошибка: " . mysqli_error($link));
        $rnum = mysqli_num_rows($result);
        for ($rows_num = 0; $rows_num < $rnum; $rows_num++)
        {
            $cnum = mysqli_fetch_row($result);
            $cell = array();
            for ($cell_num = 0; $cell_num < $count; $cell_num++) {
                array_push($cell, $cnum[$cell_num]);
            }
            array_push($rows, $cell);
        }
        $tbody = $rows;
        $send = array('thead' => $thead, 'type' => $type, 'key' => $key, 'tbody' => $tbody);
        header('Content-Type: application/json');
        echo json_encode($send, JSON_UNESCAPED_UNICODE);
    }
?>