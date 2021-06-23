var ul = document.getElementById('list');
var tar = document.querySelector('div.table');
var form_table = document.querySelector('div.form_table');
var emptytable = false;
var keydown = false;

document.addEventListener("DOMContentLoaded", function() {
    Selection(document.querySelector('li.active').innerHTML, "select");
});


let observer = new MutationObserver(mutationRecords => {
    if (emptytable != true)
    {
        tar.getElementsByTagName('tbody')[0].addEventListener('click', function(row_target) {
            var rows = tar.getElementsByTagName('tr');
            let cell_target = row_target.target.parentElement;
            let form = document.querySelector('form[name=taxi]');
            let inputs = form.querySelectorAll('input[class=new_input]');
            let hinputs = form.querySelectorAll('input[class=hidden_input]');
            for (let row_counter = 0; row_counter < rows.length; row_counter++)
            {
                if (rows[row_counter] == cell_target) 
                {
                    for (let cell_counter = 0; cell_counter < inputs.length; cell_counter++)
                    {
                        inputs[cell_counter].value = rows[row_counter].getElementsByTagName('td')[cell_counter].innerHTML;
                        hinputs[cell_counter].value = rows[row_counter].getElementsByTagName('td')[cell_counter].innerHTML;
                    }
                    break;
                }
            }
        });
    } else {
        if (document.querySelector('div.filter_sort_table'))
        {
            document.querySelector('div.filter_sort_table').onkeyup = function() {
                let filters = new Array();
                let form = document.querySelector('div.filter_sort_table');
                let inputs = form.querySelectorAll('input');
                if (keydown == false)
                {
                    for (let num = 0; num < inputs.length; num++)
                    {
                        filters.push(inputs[num].value);
                    }
                }
                keydown = true;
                Selection('Сводная таблица', 'consolidated', Array(filters));
            }
            document.querySelector('div.filter_sort_table').onkeydown = function() {
                keydown = false; 
            }
        }
        if (document.querySelector('div.select_sort_table'))
        {
            document.getElementById('SortReport').addEventListener("click", function() {
                if (selectArg1.value == selectArg2.value) {
                    document.querySelector('div.result').innerHTML = "<div class='alert alert-danger'>Аргументы для сортировки не могут быть похожи!</div>";
                    return;
                } else {
                    let options = new Array();
                    let filters = new Array();
                    let form = document.querySelector('div.filter_sort_table');
                    let inputs = form.querySelectorAll('input');
                    for (let num = 0; num < inputs.length; num++)
                    {
                        filters.push(inputs[num].value);
                    }
                    options.push(selectArg1.value);
                    options.push(selectArg2.value);
                    Selection('Сводная таблица', 'consolidated', Array(filters), '', Array(options));
                }
            });
        }
    }
});



observer.observe(tar, {
    childList: true, 
    subtree: true, 
    characterDataOldValue: true 
});

function getEventTarget(e) {
    e = e || window.event;
    return e.target || e.srcElement; 
}

function Clear(arg)
{
    let myNode = document.querySelector(arg);
    while(myNode.firstChild) {
        myNode.removeChild(myNode.firstChild);
    }
}

function CreateFormButton()
{
    let classButtons = document.createElement('div');
    classButtons.setAttribute("class", "button_confirm");

    let button_insert = document.createElement('button');
    button_insert.id = "insert";
    button_insert.setAttribute("class", "btn btn-primary");
    button_insert.innerHTML = "Добавить запись";
    classButtons.appendChild(button_insert);

    let button_delete = document.createElement('button');
    button_delete.id = "delete";
    button_delete.setAttribute("class", "btn btn-primary");
    button_delete.innerHTML = "Удалить запись";
    classButtons.appendChild(button_delete);

    let button_update = document.createElement('button');
    button_update.id = "update";
    button_update.setAttribute("class", "btn btn-primary");
    button_update.innerHTML = "Изменить запись";
    classButtons.appendChild(button_update);

    form_table.appendChild(classButtons);
    document.getElementById('insert').addEventListener('click', function() {
        if (Validateform())
        {
            let formArray = new Array();
            let forms = document.forms.taxi;
            let inputs = forms.querySelectorAll('input[class="new_input"]');
            for (let num = 0; num < inputs.length; num++)
            {
                formArray.push(inputs[num].value);
            }
            Selection(document.querySelector('li.active').innerHTML, "insert", Array(formArray));
        }
    });
    
    document.getElementById('delete').addEventListener('click', function() {
        if (Validateform())
        {
            let formArray = new Array();
            let forms = document.forms.taxi;
            let inputs = forms.querySelectorAll('input[class="new_input"]');
            for (let num = 0; num < inputs.length; num++)
            {
                formArray.push(inputs[num].value);
            }
            Selection(document.querySelector('li.active').innerHTML, "delete", Array(formArray));
        }
    });
    
    document.getElementById('update').addEventListener('click', function() {
        if (document.querySelector('input[class="hidden_input"]').value == '')
        {
            document.querySelector('div.result').innerHTML = "<div class='alert alert-warning'>Сначала выберите запись из таблицы!</div>";
        }
        else {
            if (Validateform())
            {
                let formDataNew = new Array();
                let formDataOld = new Array();
                let forms = document.forms.taxi;
                let inputsNew = forms.querySelectorAll('input[class="new_input"]');
                let inputsOld = forms.querySelectorAll('input[class="hidden_input"]');
                for (let num = 0; num < inputsNew.length; num++)
                {
                    formDataNew.push(inputsNew[num].value);
                    formDataOld.push(inputsOld[num].value);
                }
                Selection(document.querySelector('li.active').innerHTML, "update", Array(formDataNew), Array(formDataOld));
            }
        }
    });
}

// здесь генерируем форму по таблице
function CreateForm(data)
{
    let Form = document.createElement('form');
    Form.setAttribute('name', 'taxi');
    let inputForm = document.createElement('div');
    inputForm.setAttribute('class', 'input_form');
    let alertText = document.createElement('p');
    alertText.setAttribute('class', 'text-md-left alertText');
    alertText.innerHTML = "Поле с «*» обязательно к заполнению.";
    inputForm.appendChild(alertText);
    inputForm.appendChild(Form);
    for (let num = 0; num < data.type[0].length; num++)
    {
        let label = document.createElement('label');
        let input = document.createElement('input');
        input.setAttribute("class", "new_input");
        let p = document.createElement('p');
        p.setAttribute('class', "name_input");
        p.innerHTML = data.thead[0][num];
        if (data.type[0][num].match(/varchar/) || data.type[0][num].match(/char/))
        {
            input.type = "text";
            input.size = parseInt(data.type[0][num].match(/\d+/));
            input.placeholder = (emptytable == true ? '' : "Например, " + data.tbody[0][num]);
        }
        if (data.type[0][num].match(/int/))
        {
            input.type = "number";
            input.min = 0;
            input.value = 0;
        }
        if (data.type[0][num].match(/date/))
        {
            input.type = "date";
        }
        if (data.type[0][num].match(/time/))
        {
            input.type = "time";
            input.value = "00:00";
        }
        if (data.key[0][num] == "PRI")
        {
            input.required = true;
            let sub = document.createElement('sub');
            sub.innerHTML = "*";
            p.innerHTML = data.thead[0][num];
            p.appendChild(sub);
        }
        input.name = transliterate(data.thead[0][num]);
        let hinputs = document.createElement('input');
        hinputs.type = "hidden";
        hinputs.setAttribute("class", "hidden_input");
        hinputs.name = input.name + "_Old";
        label.appendChild(p);
        label.appendChild(input);
        Form.appendChild(label);
        Form.appendChild(hinputs);
    }
    form_table.appendChild(inputForm);
    
}

function Validateform()
{
    let inputs = document.querySelectorAll('input[class="new_input"]');
    let ulalert = document.createElement('ul');
    ulalert.setAttribute("class", "alert alert-danger");
    let name = document.querySelectorAll('p.name_input');
    for (let num = 0; num < inputs.length; num++)
    {
        let ulLi = document.createElement('li');
        if (inputs[num].validity.valueMissing)
        {
            ulLi.innerHTML = "Поле '" + name[num].innerHTML + "' было не заполнено!";
            ulalert.appendChild(ulLi);
        } 
        if (inputs[num].validity.rangeUnderflow)
        {
            ulLi.innerHTML = "Поле '" + name[num].innerHTML + "' меньше " + inputs[num].min + "!";
            ulalert.appendChild(ulLi);
        }
        if (inputs[num].validity.rangeOverflow)
        {
            ulLi.innerHTML = "Поле '" + name[num].innerHTML + "' больше " + inputs[num].max + "!";
            ulalert.appendChild(ulLi);
        }
        if (inputs[num].validity.typeMismatch)
        {
            ulLi.innerHTML = "Поле '" + name[num].innerHTML + " имеет другой формат ввода!";
            ulalert.appendChild(ulLi);
        }
    }
    if (ulalert.firstChild)
    {
        document.querySelector('div.result').appendChild(ulalert);
        return false;
    }
    return true;
}

// здесь заполняем таблицу
function CreateTable(data)
{
    Clear('div.table');
    Clear('div.result');
    if (data.tbody.length == 0)
    {
        document.querySelector('div.result').innerHTML = "<div class='alert alert-warning'>Таблица пуста.</div>";
        emptytable = true;
    }
    else {
        emptytable = false;
        let content = document.querySelector('div.table');
        let table = document.createElement('table');
        table.setAttribute("class", "table table-hover table-dark")
        let thead = document.createElement('thead');
        let tbody = document.createElement('tbody');
        let cell = thead.insertRow(0);
        for (let num = 0; num < data.thead[0].length; num++)
        {
            cell.insertCell().innerHTML = data.thead[0][num];
        }
        for (let num = 0; num < data.tbody.length; num++)
        {
            cell = tbody.insertRow(num);
            for (let jnum = 0; jnum < data.tbody[num].length; jnum++)
            {
                cell.insertCell().innerHTML = data.tbody[num][jnum];
            }
        }
        table.appendChild(thead);
        table.appendChild(tbody);
        content.appendChild(table);
    }
    if (form_table.innerHTML == '') {
        CreateForm(data);
        CreateFormButton();
    } else {
        Clear('div.form_table');
        CreateForm(data);
        CreateFormButton();
    }
}

ul.onclick = function(event) {
    var target = getEventTarget(event);
    let list = document.getElementById('list');
    let listLi = list.getElementsByTagName('li');
    let select;
    for (let num = 0; num < listLi.length; num++)
    {
        if (target.innerHTML == listLi[num].innerHTML)
        {
            listLi[num].setAttribute("class", "nav-item nav-link active");
            select = listLi[num].innerHTML;
        } else listLi[num].setAttribute("class", "nav-item nav-link");
    }
    if (document.querySelector('li.active').innerHTML != "Сводная таблица") Selection(select, "select");
    else {
        Clear('div.form_table');
        Selection("Сводная таблица", "consolidated");
    }
};

function CreateSelectSort(data)
{
        let settingsReport = document.querySelector('div.setting_report');
        let msgSort = document.createElement('h3');
        msgSort.innerHTML = 'Отсортировать: ';
        let selectSortTable = document.createElement('div');
        selectSortTable.setAttribute("class", "select_sort_table");
        selectSortTable.appendChild(msgSort);
        settingsReport.appendChild(selectSortTable);
        let selectArg1 = document.createElement('select');
        selectArg1.id = "selectArg1";
        let selectArg2 = document.createElement('select');
        selectArg2.id = "selectArg2";
        // опционально можно написать цикл для всех столбцов таблицы для сортировки.
        // в этой работе будет 2 поля для выбора
        for (let num = 0; num < data.thead[0].length; num++)
        {
            let option1 = document.createElement('option');
            let option2 = document.createElement('option');
            option1.value = data.thead[0][num];
            option1.innerHTML = data.thead[0][num];
            option2.value =data.thead[0][num];
            option2.innerHTML = data.thead[0][num];
            selectArg1.appendChild(option1);
            selectArg2.appendChild(option2);
        }
        let option1 = document.createElement('option');
        option1.innerHTML = "Не выбрано";
        option1.value = "Не выбрано";
        option1.selected = true;
        
        let option2 = document.createElement('option');
        option2.value = "Не выбрано";
        option2.innerHTML = "Не выбрано";
        option2.selected = true;

        selectArg1.appendChild(option1);
        selectArg2.appendChild(option2);

        let buttonSort = document.createElement('button');
        buttonSort.innerHTML = "Отсортировать таблицу";
        buttonSort.setAttribute("class", "btn btn-primary");
        buttonSort.id = "SortReport";
        selectSortTable.appendChild(selectArg1);
        selectSortTable.appendChild(selectArg2);
        selectSortTable.appendChild(buttonSort);

        form_table.appendChild(settingsReport);
}

function CreateFilterSort()
{
    let settingsReport = document.querySelector('div.setting_report');
    let msgSort = document.createElement('h3');
    msgSort.innerHTML = 'Фильтры: ';
    let filterSortTable = document.createElement('div');
    filterSortTable.setAttribute("class", "filter_sort_table");
    filterSortTable.appendChild(msgSort);
    let row = document.getElementsByTagName('tbody')[0];
    let thead = document.getElementsByTagName('thead')[0].rows[1];
    for (let num = 0; num < row.rows[0].cells.length; num++)
    {
        let label = document.createElement('label');
        label.innerHTML = thead.cells[num].innerHTML;
        let input = document.createElement('input');
        input.setAttribute("class", "data_report_column_input_" + num);
        input.value = "%";
        label.appendChild(input);
        filterSortTable.appendChild(label);
    }
    settingsReport.appendChild(filterSortTable);
    form_table.appendChild(settingsReport);

}

function ShowReport(data)
{
    emptytable = true;
    Clear('div.result');
    Clear('div.table');
    let tableReport = document.createElement('table');
    tableReport.setAttribute("class", "table table-hover table-dark table-bordered");
    let thead = tableReport.createTHead();
    if (data.tbody.length == 0)
    {
        document.querySelector('div.result').innerHTML = "<div class='alert alert-warning'>По вашему запросу не найдено ни одной записи.</div>";
        return;
    }
    for (let num = 0, colspan = 0; num < data.thead.length; num++)
    {
        let row = thead.insertRow(num);
        for (let jnum = 0; jnum < data.thead[num].length; jnum++, colspan++)
        {
            row.insertCell(jnum);
            row.cells[jnum].classList.add("thead_consolidated");
            row.cells[jnum].colSpan = data.tcolspans[colspan];
            row.cells[jnum].innerHTML = data.thead[num][jnum];
        }
    }
    [thead.rows[0].innerHTML , thead.rows[1].innerHTML] = [thead.rows[1].innerHTML, thead.rows[0].innerHTML];
    let tbody = tableReport.createTBody();
    for (let num = 0, colspan = 0; num < data.tbody.length; num++)
    {
        let row = tbody.insertRow(num);
        for (let jnum = 0; jnum < data.tbody[num].length; jnum++, colspan++)
        {
            row.insertCell(jnum);
            row.cells[jnum].innerHTML = data.tbody[num][jnum];
            if (data.bcolspans[colspan] != 1) {
                row.cells[jnum].colSpan = data.bcolspans[colspan];
                row.cells[jnum].align = "right";
            }
        }
    }
    document.querySelector('div.table').appendChild(tableReport);
    if (!document.querySelector('div.setting_report')) {
        let settingsReport = document.createElement('div');
        settingsReport.setAttribute("class", "setting_report");
        form_table.appendChild(settingsReport);
    }
    if (!document.querySelector('div.filter_sort_table')) CreateFilterSort();
    if (!document.querySelector('div.select_sort_table')) CreateSelectSort(data);
}

var transliterate = function(text) {

    text = text
        .replace(/\u0401/g, 'YO')
        .replace(/\u0419/g, 'I')
        .replace(/\u0426/g, 'TS')
        .replace(/\u0423/g, 'U')
        .replace(/\u041A/g, 'K')
        .replace(/\u0415/g, 'E')
        .replace(/\u041D/g, 'N')
        .replace(/\u0413/g, 'G')
        .replace(/\u0428/g, 'SH')
        .replace(/\u0429/g, 'SCH')
        .replace(/\u0417/g, 'Z')
        .replace(/\u0425/g, 'H')
        .replace(/\u042A/g, '')
        .replace(/\u0451/g, 'yo')
        .replace(/\u0439/g, 'i')
        .replace(/\u0446/g, 'ts')
        .replace(/\u0443/g, 'u')
        .replace(/\u043A/g, 'k')
        .replace(/\u0435/g, 'e')
        .replace(/\u043D/g, 'n')
        .replace(/\u0433/g, 'g')
        .replace(/\u0448/g, 'sh')
        .replace(/\u0449/g, 'sch')
        .replace(/\u0437/g, 'z')
        .replace(/\u0445/g, 'h')
        .replace(/\u044A/g, "'")
        .replace(/\u0424/g, 'F')
        .replace(/\u042B/g, 'I')
        .replace(/\u0412/g, 'V')
        .replace(/\u0410/g, 'a')
        .replace(/\u041F/g, 'P')
        .replace(/\u0420/g, 'R')
        .replace(/\u041E/g, 'O')
        .replace(/\u041B/g, 'L')
        .replace(/\u0414/g, 'D')
        .replace(/\u0416/g, 'ZH')
        .replace(/\u042D/g, 'E')
        .replace(/\u0444/g, 'f')
        .replace(/\u044B/g, 'i')
        .replace(/\u0432/g, 'v')
        .replace(/\u0430/g, 'a')
        .replace(/\u043F/g, 'p')
        .replace(/\u0440/g, 'r')
        .replace(/\u043E/g, 'o')
        .replace(/\u043B/g, 'l')
        .replace(/\u0434/g, 'd')
        .replace(/\u0436/g, 'zh')
        .replace(/\u044D/g, 'e')
        .replace(/\u042F/g, 'Ya')
        .replace(/\u0427/g, 'CH')
        .replace(/\u0421/g, 'S')
        .replace(/\u041C/g, 'M')
        .replace(/\u0418/g, 'I')
        .replace(/\u0422/g, 'T')
        .replace(/\u042C/g, "'")
        .replace(/\u0411/g, 'B')
        .replace(/\u042E/g, 'YU')
        .replace(/\u044F/g, 'ya')
        .replace(/\u0447/g, 'ch')
        .replace(/\u0441/g, 's')
        .replace(/\u043C/g, 'm')
        .replace(/\u0438/g, 'i')
        .replace(/\u0442/g, 't')
        .replace(/\u044C/g, "'")
        .replace(/\u0431/g, 'b')
        .replace(/\u044E/g, 'yu');

    return text;
};