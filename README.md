# Geodesy Project README

This repository contains a collection of code and tools related to geodesy, specifically focused on geographic calculations and data manipulation. The project includes C++ code that interfaces with geospatial data and generates geodetic calculations, with a particular focus on the JGD2000 coordinate system.

The main functionality of the repository includes:

1. **Geodesic Calculations**: The project is designed to perform various geodesic computations, such as calculating the ellipsoid parameters, distances, and other spatial measurements based on the JGD2000 system.
  
2. **Data Output in Excel Format**: The code uses the [libxlsxwriter](https://libxlsxwriter.github.io/) library to generate Excel spreadsheets with the results of the geodesic calculations. The spreadsheets contain tables and formulas that allow for in-depth analysis and documentation of the results.

### Key Features:

- **Coordinate System**: The project works with the **JGD2000** (Japan Geodetic Datum 2000) system, making it suitable for geodesy and mapping applications focused on Japan's geospatial data.
  
- **Excel Output**: All results are written to Excel files (`.xlsx` format), where users can analyze the data in a structured way. The format includes calculated values, formulas, and organized tables for easy use.

- **Advanced Geodetic Calculations**: The project performs various calculations involving:
  - Latitude and longitude adjustments
  - Azimuth calculations
  - Geodetic distances and corrections
  
- **Dynamic Formula Calculation**: The C++ code leverages macros and formulas to dynamically compute values such as the Earth's semi-major axis, eccentricity, and more.

### Example of Code and Data Output

The code writes values and formulas to an Excel sheet. For example:

```cpp
worksheet_write_number(worksheet, 4,1,e_2_jgd2000,NULL);  // e1
worksheet_write_string(worksheet,3,1,"(e1^1)^2",NULL);
worksheet_write_number(worksheet, 4, 2, c_jgd2000, NULL);  // c
worksheet_write_string(worksheet,3,2,"c",NULL);
worksheet_write_string(worksheet,3,3,"Betta",NULL);  // Betta
worksheet_write_formula(worksheet, 4,3,"=1.25*B5", NULL);
```

This code dynamically writes calculated geodesic data into specific cells in an Excel worksheet, using both numeric values and formulas for further analysis.

### Setup and Requirements

- **C++**: The project is written in C++ and requires a C++ compiler (GCC or Clang).
  
- **libxlsxwriter**: To output results in Excel format, the project uses the [libxlsxwriter](https://libxlsxwriter.github.io/) library, which needs to be installed and linked during compilation.

To set up this project on your machine:

1. Clone the repository:
    ```bash
    git clone https://github.com/yourusername/geodesy-project.git
    ```

2. Install the required dependencies:
   - [libxlsxwriter](https://libxlsxwriter.github.io/)

3. Compile the project:
    ```bash
    g++ -o geodesy main.cpp -lxlsxwriter -lm
    ```

4. Run the program:
    ```bash
    ./geodesy
    ```

5. The program will output an Excel file, `out2342.xlsx`, with the geodesic calculations.

### File Structure

```
/bin
    ├── geo_eight.cpp        - Geodesic calculation module 8
    ├── geo_seven.cpp        - Geodesic calculation module 7
    ├── geo_three_h.h        - Header for geodesic calculation module 3
    ├── geo_two_h.h          - Header for geodesic calculation module 2
    ├── geodesy-1.cpp        - Main geodesic computation program (version 1)
    ├── geodesy_five.cpp     - Geodesic calculation module 5
    ├── geodesy_four.cpp     - Geodesic calculation module 4
    ├── geodesy_six.cpp      - Geodesic calculation module 6
    ├── geodesy_three.cpp    - Geodesic calculation module 3
    └── geodesy_two.cpp      - Geodesic calculation module 2
/build
LICENSE
README.md
/src
    └── con.md              - Documentation or content file (possibly explanation of the project)
```

### Contributions

If you would like to contribute to this project, please fork the repository, make your changes, and submit a pull request. We welcome improvements to the geodesic calculations, code optimizations, or additions to the functionality (such as support for other coordinate systems).

### License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

Feel free to explore the code and utilize it for your own geodesic and mapping applications!
