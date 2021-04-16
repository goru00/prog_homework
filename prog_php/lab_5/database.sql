DROP DATABASE dubna;
CREATE DATABASE dubna;
/* -1-2- */
USE dubna;
DROP TABLE IF EXISTS `Поездки`;
DROP TABLE IF EXISTS `Водители`;
DROP TABLE IF EXISTS `Марки_автомобилей`;
CREATE TABLE `Марки_автомобилей` (
	`Модель автомобиля` CHAR(35) NOT NULL,
	`Минуты простоя` INT NOT NULL,
	`Километра проезда` INT NOT NULL,
	PRIMARY KEY(`Модель автомобиля`)
) ENGINE=InnoDB;
CREATE TABLE `Водители` (
	`Гос.номер` VARCHAR(12) NOT NULL,
	`ФИО Водителя` VARCHAR(36) NOT NULL,
	`Телефон` CHAR(16) NOT NULL,
	`Модель автомобиля` CHAR(35) NOT NULL,
	PRIMARY KEY(`Гос.номер`),
	FOREIGN KEY(`Модель автомобиля`) 
	REFERENCES `Марки_автомобилей`(`Модель автомобиля`)
	ON DELETE RESTRICT ON UPDATE CASCADE
) ENGINE=InnoDB;
CREATE TABLE `Поездки` (
	`Гос.номер` VARCHAR(12) NOT NULL,
	`Дата` DATE NOT NULL,
	`Время вызова` TIME NOT NULL,
	`Время завершения` TIME NOT NULL,
	`Время ожидания у клиента` INT NOT NULL,
	`Расстояние` INT NOT NULL,
	PRIMARY KEY(`Гос.номер`, `Дата`, `Время вызова`),
	FOREIGN KEY(`Гос.номер`) 
	REFERENCES `Водители`(`Гос.номер`) 
	ON DELETE RESTRICT ON UPDATE CASCADE
) ENGINE=InnoDB;
/* -3- */
INSERT INTO `Марки_автомобилей` 
	(`Модель автомобиля`, `Минуты простоя`, `километра проезда`)
	VALUES
	('Kia Rio', 5, 20),
	('Toyota Camry', 8, 30),
	('Ford Focus', 5, 20);
INSERT INTO `Водители`
	(`Гос.номер`, `ФИО водителя`, `Телефон`, `Модель автомобиля`)
	VALUES
	('C734XK750', 'Иванов Петр Васильевич', '908-891-78-92', 'Kia Rio'), 
	('C865MP750', 'Петров Андрей Иванович', '928-742-87-34', 'Kia Rio'),
	('M777KM777', 'Бендер Остап Ибрагомович', '916-758-34-90', 'Toyota Camry'),
	('C654PP7150', 'Фролов Виктор Валерьевич', '967-456-12-18', 'Ford Focus');
INSERT INTO `Поездки`
	(`Гос.номер`, `Дата`, `Время вызова`, `Время завершения`, `Время ожидания у клиента`, `Расстояние`)
	VALUES
	('C734XK750', '2020.02.02', '12:20', '13:10', 2, 90),
	('C734XK750', '2020.02.02', '14:45', '15:50', 5, 50),
	('M777KM777', '2020.02.03', '18:30', '20:20', 5, 70),
	('C865MP750', '2020.02.02', '10:00', '10:20', 2, 30),
    ('C865MP750', '2020.02.02', '12:20', '13:45', 5, 80),
	('C865MP750', '2020.02.03', '10:30', '11:45', 10, 45),
	('C865MP750', '2020.02.03', '23:40', '01:10', 12, 88);