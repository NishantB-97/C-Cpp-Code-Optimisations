#include <iostream>
#include <cstdio>
#include <unistd.h>
#include <chrono>
#include <string>
#include <fstream>

const int ITERATIONS = 1;
const char* FILENAME = "output_log.txt";

// Test 1: printf() - Returns execution time in nanoseconds as string
std::string test_printf() {
    printf("\nprintf() Test...>\n");
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < ITERATIONS; ++i) {
        printf("%d\n", i);
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    return std::to_string(duration.count()) + " ns ";
}

// Test 2: stdout (using write) - Returns execution time in nanoseconds as string
std::string test_stdout() {
    std::cout << "\ncout Test...>\n";
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < ITERATIONS; ++i) {
        std::string s = std::to_string(i) + "\n";
        write(STDOUT_FILENO, s.c_str(), s.length());
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    return std::to_string(duration.count()) + " ns ";
}

// Test 3: No output - Returns execution time in nanoseconds as string
std::string test_no_output() {
    std::cout << "\nNo Output Test...>\n";
    auto start = std::chrono::high_resolution_clock::now();
    int sum = 0;
    for (int i = 0; i < ITERATIONS; ++i) {
        sum += i; // Do Something instead of output
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    return std::to_string(duration.count()) + " ns ";
}

// Test 4: fprintf to file (C-style) - Returns execution time in nanoseconds as string
std::string test_fprintf_file() {
    FILE* fp = fopen(FILENAME, "w");
    if (!fp) {
        return "Error opening file for fprintf";
    }
    std::cout << "\nFileIO [Using fprintf()] Test...>\n";
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < ITERATIONS; ++i) {
        fprintf(fp, "%d\n", i);
    }
    fclose(fp);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    return std::to_string(duration.count()) + " ns ";
}

// Test 5: std::ofstream to file (C++-style) - Returns execution time in nanoseconds as string
std::string test_ofstream_file() {
    std::ofstream outfile(FILENAME);
    if (!outfile.is_open()) {
        return "Error opening file for ofstream";
    }
    std::cout << "\nFileIO [std::ofstream] Test...>\n";
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < ITERATIONS; ++i) {
        outfile << i << "\n";
    }
    outfile.close();
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    return std::to_string(duration.count()) + " ns ";
}

int main() {
    std::string time_printf = test_printf();
    std::string time_stdout = test_stdout();
    std::string time_no_output = test_no_output();
    std::string time_fprintf = test_fprintf_file();
    std::string time_ofstream = test_ofstream_file();

    std::cout << "\n-------------| Execution Times (nanoseconds) |-------------\n\n";
    std::cout << "1.printf() to stdout:    " << time_printf << "\n";
    std::cout << "2.stdout (write):        " << time_stdout << "\n";
    std::cout << "3.No output:             " << time_no_output << "\n";
    std::cout << "4.fprintf() to file:     " << time_fprintf << "\n";
    std::cout << "5.std::ofstream to file: " << time_ofstream << "\n";

    return 0;
}
