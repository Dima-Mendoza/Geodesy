#include <xlsxwriter.h>

int main() {
    lxw_workbook *workbook = workbook_new("out.xlsx");
    lxw_worksheet *worksheet = workbook_add_worksheet(workbook, NULL);

    worksheet_write_string(worksheet,0,0,"Hello",NULL);
    worksheet_write_number(worksheet,0,1,999999.9999999999999999,NULL);

    workbook_close(workbook);
    return 0;
}
//