#include <xc.h>
char *gear[]={"ON","GN","G1","G2","G3","G4","G5","RG"};
char *main_menu[]={"view_log","clear_log","Download_log","Set_time"};
int main_index=0;
unsigned char key;
unsigned int min,hour,sec;
unsigned int flag_menu=0;
unsigned char write_addr =0x00;
unsigned char str1[10][18];
unsigned int store_count=0;
int index=0;
int once=0;
 int set_flag=0;
int change_menu=0;
unsigned char clock_reg[3];
unsigned char calender_reg[4];
unsigned char time[9];
void get_time(void);

/* Enum for maintaining the app state */
typedef enum {
    e_dashboard, e_main_menu, e_view_log, e_set_time, e_download_log, e_clear_log
} State_t;

State_t state;
extern State_t state; // App state

//Function declarations
void init_adc(void);
unsigned short read_adc(void);

//Dashboard function declaration
void view_dashboard(void);

//Storing events function declaration
void event_store(void);

//Password function declaration
void password(void);

//main menu function declaration
void display_main_menu(void);

//View log function declaration
void view_log(void);

//Reading events function declaration
void event_reader(void);

//Change password function declaration
void change_password(void);

//Set time function declaration
void set_time(void);

//Download log function _decleration
void download_log(void);

//Clear log function declaration
void clear_log(void);









#define CLCD_PORT			PORTD
#define CLCD_EN				RC2
#define CLCD_RS				RC1
#define CLCD_RW				RC0
#define CLCD_BUSY			RD7
#define PORT_DIR			TRISD7
#define ALL_RELEASED			0x0F
#define  INPUT_PINS             0x0F


#define HI												1
#define LO												0

#define INPUT											0xFF
#define OUTPUT											0x00

#define DATA_COMMAND									1
#define INSTRUCTION_COMMAND								0
#define _XTAL_FREQ                  20000000
#define LINE1(x)									(0x80 + (x))
#define LINE2(x)										(0xC0 + (x))

#define TWO_LINE_5x8_MATRIX_8_BIT					clcd_write(0x38, INSTRUCTION_COMMAND)
#define CLEAR_DISP_SCREEN				                clcd_write(0x01, INSTRUCTION_COMMAND)
#define CURSOR_HOME							clcd_write(0x02, INSTRUCTION_COMMAND)
#define DISP_ON_AND_CURSOR_OFF						clcd_write(0x0C, INSTRUCTION_COMMAND)
#define EIGHT_BIT_MODE   0x33
void init_clcd(void);
unsigned char scan_key();
unsigned char read_matrix_keypad(unsigned char detection_type);
void clcd_print(const unsigned char *data, unsigned char addr);
void clcd_putch(const unsigned char data, unsigned char addr);
void clcd_write(unsigned char bit_values, unsigned char control_bit);
void init_adc();
unsigned short read_adc();






