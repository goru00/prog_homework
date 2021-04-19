DROP DATABASE IF EXISTS dubna;
CREATE DATABASE dubna;
use dubna;

DROP TABLE IF EXISTS `Игроки`;

CREATE TABLE `Игроки` (
    `№ игрока` INT NOT NULL,
    `ФИО игрока` VARCHAR(40) NOT NULL,
    `Страна` VARCHAR(24) NOT NULL,
    `Амплуа` VARCHAR(24) NOT NULL,
    PRIMARY KEY(`№ игрока`, `Страна`)
)ENGINE=InnoDB;