<?php
    require_once 'login.php';
    $link = mysqli_connect($server, $user, $pass, $db) or die("Ошибка: " . mysqli_error($link));
    $link->set_charset('utf8');
    header("Content-Type: application/json");
    $postData = file_get_contents("php://input");
    $dataPost = json_decode($postData);
    if (isset($dataPost->tab))
    {
        $msg;
        $val = htmlentities(mysqli_real_escape_string($link, $dataPost->tab));
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
        if (isset($dataPost->status))
        {
            $status = htmlentities(mysqli_real_escape_string($link, $dataPost->status));
            switch($status)
            {
                case 'insert':
                    $query = "INSERT INTO '$val' VALUES (";
                    for ($num = 0; $num < $count; $num++) {
                        if ($num + 1 == $count) $query .= "'$dataPost->data[$num]');";
                        else $query .= "'$dataPost->data[$num]',";
                    }
                    $result = mysqli_query($link, $query);
                    if ($result) $msg = "<div class='alert alert-success' role='alert'>Запись была успешно добавлена!</div>";
                    else $msg = "<div class='alert alert-danger' role='alert'>Невозможно добавить запись! Такая запись уже существует!</div>";
                    break;
                case 'update':
                    break;
                case 'delete':
                    break;
            }
        }
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