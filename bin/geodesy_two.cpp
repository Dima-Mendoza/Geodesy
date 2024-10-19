#include <iomanip>
#include <xlsxwriter.h>
#include "geo_two_h.h"

int main() {
    lxw_workbook *workbook = workbook_new("out.xlsx");
    lxw_worksheet *worksheet = workbook_add_worksheet(workbook, NULL);
    //lxw_format *format = workbook.add_format({'num_format': '#,##0.00'};
    lxw_format *format = workbook_add_format(workbook);
    format_set_num_format(format, "#,#.#");


    worksheet_write_string(worksheet,0,0,"Hello",format);
    worksheet_write_number(worksheet,0,1,v_krosvskogo,NULL);


    workbook_close(workbook);

    cout << fixed << setprecision(10) <<  v_krosvskogo;
    return 0;
}