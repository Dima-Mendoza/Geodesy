#include <cmath>
#include <iomanip>
#include <xlsxwriter.h>
#include "geo_three_h.h"

// Преобразование в радианы
long double toRadian(long double a);
long double toDegree(long double a);

// Преобразование из десятичного градуса в градусы, минуты и секунды
void decimalToDMS(long double degree, int &deg, int &min, long double &sec) {
    deg = static_cast<int>(degree);
    long double frac = degree - deg;

    min = static_cast<int>(frac * 60);
    frac = frac * 60 - min;

    sec = frac * 60;

    if (sec >= 60.0) {
        int extra_minutes = static_cast<int>(sec / 60);
        sec -= extra_minutes * 60;
        min += extra_minutes;
    }

    if (min >= 60) {
        int extra_degrees = min / 60;
        min -= extra_degrees * 60;
        deg += extra_degrees;
    }
}

int main() {
    // Коэффициенты
    long double b = 44797.282 + 12 * 18;
    long double k = 0.000000000000004097456;

    // Градусы
    long double A = 62.21257138888888888888;
    long double B = 50.33904222222222222222;
    long double C = 67.44991694444444444444;

    // Коэффициент функции широты
    long double fi = 0.00253;

    long double epsilon = fi * pow(b/1000.0, 2) * sin(toRadian(A)) * sin(toRadian(C)) / sin(toRadian(B));

    long double W = A*3600 + B*3600 + C*3600 - (180.0*3600.0) - epsilon;

    // Невязка
    long double deltai = -1 * (W / 3.0);

    // Невязка к градусам
    long double A_ispr = A + deltai / 3600.0;
    long double B_ispr = B + deltai / 3600.0;
    long double C_ispr = C + deltai / 3600.0;

    // Сферические и плоские стороны, а также A
    long double sf_B = b;
    long double A_b = k * pow(b, 3);
    long double pl_B = sf_B - A_b;

    long double pl_A = pl_B * (sin(toRadian(A_ispr)) / sin(toRadian(B_ispr)));
    long double A_a = k * pow(pl_A, 3);
    long double sf_A = pl_A - A_a;

    long double pl_C = pl_B * (sin(toRadian(C_ispr)) / sin(toRadian(B_ispr)));
    long double A_c = k * pow(pl_C, 3);
    long double sf_C = pl_C - A_c;

    // Теорема Лежандра
    long double epsi = -1 * (epsilon) / 3;

    // Синусы
    long double A_ispr_2 = A + epsi/3600 + deltai/3600;
    long double B_ispr_2 = B + epsi/3600 + deltai/3600;
    long double C_ispr_2 = C + epsi/3600 + deltai/3600;

    // Сфер стороны
    long double sf_B_2 = b;
    long double sf_A_2 = sf_B_2 * sin(toRadian(A_ispr_2)) / sin(toRadian(B_ispr_2));
    long double sf_C_2 = sf_B_2 * sin(toRadian(C_ispr_2)) / sin(toRadian(B_ispr_2));

    //-------------------------ЗАПИСЬ ДАННЫХ----------------------------

    lxw_workbook *workbook = workbook_new("out.xlsx");
    lxw_worksheet *worksheet = workbook_add_worksheet(workbook, NULL);
    lxw_format *format03 = workbook_add_format(workbook);
    lxw_format *format09 = workbook_add_format(workbook);

    format_set_num_format(format09, "0.000000000");
    format_set_num_format(format03, "0.000");

    worksheet_write_string(worksheet, 0, 1, "Сферические углы", NULL);
    worksheet_write_string(worksheet, 0, 4, "delta i", NULL);
    worksheet_write_string(worksheet, 0, 5, "Испр углы", NULL);
    worksheet_write_string(worksheet, 0, 8, "Син углов", NULL);
    worksheet_write_string(worksheet, 0, 9, "Плоская сторона", NULL);
    worksheet_write_string(worksheet, 0, 10, "А", NULL);
    worksheet_write_string(worksheet, 0, 11, "Сферические стороны", NULL);

    worksheet_write_string(worksheet, 1, 0, "A", NULL);
    worksheet_write_string(worksheet, 2, 0, "B", NULL);
    worksheet_write_string(worksheet, 3, 0, "C", NULL);
    worksheet_write_string(worksheet, 4, 0, "SUM", NULL);
    worksheet_write_string(worksheet, 5, 0, "Epsilon", NULL);
    worksheet_write_string(worksheet, 6, 0, "W", NULL);

    worksheet_write_number(worksheet, 4, 1, A+B+C, NULL);
    worksheet_write_number(worksheet, 5, 1, epsilon, NULL);
    worksheet_write_number(worksheet, 6, 1, W, NULL);

    int A_deg, A_min, B_deg, B_min, C_deg, C_min;
    long double A_sec, B_sec, C_sec;

    decimalToDMS(A, A_deg, A_min, A_sec);
    decimalToDMS(B, B_deg, B_min, B_sec);
    decimalToDMS(C, C_deg, C_min, C_sec);

    worksheet_write_number(worksheet, 1, 1, A_deg, NULL);
    worksheet_write_number(worksheet, 2, 1, B_deg, NULL);
    worksheet_write_number(worksheet, 3, 1, C_deg, NULL);

    worksheet_write_number(worksheet, 1, 2, A_min, NULL);
    worksheet_write_number(worksheet, 2, 2, B_min, NULL);
    worksheet_write_number(worksheet, 3, 2, C_min, NULL);

    worksheet_write_number(worksheet, 1, 3, A_sec, format03);
    worksheet_write_number(worksheet, 2, 3, B_sec, format03);
    worksheet_write_number(worksheet, 3, 3, C_sec, format03);

    worksheet_write_number(worksheet, 1, 4, deltai, format03);
    worksheet_write_number(worksheet, 2, 4, deltai, format03);
    worksheet_write_number(worksheet, 3, 4, deltai, format03);

    // Преобразуем исправленные углы в DMS (с учётом невязки)
    decimalToDMS(A_ispr, A_deg, A_min, A_sec);
    decimalToDMS(B_ispr, B_deg, B_min, B_sec);
    decimalToDMS(C_ispr, C_deg, C_min, C_sec);

    // Записываем исправленные углы в Excel
    worksheet_write_number(worksheet, 1, 5, A_deg, NULL);
    worksheet_write_number(worksheet, 2, 5, B_deg, NULL);
    worksheet_write_number(worksheet, 3, 5, C_deg, NULL);

    worksheet_write_number(worksheet, 1, 6, A_min, NULL);
    worksheet_write_number(worksheet, 2, 6, B_min, NULL);
    worksheet_write_number(worksheet, 3, 6, C_min, NULL);

    worksheet_write_number(worksheet, 1, 7, A_sec, format03);
    worksheet_write_number(worksheet, 2, 7, B_sec, format03);
    worksheet_write_number(worksheet, 3, 7, C_sec, format03);

    worksheet_write_number(worksheet, 1, 8, sin(toRadian(A_ispr)), format09);
    worksheet_write_number(worksheet, 2, 8, sin(toRadian(B_ispr)), format09);
    worksheet_write_number(worksheet, 3, 8, sin(toRadian(C_ispr)), format09);

    worksheet_write_number(worksheet, 1, 9, pl_A, format03);
    worksheet_write_number(worksheet, 2, 9, pl_B, format03);
    worksheet_write_number(worksheet, 3, 9, pl_C, format03);

    worksheet_write_number(worksheet, 1, 10, A_a, format03);
    worksheet_write_number(worksheet, 2, 10, A_b, format03);
    worksheet_write_number(worksheet, 3, 10, A_c, format03);

    worksheet_write_number(worksheet, 1, 11, sf_A, format03);
    worksheet_write_number(worksheet, 2, 11, sf_B, format03);
    worksheet_write_number(worksheet, 3, 11, sf_C, format03);

    worksheet_write_string(worksheet, 0, 14, "Сферические углы", NULL);
    worksheet_write_string(worksheet, 0, 17, "-epsilon/3", NULL);
    worksheet_write_string(worksheet, 0, 18, "delta i", NULL);
    worksheet_write_string(worksheet, 0, 19, "Плоские углы", NULL);
    worksheet_write_string(worksheet, 0, 22, "Син углов", NULL);
    worksheet_write_string(worksheet, 0, 23, "Сферические стороны", NULL);

    worksheet_write_string(worksheet, 1, 13, "A", NULL);
    worksheet_write_string(worksheet, 2, 13, "B", NULL);
    worksheet_write_string(worksheet, 3, 13, "C", NULL);
    worksheet_write_string(worksheet, 4, 13, "SUM", NULL);
    worksheet_write_string(worksheet, 5, 13, "Epsilon", NULL);
    worksheet_write_string(worksheet, 6, 13, "W", NULL);

    worksheet_write_number(worksheet, 4, 14, A+B+C, NULL);
    worksheet_write_number(worksheet, 5, 14, epsilon, NULL);
    worksheet_write_number(worksheet, 6, 14, W, NULL);

    decimalToDMS(A, A_deg, A_min, A_sec);
    decimalToDMS(B, B_deg, B_min, B_sec);
    decimalToDMS(C, C_deg, C_min, C_sec);

    worksheet_write_number(worksheet, 1, 14, A_deg, NULL);
    worksheet_write_number(worksheet, 2, 14, B_deg, NULL);
    worksheet_write_number(worksheet, 3, 14, C_deg, NULL);

    worksheet_write_number(worksheet, 1, 15, A_min, NULL);
    worksheet_write_number(worksheet, 2, 15, B_min, NULL);
    worksheet_write_number(worksheet, 3, 15, C_min, NULL);

    worksheet_write_number(worksheet, 1, 16, A_sec, format03);
    worksheet_write_number(worksheet, 2, 16, B_sec, format03);
    worksheet_write_number(worksheet, 3, 16, C_sec, format03);

    worksheet_write_number(worksheet, 1, 17, epsi, format03);
    worksheet_write_number(worksheet, 2, 17, epsi, format03);
    worksheet_write_number(worksheet, 3, 17, epsi, format03);

    worksheet_write_number(worksheet, 1, 18, deltai, format03);
    worksheet_write_number(worksheet, 2, 18, deltai, format03);
    worksheet_write_number(worksheet, 3, 18, deltai, format03);

    decimalToDMS(A_ispr_2, A_deg, A_min, A_sec);
    decimalToDMS(B_ispr_2, B_deg, B_min, B_sec);
    decimalToDMS(C_ispr_2, C_deg, C_min, C_sec);

    worksheet_write_number(worksheet, 1, 19, A_deg, NULL);
    worksheet_write_number(worksheet, 2, 19, B_deg, NULL);
    worksheet_write_number(worksheet, 3, 19, C_deg, NULL);

    worksheet_write_number(worksheet, 1, 20, A_min, NULL);
    worksheet_write_number(worksheet, 2, 20, B_min, NULL);
    worksheet_write_number(worksheet, 3, 20, C_min, NULL);

    worksheet_write_number(worksheet, 1, 21, A_sec, format03);
    worksheet_write_number(worksheet, 2, 21, B_sec, format03);
    worksheet_write_number(worksheet, 3, 21, C_sec, format03);

    worksheet_write_number(worksheet, 1, 22, sin(toRadian(A_ispr_2)), format09);
    worksheet_write_number(worksheet, 2, 22, sin(toRadian(B_ispr_2)), format09);
    worksheet_write_number(worksheet, 3, 22, sin(toRadian(C_ispr_2)), format09);

    worksheet_write_number(worksheet, 1, 23, sf_A_2, format03);
    worksheet_write_number(worksheet, 2, 23, sf_B_2, format03);
    worksheet_write_number(worksheet, 3, 23, sf_C_2, format03);



    workbook_close(workbook);

    return 0;
}

long double toRadian(long double a) {
    return a * (M_PI / 180.0);
}

long double toDegree(long double a) {
    return a * (180.0 / M_PI);
}