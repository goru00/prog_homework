DROP DATABASE IF EXISTS dubna;
CREATE DATABASE dubna;

use dubna;

DROP TABLE IF EXISTS `Игроки`;

CREATE TABLE `Игроки` (
    `Страна` VARCHAR(32) NOT NULL,
    `№ игрока` INT NOT NULL,
    `ФИО игрока` VARCHAR(48) NOT NULL,
    `Амплуа` VARCHAR(32) NOT NULL,
    PRIMARY KEY(`№ игрока`, `Страна`)
)ENGINE=InnoDB;

INSERT INTO `Игроки` VALUES
('Россия', 1, 'Семен Варламов', 'Вратарь'),
('Россия', 3, 'Евгений Малкин', 'Нападающий'),
('Россия', 4, 'Вячеслав Войнов', 'Защитник'),
('Чехия', 3, 'Баринка Михаил', 'Защитник'),
('Чехия', 2, 'Хемски Алеш', 'Нападающий'),
('Чехия', 1, 'Павелец Оджий', 'Вратарь');