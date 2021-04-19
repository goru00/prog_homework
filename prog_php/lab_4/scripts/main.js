var table = document.getElementsByTagName('tbody')[0];
var country = document.getElementById('country');
var num_player = document.getElementById('num_player');
var name_player = document.getElementById('name_player');
var amp = document.getElementById('amp');
var row_counter;

document.getElementById('insert').addEventListener('click', function() {
    XMLHTTPRequestSend('insert');
});
document.getElementById('update').addEventListener('click', function() {
    XMLHTTPRequestSend('update');
});
document.getElementById('delete').addEventListener('click', function() {
    XMLHTTPRequestSend('delete');
});
table.addEventListener("click", function(row_target) {
    let cell_target = row_target.target.parentElement;
    let row = table.rows;
    for (row_counter = 0; row_counter < row.length; row_counter++)
    {
        if (row[row_counter] === cell_target) 
        {
            document.getElementById('country_old').value = row[row_counter].getElementsByTagName('td')[2].innerHTML;
            document.getElementById('num_player_old').value = row[row_counter].getElementsByTagName('td')[0].innerHTML;
            document.getElementById('name_player_old').value = row[row_counter].getElementsByTagName('td')[1].innerHTML;
            document.getElementById('amp_old').value = row[row_counter].getElementsByTagName('td')[3].innerHTML;
            num_player.value = row[row_counter].getElementsByTagName('td')[0].innerHTML;
            document.getElementById('num_player_range').innerHTML = row[row_counter].getElementsByTagName('td')[0].innerHTML;
            name_player.value = row[row_counter].getElementsByTagName('td')[1].innerHTML;
            amp.value = row[row_counter].getElementsByTagName('td')[3].innerHTML;
            break;
        }
    }
});
