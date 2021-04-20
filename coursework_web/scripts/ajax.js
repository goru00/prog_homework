var XMLHttpRequestObject = false;
if (window.XMLHttpRequest)
{
    XMLHttpRequestObject = new XMLHttpRequest();
} else if (window.ActiveXObject)
{
    XMLHttpRequestObject = new ActiveXObject("Microsoft.XMLHTTP");
}

if (window.history.replaceState)
{
    window.history.replaceState(null, null, window.location.href);
}

function GetColumnType(val) {
    var xhr = new XMLHttpRequest();
    xhr.open("POST", "src/ajax.php");
    xhr.onreadystatechange = function() {
        if (xhr.readyState == 4 && xhr.status == 200) {
            SetTypeColumn(this.responseText);
        }
    }
    xhr.setRequestHeader('Content-type', 'application/x-www-form-urlencoded');
    xhr.send("status=type&" + "tab=" + val);
}


function Selection(val)
{
    var xhr = new XMLHttpRequest();
    xhr.open("POST", "src/ajax.php");
    xhr.onreadystatechange = function() {
        if (xhr.readyState == 4 && xhr.status == 200) {
            document.querySelector("div.table").innerHTML = this.responseText;
            document.querySelector('form[name=taxi]').innerHTML = CreateForm().innerHTML;
        }
    }
    xhr.setRequestHeader('Content-type', 'application/x-www-form-urlencoded');
    xhr.send("status=select&" + "tab=" + val);
}
