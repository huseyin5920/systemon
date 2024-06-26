// color.h

#ifndef COLOR_H
#define COLOR_H

// ANSI renk kaçış dizilerini içeren renklerin tanımları
#define RESET   "\033[0m"
#define BLACK   "\033[0;30m"      
#define RED     "\033[0;31m"      
#define GREEN   "\033[0;32m"      
#define YELLOW  "\033[0;33m"      
#define BLUE    "\033[0;34m"      
#define MAGENTA "\033[0;35m"      
#define CYAN    "\033[0;36m"      
#define WHITE   "\033[0;37m"      

// Renklendirilmiş metni yazdıran fonksiyon
void print_color(const char *color_code, const char *format, ...);

#endif
