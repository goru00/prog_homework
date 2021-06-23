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


function Selection(val)
{
    var xhr = new XMLHttpRequest();
    xhr.open("POST", "src/ajax.php");
    xhr.onreadystatechange = function() {
        if (xhr.readyState == 4 && xhr.status == 200) {
            document.querySelector("div.content").innerHTML = this.responseText;
        }
    }
    xhr.setRequestHeader('Content-type', 'application/x-www-form-urlencoded');
    xhr.send("taxi=" + val);
}
