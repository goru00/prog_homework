<?php
// здесь начинаются проверки по regexp
if ($status != "select") {
    if ($dataPost->tab == "водители") {
        if (!preg_match('/^[0-9]{3}-[0-9]{3}-[0-9]{2}-[0-9]{2}/', $dataPost->data[0][2])) {
            $msg = '<div class="alert alert-danger" role="alert">Номер телефона должен быть в формате XXX-XXX-XX-XX .</div>';
            array_push($rows, $msg);
            $flag = false;
        }
        if (!preg_match('/^[а-яё\s]++$/ui', $dataPost->data[0][1])) {
            $msg = '<div class="alert alert-danger" role="alert">ФИО водителя должно состоять из кириллицы!</div>';
            array_push($rows, $msg);
            $flag = false;
        }
    }
    if ($dataPost->tab == "водители" || $dataPost->tab == "поездки") {
        if (!preg_match('/^[A-Z]\d{3}(?<!000)[A-Z]{2}\d{2,4}$/ui', $dataPost->data[0][0])) {
            $msg = '<div class="alert alert-danger" role="alert">Текст в поле "Гос.номер" должен быть формата X000XX000, либо X000XX00 .</div>';
            array_push($rows, $msg);
            $flag = false;
        }
    }
    if ($dataPost->tab == "поездки") {
        if (!preg_match('/^(19|20)[0-9]{2}-(0[1-9]|1[0-2])-(0[1-9]|[12][0-9]|3[01])$/ui', $dataPost->data[0][1])) {
            $msg = '<div class="alert alert-danger" role="alert">Поле "Дата" должно находиться в диапазоне 19xx-20xx .</div>';
            array_push($rows, $msg);
            $flag = false;
        }
        if ($dataPost->data[0][4] < 0 || $dataPost->data[0][4] > 60) {
            $msg = '<div class="alert alert-danger" role="alert">Поле "Время ожидания у клиента" должны быть в диапазоне 0-60</div>';
            array_push($rows, $msg);
            $flag = false;
        }
    }
    if ($dataPost->tab == "марки автомобилей") {
        if ($dataPost->data[0][1] < 0 || $dataPost->data[0][1] > 60) {
            $msg = '<div class="alert alert-danger" role="alert">Поле "Минуты простоя" должны быть в диапазоне 0-60</div>';
            array_push($rows, $msg);
            $flag = false;
        }
    }
}
?>