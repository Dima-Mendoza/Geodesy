#include <cmath>
#include <cstddef>
#include <iomanip>
#include <xlsxwriter.h>
#include "geo_two_h.h"

int main() {

    lxw_workbook *workbook = workbook_new("geo_8.xlsx");
    lxw_worksheet *worksheet = workbook_add_worksheet(workbook, "sh8");
    lxw_format *format03 = workbook_add_format(workbook);
    lxw_format *format09 = workbook_add_format(workbook);

    worksheet_write_string(worksheet, 4, 1, "Aac", NULL);
    worksheet_write_string(worksheet, 5, 1, "S, м", NULL);
    worksheet_write_string(worksheet, 8, 1, "A", NULL);
    worksheet_write_string(worksheet, 10, 1, "B", NULL);
    worksheet_write_string(worksheet, 12, 1, "C", NULL);
    worksheet_write_string(worksheet, 16, 1, "AB", NULL);
    worksheet_write_string(worksheet, 17, 1, "AC", NULL);
    worksheet_write_string(worksheet, 18, 1, "BC", NULL);
    worksheet_write_string(worksheet, 19, 1, "BA", NULL);
    worksheet_write_string(worksheet, 20, 1, "CA", NULL);
    worksheet_write_string(worksheet, 21, 1, "CB", NULL);
    worksheet_write_string(worksheet, 24, 1, "ΔH", NULL);
    worksheet_write_string(worksheet, 25, 1, "Hm", NULL);
    worksheet_write_string(worksheet, 26, 1, "Rm", NULL);

    worksheet_write_formula(worksheet, 4, 2, "1.911135531", NULL);
    worksheet_write_formula(worksheet, 5, 2, "45444.432", NULL);
    worksheet_write_string(worksheet, 8, 2, "B", NULL);
    worksheet_write_string(worksheet, 9, 2, "C", NULL);
    worksheet_write_string(worksheet, 10, 2, "C", NULL);
    worksheet_write_string(worksheet, 11, 2, "A", NULL);
    worksheet_write_string(worksheet, 12, 2, "A", NULL);
    worksheet_write_string(worksheet, 13, 2, "B", NULL);
    worksheet_write_string(worksheet, 16, 2, "A", NULL);
    worksheet_write_string(worksheet, 17, 2, "A", NULL);
    worksheet_write_string(worksheet, 18, 2, "B", NULL);
    worksheet_write_string(worksheet, 19, 2, "B", NULL);
    worksheet_write_string(worksheet, 20, 2, "C", NULL);
    worksheet_write_string(worksheet, 21, 2, "C", NULL);
    worksheet_write_formula(worksheet, 24, 2, "=ABS((G13-G9)*1000)", NULL);
    worksheet_write_formula(worksheet, 25, 2, "=(G13/2+G9/2)*1000", NULL);
    worksheet_write_formula(worksheet, 26, 2, "=E6*(1-0.5*G6*COS(2*E5))", NULL);

    worksheet_write_string(worksheet, 4, 3, "Bm", NULL);
    worksheet_write_string(worksheet, 5, 3, "a, км", NULL);

    worksheet_write_string(worksheet, 7, 3, "Угол", NULL);
    worksheet_write_formula(worksheet, 8, 3, "1.085815133", NULL);

    worksheet_write_formula(worksheet, 10, 3, "0.878580895", NULL);

    worksheet_write_formula(worksheet, 12, 3, "1.177221371", NULL);

    worksheet_write_string(worksheet, 15, 3, "v1", NULL);
    worksheet_write_string(worksheet, 15, 4, "v2", NULL);
    worksheet_write_formula(worksheet, 16, 3, "=_xlfn.COT(E9)*(I9*COS(F9)-H9*SIN(F9))", NULL);
    worksheet_write_formula(worksheet, 17, 3, "=_xlfn.COT(E10)*(I9*COS(F10)-H9*SIN(F10))", NULL);
    worksheet_write_formula(worksheet, 18, 3, "=_xlfn.COT(E11)*(I11*COS(F11)-H11*SIN(F11))", NULL);
    worksheet_write_formula(worksheet, 19, 3, "=_xlfn.COT(E12)*(I11*COS(F12)-H11*SIN(F12))", NULL);
    worksheet_write_formula(worksheet, 20, 3, "=_xlfn.COT(E13)*(I13*COS(F13)-H13*SIN(F13))", NULL);
    worksheet_write_formula(worksheet, 21, 3, "=_xlfn.COT(E14)*(I13*COS(F14)-H13*SIN(F14))", NULL);

    worksheet_write_string(worksheet, 24, 3, "d", NULL);
    worksheet_write_string(worksheet, 25, 3, "S0", NULL);
    worksheet_write_string(worksheet, 26, 3, "ΔS", NULL);
    worksheet_write_formula(worksheet, 4, 4, "0.959931089", NULL);
    worksheet_write_formula(worksheet, 5, 4, "6378.15", NULL);
    worksheet_write_string(worksheet, 7, 4, "Z", NULL);
    worksheet_write_formula(worksheet, 8, 4, "1.576323203", NULL);
    worksheet_write_formula(worksheet, 9, 4, "1.584177184", NULL);
    worksheet_write_formula(worksheet, 10, 4, "1.576904979", NULL);
    worksheet_write_formula(worksheet, 11, 4, "1.564978563", NULL);
    worksheet_write_formula(worksheet, 12, 4, "1.557415469", NULL);
    worksheet_write_formula(worksheet, 13, 4, "1.565560339", NULL);
    worksheet_write_formula(worksheet, 16, 4, "=I5*G11*COS(D11)^2*SIN(2*F9)", NULL);
    worksheet_write_formula(worksheet, 17, 4, "=I5*G13*COS(D13)^2*SIN(2*F10)", NULL);
    worksheet_write_formula(worksheet, 18, 4, "=I5*G13*COS(D13)^2*SIN(2*F11)", NULL);
    worksheet_write_formula(worksheet, 19, 4, "=I5*G9*COS(D9)^2*SIN(2*F12)", NULL);
    worksheet_write_formula(worksheet, 20, 4, "=I5*G9*COS(D9)^2*SIN(2*F13)", NULL);
    worksheet_write_formula(worksheet, 21, 4, "=I5*G11*COS(D11)^2*SIN(2*F14)", NULL);
    worksheet_write_formula(worksheet, 24, 4, "=((C6^2-C25^2)^0.5)*(1-(C26/C27/1000))", NULL);
    worksheet_write_formula(worksheet, 25, 4, "=E25+(E25^3/(24*(C27*1000)^2))", NULL);
    worksheet_write_formula(worksheet, 26, 4, "=E26-C6", NULL);

    worksheet_write_string(worksheet, 4, 5, "e1", NULL);
    worksheet_write_string(worksheet, 5, 5, "e2", NULL);
    worksheet_write_string(worksheet, 7, 5, "A", NULL);
    worksheet_write_formula(worksheet, 8, 5, "0.791215928", NULL);
    worksheet_write_formula(worksheet, 9, 5, "1.877101611", NULL);
    worksheet_write_formula(worksheet, 10, 5, "3.054326191", NULL);
    worksheet_write_formula(worksheet, 11, 5, "3.932808581", NULL);
    worksheet_write_formula(worksheet, 12, 5, "5.018694264", NULL);
    worksheet_write_formula(worksheet, 13, 5, "6.195918845", NULL);
    worksheet_write_string(worksheet, 24, 5, "Sac", NULL);

    worksheet_write_formula(worksheet, 4, 6, "=(0.00673852567881267)^(1/2)", NULL);
    worksheet_write_formula(worksheet, 5, 6, "0.0066934218835711", NULL);
    worksheet_write_string(worksheet, 7, 6, "H, км", NULL);
    worksheet_write_formula(worksheet, 8, 6, "2.6503", NULL);
    worksheet_write_formula(worksheet, 10, 6, "2.3414", NULL);
    worksheet_write_formula(worksheet, 12, 6, "1.6003", NULL);
    worksheet_write_formula(worksheet, 24, 6, "=C6+E27", NULL);

    worksheet_write_string(worksheet, 4, 7, "k1", NULL);
    worksheet_write_string(worksheet, 7, 7, "ξ ″", NULL);
    worksheet_write_formula(worksheet, 8, 7, "-0.000119749", NULL);
    worksheet_write_formula(worksheet, 10, 7, "-0.00006545", NULL);
    worksheet_write_formula(worksheet, 12, 7, "-0.000069813", NULL);

    worksheet_write_formula(worksheet, 4, 8, "=0.0186977777777778*G5/(2*E6)", NULL);
    worksheet_write_string(worksheet, 7, 8, "ƞ″", NULL);
    worksheet_write_formula(worksheet, 8, 8, "0.000087266", NULL);
    worksheet_write_formula(worksheet, 10, 8, "0.000118295", NULL);
    worksheet_write_formula(worksheet, 12, 8, "-0.000004848", NULL);


    workbook_close(workbook);

    return 0;
}
