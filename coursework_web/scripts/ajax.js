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

function XHRHttpRequestSend(operat, val)
{
    var xhr = new XMLHttpRequest();
    xhr.open("POST", "src/ajax.php");
    xhr.onreadystatechange = function() {

    }
    xhr.setRequestHeader('Content-type', 'application/x-www-form-urlencoded');
    xhr.getResponseHeader('Content-Type');
    xhr.send("status=" + operat + + "tab=" + val)
}

function Selection(val)
{
    var xhr = new XMLHttpRequest();
    xhr.open("POST", "src/ajax.php");
    xhr.onreadystatechange = function() {
        if (xhr.readyState == 4 && xhr.status == 200) {
            CreateTable(JSON.parse(this.responseText));
        }
    }
    xhr.setRequestHeader('Content-type', 'application/x-www-form-urlencoded');
    xhr.getResponseHeader('Content-Type');
    xhr.send("status=select&" + "tab=" + val);
}
