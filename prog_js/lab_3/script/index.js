const Sort = () => {
    var table = document.getElementById('table');
    var rows = table.rows;
    for (let i = 1; i < rows.length - 1; i++)
    {
        for (let j = i + 1; j < rows.length; j++)
        {
            if (rows[i].cells[3].innerHTML > rows[j].cells[3].innerHTML) 
            {
                [rows[i].innerHTML, rows[j].innerHTML] = [rows[j].innerHTML, rows[i].innerHTML];
            }
            if (rows[i].cells[3].innerHTML == rows[j].cells[3].innerHTML && rows[i].cells[2].innerHTML > rows[j].cells[2].innerHTML) //сортировка по количеству в случае если наименования одинаковы
            {
                [rows[i].innerHTML, rows[j].innerHTML] = [rows[j].innerHTML, rows[i].innerHTML];
            }
        }
    }
}