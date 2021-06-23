var cnt = document.getElementById("container");
var btnShowTable = document.getElementById("btnShowTable");
var btnShowForm = document.getElementById("btnShowForm");
var xhr = new XMLHttpRequest();

btnShowForm.addEventListener("click", function() {
    xhr.open('GET', 'prop/playersForm.txt');
    xhr.onreadystatechange = function() {
        if (xhr.readyState == 4 && xhr.status == 200) {
            cnt.innerHTML = this.responseText;
        }
    }
    xhr.send();
});

btnShowTable.addEventListener("click", function() {
    xhr.open('GET', 'prop/playersTable.txt');
    xhr.onreadystatechange = function() {
        if (xhr.readyState == 4 && xhr.status == 200) {
            if (this.responseText == "") {
                cnt.innerHTML = "Таблица пуста";
            } else cnt.innerHTML = this.responseText;
        }
    }
    xhr.send();
});


function ValidateForm() {
    let res = document.querySelector('.result');
    let num_player = Number.parseInt(document.querySelector('form[name=players] input[name=num_player]').value);
    if (num_player < 1 || num_player > 25)
    {
        res.innerHTML = "№ игрока должен находиться в диапазоне от 1 до 25";
        return;
    }
    let country = document.querySelector("form[name=players] input[name=country]").value;
    if (country != "Ч" && country != "Р")
    {
        res.innerHTML = 'Страна должна быть либо "Ч", либо "Р"';
        return;
    }
    let name_player = document.querySelector("form[name=players] input[name=name_player]").value;
    if (name_player.search("[а-яА-ЯёЁ]"))
    {
        res.innerHTML = 'Имя и фамилия игрока должны состоять из русских символов и содержать пробелы';
        return;
    }
    let amp = document.getElementById('amp').options.selectedIndex;
    if (amp == -1)
    {
        res.innerHTML = 'Амплуа игрока должна соответствовать с предложенным выбором';
        return;
    }
    amp = document.getElementById('amp').value;
    let json = JSON.stringify({
        "№ игрока": num_player,
        "Страна": country, 
        "ФИО игрока": name_player,
        "Амплуа": amp
    });
    xhr.open('POST', 'prop/result.txt'); /* ничего не будет происходить, просто для примера */
    xhr.setRequestHeader('Content-type', 'application/json; charset=utf-8');
    xhr.send(json);
    /* если отправка придет со статусом 200, то выдаем сообщение */
    xhr.onload = () => {
        res.innerHTML = `Данные были успешно отправлены: ${xhr.status}`;
    };
    /* иначе */
    xhr.onerror = () => {
        alert(`Произошла ошибка во время отправки: ${xhr.status}`);
      };
}