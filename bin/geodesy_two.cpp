#include <cmath>
#include <iomanip>
#include <xlsxwriter.h>
#include "geo_two_h.h"

//To-Do
//РАЗОБРАТЬСЯ С ФОРМУЛОЙ ДЛЯ ИКС А ИМЕННО УМНОЖЕНИЕ ЧИСЛА НА ГРУДУСНУЮ ВЕЛЕЧИНУ
//ВОЗМОЖНО РАЗБИТЬ ФОРМУЛУ НА 3 СОСТАВНЫЕ ЧАСТИ

int main() {

    double B_2[3] = {57, 36, 0 };
    double L_2[3] = {39,36,0};

    //Приводим градусы к секундам для облегчения расчетов
    /*
    long double B_sec = B[0] * 3600 + B_2[1] * 60 + B[2];
    long double L_sec = L[0] * 3600 + L[1] * 60 + L[2];
    long double B_2_sec = B_2[0] * 3600 + B_2[1] * 60 + B_2[2];
    long double L_2_sec = L_2[0] * 3600 + L_2[1] * 60 + L_2[2];
    */

    //Синусы и косинусы
    double angle_in_degree_2 = B_2[0] + (B_2[1]/60.0);
    double angle_in_rad_2 = angle_in_degree_2 * M_PI/180.0;
    double L_ang_in_deg_2 = L_2[0] + (L_2[1]/60.0);
    double L_ang_in_rad_2 = L_ang_in_deg_2 * M_PI/180.0;
    long double sin_b_2 = sin(angle_in_rad_2);
    long double cos_b_2 = cos(angle_in_rad_2);
    long double sin_l_2 = sin(L_ang_in_rad_2);
    long double cos_l_2 = cos(L_ang_in_rad_2);


    //Коэффиценты m
    long double m_0_jgd2000 = jgd2000.semi_major_axis*(1 - e_1_jgd2000);
    long double m_2_jgd2000 = (3.0/2.0)*e_1_jgd2000*m_0_jgd2000;
    long double m_4_jgd2000 = (5.0/4.0)*e_1_jgd2000*m_2_jgd2000;
    long double m_6_jgd2000 = (7.0/6.0)*e_1_jgd2000*m_4_jgd2000;
    long double m_0_krosvskogo = krosvskogo.semi_major_axis*(1 - e_1_krosvskogo);
    long double m_2_krosvskogo = (3.0/2.0)*e_1_krosvskogo*m_0_krosvskogo;
    long double m_4_krosvskogo = (5.0/4.0)*e_1_krosvskogo*m_2_krosvskogo;
    long double m_6_krosvskogo = (7.0/6.0)*e_1_krosvskogo*m_4_krosvskogo;
    long double m_0_wgs84 = wgs84.semi_major_axis*(1 - e_1_wgs84);
    long double m_2_wgs84 = (3.0/2.0)*e_1_wgs84*m_0_wgs84;
    long double m_4_wgs84 = (5.0/4.0)*e_1_wgs84*m_2_wgs84;
    long double m_6_wgs84 = (7.0/6.0)*e_1_wgs84*m_4_wgs84;
    long double m_0_pz90 = pz90.semi_major_axis*(1 - e_1_pz90);
    long double m_2_pz90 = (3.0/2.0)*e_1_pz90*m_0_pz90;
    long double m_4_pz90 = (5.0/4.0)*e_1_pz90*m_2_pz90;
    long double m_6_pz90 = (7.0/6.0)*e_1_pz90*m_4_pz90;
    long double m_0_gsk2011 = gsk2011.semi_major_axis*(1 - e_1_gsk2011);
    long double m_2_gsk2011 = (3.0/2.0)*e_1_gsk2011*m_0_gsk2011;
    long double m_4_gsk2011 = (5.0/4.0)*e_1_gsk2011*m_2_gsk2011;
    long double m_6_gsk2011 = (7.0/6.0)*e_1_gsk2011*m_4_gsk2011;

    //Коэффициенты a
    long double a_0_jgd2000 = m_0_jgd2000 + (m_2_jgd2000/2) + (3.0/8.0)*m_4_jgd2000;
    long double a_2_jgd2000 = (m_2_jgd2000/2.0) + (m_4_jgd2000/2.0) + (15.0/32.0)*m_6_jgd2000;
    long double a_4_jgd2000 = (m_4_jgd2000/8.0) + (3.0/16.0)*m_6_jgd2000;
    long double a_6_jgd2000 = (m_6_jgd2000/32.0);
    long double a_0_krosvskogo = m_0_krosvskogo + (m_2_krosvskogo/2.0) + (3.0/8.0)*m_4_krosvskogo;
    long double a_2_krosvskogo = (m_2_krosvskogo/2.0) + (m_4_krosvskogo/2.0) + (15.0/32.0)*m_6_krosvskogo;
    long double a_4_krosvskogo = (m_4_krosvskogo/8.0) + (3.0/16.0)*m_6_krosvskogo;
    long double a_6_krosvskogo = (m_6_krosvskogo/32.0);
    long double a_0_gsk2011 = m_0_gsk2011 + (m_2_gsk2011 / 2.0) + (3.0 / 8.0) * m_4_gsk2011;
    long double a_2_gsk2011 = (m_2_gsk2011 / 2.0) + (m_4_gsk2011 / 2.0) + (15.0 / 32.0) * m_6_gsk2011;
    long double a_4_gsk2011 = (m_4_gsk2011 / 8.0) + (3.0 / 16.0) * m_6_gsk2011;
    long double a_6_gsk2011 = (m_6_gsk2011 / 32.0);
    long double a_0_pz90 = m_0_pz90 + (m_2_pz90 / 2.0) + (3.0 / 8.0) * m_4_pz90;
    long double a_2_pz90 = (m_2_pz90 / 2.0) + (m_4_pz90 / 2.0) + (15.0 / 32.0) * m_6_pz90;
    long double a_4_pz90 = (m_4_pz90 / 8.0) + (3.0 / 16.0) * m_6_pz90;
    long double a_6_pz90 = (m_6_pz90 / 32.0);
    long double a_0_wgs84 = m_0_wgs84 + (m_2_wgs84 / 2.0) + (3.0 / 8.0) * m_4_wgs84;
    long double a_2_wgs84 = (m_2_wgs84 / 2.0) + (m_4_wgs84 / 2.0) + (15.0 / 32.0) * m_6_wgs84;
    long double a_4_wgs84 = (m_4_wgs84 / 8.0) + (3.0 / 16.0) * m_6_wgs84;
    long double a_6_wgs84 = (m_6_wgs84 / 32.0);

    //X 1.1

    long double X_1_jgd2000 = a_0_jgd2000 * angle_in_rad 
        - (a_2_jgd2000 / 2) * sin(2 * angle_in_rad) 
        + (a_4_jgd2000 / 4) * sin(4 * angle_in_rad) 
        - (a_6_jgd2000 / 6) * sin(6 * angle_in_rad);

    long double X_2_jgd2000 = a_0_jgd2000 * angle_in_rad_2 
        - (a_2_jgd2000 / 2) * sin(2 * angle_in_rad_2) 
        + (a_4_jgd2000 / 4) * sin(4 * angle_in_rad_2) 
        - (a_6_jgd2000 / 6) * sin(6 * angle_in_rad_2);

    long double X_1_krosvskogo = a_0_krosvskogo * angle_in_rad 
        - (a_2_krosvskogo / 2) * sin(2 * angle_in_rad) 
        + (a_4_krosvskogo / 4) * sin(4 * angle_in_rad) 
        - (a_6_krosvskogo / 6) * sin(6 * angle_in_rad);

    long double X_2_krosvskogo = a_0_krosvskogo * angle_in_rad_2 
        - (a_2_krosvskogo / 2) * sin(2 * angle_in_rad_2) 
        + (a_4_krosvskogo / 4) * sin(4 * angle_in_rad_2) 
        - (a_6_krosvskogo / 6) * sin(6 * angle_in_rad_2);

    long double X_1_pz90 = a_0_pz90 * angle_in_rad 
        - (a_2_pz90 / 2) * sin(2 * angle_in_rad) 
        + (a_4_pz90 / 4) * sin(4 * angle_in_rad) 
        - (a_6_pz90 / 6) * sin(6 * angle_in_rad);

    long double X_2_pz90 = a_0_pz90 * angle_in_rad_2 
        - (a_2_pz90 / 2) * sin(2 * angle_in_rad_2) 
        + (a_4_pz90 / 4) * sin(4 * angle_in_rad_2) 
        - (a_6_pz90 / 6) * sin(6 * angle_in_rad_2);

    long double X_1_wgs84 = a_0_wgs84 * angle_in_rad 
        - (a_2_wgs84 / 2) * sin(2 * angle_in_rad) 
        + (a_4_wgs84 / 4) * sin(4 * angle_in_rad) 
        - (a_6_wgs84 / 6) * sin(6 * angle_in_rad);

    long double X_2_wgs84 = a_0_wgs84 * angle_in_rad_2 
        - (a_2_wgs84 / 2) * sin(2 * angle_in_rad_2) 
        + (a_4_wgs84 / 4) * sin(4 * angle_in_rad_2) 
        - (a_6_wgs84 / 6) * sin(6 * angle_in_rad_2);

    long double X_1_gsk2011 = a_0_gsk2011 * angle_in_rad 
        - (a_2_gsk2011 / 2) * sin(2 * angle_in_rad) 
        + (a_4_gsk2011 / 4) * sin(4 * angle_in_rad) 
        - (a_6_gsk2011 / 6) * sin(6 * angle_in_rad);

    long double X_2_gsk2011 = a_0_gsk2011 * angle_in_rad_2 
        - (a_2_gsk2011 / 2) * sin(2 * angle_in_rad_2) 
        + (a_4_gsk2011 / 4) * sin(4 * angle_in_rad_2) 
        - (a_6_gsk2011 / 6) * sin(6 * angle_in_rad_2);




    //long double X_1_jgd2000 = a_0_jgd2000*angle_in_rad- (a_2_jgd2000/2)*sin_b*2 + (a_4_jgd2000/4)*sin_b*4 - (a_6_jgd2000/6)*sin_b*6;
    //long double X_2_jgd2000 = a_0_jgd2000*angle_in_rad_2- (a_2_jgd2000/2)*sin_b_2*2 + (a_4_jgd2000/4)*sin_b_2*4 - (a_6_jgd2000/6)*sin_b_2*6;
    long double delta_X_jgd2000 = X_2_jgd2000 - X_1_jgd2000;
    //long double X_1_krosvskogo = a_0_krosvskogo*angle_in_rad - (a_2_krosvskogo/2)*sin_b*2 + (a_4_krosvskogo/4)*sin_b*4 - (a_6_krosvskogo/6)*sin_b*6;
    //long double X_2_krosvskogo = a_0_krosvskogo*angle_in_rad_2- (a_2_krosvskogo/2)*sin_b_2*2 + (a_4_krosvskogo/4)*sin_b_2*4 - (a_6_krosvskogo/6)*sin_b_2*6;
    long double delta_X_krosvskogo = X_2_krosvskogo - X_1_krosvskogo;
    long double delta_X_gsk2011 = X_2_gsk2011 - X_1_gsk2011;
    long double delta_X_pz90 = X_2_pz90 - X_1_pz90;
    long double delta_X_wgs84 = X_2_wgs84 - X_1_wgs84;



    cout << fixed << setprecision(4) << delta_X_jgd2000 << endl;
    cout << fixed << setprecision(4) << delta_X_krosvskogo << endl;
    cout << fixed << setprecision(4) << delta_X_gsk2011 << endl;
    cout << fixed << setprecision(4) << delta_X_pz90 << endl;
    cout << fixed << setprecision(4) << delta_X_wgs84 << endl;

    //1.2

    //Коэф v для вычисления радиуса кривизны
    long double v_krosvskogo_2 = 1 + e_2_krosvskogo*pow(cos_b_2,2);
    long double v_wgs84_2 = 1 + e_2_wgs84*pow(cos_b_2,2);
    long double v_pz90_2 = 1 + e_2_pz90*pow(cos_b_2,2);
    long double v_gsk2011_2 = 1 + e_2_gsk2011*pow(cos_b_2,2);
    long double v_jgd2000_2 = 1 + e_2_jgd2000*pow(cos_b_2,2);

    //TO--DO добавить значение M2 и выяснить как вычилить Mср



    // krosvskogo wgs84 pz90 gsk2011 jgd2000






/*
    lxw_workbook *workbook = workbook_new("out.xlsx");
    lxw_worksheet *worksheet = workbook_add_worksheet(workbook, NULL);
    //lxw_format *format = workbook.add_format({'num_format': '#,##0.00'};
    lxw_format *format = workbook_add_format(workbook);
    format_set_num_format(format, "0.0000000000");

    worksheet_write_string(worksheet,0,0,"Hello",format);
    worksheet_write_number(worksheet,0,1,v_krosvskogo,format);

    workbook_close(workbook);
*/
    return 0;
}
