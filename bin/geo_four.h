#include <cmath>
#include <iomanip>
#include <xlsxwriter.h>
#include "geo_three_h.h"

namespace GeoF {

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
}