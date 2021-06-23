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

function Selection(val, status = '', data, dataOld = '')
{
    var xhr = new XMLHttpRequest();
    xhr.open("POST", "src/ajax.php");
    xhr.onreadystatechange = function() {
        if (xhr.readyState == 4 && xhr.status == 200) {
            json = JSON.parse(this.responseText);
            CreateTable(json);
            if (json.msg[0] != '') document.querySelector('div.result').innerHTML = json.msg[0][0];
        }
    }
    xhr.setRequestHeader('Content-type', 'application/json');
    xhr.getResponseHeader('Content-type', 'application/json');
    let json = JSON.stringify({
        status: status,
        tab: val,
        data: data,
        dataOld: dataOld
    });
    xhr.send(json);
}
