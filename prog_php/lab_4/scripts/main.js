var ul = document.getElementById('list');
var tar = document.querySelector('div.table');
var emptytable = false;

// переписать эту строку
Selection(document.querySelector('li.active').innerHTML, "select");

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
    }
});



observer.observe(tar, {
    // под вопросов subtree, надо проверять на пустоту таблицы
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

// здесь генерируем форму по таблице
function CreateForm(data)
{
    Clear('form[name=taxi]');
    let content = document.querySelector('form[name=taxi]');
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
        content.appendChild(label);
        content.appendChild(hinputs);
    }
}

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
    CreateForm(data);
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
    Selection(select, "select");
};

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