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