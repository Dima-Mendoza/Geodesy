#include <cmath>
#include <cstddef>
#include <iomanip>
#include <xlsxwriter.h>
#include "geo_two_h.h"

int main() {

//macros run updateformula
//3гр 30м + 12м*18
//7 гр 6 минут

    lxw_workbook *workbook = workbook_new("out2342.xlsx");
    lxw_worksheet *worksheet = workbook_add_worksheet(workbook, "sh1");
    lxw_format *format03 = workbook_add_format(workbook);
    lxw_format *format09 = workbook_add_format(workbook);

    format_set_num_format(format09, "0.000000000");
    format_set_num_format(format03, "0.000");

    worksheet_write_number(worksheet, 4,1,e_2_jgd2000,NULL);//e1
    worksheet_write_string(worksheet,3,1,"(e1^1)^2",NULL);
    worksheet_write_number(worksheet, 4, 2, c_jgd2000, NULL);//c
    worksheet_write_string(worksheet,3,2,"c",NULL);
    worksheet_write_string(worksheet,3,3,"Betta",NULL);//Betta
    worksheet_write_formula(worksheet, 4,3,"=1.25*B5", NULL);

    worksheet_write_number(worksheet, 6, 2, 281260.18, NULL);//S
        worksheet_write_string(worksheet,5,2,"S",NULL);
    worksheet_write_formula(worksheet, 6,1,"=6399592.6*0.032231/C5*C7", NULL);//S0
        worksheet_write_string(worksheet,5,1,"S0",NULL);
    worksheet_write_number(worksheet, 6,3,0.123918377,NULL); // A1
        worksheet_write_string(worksheet,5,3,"A1",NULL);
    worksheet_write_number(worksheet, 6,4,0.874894769,NULL); //B!
        worksheet_write_string(worksheet,5,4,"B1",NULL);
    worksheet_write_number(worksheet, 6,5,0.432036864,NULL); //L1
        worksheet_write_string(worksheet,5,5,"L1",NULL);
    worksheet_write_formula(worksheet, 6,6,"=E7+E15",NULL); //B2
        worksheet_write_string(worksheet,5,6,"B2",NULL);
    worksheet_write_formula(worksheet, 6,7,"=F7+F15",NULL); //B2//L2
        worksheet_write_string(worksheet,5,7,"L2",NULL);

    //Column and row names
    worksheet_write_string(worksheet,8,1,"№",NULL);
    worksheet_write_string(worksheet,9,1,"1",NULL);
    worksheet_write_string(worksheet,10,1,"2",NULL);
    worksheet_write_string(worksheet,11,1,"3",NULL);
    worksheet_write_string(worksheet,12,1,"4",NULL);
    worksheet_write_string(worksheet,8,2,"Bi",NULL);
    worksheet_write_string(worksheet,8,3,"Ai",NULL);
    worksheet_write_string(worksheet,8,4,"del Bi",NULL);
    worksheet_write_string(worksheet,8,5,"del Li",NULL);
    worksheet_write_string(worksheet,8,6,"del Ai",NULL);
    worksheet_write_string(worksheet,8,7,"Vi",NULL);
    worksheet_write_string(worksheet,8,8,"yi",NULL);
    worksheet_write_string(worksheet,13,1,"B2",NULL);
    worksheet_write_string(worksheet,13,2,"L2",NULL);
    worksheet_write_string(worksheet,13,3,"A21",NULL);
    worksheet_write_string(worksheet,13,4,"del B",NULL);
    worksheet_write_string(worksheet,13,5,"del L",NULL);
    worksheet_write_string(worksheet,13,6,"del A",NULL);
    worksheet_write_string(worksheet,17,1,"B2",NULL);//Table 2
    worksheet_write_string(worksheet,18,1,"B1",NULL);
    worksheet_write_string(worksheet,19,1,"Betta",NULL);
    worksheet_write_string(worksheet,20,1,"I rad",NULL);
    worksheet_write_string(worksheet,21,1,"Bm",NULL);
    worksheet_write_string(worksheet,22,1,"sinBm",NULL);
    worksheet_write_string(worksheet,23,1,"cosBm",NULL);
    worksheet_write_string(worksheet,24,1,"e^1^2cos^2Bm",NULL);
    worksheet_write_string(worksheet,25,1,"Vm",NULL);
    worksheet_write_string(worksheet,26,1,"Nm",NULL);
    worksheet_write_string(worksheet,27,1,"Mm",NULL);
    worksheet_write_string(worksheet,28,1,"c",NULL);

    worksheet_write_string(worksheet,17,3,"Q",NULL);//Table 2 part 2
    worksheet_write_string(worksheet,18,3,"P",NULL);
    worksheet_write_string(worksheet,19,3,"tg Am",NULL);
    worksheet_write_string(worksheet,20,3,"Am",NULL);
    worksheet_write_string(worksheet,21,3,"IsinBm",NULL);
    worksheet_write_string(worksheet,22,3,"A",NULL);
    worksheet_write_string(worksheet,23,3,"A/2",NULL);
    worksheet_write_string(worksheet,24,3,"A12",NULL);
    worksheet_write_string(worksheet,25,3,"A21",NULL);
    worksheet_write_string(worksheet,26,3,"S",NULL);
    worksheet_write_string(worksheet,27,3,"Контроль",NULL);
    worksheet_write_string(worksheet,28,3,"N/M",NULL);
    worksheet_write_string(worksheet,28,4,"V^2",NULL);


    //Bi
    worksheet_write_number(worksheet, 9, 2, 0.874894769, NULL);
    worksheet_write_formula(worksheet, 10, 2, "=C10+RADIANS(E10/3600)/2", NULL);
    worksheet_write_formula(worksheet, 11, 2, "=C10+(RADIANS(E10/3600)+RADIANS(E11/3600))/4", NULL);
    worksheet_write_formula(worksheet, 12, 2, "=C10-RADIANS(E11/3600)+2*RADIANS(E12/3600)", NULL);

    //Ai
    worksheet_write_number(worksheet, 9, 3, 0.123918377, NULL);
    worksheet_write_formula(worksheet, 10, 3, "=D10+RADIANS(G10/3600)/2", NULL);
    worksheet_write_formula(worksheet, 11, 3, "=D10+(RADIANS(G10/3600)+RADIANS(G11/3600))/4", NULL);
    worksheet_write_formula(worksheet, 12, 3, "=D10-RADIANS(G11/3600)+2*RADIANS(G12/3600)", NULL);

    //del Bi
    worksheet_write_formula(worksheet, 9, 4, "=B7*H10^3*COS(D10)", NULL);
    worksheet_write_formula(worksheet, 10, 4, "=B7*H11^3*COS(D11)", NULL);
    worksheet_write_formula(worksheet, 11, 4, "=B7*H12^3*COS(D12)", NULL);
    worksheet_write_formula(worksheet, 12, 4, "=B7*H13^3*COS(D13)", NULL);

    //del Li
    worksheet_write_formula(worksheet, 9, 5, "=B7*H10*(SIN(D10)/COS(C10))", NULL);
    worksheet_write_formula(worksheet, 10, 5, "=B7*H11*(SIN(D11)/COS(C11))", NULL);
    worksheet_write_formula(worksheet, 11, 5, "=B7*H12*(SIN(D12)/COS(C12))", NULL);
    worksheet_write_formula(worksheet, 12, 5, "=B7*H13*(SIN(D13)/COS(C13))", NULL);

    //del Ai
    worksheet_write_formula(worksheet, 9, 6, "=F10*SIN(C10)", NULL);
    worksheet_write_formula(worksheet, 10, 6, "=F11*SIN(C11)", NULL);
    worksheet_write_formula(worksheet, 11, 6, "=F12*SIN(C12)", NULL);
    worksheet_write_formula(worksheet, 12, 6, "=F13*SIN(C13)", NULL);

    //Vi
    worksheet_write_formula(worksheet, 9, 7, "=(1+0.6*I10)/(1+0.2*I10)", NULL);
    worksheet_write_formula(worksheet, 10, 7, "=(1+0.6*I11)/(1+0.2*I11)", NULL);
    worksheet_write_formula(worksheet, 11, 7, "=(1+0.6*I12)/(1+0.2*I12)", NULL);
    worksheet_write_formula(worksheet, 12, 7, "=(1+0.6*I13)/(1+0.2*I13)", NULL);

    //yi
    worksheet_write_formula(worksheet, 9, 8, "=D5*(COS(C10))^2", NULL);
    worksheet_write_formula(worksheet, 10, 8, "=D5*(COS(C11))^2", NULL);
    worksheet_write_formula(worksheet, 11, 8, "=D5*(COS(C12))^2", NULL);
    worksheet_write_formula(worksheet, 12, 8, "=D5*(COS(C13))^2", NULL);

    //Result
    worksheet_write_formula(worksheet, 14, 1, "=C10+E15", NULL);
    worksheet_write_formula(worksheet, 14, 2, "=F7+F15", NULL);
    worksheet_write_formula(worksheet, 14, 3, "=D7+G15+RADIANS(180)", NULL);
    worksheet_write_formula(worksheet, 14, 4, "=(RADIANS(E10/3600)+(RADIANS(E12/3600))*4+RADIANS(E13/3600))/6", NULL);
    worksheet_write_formula(worksheet, 14, 5, "=1/6*(RADIANS(F10/3600)+(RADIANS(F12/3600))*4+RADIANS(F13/3600))", NULL);
    worksheet_write_formula(worksheet, 14, 6, "=1/6*(RADIANS(G10/3600)+(RADIANS(G12/3600))*4+RADIANS(G13/3600))", NULL);

    //Table 2 column 1
    worksheet_write_formula(worksheet, 17, 2, "=E7+E15", NULL);
    worksheet_write_formula(worksheet, 18, 2, "=F7+F15", NULL);
    worksheet_write_formula(worksheet, 19, 2, "=(G7-E7)", NULL);
    worksheet_write_formula(worksheet, 20, 2, "=H7-F7", NULL);
    worksheet_write_formula(worksheet, 21, 2, "=(G7+E7)/2", NULL);
    worksheet_write_formula(worksheet, 22, 2, "=SIN(C22)", NULL);
    worksheet_write_formula(worksheet, 23, 2, "=COS(C22)", NULL);
    worksheet_write_formula(worksheet, 24, 2, "=B5*C24^2", NULL);
    worksheet_write_formula(worksheet, 25, 2, "=(1+B5*(C24)^2)^(1/2)", NULL);
    worksheet_write_formula(worksheet, 26, 2, "=C29/C26", NULL);
    worksheet_write_formula(worksheet, 27, 2, "=C29/(C26^3)", NULL);

    long double fm = jgd2000.semi_major_axis / (pow(1 - e_1_jgd2000,1/2));
    worksheet_write_number(worksheet, 28, 2, fm, NULL);

    //Table 2 column 2
    worksheet_write_formula(worksheet, 17, 4, "=C20*C28*(1-(((C21^2)*(2+SIN(C22)^2))/24))", NULL);
    worksheet_write_formula(worksheet, 18, 4, "=C21*C27*COS(C22)*(1+(C20^2-(E22)^2)/24)", NULL);
    worksheet_write_formula(worksheet, 19, 4, "=E19/E18", NULL);
    worksheet_write_formula(worksheet, 20, 4, "=ATAN(E20)", NULL);
    worksheet_write_formula(worksheet, 21, 4, "=C21*C23", NULL);
    worksheet_write_formula(worksheet, 22, 4, "=E22*(1+((3*C20^2+2*C21^2-2*E22^2)/24))", NULL);
    worksheet_write_formula(worksheet, 23, 4, "=E23/2", NULL);
    worksheet_write_formula(worksheet, 24, 4, "=E21-E24", NULL);
    worksheet_write_formula(worksheet, 25, 4, "=E21+E24+(180/(6399592.6*0.032231/3600))", NULL);
    worksheet_write_formula(worksheet, 26, 4, "=(E18^2+E19^2)^0.5", NULL);
    worksheet_write_formula(worksheet, 26, 5, "=E19/SIN(E21)", NULL);
    worksheet_write_formula(worksheet, 26, 6, "=E18/COS(E21)", NULL);
    worksheet_write_formula(worksheet, 29, 4, "=C26^2", NULL);
    worksheet_write_formula(worksheet, 29, 3, "=C27/C28", NULL);

    workbook_close(workbook);

    return 0;
}