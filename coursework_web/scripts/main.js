var ul = document.getElementById('list');
var tar = document.querySelector('div.table');

// переписать эту строку
Selection(document.querySelector('li.active').innerHTML, "select");

let observer = new MutationObserver(mutationRecords => {
    tar.getElementsByTagName('tbody')[0].addEventListener('click', function(row_target) {
        var rows = tar.getElementsByTagName('tr');
        let cell_target = row_target.target.parentElement;
        let form = document.querySelector('form[name=taxi]');
        let inputs = form.querySelectorAll('input');
        for (let row_counter = 0; row_counter < rows.length; row_counter++)
        {
            if (rows[row_counter] == cell_target) 
            {
                for (let cell_counter = 0; cell_counter < inputs.length; cell_counter++)
                {
                    inputs[cell_counter].value = rows[row_counter].getElementsByTagName('td')[cell_counter].innerHTML;
                }
                break;
            }
        }
    });
});

observer.observe(tar, {
    // под вопросов subtree, надо проверять на пустоту таблицы
    childList: true, 
    subtree: true, 
    characterDataOldValue: true 
});


document.getElementById('insert').addEventListener('click', function() {
    let formArray;
    Selection(document.querySelector('li.active').innerHTML, "insert", formArray);
});

document.getElementById('delete').addEventListener('click', function() {
    alert('delete');
});

document.getElementById('update').addEventListener('click', function() {
    alert('update');
});

function getEventTarget(e) {
    e = e || window.event;
    return e.target || e.srcElement; 
}

function SetResult(data)
{
    let res = document.querySelector('div.result');
    res.innerHTML = data.msg[0];
}

function Clear(arg)
{
    let myNode = document.querySelector(arg);
    while(myNode.firstChild) {
        myNode.removeChild(myNode.firstChild);
    }
}

// здесь заполняем форму по таблице
function CreateForm(data)
{
    Clear('form[name=taxi]');
    let content = document.querySelector('form[name=taxi]');
    for (let num = 0; num < data.type[0].length; num++)
    {
        let label = document.createElement('label');
        let input = document.createElement('input');
        let p = document.createElement('p');
        p.innerHTML = data.thead[0][num];
        if (data.type[0][num].match(/varchar/))
        {
            input.type = "text";
            input.placeholder = "Например, " + data.tbody[0][num];
            input.name = transliterate(data.thead[0][num]);
        }
        if (data.type[0][num].match(/char/))
        {
            input.type = "text";
            input.placeholder = "Например, " + data.tbody[0][num];
            input.name = transliterate(data.thead[0][num]);
        }
        if (data.type[0][num].match(/int/))
        {
            input.type = "number";
            input.min = 0;
            input.value = 0;
            input.name = transliterate(data.thead[0][num]);
        }
        if (data.type[0][num].match(/date/))
        {
            input.type = "date";
            input.name = transliterate(data.thead[0][num]);
        }
        if (data.type[0][num].match(/time/))
        {
            input.type = "time";
            input.value = "00:00";
            input.name = transliterate(data.thead[0][num]);
        }
        if (data.key[0][num] == "PRI")
        {
            input.required = true;
        }
        label.appendChild(p);
        label.appendChild(input);
        //label.innerHTML = data.thead[0][num];
        content.appendChild(label);
    }
}
// здесь заполняем таблицу
function CreateTable(data)
{
    Clear('div.table');
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