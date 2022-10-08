#include<iostream>
#include<map>
#include<utility>
#include<algorithm>

typedef std::pair<std::string, int> key;
typedef std::pair<std::string, std::string> val;

// обход карты
void show(std::map<key, val> m) {
	for (const auto& item : m) {
		auto key_pair = item.first;
		auto val_pair = item.second;
		std::cout << key_pair.first << " " << key_pair.second << " " << val_pair.first << " " << val_pair.second << std::endl;
	}
}

//хорошо данные с которыми работаем обернуть в общий класс
int main() {
	setlocale(0, "");
	std::map<key, val> obj1, obj2;

	obj1 = {
		{ std::make_pair("Чехия", 1), std::make_pair("Павелец Оджий", "Вратарь")},
		{ std::make_pair("Белоруссия", 4), std::make_pair("Роман Граборенко", "Защитник")},
		{ std::make_pair("Чехия", 6), std::make_pair("Баринка Михаил", "Защитник")},
		{ std::make_pair("Белоруссия", 2), std::make_pair("Дмитрия Мальчиков", "Вратарь")},
		{ std::make_pair("Чехия", 2), std::make_pair("Хемски Алеш", "Нападающий")}
	};

	obj2 = {
		{ std::make_pair("Россия", 10), std::make_pair("Семен Варламов", "Вратарь")},
		{ std::make_pair("Россия", 3), std::make_pair("Евгений Малкин", "Нападающий")},
		{ std::make_pair("Россия", 4), std::make_pair("Вячеслав Войнов", "Защитник")}
	};

	std::cout << "Вывод первого списка" << std::endl;
	show(obj1);

	std::cout << std::endl;

	std::cout << "Вывод второго списка" << std::endl;
	show(obj2);

	std::map<key, val> obj3;

	obj3.insert(obj1.begin(), obj1.end());
	obj3.insert(obj2.begin(), obj2.end());

	std::cout << std::endl;

	std::cout << "Вывод третьего списка" << std::endl;
	show(obj3);

	std::cout << std::endl;

	std::cout << "Изменение значения в списке" << std::endl;
	// реализую поиск по карте с последующим изменением его значений через итератор (можно сделать это другим способом)
	std::map<key, val>::iterator it = obj3.find(std::make_pair("Белоруссия", 5));
	if (it != obj3.end()) {
		auto key_pair = it->first;
		auto val_pair = it->second;
		val_pair.second = "Нападающий";
		obj3[std::make_pair(key_pair.first, key_pair.second)] = std::make_pair(val_pair.first, val_pair.second);
		std::cout << "Элемент изменен" << std::endl;
	}
	else {
		std::cout << "Элемент не найден" << std::endl;
	}

	std::cout << std::endl;

	std::cout << "Вывод списка после изменения" << std::endl;

	show(obj3);

	std::cout << std::endl;

	std::cout << "Удаление узла дерева с ключом Россия №10" << std::endl;
	obj3.erase(std::make_pair("Россия", 10));

	std::cout << std::endl;

	std::cout << "Вывод списка после удаления" << std::endl;
	show(obj3);

	std::cout << std::endl;

	std::cout << "Очистка списка и последующий его вывод " << std::endl;

	obj3.clear();
	show(obj3);

	return 0;
}