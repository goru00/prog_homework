var table = document.getElementsByTagName('tbody')[0];
var row_counter;
var country = document.getElementById('country');
var num_player = document.getElementById('num_player');
var lf_name = document.getElementById('lf_name');
var amp = document.getElementById('amp');
var rows = table.getElementsByTagName('tr');

table.addEventListener("click", function(row_target){
    let cell_target = row_target.target.parentElement;
    for (row_counter = 0; row_counter < rows.length; row_counter++)
    {
        if (rows[row_counter] === cell_target) 
        {
            country.value = rows[row_counter].getElementsByTagName('td')[0].innerHTML;
            num_player.value = rows[row_counter].getElementsByTagName('td')[1].innerHTML;
            lf_name.value = rows[row_counter].getElementsByTagName('td')[2].innerHTML;
            amp.value = rows[row_counter].getElementsByTagName('td')[3].innerHTML;
            break;
        }
    }
});

document.getElementById('insert').addEventListener("click", function() {
    let cell;
    if (country.value != "" && num_player.value != "") {
        for (counter = 0; counter < rows.length; counter++)
        {
            cell = rows[counter].getElementsByTagName('td');
            if ((cell[0].innerHTML == country.value && cell[1].innerHTML == num_player.value) && counter != row_counter)
            {
                alert('Запись с полем "Страна" и "№ игрока" уже существует');
                return;
            }
        }
    } else {
        alert('Не все поля формы были заполнены!');
        return;
    }
    cell = table.insertRow();
    cell.insertCell().innerHTML = country.value;
    cell.insertCell().innerHTML = num_player.value;
    cell.insertCell().innerHTML = lf_name.value;
    cell.insertCell().innerHTML = amp.value;
});

document.getElementById('update').addEventListener("click", function() {
    let cell;
    if (country.value != "" && num_player.value != "") {
        for (counter = 0; counter < rows.length; counter++)
        {
            cell = rows[counter].getElementsByTagName('td');
            if ((cell[0].innerHTML == country.value && cell[1].innerHTML == num_player.value) && counter != row_counter)
            {
                alert('Запись с полем "Страна" и "№ игрока" уже существует');
                return;
            }
        }
    } else {
        alert('Не все поля формы были заполнены!');
        return;
    }
    console.log(rows[row_counter]);
    cell = rows[row_counter].getElementsByTagName('td');

    cell[0].innerHTML = country.value;
    cell[1].innerHTML = num_player.value;
    cell[2].innerHTML = lf_name.value;
    cell[3].innerHTML = amp.value;
});

document.getElementById('delete').addEventListener("click", function() {
    let cell;
    if (country.value != "" && num_player.value != "") {
        for (let i = 0; i < rows.length; i++)
        {
            cell = rows[i].getElementsByTagName('td');
            if (country.value === cell[0].innerHTML && num_player.value === cell[1].innerHTML) {
                table.deleteRow(i);
                alert('Запись была успешно удалена');
                return;
            }
        }
        alert('Запись была не найдена!');
    } else {
        alert('Не все поля формы были заполнены!');
        return;
    }
});
