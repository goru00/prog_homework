var row_counter;
var country = document.getElementById('country');
var num_player = document.getElementById('num_player');
var name_player = document.getElementById('name_player');
var amp = document.getElementById('amp');
var table = document.getElementsByTagName('tbody')[0];

document.getElementById('update').addEventListener("click", function() {
    document.getElementById('amp_old').setAttribute("name", "amp_old");
    document.getElementById('name_player_old').setAttribute("name", "name_player_old");
    document.getElementById('country_old').setAttribute("name", "country_old");
    document.getElementById('num_player_old').setAttribute("name", "num_player_old");
});

const Sort = () => {
    let table = document.getElementsByTagName('tbody')[0];
    let rows = table.rows;
    for (let i = 0; i < rows.length; i++)
    {
        for (let j = i + 1; j < rows.length; j++)
        {
            if (rows[i].cells[3].innerHTML > rows[j].cells[3].innerHTML) 
            {
                [rows[i].innerHTML, rows[j].innerHTML] = [rows[j].innerHTML, rows[i].innerHTML];
            }
            if (rows[i].cells[3].innerHTML == rows[j].cells[3].innerHTML && rows[i].cells[2].innerHTML > rows[j].cells[2].innerHTML)
            {
                [rows[i].innerHTML, rows[j].innerHTML] = [rows[j].innerHTML, rows[i].innerHTML];
            }
        }
    }
}

table.addEventListener("click", function(row_target) {
    let cell_target = row_target.target.parentElement;
    let row = table.rows;
    for (row_counter = 0; row_counter < row.length; row_counter++)
    {
        if (row[row_counter] === cell_target) 
        {
            document.getElementById('country_old').value = row[row_counter].getElementsByTagName('td')[1].innerHTML;
            document.getElementById('num_player_old').value = row[row_counter].getElementsByTagName('td')[0].innerHTML;
            document.getElementById('name_player_old').value = row[row_counter].getElementsByTagName('td')[2].innerHTML;
            document.getElementById('amp_old').value = row[row_counter].getElementsByTagName('td')[3].innerHTML;
            country.value = row[row_counter].getElementsByTagName('td')[1].innerHTML;
            num_player.value = row[row_counter].getElementsByTagName('td')[0].innerHTML;
            name_player.value = row[row_counter].getElementsByTagName('td')[2].innerHTML;
            amp.value = row[row_counter].getElementsByTagName('td')[3].innerHTML;
            break;
        }
    }
});