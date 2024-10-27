#include <cmath>
#include <iomanip>
#include <xlsxwriter.h>
#include "geo_three_h.h"

int main() {
    long double B_1[3] = {50, 36, 0};
    long double B_2[3] = {50, 46, 0};

    long double angle_in_degree = B_1[0] + (B_1[1]/60.0);
    long double angle_in_degree_2 = B_2[0] + (B_2[1]/60.0);
    long double angle_in_rad = angle_in_degree * M_PI/180.0;
    long double angle_in_rad_2 = angle_in_degree_2 * M_PI/180.0;

    long double sin_b_1 = sin(angle_in_rad);
    long double sin_b_2 = sin(angle_in_rad_2);

    long double cos_b = cos(angle_in_rad);
    long double cos_b_2 = cos(angle_in_rad_2);

    long double delta_L = 15.0/60.0 * M_PI/180.0;

    long double X_1_jgd2000 = (a_0_jgd2000  * angle_in_rad
    - (a_2_jgd2000 / (2.0* 500)) * sin(2 * angle_in_rad)
    + (a_4_jgd2000 / (4.0* 500)) * sin(4 * angle_in_rad)
    - (a_6_jgd2000 / (6.0 * 500)) * sin(6 * angle_in_rad)) / 500.0;

    long double X_2_jgd2000 = (a_0_jgd2000 * angle_in_rad_2
    - (a_2_jgd2000 / (2.0* 500)) * sin(2 * angle_in_rad_2)
    + (a_4_jgd2000 / (4.0* 500)) * sin(4 * angle_in_rad_2)
    - (a_6_jgd2000 / (6.0* 500)) * sin(6 * angle_in_rad_2)) / 500.0;


long double X_1_krosvskogo = (a_0_krosvskogo * angle_in_rad 
    - (a_2_krosvskogo / (2.0 * 500)) * sin(2 * angle_in_rad) 
    + (a_4_krosvskogo / (4.0 * 500)) * sin(4 * angle_in_rad) 
    - (a_6_krosvskogo / (6.0 * 500)) * sin(6 * angle_in_rad)) / 500.0;

long double X_2_krosvskogo = (a_0_krosvskogo * angle_in_rad_2 
    - (a_2_krosvskogo / (2.0 * 500)) * sin(2 * angle_in_rad_2) 
    + (a_4_krosvskogo / (4.0 * 500)) * sin(4 * angle_in_rad_2) 
    - (a_6_krosvskogo / (6.0 * 500)) * sin(6 * angle_in_rad_2)) / 500.0;

long double X_1_pz90 = (a_0_pz90 * angle_in_rad 
    - (a_2_pz90 / (2.0 * 500)) * sin(2 * angle_in_rad) 
    + (a_4_pz90 / (4.0 * 500)) * sin(4 * angle_in_rad) 
    - (a_6_pz90 / (6.0 * 500)) * sin(6 * angle_in_rad)) / 500.0;

long double X_2_pz90 = (a_0_pz90 * angle_in_rad_2 
    - (a_2_pz90 / (2.0 * 500)) * sin(2 * angle_in_rad_2) 
    + (a_4_pz90 / (4.0 * 500)) * sin(4 * angle_in_rad_2) 
    - (a_6_pz90 / (6.0 * 500)) * sin(6 * angle_in_rad_2)) / 500.0;

long double X_1_wgs84 = (a_0_wgs84 * angle_in_rad 
    - (a_2_wgs84 / (2.0 * 500)) * sin(2 * angle_in_rad) 
    + (a_4_wgs84 / (4.0 * 500)) * sin(4 * angle_in_rad) 
    - (a_6_wgs84 / (6.0 * 500)) * sin(6 * angle_in_rad)) / 500.0;

long double X_2_wgs84 = (a_0_wgs84 * angle_in_rad_2 
    - (a_2_wgs84 / (2.0 * 500)) * sin(2 * angle_in_rad_2) 
    + (a_4_wgs84 / (4.0 * 500)) * sin(4 * angle_in_rad_2) 
    - (a_6_wgs84 / (6.0 * 500)) * sin(6 * angle_in_rad_2)) / 500.0;

long double X_1_gsk2011 = (a_0_gsk2011 * angle_in_rad 
    - (a_2_gsk2011 / (2.0 * 500)) * sin(2 * angle_in_rad) 
    + (a_4_gsk2011 / (4.0 * 500)) * sin(4 * angle_in_rad) 
    - (a_6_gsk2011 / (6.0 * 500)) * sin(6 * angle_in_rad)) / 500.0;

long double X_2_gsk2011 = (a_0_gsk2011 * angle_in_rad_2 
    - (a_2_gsk2011 / (2.0 * 500)) * sin(2 * angle_in_rad_2) 
    + (a_4_gsk2011 / (4.0 * 500)) * sin(4 * angle_in_rad_2) 
    - (a_6_gsk2011 / (6.0 * 500)) * sin(6 * angle_in_rad_2)) / 500.0;



    long double C_jgd2000 = X_2_jgd2000 - X_1_jgd2000;
    long double C_krosvskogo = X_2_krosvskogo - X_1_krosvskogo;
    long double C_gsk2011 = X_2_gsk2011 - X_1_gsk2011;
    long double C_pz90 = X_2_pz90 - X_1_pz90;
    long double C_wgs84 = X_2_wgs84 - X_1_wgs84;

    //Вычисляем значение N
        long double v_krosvskogo_1 = 1 + e_2_krosvskogo * pow(cos_b, 2);
    long double v_wgs84_1 = 1 + e_2_wgs84 * pow(cos_b, 2);
    long double v_pz90_1 = 1 + e_2_pz90 * pow(cos_b, 2);
    long double v_gsk2011_1 = 1 + e_2_gsk2011 * pow(cos_b, 2);
    long double v_jgd2000_1 = 1 + e_2_jgd2000 * pow(cos_b, 2);
        long double v_krosvskogo_2 = 1 + e_2_krosvskogo*pow(cos_b_2,2);
    long double v_wgs84_2 = 1 + e_2_wgs84*pow(cos_b_2,2);
    long double v_pz90_2 = 1 + e_2_pz90*pow(cos_b_2,2);
    long double v_gsk2011_2 = 1 + e_2_gsk2011*pow(cos_b_2,2);
    long double v_jgd2000_2 = 1 + e_2_jgd2000*pow(cos_b_2,2);

        long double N_krosvskogo = c_krosvskogo/sqrt(v_krosvskogo_1);
    long double N_wgs84 = c_wgs84/sqrt(v_wgs84_1);
    long double N_pz90 = c_pz90/sqrt(v_pz90_1);
    long double N_gsk2011 = c_gsk2011/sqrt(v_gsk2011_1);
    long double N_jgd2000 = c_jgd2000/sqrt(v_jgd2000_1);
        long double N_krosvskogo_2 = c_krosvskogo / sqrt(v_krosvskogo_2);
    long double N_wgs84_2 = c_wgs84 / sqrt(v_wgs84_2);
    long double N_pz90_2 = c_pz90 / sqrt(v_pz90_2);
    long double N_gsk2011_2 = c_gsk2011 / sqrt(v_gsk2011_2);
    long double N_jgd2000_2 = c_jgd2000 / sqrt(v_jgd2000_2);



    long double alfa_1_krosvskogo = (N_krosvskogo* cos_b * delta_L) / 500;
    long double alfa_2_krosvskogo = (N_krosvskogo_2 * cos_b_2 * delta_L) / 500;
    long double alfa_1_wgs84 = (N_wgs84 * cos_b * delta_L) / 500;
    long double alfa_2_wgs84 = (N_wgs84_2 * cos_b_2 * delta_L) / 500;
    long double alfa_1_pz90 = (N_pz90 * cos_b * delta_L) / 500;
    long double alfa_2_pz90 = (N_pz90_2 * cos_b_2 * delta_L) / 500;
    long double alfa_1_gsk2011 = (N_gsk2011 * cos_b * delta_L) / 500;
    long double alfa_2_gsk2011 = (N_gsk2011_2 * cos_b_2 * delta_L) / 500;
    long double alfa_1_jgd2000 = (N_jgd2000 * cos_b * delta_L) / 500;
    long double alfa_2_jgd2000 = (N_jgd2000_2 * cos_b_2 * delta_L) / 500;

    long double d_squared_krosvskogo = sqrt(alfa_1_krosvskogo * alfa_2_krosvskogo + pow(C_krosvskogo,2));
    long double d_squared_wgs84 = sqrt(alfa_1_wgs84 * alfa_2_wgs84 + pow(C_wgs84,2));
    long double d_squared_pz90 = sqrt(alfa_1_pz90 * alfa_2_pz90 + pow(C_pz90,2));
    long double d_squared_gsk2011 = sqrt(alfa_1_gsk2011 * alfa_2_gsk2011 + pow(C_gsk2011,2));
    long double d_squared_jgd2000 = sqrt(alfa_1_jgd2000 * alfa_2_jgd2000 + pow(C_jgd2000,2));
/*
    long double I_ = (2.0/3.0) * e_1_ * (pow(sin_b_2, 3) - pow(sin_b_1,3));
    long double II_ = (3.0/5.0) * pow(e_1_,2) * (pow(sin_b_2, 5) - pow(sin_b_1,5));
    long double III_ = (4.0/7.0) * (pow(e_1_,2)*e_1_) * (pow(sin_b_2, 7) - pow(sin_b_1,7));
*/
    long double I_wgs84 = (2.0 / 3.0) * pow(sqrt(e_1_wgs84),2) * (pow(sin_b_2, 3) - pow(sin_b_1, 3));
    long double II_wgs84 = (3.0 / 5.0) * pow(sqrt(e_1_wgs84),4) * (pow(sin_b_2, 5) - pow(sin_b_1, 5));
    long double III_wgs84 = (4.0 / 7.0) * pow(sqrt(e_1_wgs84),6) * (pow(sin_b_2, 7) - pow(sin_b_1, 7));
    long double I_krosvskogo = (2.0 / 3.0) * pow(sqrt(e_1_krosvskogo), 2) * (pow(sin_b_2, 3) - pow(sin_b_1, 3));
    long double II_krosvskogo = (3.0 / 5.0) * pow(sqrt(e_1_krosvskogo), 4) * (pow(sin_b_2, 5) - pow(sin_b_1, 5));
    long double III_krosvskogo = (4.0 / 7.0) * pow(sqrt(e_1_krosvskogo), 6) * (pow(sin_b_2, 7) - pow(sin_b_1, 7));
    long double I_pz90 = (2.0 / 3.0) * pow(sqrt(e_1_pz90), 2) * (pow(sin_b_2, 3) - pow(sin_b_1, 3));
    long double II_pz90 = (3.0 / 5.0) * pow(sqrt(e_1_pz90), 4) * (pow(sin_b_2, 5) - pow(sin_b_1, 5));
    long double III_pz90 = (4.0 / 7.0) * pow(sqrt(e_1_pz90), 6) * (pow(sin_b_2, 7) - pow(sin_b_1, 7));
    long double I_jgd2000 = (2.0 / 3.0) * pow(sqrt(e_1_jgd2000), 2) * (pow(sin_b_2, 3) - pow(sin_b_1, 3));
    long double II_jgd2000 = (3.0 / 5.0) * pow(sqrt(e_1_jgd2000), 4) * (pow(sin_b_2, 5) - pow(sin_b_1, 5));
    long double III_jgd2000 = (4.0 / 7.0) * pow(sqrt(e_1_jgd2000), 6) * (pow(sin_b_2, 7) - pow(sin_b_1, 7));
    long double I_gsk2011 = (2.0 / 3.0) * pow(sqrt(e_1_gsk2011), 2) * (pow(sin_b_2, 3) - pow(sin_b_1, 3));
    long double II_gsk2011 = (3.0 / 5.0) * pow(sqrt(e_1_gsk2011), 4) * (pow(sin_b_2, 5) - pow(sin_b_1, 5));
    long double III_gsk2011 = (4.0 / 7.0) * pow(sqrt(e_1_gsk2011), 6) * (pow(sin_b_2, 7) - pow(sin_b_1, 7));


    long double P_krosvskogo = pow(b_krosvskogo,2) * delta_L * (sin_b_2 - sin_b_1 + I_krosvskogo + II_krosvskogo + III_krosvskogo)/ 1000000.0;
    long double P_wgs84 = (pow(b_wgs84, 2) * delta_L * (sin_b_2 - sin_b_1 + I_wgs84 + II_wgs84 + III_wgs84)) / 1000000.0;
    long double P_pz90 = pow(b_pz90, 2) * delta_L * (sin_b_2 - sin_b_1 + I_pz90 + II_pz90 + III_pz90)/ 1000000.0;
    long double P_jgd2000 = pow(b_jgd2000, 2) * delta_L * (sin_b_2 - sin_b_1 + I_jgd2000 + II_jgd2000 + III_jgd2000)/ 1000000.0;
    long double P_gsk2011 = pow(b_gsk2011, 2) * delta_L * (sin_b_2 - sin_b_1 + I_gsk2011 + II_gsk2011 + III_gsk2011)/ 1000000.0;

    //          ЗАПИСЬ ДАННЫХ

    lxw_workbook *workbook = workbook_new("out.xlsx");
    lxw_worksheet *worksheet = workbook_add_worksheet(workbook, NULL);
    lxw_format *format05 = workbook_add_format(workbook);
    lxw_format *format04 = workbook_add_format(workbook);
    lxw_format *format02 = workbook_add_format(workbook);
    lxw_format *format03 = workbook_add_format(workbook);

    format_set_num_format(format05, "0.00000");
    format_set_num_format(format04, "0.0000");
    format_set_num_format(format03, "0.000");
    format_set_num_format(format02, "0.00");

    worksheet_write_string(worksheet,0,1,"Красовского",NULL);
    worksheet_write_string(worksheet,0,2,"JGD2000",NULL);
    worksheet_write_string(worksheet,0,3,"GSK2011",NULL);
    worksheet_write_string(worksheet,0,4,"PZ90",NULL);
    worksheet_write_string(worksheet,0,5,"WGS84",NULL);

        worksheet_write_string(worksheet,1,0,"a0",NULL);
    worksheet_write_string(worksheet,2,0,"a2",NULL);
    worksheet_write_string(worksheet,3,0,"a4",NULL);
    worksheet_write_string(worksheet,4,0,"a6",NULL);
        worksheet_write_string(worksheet,5,0,"m0",NULL);
    worksheet_write_string(worksheet,6,0,"m2",NULL);
    worksheet_write_string(worksheet,7,0,"m4",NULL);
    worksheet_write_string(worksheet,8,0,"m6",NULL);


        worksheet_write_number(worksheet,1,1,a_0_krosvskogo,format05);
    worksheet_write_number(worksheet,1,2,a_0_jgd2000,format05);
    worksheet_write_number(worksheet,1,3,a_0_gsk2011,format05);
    worksheet_write_number(worksheet,1,4,a_0_pz90,format05);
    worksheet_write_number(worksheet,1,5,a_0_wgs84,format05);
        worksheet_write_number(worksheet,2,1,a_2_krosvskogo,format05);
    worksheet_write_number(worksheet,2,2,a_2_jgd2000,format05);
    worksheet_write_number(worksheet,2,3,a_2_gsk2011,format05);
    worksheet_write_number(worksheet,2,4,a_2_pz90,format05);
    worksheet_write_number(worksheet,2,5,a_2_wgs84,format05);
            worksheet_write_number(worksheet,3,1,a_4_krosvskogo,format05);
    worksheet_write_number(worksheet,3,2,a_4_jgd2000,format05);
    worksheet_write_number(worksheet,3,3,a_4_gsk2011,format05);
    worksheet_write_number(worksheet,3,4,a_4_pz90,format05);
    worksheet_write_number(worksheet,3,5,a_4_wgs84,format05);
            worksheet_write_number(worksheet,4,1,a_6_krosvskogo,format05);
    worksheet_write_number(worksheet,4,2,a_6_jgd2000,format05);
    worksheet_write_number(worksheet,4,3,a_6_gsk2011,format05);
    worksheet_write_number(worksheet,4,4,a_6_pz90,format05);
    worksheet_write_number(worksheet,4,5,a_6_wgs84,format05);
        worksheet_write_number(worksheet,5,1,m_0_krosvskogo,format05);
    worksheet_write_number(worksheet,5,2,m_0_jgd2000,format05);
    worksheet_write_number(worksheet,5,3,m_0_gsk2011,format05);
    worksheet_write_number(worksheet,5,4,m_0_pz90,format05);
    worksheet_write_number(worksheet,5,5,m_0_wgs84,format05);
        worksheet_write_number(worksheet,6,1,m_2_krosvskogo,format05);
    worksheet_write_number(worksheet,6,2,m_2_jgd2000,format05);
    worksheet_write_number(worksheet,6,3,m_2_gsk2011,format05);
    worksheet_write_number(worksheet,6,4,m_2_pz90,format05);
    worksheet_write_number(worksheet,6,5,m_2_wgs84,format05);
            worksheet_write_number(worksheet,7,1,m_4_krosvskogo,format05);
    worksheet_write_number(worksheet,7,2,m_4_jgd2000,format05);
    worksheet_write_number(worksheet,7,3,m_4_gsk2011,format05);
    worksheet_write_number(worksheet,7,4,m_4_pz90,format05);
    worksheet_write_number(worksheet,7,5,m_4_wgs84,format05);
            worksheet_write_number(worksheet,8,1,m_6_krosvskogo,format05);
    worksheet_write_number(worksheet,8,2,m_6_jgd2000,format05);
    worksheet_write_number(worksheet,8,3,m_6_gsk2011,format05);
    worksheet_write_number(worksheet,8,4,m_6_pz90,format05);
    worksheet_write_number(worksheet,8,5,m_6_wgs84,format05);

    worksheet_write_string(worksheet,0,8,"Красовского",NULL);
    worksheet_write_string(worksheet,0,9,"JGD2000",NULL);
    worksheet_write_string(worksheet,0,10,"GSK2011",NULL);
    worksheet_write_string(worksheet,0,11,"PZ90",NULL);
    worksheet_write_string(worksheet,0,12,"WGS84",NULL);

    worksheet_write_string(worksheet,1,7,"X1",NULL);
    worksheet_write_string(worksheet,2,7,"X2",NULL);
    worksheet_write_string(worksheet,3,7,"c",NULL);

        worksheet_write_number(worksheet,1,8,X_1_krosvskogo,format05);
    worksheet_write_number(worksheet,1,9,X_1_jgd2000,format05);
    worksheet_write_number(worksheet,1,10,X_1_gsk2011,format05);
    worksheet_write_number(worksheet,1,11,X_1_pz90,format05);
    worksheet_write_number(worksheet,1,12,X_1_wgs84,format05);
        worksheet_write_number(worksheet,2,8,X_2_krosvskogo,format05);
    worksheet_write_number(worksheet,2,9,X_2_jgd2000,format05);
    worksheet_write_number(worksheet,2,10,X_2_gsk2011,format05);
    worksheet_write_number(worksheet,2,11,X_2_pz90,format05);
    worksheet_write_number(worksheet,2,12,X_2_wgs84,format05);
            worksheet_write_number(worksheet,3,8,C_krosvskogo,format03);
    worksheet_write_number(worksheet,3,9,C_jgd2000,format03);
    worksheet_write_number(worksheet,3,10,C_gsk2011,format03);
    worksheet_write_number(worksheet,3,11,C_pz90,format03);
    worksheet_write_number(worksheet,3,12,C_wgs84,format03);

    worksheet_write_string(worksheet,0,15,"Красовского",NULL);
    worksheet_write_string(worksheet,0,16,"JGD2000",NULL);
    worksheet_write_string(worksheet,0,17,"GSK2011",NULL);
    worksheet_write_string(worksheet,0,18,"PZ90",NULL);
    worksheet_write_string(worksheet,0,19,"WGS84",NULL);

    worksheet_write_string(worksheet,1,14,"a1",NULL);
    worksheet_write_string(worksheet,2,14,"a2",NULL);

        worksheet_write_number(worksheet,1,15,alfa_1_krosvskogo,format04);
    worksheet_write_number(worksheet,1,16,alfa_1_jgd2000,format04);
    worksheet_write_number(worksheet,1,17,alfa_1_gsk2011,format04);
    worksheet_write_number(worksheet,1,18,alfa_1_pz90,format04);
    worksheet_write_number(worksheet,1,19,alfa_2_wgs84,format04);
        worksheet_write_number(worksheet,2,15,alfa_2_krosvskogo,format04);
    worksheet_write_number(worksheet,2,16,alfa_2_jgd2000,format04);
    worksheet_write_number(worksheet,2,17,alfa_2_gsk2011,format04);
    worksheet_write_number(worksheet,2,18,alfa_2_pz90,format04);
    worksheet_write_number(worksheet,2,19,alfa_2_wgs84,format04);

    worksheet_write_string(worksheet, 0, 22, "Красовского", NULL);
    worksheet_write_string(worksheet, 0, 23, "JGD2000", NULL);
    worksheet_write_string(worksheet, 0, 24, "GSK2011", NULL);
    worksheet_write_string(worksheet, 0, 25, "PZ90", NULL);
    worksheet_write_string(worksheet, 0, 26, "WGS84", NULL);

    worksheet_write_string(worksheet, 1, 21, "d", NULL);

    worksheet_write_number(worksheet, 1, 22, d_squared_krosvskogo, format04);
    worksheet_write_number(worksheet, 1, 23, d_squared_jgd2000, format04);
    worksheet_write_number(worksheet, 1, 24, d_squared_gsk2011, format04);
    worksheet_write_number(worksheet, 1, 25, d_squared_pz90, format04);
    worksheet_write_number(worksheet, 1, 26, d_squared_wgs84, format04);

    ////
// Запись заголовков I, II, III, P для Krosvskogo, WGS84, PZ90, GSK2011, JGD2000 в строку 0
    worksheet_write_string(worksheet, 0, 29, "Красовского", NULL);
    worksheet_write_string(worksheet, 0, 30, "JGD2000", NULL);
    worksheet_write_string(worksheet, 0, 31, "GSK2011", NULL);
    worksheet_write_string(worksheet, 0, 32, "PZ90", NULL);
    worksheet_write_string(worksheet, 0, 33, "WGS84", NULL);

    worksheet_write_string(worksheet, 1, 28, "I", NULL);
    worksheet_write_string(worksheet, 2, 28, "II", NULL);
    worksheet_write_string(worksheet, 3, 28, "III", NULL);
    worksheet_write_string(worksheet, 4, 28, "P", NULL);

// Запись значений в строку 1, начиная с колонки 32
// Запись значений для Krosovskogo (начиная с колонки 29)
worksheet_write_number(worksheet, 1, 29, I_krosvskogo, NULL);
worksheet_write_number(worksheet, 2, 29, II_krosvskogo, NULL);
worksheet_write_number(worksheet, 3, 29, III_krosvskogo, NULL);
worksheet_write_number(worksheet, 4, 29, P_krosvskogo, format02);

// Запись значений для WGS84 (колонка 30)
worksheet_write_number(worksheet, 1, 30, I_wgs84, NULL);
worksheet_write_number(worksheet, 2, 30, II_wgs84, NULL);
worksheet_write_number(worksheet, 3, 30, III_wgs84, NULL);
worksheet_write_number(worksheet, 4, 30, P_wgs84, format02);

// Запись значений для PZ90 (колонка 31)
worksheet_write_number(worksheet, 1, 31, I_pz90, NULL);
worksheet_write_number(worksheet, 2, 31, II_pz90, NULL);
worksheet_write_number(worksheet, 3, 31, III_pz90, NULL);
worksheet_write_number(worksheet, 4, 31, P_pz90, format02);

// Запись значений для GSK2011 (колонка 32)
worksheet_write_number(worksheet, 1, 32, I_gsk2011, NULL);
worksheet_write_number(worksheet, 2, 32, II_gsk2011, NULL);
worksheet_write_number(worksheet, 3, 32, III_gsk2011, NULL);
worksheet_write_number(worksheet, 4, 32, P_gsk2011, format02);

// Запись значений для JGD2000 (колонка 33)
worksheet_write_number(worksheet, 1, 33, I_jgd2000, NULL);
worksheet_write_number(worksheet, 2, 33, II_jgd2000, NULL);
worksheet_write_number(worksheet, 3, 33, III_jgd2000, NULL);
worksheet_write_number(worksheet, 4, 33, P_jgd2000, format02);







    workbook_close(workbook);

    return 0;
}