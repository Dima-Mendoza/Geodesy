#include <cmath>
#include <iomanip>
#include <xlsxwriter.h>
#include "geo_two_h.h"

int main() {

    double B_2[3] = {57, 36, 0 };
    double L_2[3] = {39,36,0};

    //Синусы и косинусы
    double angle_in_degree_2 = B_2[0] + (B_2[1]/60.0);
    double angle_in_rad_2 = angle_in_degree_2 * M_PI/180.0;
    double L_ang_in_deg_2 = L_2[0] + (L_2[1]/60.0);
    double L_ang_in_rad_2 = L_ang_in_deg_2 * M_PI/180.0;
    long double sin_b_2 = sin(angle_in_rad_2);
    long double cos_b_2 = cos(angle_in_rad_2);
    long double sin_l_2 = sin(L_ang_in_rad_2);
    long double cos_l_2 = cos(L_ang_in_rad_2);
    long double angle_in_rad_avg = (angle_in_rad + angle_in_rad_2) / 2.0;
    long double cos_b_avg = cos(angle_in_rad_avg);
    long double delta_B = angle_in_rad_2 - angle_in_rad;
    long double delta_L = 2.0 * M_PI/180.0;


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

    long double delta_X_jgd2000 = X_2_jgd2000 - X_1_jgd2000;
    long double delta_X_krosvskogo = X_2_krosvskogo - X_1_krosvskogo;
    long double delta_X_gsk2011 = X_2_gsk2011 - X_1_gsk2011;
    long double delta_X_pz90 = X_2_pz90 - X_1_pz90;
    long double delta_X_wgs84 = X_2_wgs84 - X_1_wgs84;


    //1.2

    //Коэф v для вычисления радиуса кривизны
    long double v_krosvskogo_2 = 1 + e_2_krosvskogo*pow(cos_b_2,2);
    long double v_wgs84_2 = 1 + e_2_wgs84*pow(cos_b_2,2);
    long double v_pz90_2 = 1 + e_2_pz90*pow(cos_b_2,2);
    long double v_gsk2011_2 = 1 + e_2_gsk2011*pow(cos_b_2,2);
    long double v_jgd2000_2 = 1 + e_2_jgd2000*pow(cos_b_2,2);
    long double v_krosvskogo_avg = 1 + e_2_krosvskogo*pow(cos_b_avg,2);
    long double v_wgs84_avg = 1 + e_2_wgs84 * pow(cos_b_avg, 2);
    long double v_pz90_avg = 1 + e_2_pz90 * pow(cos_b_avg, 2);
    long double v_gsk2011_avg = 1 + e_2_gsk2011 * pow(cos_b_avg, 2);
    long double v_jgd2000_avg = 1 + e_2_jgd2000 * pow(cos_b_avg, 2);


    //M2
    long double M_2_krosvskogo = c_krosvskogo / pow(sqrt(v_krosvskogo_2),3);
    long double M_2_wgs84 = c_wgs84 / pow(sqrt(v_wgs84_2), 3);
    long double M_2_pz90 = c_pz90 / pow(sqrt(v_pz90_2), 3);
    long double M_2_gsk2011 = c_gsk2011 / pow(sqrt(v_gsk2011_2), 3);
    long double M_2_jgd2000 = c_jgd2000 / pow(sqrt(v_jgd2000_2), 3);

    //Mср
    long double M_avg_krosvskogo = c_krosvskogo / pow(sqrt(v_krosvskogo_avg),3);
    long double M_avg_wgs84 = c_wgs84 / pow(sqrt(v_wgs84_avg), 3);
    long double M_avg_pz90 = c_pz90 / pow(sqrt(v_pz90_avg), 3);
    long double M_avg_gsk2011 = c_gsk2011 / pow(sqrt(v_gsk2011_avg), 3);
    long double M_avg_jgd2000 = c_jgd2000 / pow(sqrt(v_jgd2000_avg), 3);

    long double delta_X_krosvskogo_2 = (delta_B/6.0)* (M_krosvskogo + 4 * M_avg_krosvskogo + M_2_krosvskogo);
    long double delta_X_wgs84_2 = (delta_B / 6.0) * (M_wgs84 + 4 * M_avg_wgs84 + M_2_wgs84);
    long double delta_X_pz90_2 = (delta_B / 6.0) * (M_pz90 + 4 * M_avg_pz90 + M_2_pz90);
    long double delta_X_gsk2011_2 = (delta_B / 6.0) * (M_gsk2011 + 4 * M_avg_gsk2011 + M_2_gsk2011);
    long double delta_X_jgd2000_2 = (delta_B / 6.0) * (M_jgd2000 + 4 * M_avg_jgd2000 + M_2_jgd2000);

    long double N_krosvskogo_2 = c_krosvskogo / sqrt(v_krosvskogo_2);
    long double N_wgs84_2 = c_wgs84 / sqrt(v_wgs84_2);
    long double N_pz90_2 = c_pz90 / sqrt(v_pz90_2);
    long double N_gsk2011_2 = c_gsk2011 / sqrt(v_gsk2011_2);
    long double N_jgd2000_2 = c_jgd2000 / sqrt(v_jgd2000_2);


    long double delta_Y_1_krosvskogo = N_krosvskogo * cos_b * delta_L;
    long double delta_Y_2_krosvskogo = N_krosvskogo_2 * cos_b_2 * delta_L;
    long double delta_Y_1_wgs84 = N_wgs84 * cos_b * delta_L;
    long double delta_Y_2_wgs84 = N_wgs84_2 * cos_b_2 * delta_L;
    long double delta_Y_1_pz90 = N_pz90 * cos_b * delta_L;
    long double delta_Y_2_pz90 = N_pz90_2 * cos_b_2 * delta_L;
    long double delta_Y_1_gsk2011 = N_gsk2011 * cos_b * delta_L;
    long double delta_Y_2_gsk2011 = N_gsk2011_2 * cos_b_2 * delta_L;
    long double delta_Y_1_jgd2000 = N_jgd2000 * cos_b * delta_L;
    long double delta_Y_2_jgd2000 = N_jgd2000_2 * cos_b_2 * delta_L;

    long double sr_M_1_krosvskogo = delta_X_krosvskogo_2 / 2.0 / 1000.0;
    long double sr_M_2_krosvskogo = sr_M_1_krosvskogo / 60.0 * 1000;
    long double sr_M_3_krosvskogo = sr_M_2_krosvskogo / 60.0;

    long double rm_P_1_krosvskogo = delta_Y_1_krosvskogo / 2.0 / 1000.0;
    long double rm_P_2_krosvskogo = rm_P_1_krosvskogo / 60.0 * 1000;
    long double rm_P_3_krosvskogo = delta_Y_1_krosvskogo / 60.0;

    long double sr_M_1_wgs84 = delta_X_wgs84_2 / 2.0 / 1000.0;
    long double sr_M_2_wgs84 = sr_M_1_wgs84 / 60.0 * 1000;
    long double sr_M_3_wgs84 = sr_M_2_wgs84 / 60.0;

    long double rm_P_1_wgs84 = delta_Y_1_wgs84 / 2.0 / 1000.0;
    long double rm_P_2_wgs84 = rm_P_1_wgs84 / 60.0 * 1000;
    long double rm_P_3_wgs84 = delta_Y_1_wgs84 / 60.0;

    long double sr_M_1_pz90 = delta_X_pz90_2 / 2.0 / 1000.0;
    long double sr_M_2_pz90 = sr_M_1_pz90 / 60.0 * 1000;
    long double sr_M_3_pz90 = sr_M_2_pz90 / 60.0;

    long double rm_P_1_pz90 = delta_Y_1_pz90 / 2.0 / 1000.0;
    long double rm_P_2_pz90 = rm_P_1_pz90 / 60.0 * 1000;
    long double rm_P_3_pz90 = delta_Y_1_pz90 / 60.0;

    long double sr_M_1_gsk2011 = delta_X_gsk2011_2 / 2.0 / 1000.0;
    long double sr_M_2_gsk2011 = sr_M_1_gsk2011 / 60.0 * 1000;
    long double sr_M_3_gsk2011 = sr_M_2_gsk2011 / 60.0;

    long double rm_P_1_gsk2011 = delta_Y_1_gsk2011 / 2.0 / 1000.0;
    long double rm_P_2_gsk2011 = rm_P_1_gsk2011 / 60.0 * 1000;
    long double rm_P_3_gsk2011 = delta_Y_1_gsk2011 / 60.0;

    long double sr_M_1_jgd2000 = delta_X_jgd2000_2 / 2.0 / 1000.0;
    long double sr_M_2_jgd2000 = sr_M_1_jgd2000 / 60.0 * 1000;
    long double sr_M_3_jgd2000 = sr_M_2_jgd2000 / 60.0;

    long double rm_P_1_jgd2000 = delta_Y_1_jgd2000 / 2.0 / 1000.0;
    long double rm_P_2_jgd2000 = rm_P_1_jgd2000 / 60.0 * 1000;
    long double rm_P_3_jgd2000 = delta_Y_1_jgd2000 / 60.0;

//      ЗАПИСЬ ДАННЫХ В ЭКСЕЛЬ

    lxw_workbook *workbook = workbook_new("out.xlsx");
    lxw_worksheet *worksheet = workbook_add_worksheet(workbook, NULL);
    lxw_format *format05 = workbook_add_format(workbook);
    lxw_format *format04 = workbook_add_format(workbook);
    lxw_format *format02 = workbook_add_format(workbook);
    lxw_format *format03 = workbook_add_format(workbook);
    lxw_format *format00 = workbook_add_format(workbook);

    format_set_num_format(format05, "0.00000");
    format_set_num_format(format04, "0.0000");
    format_set_num_format(format03, "0.000");
    format_set_num_format(format02, "0.00");
    format_set_num_format(format00, "0");


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
    worksheet_write_string(worksheet,3,7,"deltaX",NULL);

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
            worksheet_write_number(worksheet,3,8,delta_X_krosvskogo,format04);
    worksheet_write_number(worksheet,3,9,delta_X_jgd2000,format04);
    worksheet_write_number(worksheet,3,10,delta_X_gsk2011,format04);
    worksheet_write_number(worksheet,3,11,delta_X_pz90,format04);
    worksheet_write_number(worksheet,3,12,delta_X_wgs84,format04);

    worksheet_write_string(worksheet,0,15,"Красовского",NULL);
    worksheet_write_string(worksheet,0,16,"JGD2000",NULL);
    worksheet_write_string(worksheet,0,17,"GSK2011",NULL);
    worksheet_write_string(worksheet,0,18,"PZ90",NULL);
    worksheet_write_string(worksheet,0,19,"WGS84",NULL);

    worksheet_write_string(worksheet,1,14,"M1",NULL);
    worksheet_write_string(worksheet,2,14,"Mср",NULL);
    worksheet_write_string(worksheet,3,14,"M2",NULL);

        worksheet_write_number(worksheet,1,15,M_krosvskogo,format04);
    worksheet_write_number(worksheet,1,16,M_jgd2000,format04);
    worksheet_write_number(worksheet,1,17,M_gsk2011,format04);
    worksheet_write_number(worksheet,1,18,M_pz90,format04);
    worksheet_write_number(worksheet,1,19,M_wgs84,format04);
        worksheet_write_number(worksheet,2,15,M_avg_krosvskogo,format04);
    worksheet_write_number(worksheet,2,16,M_avg_jgd2000,format04);
    worksheet_write_number(worksheet,2,17,M_avg_gsk2011,format04);
    worksheet_write_number(worksheet,2,18,M_avg_pz90,format04);
    worksheet_write_number(worksheet,2,19,M_avg_wgs84,format04);
            worksheet_write_number(worksheet,3,15,M_2_krosvskogo,format04);
    worksheet_write_number(worksheet,3,16,M_2_jgd2000,format04);
    worksheet_write_number(worksheet,3,17,M_2_gsk2011,format04);
    worksheet_write_number(worksheet,3,18,M_2_pz90,format04);
    worksheet_write_number(worksheet,3,19,M_2_wgs84,format04);

    worksheet_write_string(worksheet,0,22,"Красовского",NULL);
    worksheet_write_string(worksheet,0,23,"JGD2000",NULL);
    worksheet_write_string(worksheet,0,24,"GSK2011",NULL);
    worksheet_write_string(worksheet,0,25,"PZ90",NULL);
    worksheet_write_string(worksheet,0,26,"WGS84",NULL);

    worksheet_write_string(worksheet,1,21,"deltaX",NULL);

    worksheet_write_number(worksheet,1,22,delta_X_krosvskogo_2,format02);
    worksheet_write_number(worksheet,1,23,delta_X_jgd2000_2,format02);
    worksheet_write_number(worksheet,1,24,delta_X_gsk2011_2,format02);
    worksheet_write_number(worksheet,1,25,delta_X_pz90_2,format02);
    worksheet_write_number(worksheet,1,26,delta_X_wgs84_2,format02);

    worksheet_write_string(worksheet,0,29,"Красовского",NULL);
    worksheet_write_string(worksheet,0,30,"JGD2000",NULL);
    worksheet_write_string(worksheet,0,31,"GSK2011",NULL);
    worksheet_write_string(worksheet,0,32,"PZ90",NULL);
    worksheet_write_string(worksheet,0,33,"WGS84",NULL);

    worksheet_write_string(worksheet,1,28,"deltaX",NULL);

    worksheet_write_number(worksheet,1,29,delta_X_krosvskogo_2,format00);
    worksheet_write_number(worksheet,1,30,delta_X_jgd2000_2,format00);
    worksheet_write_number(worksheet,1,31,delta_X_gsk2011_2,format00);
    worksheet_write_number(worksheet,1,32,delta_X_pz90_2,format00);
    worksheet_write_number(worksheet,1,33,delta_X_wgs84_2,format00);

    worksheet_write_string(worksheet,0,36,"Красовского",NULL);
    worksheet_write_string(worksheet,0,37,"JGD2000",NULL);
    worksheet_write_string(worksheet,0,38,"GSK2011",NULL);
    worksheet_write_string(worksheet,0,39,"PZ90",NULL);
    worksheet_write_string(worksheet,0,40,"WGS84",NULL);

    worksheet_write_string(worksheet,1,35,"deltaY1",NULL);
    worksheet_write_string(worksheet,2,35,"deltaY2",NULL);

        worksheet_write_number(worksheet,1,36,delta_Y_1_krosvskogo,format04);
    worksheet_write_number(worksheet,1,37,delta_Y_1_jgd2000,format04);
    worksheet_write_number(worksheet,1,38,delta_Y_1_gsk2011,format04);
    worksheet_write_number(worksheet,1,39,delta_Y_1_pz90,format04);
    worksheet_write_number(worksheet,1,40,delta_Y_1_wgs84,format04);
        worksheet_write_number(worksheet,2,36,delta_Y_2_krosvskogo,format04);
    worksheet_write_number(worksheet,2,37,delta_Y_2_jgd2000,format04);
    worksheet_write_number(worksheet,2,38,delta_Y_2_gsk2011,format04);
    worksheet_write_number(worksheet,2,39,delta_Y_2_pz90,format04);
    worksheet_write_number(worksheet,2,40,delta_Y_2_wgs84,format04);

    worksheet_write_string(worksheet,0,44,"Красовского",NULL);
    worksheet_write_string(worksheet,0,45,"JGD2000",NULL);
    worksheet_write_string(worksheet,0,46,"GSK2011",NULL);
    worksheet_write_string(worksheet,0,47,"PZ90",NULL);
    worksheet_write_string(worksheet,0,48,"WGS84",NULL);

    worksheet_write_string(worksheet,1,42,"МЕРИДИАН",NULL);
    worksheet_write_string(worksheet,4,42,"ПАРАЛЕЛЬ",NULL);

    worksheet_write_string(worksheet,1,43,"1гр, км",NULL);
    worksheet_write_string(worksheet,2,43,"1м, м",NULL);
    worksheet_write_string(worksheet,3,43,"1с, м",NULL);

    worksheet_write_string(worksheet,4,43,"1гр, км",NULL);
    worksheet_write_string(worksheet,5,43,"1м, м",NULL);
    worksheet_write_string(worksheet,6,43,"1с, м",NULL);

        worksheet_write_number(worksheet,1,44,sr_M_1_krosvskogo,format03);
    worksheet_write_number(worksheet,1,45,sr_M_1_jgd2000,format03);
    worksheet_write_number(worksheet,1,46,sr_M_1_gsk2011,format03);
    worksheet_write_number(worksheet,1,47,sr_M_1_pz90,format03);
    worksheet_write_number(worksheet,1,48,sr_M_1_wgs84,format03);
        worksheet_write_number(worksheet,2,44,sr_M_2_krosvskogo,format03);
    worksheet_write_number(worksheet,2,45,sr_M_2_jgd2000,format03);
    worksheet_write_number(worksheet,2,46,sr_M_2_gsk2011,format03);
    worksheet_write_number(worksheet,2,47,sr_M_2_pz90,format03);
    worksheet_write_number(worksheet,2,48,sr_M_2_wgs84,format03);
        worksheet_write_number(worksheet,3,44,sr_M_3_krosvskogo,format03);
    worksheet_write_number(worksheet,3,45,sr_M_3_jgd2000,format03);
    worksheet_write_number(worksheet,3,46,sr_M_3_gsk2011,format03);
    worksheet_write_number(worksheet,3,47,sr_M_3_pz90,format03);
    worksheet_write_number(worksheet,3,48,sr_M_3_wgs84,format03);

        worksheet_write_number(worksheet,4,44,rm_P_1_krosvskogo,format03);
    worksheet_write_number(worksheet,4,45,rm_P_1_jgd2000,format03);
    worksheet_write_number(worksheet,4,46,rm_P_1_gsk2011,format03);
    worksheet_write_number(worksheet,4,47,rm_P_1_pz90,format03);
    worksheet_write_number(worksheet,4,48,rm_P_1_wgs84,format03);
        worksheet_write_number(worksheet,5,44,rm_P_2_krosvskogo,format03);
    worksheet_write_number(worksheet,5,45,rm_P_2_jgd2000,format03);
    worksheet_write_number(worksheet,5,46,rm_P_2_gsk2011,format03);
    worksheet_write_number(worksheet,5,47,rm_P_2_pz90,format03);
    worksheet_write_number(worksheet,5,48,rm_P_2_wgs84,format03);
        worksheet_write_number(worksheet,6,44,rm_P_3_krosvskogo,format03);
    worksheet_write_number(worksheet,6,45,rm_P_3_jgd2000,format03);
    worksheet_write_number(worksheet,6,46,rm_P_3_gsk2011,format03);
    worksheet_write_number(worksheet,6,47,rm_P_3_pz90,format03);
    worksheet_write_number(worksheet,6,48,rm_P_3_wgs84,format03);

    workbook_close(workbook);

    return 0;
}
