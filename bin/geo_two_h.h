#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

//#define _USE_MATH_DEFINES

#define M_PI       3.14159265358979323846


struct ellipsoid {
double semi_major_axis;
long double compression;
};


using namespace std;

//cout << fixed << setprecision(10);

ellipsoid krosvskogo = {6378245,0.003352330};
ellipsoid wgs84 = {6378137,0.003352891};
ellipsoid pz90 = {6378136,0.003352804};
ellipsoid gsk2011 = {6378136.5,0.003352820};
ellipsoid jgd2000 = {6378137,0.003352811}; // https://www.gsi.go.jp/common/000001191.pdf

//Широта и долгота
double B[3] = {55,36,0};
double L[3] = {37,36,0};

//Синусы и косинусы
double angle_in_degree = B[0] + (B[1]/60.0);
double angle_in_rad = angle_in_degree * M_PI/180.0;
double L_ang_in_deg = L[0] + (L[1]/60.0);
double L_ang_in_rad = L_ang_in_deg * M_PI/180.0;
long double sin_b = sin(angle_in_rad);
long double cos_b = cos(angle_in_rad);
long double tan_b = tan(angle_in_rad);
long double sin_l = sin(L_ang_in_rad);
long double cos_l = cos(L_ang_in_rad);
long double tan_l = tan(L_ang_in_rad);


//Значение параметров основных элементов эллипсоида

//Значение малой полуоси
long double b_krosvskogo = krosvskogo.semi_major_axis * (1 - krosvskogo.compression);
long double b_wgs84 = wgs84.semi_major_axis * (1 - wgs84.compression);
long double b_pz90 = pz90.semi_major_axis * (1 - pz90.compression);
long double b_gsk2011 = gsk2011.semi_major_axis * (1 - gsk2011.compression);
long double b_jgd2000 = jgd2000.semi_major_axis * (1 - jgd2000.compression);

//Квадрат значения первого эксцентриситета
long double e_1_krosvskogo = krosvskogo.compression * (2 - krosvskogo.compression);
long double e_1_wgs84 = wgs84.compression * (2 - wgs84.compression);
long double e_1_pz90 = pz90.compression * (2 - pz90.compression);
long double e_1_gsk2011 = gsk2011.compression * (2 - gsk2011.compression);
long double e_1_jgd2000 = jgd2000.compression * (2 - jgd2000.compression);

//Квадрат значения второго эксцентриситета
long double e_2_krosvskogo = e_1_krosvskogo / (1-e_1_krosvskogo);
long double e_2_wgs84 = e_1_wgs84 / (1-e_1_wgs84);
long double e_2_pz90 = e_1_pz90 / (1-e_1_pz90);
long double e_2_gsk2011 = e_1_gsk2011 / (1-e_1_gsk2011);
long double e_2_jgd2000 = e_1_jgd2000 / (1-e_1_jgd2000);

//Значение полярного радиуса кривизны
long double c_krosvskogo = pow(krosvskogo.semi_major_axis,2) / b_krosvskogo;
long double c_wgs84 = pow(wgs84.semi_major_axis,2) / b_wgs84;
long double c_pz90 = pow(pz90.semi_major_axis,2) / b_pz90;
long double c_gsk2011 = pow(gsk2011.semi_major_axis,2) / b_gsk2011;
long double c_jgd2000 = pow(jgd2000.semi_major_axis,2) / b_jgd2000;

//Контроль
//1.7
long double b_2_control_krosvskogo = pow(krosvskogo.semi_major_axis,2)*(1-e_1_krosvskogo);
long double b_2_control_wgs84 = pow(wgs84.semi_major_axis,2)*(1-e_1_wgs84);
long double b_2_control_pz90 = pow(pz90.semi_major_axis,2)*(1-e_1_pz90);
long double b_2_control_gsk2011 = pow(gsk2011.semi_major_axis,2)*(1-e_1_gsk2011);
long double b_2_control_jgd2000 = pow(jgd2000 .semi_major_axis,2)*(1-e_1_jgd2000 );

//1.8
long double b_control_krosvskogo = pow(krosvskogo.semi_major_axis,2)/c_krosvskogo;
long double b_control_wgs84 = pow(wgs84.semi_major_axis,2)/c_wgs84;
long double b_control_pz90 = pow(pz90.semi_major_axis,2)/c_pz90;
long double b_control_gsk2011 = pow(gsk2011.semi_major_axis,2)/c_gsk2011;
long double b_control_jgd2000 = pow(jgd2000.semi_major_axis,2)/c_jgd2000;

//1.9
long double e_1_control_krosvskogo = (pow(krosvskogo.semi_major_axis,2)-pow(b_krosvskogo,2))/pow(krosvskogo.semi_major_axis,2);
long double e_1_control_wgs84 = (pow(wgs84.semi_major_axis,2)-pow(b_wgs84,2))/pow(wgs84.semi_major_axis,2);
long double e_1_control_pz90 = (pow(pz90.semi_major_axis,2)-pow(b_pz90,2))/pow(pz90.semi_major_axis,2);
long double e_1_control_gsk2011 = (pow(gsk2011.semi_major_axis,2)-pow(b_gsk2011,2))/pow(gsk2011.semi_major_axis,2);
long double e_1_control_jgd2000 = (pow(jgd2000.semi_major_axis,2)-pow(b_jgd2000,2))/pow(jgd2000.semi_major_axis,2);

//1.10
long double e_2_control_krosvskogo = (pow(krosvskogo.semi_major_axis,2)-pow(b_krosvskogo,2))/pow(b_krosvskogo,2);
long double e_2_control_wgs84 = (pow(wgs84.semi_major_axis,2)-pow(b_wgs84,2))/pow(b_wgs84,2);
long double e_2_control_pz90 = (pow(pz90.semi_major_axis,2)-pow(b_pz90,2))/pow(b_pz90,2);
long double e_2_control_gsk2011 = (pow(gsk2011.semi_major_axis,2)-pow(b_gsk2011,2))/pow(b_gsk2011,2);
long double e_2_control_jgd2000 = (pow(jgd2000.semi_major_axis,2)-pow(b_jgd2000,2))/pow(b_jgd2000,2);

//1.11
long double alfa_control_krosvskogo_1 = (krosvskogo.semi_major_axis-b_krosvskogo)/krosvskogo.semi_major_axis;
long double alfa_control_wgs84_1 = (wgs84.semi_major_axis-b_wgs84)/wgs84.semi_major_axis;
long double alfa_control_pz90_1 = (pz90.semi_major_axis-b_pz90)/pz90.semi_major_axis;
long double alfa_control_gsk2011_1 = (gsk2011.semi_major_axis-b_gsk2011)/gsk2011.semi_major_axis;
long double alfa_control_jgd2000_1 = (jgd2000.semi_major_axis-b_jgd2000)/jgd2000.semi_major_axis;

long double alfa_control_krosvskogo_2 = 1-sqrt(1-e_1_krosvskogo);
long double alfa_control_wgs84_2 = 1-sqrt(1-e_1_wgs84);
long double alfa_control_pz90_2 = 1-sqrt(1-e_1_pz90);
long double alfa_control_gsk2011_2 = 1-sqrt(1-e_1_gsk2011);
long double alfa_control_jgd2000_2 = 1-sqrt(1-e_1_jgd2000);

//1.12
long double f_12_krosvskogo_1 = krosvskogo.semi_major_axis - b_krosvskogo;
long double f_12_wgs84_1 = wgs84.semi_major_axis - b_wgs84;
long double f_12_pz90_1 = pz90.semi_major_axis - b_pz90;
long double f_12_gsk2011_1 = gsk2011.semi_major_axis - b_gsk2011;
long double f_12_jgd2000_1 = jgd2000.semi_major_axis - b_jgd2000;

long double f_12_krosvskogo_2 = krosvskogo.semi_major_axis * krosvskogo.compression;
long double f_12_wgs84_2 = wgs84.semi_major_axis * wgs84.compression;
long double f_12_pz90_2 = pz90.semi_major_axis * pz90.compression;
long double f_12_gsk2011_2 = gsk2011.semi_major_axis * gsk2011.compression;
long double f_12_jgd2000_2 = jgd2000.semi_major_axis * jgd2000.compression;

//1.13
long double c_control_krosvskogo = krosvskogo.semi_major_axis/(1-krosvskogo.compression);
long double c_control_wgs84 = wgs84.semi_major_axis/(1-wgs84.compression);
long double c_control_pz90 = pz90.semi_major_axis/(1-pz90.compression);
long double c_control_gsk2011 = gsk2011.semi_major_axis/(1-gsk2011.compression);
long double c_control_jgd2000 = jgd2000.semi_major_axis/(1-jgd2000.compression);

//Значения основных сфероидических функций W & V геодезическойй широты B
long double w_krosvskogo = 1 - e_1_krosvskogo * pow(sin_b,2);
long double w_wgs84 = 1 - e_1_wgs84 * pow(sin_b,2);
long double w_pz90 = 1 - e_1_pz90 * pow(sin_b,2);
long double w_gsk2011 = 1 - e_1_gsk2011 * pow(sin_b,2);
long double w_jgd2000 = 1 - e_1_jgd2000 * pow(sin_b,2);

long double v_krosvskogo = 1 + e_2_krosvskogo*pow(cos_b,2);
long double v_wgs84 = 1 + e_2_wgs84*pow(cos_b,2);
long double v_pz90 = 1 + e_2_pz90*pow(cos_b,2);
long double v_gsk2011 = 1 + e_2_gsk2011*pow(cos_b,2);
long double v_jgd2000 = 1 + e_2_jgd2000*pow(cos_b,2);

//Контроль 1.16
long double wv_control_krosvskogo_1 = krosvskogo.semi_major_axis * sqrt(w_krosvskogo);
long double wv_control_wgs84_1 = wgs84.semi_major_axis * sqrt(w_wgs84);
long double wv_control_pz90_1 = pz90.semi_major_axis * sqrt(w_pz90);
long double wv_control_gsk2011_1 = gsk2011.semi_major_axis * sqrt(w_gsk2011);
long double wv_control_jgd2000_1 = jgd2000.semi_major_axis * sqrt(w_jgd2000);

long double wv_control_krosvskogo_2 = b_krosvskogo * sqrt(v_krosvskogo);
long double wv_control_wgs84_2 = b_wgs84 * sqrt(v_wgs84);
long double wv_control_pz90_2 = b_pz90 * sqrt(v_pz90);
long double wv_control_gsk2011_2 = b_gsk2011 * sqrt(v_gsk2011);
long double wv_control_jgd2000_2 = b_jgd2000 * sqrt(v_jgd2000);

//Значения главных радиусов кривизны главных нормальных сечений и среднего радиуса кривизны

//Меридиан
long double M_krosvskogo = c_krosvskogo / pow(sqrt(v_krosvskogo),3);
long double M_wgs84 = c_wgs84 / pow(sqrt(v_wgs84),3);
long double M_pz90 = c_pz90 / pow(sqrt(v_pz90),3);
long double M_gsk2011 = c_gsk2011 / pow(sqrt(v_gsk2011),3);
long double M_jgd2000 = c_jgd2000 / pow(sqrt(v_jgd2000),3);

//Первый вертикал
long double N_krosvskogo = c_krosvskogo/sqrt(v_krosvskogo);
long double N_wgs84 = c_wgs84/sqrt(v_wgs84);
long double N_pz90 = c_pz90/sqrt(v_pz90);
long double N_gsk2011 = c_gsk2011/sqrt(v_gsk2011);
long double N_jgd2000 = c_jgd2000/sqrt(v_jgd2000);

//Радиус кривизны
long double R_krosvskogo = sqrt(M_krosvskogo * N_krosvskogo );
long double R_wgs84 = sqrt(M_wgs84 * N_wgs84 );
long double R_pz90 = sqrt(M_pz90 * N_pz90 );
long double R_gsk2011 = sqrt(M_gsk2011 * N_gsk2011 );
long double R_jgd2000 = sqrt(M_jgd2000 * N_jgd2000 );

//Кнтроль 1.20
long double nm_control_krosvskogo = N_krosvskogo / M_krosvskogo;
long double nm_control_wgs84 = N_wgs84 / M_wgs84;
long double nm_control_pz90 = N_pz90 / M_pz90;
long double nm_control_gsk2011 = N_gsk2011 / M_gsk2011;
long double nm_control_jgd2000 = N_jgd2000 / M_jgd2000;

//Значения декартовых координат заданной точки поверхности элипсоида, используя параметрические уравнения поверхности эллипсоида

//1.24
long double tgU_krosvskogo = sqrt(1-e_1_krosvskogo) * tan_b;
long double tgU_wgs84 = sqrt(1-e_1_wgs84) * tan_b;
long double tgU_pz90 = sqrt(1-e_1_pz90) * tan_b;
long double tgU_gsk2011 = sqrt(1-e_1_gsk2011) * tan_b;
long double tgU_jgd2000 = sqrt(1-e_1_jgd2000) * tan_b;

//Косинусы и синусы
long double cos_u_krosvskogo = 1/sqrt(1+pow(tgU_krosvskogo,2));
long double cos_u_wgs84 = 1/sqrt(1+pow(tgU_wgs84,2));
long double cos_u_pz90 = 1/sqrt(1+pow(tgU_pz90,2));
long double cos_u_gsk2011 = 1/sqrt(1+pow(tgU_gsk2011,2));
long double cos_u_jgd2000 = 1/sqrt(1+pow(tgU_jgd2000,2));

long double sin_u_krosvskogo = tgU_krosvskogo / (sqrt(1+pow(tgU_krosvskogo,2)));
long double sin_u_wgs84 = tgU_wgs84 / (sqrt(1+pow(tgU_wgs84,2)));
long double sin_u_pz90 = tgU_pz90 / (sqrt(1+pow(tgU_pz90,2)));
long double sin_u_gsk2011 = tgU_gsk2011 / (sqrt(1+pow(tgU_gsk2011,2)));
long double sin_u_jgd2000 = tgU_jgd2000 / (sqrt(1+pow(tgU_jgd2000,2)));

//1.21
long double x_krosvskogo = krosvskogo.semi_major_axis * cos_u_krosvskogo*cos_l;
long double x_wgs84 = wgs84.semi_major_axis * cos_u_wgs84*cos_l;
long double x_pz90 = pz90.semi_major_axis * cos_u_pz90*cos_l;
long double x_gsk2011 = gsk2011.semi_major_axis * cos_u_gsk2011*cos_l;
long double x_jgd2000 = jgd2000.semi_major_axis * cos_u_jgd2000*cos_l;

//1.22
long double y_krosvskogo = krosvskogo.semi_major_axis * cos_u_krosvskogo*sin_l;
long double y_wgs84 = wgs84.semi_major_axis * cos_u_wgs84*sin_l;
long double y_pz90 = pz90.semi_major_axis * cos_u_pz90*sin_l;
long double y_gsk2011 = gsk2011.semi_major_axis * cos_u_gsk2011*sin_l;
long double y_jgd2000 = jgd2000.semi_major_axis * cos_u_jgd2000*sin_l;

//1.23
long double z_krosvskogo = b_krosvskogo * sin_u_krosvskogo;
long double z_wgs84 = b_wgs84 * sin_u_wgs84;
long double z_pz90 = b_pz90 * sin_u_pz90;
long double z_gsk2011 = b_gsk2011 * sin_u_gsk2011;
long double z_jgd2000 = b_jgd2000 * sin_u_jgd2000;

//Контроль

//1.25
long double x_control_krosvskogo = N_krosvskogo * cos_b*cos_l;
long double x_control_wgs84 = N_wgs84 * cos_b*cos_l;
long double x_control_pz90 = N_pz90 * cos_b*cos_l;
long double x_control_gsk2011 = N_gsk2011 * cos_b*cos_l;
long double x_control_jgd2000 = N_jgd2000 * cos_b*cos_l;

//1.26
long double y_control_krosvskogo = N_krosvskogo * cos_b * sin_l;
long double y_control_wgs84 = N_wgs84 * cos_b * sin_l;
long double y_control_pz90 = N_pz90 * cos_b * sin_l;
long double y_control_gsk2011 = N_gsk2011 * cos_b * sin_l;
long double y_control_jgd2000 = N_jgd2000 * cos_b * sin_l;

//1.27
long double z_control_krosvskogo = N_krosvskogo * (1 - e_1_krosvskogo) * sin_b;
long double z_control_wgs84 = N_wgs84 * (1 - e_1_wgs84) * sin_b;
long double z_control_pz90 = N_pz90* (1 - e_1_pz90) * sin_b;
long double z_control_gsk2011 = N_gsk2011 * (1 - e_1_gsk2011) * sin_b;
long double z_control_jgd2000 = N_jgd2000 * (1 - e_1_jgd2000) * sin_b;