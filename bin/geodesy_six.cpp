#include <cmath>
#include <cstddef>
#include <iomanip>
#include <xlsxwriter.h>
#include "geo_two_h.h"

int main() {
    lxw_workbook *workbook = workbook_new("geo_6.xlsx");
    lxw_worksheet *worksheet = workbook_add_worksheet(workbook, "sh6");
    lxw_format *format03 = workbook_add_format(workbook);
    lxw_format *format09 = workbook_add_format(workbook);

    format_set_num_format(format09, "0.000000000");
    format_set_num_format(format03, "0.000");

    worksheet_write_number(worksheet, 1,1,krosvskogo.semi_major_axis, NULL);
    worksheet_write_number(worksheet, 2,1,krosvskogo.compression, NULL);
    worksheet_write_number(worksheet, 3,1,b_krosvskogo, NULL);
    worksheet_write_number(worksheet, 4,1,e_1_krosvskogo, NULL);
    worksheet_write_number(worksheet, 5,1,e_2_krosvskogo, NULL);
    worksheet_write_number(worksheet, 6,1,c_krosvskogo, NULL);
    worksheet_write_number(worksheet, 7,1,50.51138055, NULL);
    worksheet_write_number(worksheet, 8,1,3030.68, NULL);
    worksheet_write_number(worksheet, 9,1,181840.97, NULL);

    //

    worksheet_write_formula(worksheet, 11,1,"=(53/B8)+(43/B9)+(40.97/B10)", NULL);
    worksheet_write_formula(worksheet, 12,1,"=(27/B8)+(21/B9)+(13.43/B10)", NULL);
    worksheet_write_formula(worksheet, 13,1,"=27/B8", NULL);
    worksheet_write_formula(worksheet, 14,1,"=B13-B14", NULL);
    worksheet_write_formula(worksheet, 15, 1, "=SIN(B12)", NULL);
    worksheet_write_formula(worksheet, 16, 1, "=SIN(B12*2)", NULL);
    worksheet_write_formula(worksheet, 17, 1, "=SIN(B12*4)", NULL);
    worksheet_write_formula(worksheet, 18, 1, "=SIN(B12*6)", NULL);
    worksheet_write_formula(worksheet, 19, 1, "=COS(B12)", NULL);
    worksheet_write_formula(worksheet, 20, 1, "=B20^2", NULL);
    worksheet_write_formula(worksheet, 21, 1, "=B20^3", NULL);
    worksheet_write_formula(worksheet, 22, 1, "=B20^5", NULL);
    worksheet_write_formula(worksheet, 23, 1, "=B16*B20", NULL);
    worksheet_write_formula(worksheet, 24, 1, "=TAN(B12)", NULL);
    worksheet_write_formula(worksheet, 25, 1, "=B25^2", NULL);
    worksheet_write_formula(worksheet, 26, 1, "=B25^4", NULL);
    worksheet_write_formula(worksheet, 27, 1, "6367558.497", NULL);
    worksheet_write_formula(worksheet, 28, 1, "32072.960", NULL);
    worksheet_write_formula(worksheet, 29, 1, "67.312", NULL);
    worksheet_write_formula(worksheet, 30, 1, "0.132", NULL);
    worksheet_write_formula(worksheet, 31, 1, "=B28*B12", NULL);
    worksheet_write_formula(worksheet, 32, 1, "=B29/2", NULL);
    worksheet_write_formula(worksheet, 33, 1, "=B30/4", NULL);
    worksheet_write_formula(worksheet, 34, 1, "=B31/6", NULL);
    worksheet_write_formula(worksheet, 35, 1, "=B32-(B33*B17)+(B34*B18)-(B35*B19)", NULL);
    worksheet_write_formula(worksheet, 36, 1, "=B7/(1+B6*B21)^0.5", NULL);
    worksheet_write_formula(worksheet, 37, 1, "=(B6^0.5)*B20", NULL);
    worksheet_write_formula(worksheet, 38, 1, "=B38^2", NULL);
    worksheet_write_formula(worksheet, 39, 1, "=B38^4", NULL);
    worksheet_write_formula(worksheet, 40, 1, "=B15^2", NULL);
    worksheet_write_formula(worksheet, 41, 1, "=B15^4", NULL);
    worksheet_write_formula(worksheet, 42, 1, "=B15^6", NULL);
    worksheet_write_formula(worksheet, 43, 1, "=B15^3", NULL);
    worksheet_write_formula(worksheet, 44, 1, "=B15^5", NULL);
    worksheet_write_formula(worksheet, 45, 1, "=B37*B16", NULL);
    worksheet_write_formula(worksheet, 46, 1, "=(1/2)*B37*B24", NULL);
    worksheet_write_formula(worksheet, 47, 1, "=(1/24)*B46*B22*(5-B26+(9*B39)+(4*B40))", NULL);
    worksheet_write_formula(worksheet, 48, 1, "=(1/720)*B46*B23*(61-(58*B26)+B27+(270*B39)-(330*B39*B26))", NULL);
    worksheet_write_formula(worksheet, 49, 1, "=B37*B20", NULL);
    worksheet_write_formula(worksheet, 50, 1, "=(1/6)*B37*B22*(1-B26+B39)", NULL);
    worksheet_write_formula(worksheet, 51, 1, "=(1/120)*B37*B23*(5-(18*B26)+B27+(14*B39)-(58*B39*B26))", NULL);
    worksheet_write_formula(worksheet, 52, 1, "=B36+(B47*B41)+(B48*B42)+(B49*B43)", NULL);
    worksheet_write_formula(worksheet, 53, 1, "=(B50*B15)+(B51*B44)+(B52*B45)", NULL);
//
    worksheet_write_formula(worksheet, 55, 1, "=B53/B28", NULL);
    worksheet_write_formula(worksheet, 56, 1, "0.002518465", NULL);
    worksheet_write_formula(worksheet, 57, 1, "0.0000037", NULL);
    worksheet_write_formula(worksheet, 58, 1, "0.000000007", NULL);
    worksheet_write_formula(worksheet, 59, 1, "=SIN(B56)", NULL);
    worksheet_write_formula(worksheet, 60, 1, "=SIN(B56*2)", NULL);
    worksheet_write_formula(worksheet, 61, 1, "=SIN(B56*4)", NULL);
    worksheet_write_formula(worksheet, 62, 1, "=SIN(B56*6)", NULL);
    worksheet_write_formula(worksheet, 63, 1, "=B57*B61", NULL);
    worksheet_write_formula(worksheet, 64, 1, "=B58*B62", NULL);
    worksheet_write_formula(worksheet, 65, 1, "=B59*B63", NULL);
    worksheet_write_formula(worksheet, 66, 1, "=B56+B64+B65+B66", NULL);
    worksheet_write_formula(worksheet, 67, 1, "=SIN(B67)", NULL);
    worksheet_write_formula(worksheet, 68, 1, "=B68^2", NULL);
    worksheet_write_formula(worksheet, 69, 1, "=COS(B67)", NULL);
    worksheet_write_formula(worksheet, 70, 1, "=TAN(B67)", NULL);
    worksheet_write_formula(worksheet, 71, 1, "=B71^2", NULL);
    worksheet_write_formula(worksheet, 72, 1, "=B71^4", NULL);
    worksheet_write_formula(worksheet, 73, 1, "=B2/(1-B5*B69)^0.5", NULL);
    worksheet_write_formula(worksheet, 74, 1, "=B74^2", NULL);
    worksheet_write_formula(worksheet, 75, 1, "=B74^4", NULL);
    worksheet_write_formula(worksheet, 76, 1, "=B7/B74", NULL);
    worksheet_write_formula(worksheet, 77, 1, "=B77^2", NULL);
    worksheet_write_formula(worksheet, 78, 1, "=(B6^0.5)*B70", NULL);
    worksheet_write_formula(worksheet, 79, 1, "=B79^2", NULL);
    worksheet_write_formula(worksheet, 80, 1, "=B79^4", NULL);
    worksheet_write_formula(worksheet, 81, 1, "=-((B78*B71)/(2*B75))", NULL);
    worksheet_write_formula(worksheet, 82, 1, "=-((B82/(12*B75))*(5+(3*B72)+B80-(9*B80*B72)-(4*B81)))", NULL);
    worksheet_write_formula(worksheet, 83, 1, "=(B82/(360*B76))*(61+(90*B72)+(45*B73)+(46*B80)-(252*B80*B72)-(90*B80*B73))", NULL);
    worksheet_write_formula(worksheet, 84, 1, "=B54^2", NULL);
    worksheet_write_formula(worksheet, 85, 1, "=B54^4", NULL);
    worksheet_write_formula(worksheet, 86, 1, "=B54^6", NULL);
    worksheet_write_formula(worksheet, 87, 1, "=B54^3", NULL);
    worksheet_write_formula(worksheet, 88, 1, "=B54^5", NULL);
    worksheet_write_formula(worksheet, 89, 1, "=B82*B85", NULL);
    worksheet_write_formula(worksheet, 90, 1, "=B83*B86", NULL);
    worksheet_write_formula(worksheet, 91, 1, "=B84*B87", NULL);
    worksheet_write_formula(worksheet, 92, 1, "=1/(B74*B70)", NULL);
    worksheet_write_formula(worksheet, 93, 1, "=-((B93/(6*B75))*(1+(2*B72)+B80))", NULL);
    worksheet_write_formula(worksheet, 94, 1, "=(B93/(120*B76))*(5+(28*B72)+(24*B73)+(6*B80)+(8*B80*B72))", NULL);
    worksheet_write_formula(worksheet, 95, 1, "=B93*B54", NULL);
    worksheet_write_formula(worksheet, 96, 1, "=B94*B88", NULL);
    worksheet_write_formula(worksheet, 97, 1, "=B95*B89", NULL);
    worksheet_write_formula(worksheet, 98, 1, "=B96+B97+B98", NULL);
    worksheet_write_formula(worksheet, 99, 1, "=B67+B90+B91+B92", NULL);
    worksheet_write_formula(worksheet, 100, 1, "=B14+B99", NULL);

worksheet_write_string(worksheet, 1, 0, "a", NULL);
worksheet_write_string(worksheet, 2, 0, "α", NULL);
worksheet_write_string(worksheet, 3, 0, "b", NULL);
worksheet_write_string(worksheet, 4, 0, "e^2", NULL);
worksheet_write_string(worksheet, 5, 0, "(e^1)^2", NULL);
worksheet_write_string(worksheet, 6, 0, "c", NULL);
worksheet_write_string(worksheet, 7, 0, "ρ˚", NULL);
worksheet_write_string(worksheet, 8, 0, "ρ'", NULL);
worksheet_write_string(worksheet, 9, 0, "ρ''", NULL);

worksheet_write_string(worksheet, 11, 0, "B", NULL);
worksheet_write_string(worksheet, 12, 0, "L", NULL);
worksheet_write_string(worksheet, 13, 0, "L0", NULL);
worksheet_write_string(worksheet, 14, 0, "ℓ", NULL);
worksheet_write_string(worksheet, 15, 0, "sinB", NULL);
worksheet_write_string(worksheet, 16, 0, "sin2B", NULL);
worksheet_write_string(worksheet, 17, 0, "sin4B", NULL);
worksheet_write_string(worksheet, 18, 0, "sin6B", NULL);
worksheet_write_string(worksheet, 19, 0, "cosB", NULL);
worksheet_write_string(worksheet, 20, 0, "cos^2B", NULL);
worksheet_write_string(worksheet, 21, 0, "cos^3B", NULL);
worksheet_write_string(worksheet, 22, 0, "cos^5B", NULL);
worksheet_write_string(worksheet, 23, 0, "sinB*cosB", NULL);
worksheet_write_string(worksheet, 24, 0, "tgB", NULL);
worksheet_write_string(worksheet, 25, 0, "tg^2B", NULL);
worksheet_write_string(worksheet, 26, 0, "tg^4B", NULL);
worksheet_write_string(worksheet, 27, 0, "A0", NULL);
worksheet_write_string(worksheet, 28, 0, "A2", NULL);
worksheet_write_string(worksheet, 29, 0, "A4", NULL);
worksheet_write_string(worksheet, 30, 0, "A6", NULL);
worksheet_write_string(worksheet, 31, 0, "A0*B", NULL);
worksheet_write_string(worksheet, 32, 0, "A2/2", NULL);
worksheet_write_string(worksheet, 33, 0, "A4/4", NULL);
worksheet_write_string(worksheet, 34, 0, "A6/6", NULL);
worksheet_write_string(worksheet, 35, 0, "X", NULL);
worksheet_write_string(worksheet, 36, 0, "N", NULL);
worksheet_write_string(worksheet, 37, 0, "η", NULL);
worksheet_write_string(worksheet, 38, 0, "η^2", NULL);
worksheet_write_string(worksheet, 39, 0, "η^4", NULL);
worksheet_write_string(worksheet, 40, 0, "ℓ^2", NULL);
worksheet_write_string(worksheet, 41, 0, "ℓ^4", NULL);
worksheet_write_string(worksheet, 42, 0, "ℓ^6", NULL);
worksheet_write_string(worksheet, 43, 0, "ℓ^3", NULL);
worksheet_write_string(worksheet, 44, 0, "ℓ^5", NULL);
worksheet_write_string(worksheet, 45, 0, "N*sinB", NULL);
worksheet_write_string(worksheet, 46, 0, "a2", NULL);
worksheet_write_string(worksheet, 47, 0, "a4", NULL);
worksheet_write_string(worksheet, 48, 0, "a6", NULL);
worksheet_write_string(worksheet, 49, 0, "b1", NULL);
worksheet_write_string(worksheet, 50, 0, "b3", NULL);
worksheet_write_string(worksheet, 51, 0, "b5", NULL);
worksheet_write_string(worksheet, 52, 0, "x", NULL);
worksheet_write_string(worksheet, 53, 0, "y", NULL);

worksheet_write_string(worksheet, 55, 0, "β", NULL);
worksheet_write_string(worksheet, 56, 0, "b2", NULL);
worksheet_write_string(worksheet, 57, 0, "b4", NULL);
worksheet_write_string(worksheet, 58, 0, "b6", NULL);
worksheet_write_string(worksheet, 59, 0, "sinβ", NULL);
worksheet_write_string(worksheet, 60, 0, "sin2β", NULL);
worksheet_write_string(worksheet, 61, 0, "sin4β", NULL);
worksheet_write_string(worksheet, 62, 0, "sin6β", NULL);
worksheet_write_string(worksheet, 63, 0, "b2sin2β", NULL);
worksheet_write_string(worksheet, 64, 0, "b4sin4β", NULL);
worksheet_write_string(worksheet, 65, 0, "b6sin6β", NULL);
worksheet_write_string(worksheet, 66, 0, "Bx", NULL);
worksheet_write_string(worksheet, 67, 0, "sinBx", NULL);
worksheet_write_string(worksheet, 68, 0, "sin^2Bx", NULL);
worksheet_write_string(worksheet, 69, 0, "cosBx", NULL);
worksheet_write_string(worksheet, 70, 0, "tgBx", NULL);
worksheet_write_string(worksheet, 71, 0, "tg^2Bx", NULL);
worksheet_write_string(worksheet, 72, 0, "tg^4Bx", NULL);
worksheet_write_string(worksheet, 73, 0, "Nx", NULL);
worksheet_write_string(worksheet, 74, 0, "Nx^2", NULL);
worksheet_write_string(worksheet, 75, 0, "Nx^4", NULL);
worksheet_write_string(worksheet, 76, 0, "Vx", NULL);
worksheet_write_string(worksheet, 77, 0, "V^2x", NULL);
worksheet_write_string(worksheet, 78, 0, "ηx", NULL);
worksheet_write_string(worksheet, 79, 0, "ηx^2", NULL);
worksheet_write_string(worksheet, 80, 0, "ηx^4", NULL);
worksheet_write_string(worksheet, 81, 0, "A2", NULL);
worksheet_write_string(worksheet, 82, 0, "A4", NULL);
worksheet_write_string(worksheet, 83, 0, "A6", NULL);
worksheet_write_string(worksheet, 84, 0, "y^2", NULL);
worksheet_write_string(worksheet, 85, 0, "y^4", NULL);
worksheet_write_string(worksheet, 86, 0, "y^6", NULL);
worksheet_write_string(worksheet, 87, 0, "y^3", NULL);
worksheet_write_string(worksheet, 88, 0, "y^5", NULL);
worksheet_write_string(worksheet, 89, 0, "A2*y^2", NULL);
worksheet_write_string(worksheet, 90, 0, "A4*y^4", NULL);
worksheet_write_string(worksheet, 91, 0, "A6*y^6", NULL);
worksheet_write_string(worksheet, 92, 0, "P1", NULL);
worksheet_write_string(worksheet, 93, 0, "P3", NULL);
worksheet_write_string(worksheet, 94, 0, "P5", NULL);
worksheet_write_string(worksheet, 95, 0, "P1*y", NULL);
worksheet_write_string(worksheet, 96, 0, "P3*y^3", NULL);
worksheet_write_string(worksheet, 97, 0, "P5*y^5", NULL);
worksheet_write_string(worksheet, 98, 0, "ℓ", NULL);
worksheet_write_string(worksheet, 99, 0, "B", NULL);
worksheet_write_string(worksheet, 100, 0, "L", NULL);







    workbook_close(workbook);
    return 0;
}
