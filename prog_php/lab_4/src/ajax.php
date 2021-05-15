<?php
    mb_internal_encoding ("utf-8");
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
        $rows = array();
        if (isset($dataPost->status))
        {
            $flag = true;
            $status = htmlentities(mysqli_real_escape_string($link, $dataPost->status));
            switch($status)
            {
                case 'insert':
                    if ($flag)
                    {
                        $query = "INSERT INTO `$val` VALUES (";
                        for ($num = 0; $num < $count; $num++) {
                            $value = $dataPost->data[0][$num];
                            if ($num + 1 == $count) $query .= "'$value');";
                            else $query .= "'$value',";
                        }
                        $result = mysqli_query($link, $query);
                        if (!$result) $msg = "<div class='alert alert-danger'>" . mysqli_error($link) . "</div>";
                        else $msg = "<div class='alert alert-success' role='alert'>Запись была успешно добавлена!</div>";
                        array_push($rows, $msg);
                    }
                    break;
                    // начинается полная каша, но рефакторинг будет потом(если будет)
                case 'update':
                    if ($flag)
                    {
                        $query = "select exists(select * from `$val` WHERE ";
                        $queryNew = "";
                        $queryOld = "";
                        for ($num = 0; $num < $count; $num++)
                        {
                            $name = $thead[0][$num];
                            $valueNew = $dataPost->data[0][$num];
                            $valueOld = $dataPost->dataOld[0][$num];
                            if ($num + 1 == $count) {
                                $queryNew .= "`$name`='$valueNew'";
                                $queryOld .= "`$name`='$valueOld'";
                            }
                            else {
                                $queryNew .= "`$name`='$valueNew', ";
                                $queryOld .= "`$name`='$valueOld' AND ";
                            }
                        }
                        $query .= $queryOld . ")";
                        $result = mysqli_query($link, $query);
                        $row = mysqli_fetch_row($result);
                        if ($row[0] > 0)
                        {
                            $query = "UPDATE `$val` SET " . $queryNew . " WHERE " . $queryOld;
                            $result = mysqli_query($link, $query);
                            if (!$result) $msg = "<div class='alert alert-danger'>" . mysqli_error($link) . "</div>";
                            else $msg = "<div class='alert alert-success' role='alert'>Запись была успешно обновлена!</div>";
                        } else $msg = "<div class='alert alert-danger' role='alert'>Такой записи не существует!</div>";
                        array_push($rows, $msg);
                    }
                    break;
                case 'delete':
                    if ($flag)
                    {
                        $query = "select exists(select * from `$val` WHERE ";
                        $query_del = "";
                        for ($num = 0; $num < $count; $num++)
                        {
                            $name = $thead[0][$num];
                            $value = $dataPost->data[0][$num];
                            if ($num + 1 == $count) $query_del .= "`$name`='$value'";
                            else $query_del .= "`$name`='$value' AND ";
                        }
                        $query .= $query_del . ")";
                        $result = mysqli_query($link, $query);
                        $row = mysqli_fetch_row($result);
                        if ($row[0] > 0)
                        {
                            $query = "DELETE FROM `$val` WHERE " . $query_del;
                            $result = mysqli_query($link, $query);
                            if (!$result) $msg = "<div class='alert alert-danger'>" . mysqli_error($link) . "</div>";
                            else $msg = "<div class='alert alert-success' role='alert'>Запись была успешно удалена!</div>";
                        } else $msg = "<div class='alert alert-danger' role='alert'>Такой записи не существует!</div>";
                        array_push($rows, $msg);
                        break;
                    }
            }
        }
        $msg = array($rows);
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
        $send = array('thead' => $thead, 'type' => $type, 'key' => $key, 'tbody' => $tbody, 'msg' => $msg);
        header('Content-Type: application/json');
        echo json_encode($send, JSON_UNESCAPED_UNICODE);
    }
?>