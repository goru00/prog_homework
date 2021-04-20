var ul = document.getElementById('list');

Selection(document.querySelector('li.active').innerHTML);

function getEventTarget(e) {
    e = e || window.event;
    return e.target || e.srcElement; 
}

function SetTypeColumn(data) {
    let form = document.querySelector('form[name=taxi]');
    let inputs = form.getElementsByTagName('input');
    let types = data.split(";");
    for (let num = 0; num < inputs.length; num++)
    {
        if (types[num].indexOf("varchar") > -1) {
            inputs[num].type = "text";
        }
        if (types[num].indexOf("int") > -1) {
            inputs[num].type = "number";
        }
        if (types[num].indexOf("char") > -1) {
            inputs[num].type = "text";
        }
        if (types[num].indexOf("date") > -1) {
            inputs[num].type = "date";
        }
        if (types[num].indexOf("time") > -1) {
            inputs[num].type = "varchar";
        }
    }
}

function ClearForm() {
    let myNode = document.querySelector('form[name=taxi]');
    while(myNode.firstChild) {
        myNode.removeChild(myNode.firstChild);
    }
}

function CreateForm() {
    ClearForm();
    let form = document.querySelector('form[name=taxi]');
    let thead = document.getElementsByTagName('thead')[0];
    let rows = thead.rows;
    for (let num = 0; num < rows[0].cells.length; num++){
        let label = document.createElement('label');
        let input = document.createElement('input');
        label.innerHTML = rows[0].cells[num].innerHTML;
        label.appendChild(input);
        form.appendChild(label);
    }
    return form;
}

ul.onclick = function(event) {
    var target = getEventTarget(event);
    Selection(target.innerHTML);
    //GetColumnType(target.innerHTML);
};
