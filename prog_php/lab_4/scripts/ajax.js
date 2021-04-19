var xhr = new XMLHttpRequest();

var XMLHttpRequestObject = false;

if (window.XMLHttpRequest)
{
    XMLHttpRequestObject = new XMLHttpRequest();
} else if (window.ActiveXObject)
{
    XMLHttpRequestObject = new ActiveXObject("Microsoft.XMLHTTP");
}

/* на просмотр select после вып.запроса */
function XMLHTTPRequestShow()
{
    xhr.open('GET', "http://localhost/src/select.php");
    xhr.onreadystatechange = function() {
        if (xhr.readyState == 4 && xhr.status == 200) {
            document.querySelector('div.content').innerHTML = this.responseText;
        }
    }
    xhr.send();
}
/* на вып.операции */
function XMLHTTPRequestSend(operation)
{
    let formData = new FormData(document.forms.players);
    xhr.open('POST', "http://localhost/src/" + operation + ".php");
    xhr.onreadystatechange = function() {
        if (xhr.readyState == 4 && xhr.status == 200) {
            XMLHTTPRequestShow();
            console.log("OK");
        }
    }
    xhr.send(formData);
}