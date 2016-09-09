/*========================================
 *    sl.h: SL version 5.02
 *	Copyright 1993,2002,2014
 *                Toyoda Masashi                             JIM WAS HERE
 *		  (mtoyoda@acm.org)
 *	Last Modified: 2014/06/03                                on 9/8/16
 *========================================
 */
/*
 * How to change the train.
 * The 4 constants right below here have to do with the dimensions of the train.
 * The D51 drawings are for the actual locomotive. If you add more constants,
 * you have to change the dimension constants right here, and also add the
 * constants into some arrays in sl.c. The COAL constants are for the cargo
 * crate or caboose or whatever. You need to edit some array in sl.c if you add
 * more of those constants as well (if you make the train taller you have to add
 * more constants).
 *
 * So whenever the animation is redrawn for the train, it basically shifts
 * everything forward, but does not clear the area behind the train. As a
 * result, once you get to the end of the train, all the characters printed out
 * behind if will be the last character in the String for each String constant.
 * For example, if the last character in COAL01 were an E, you would see a long
 * line of trailing Es after the end of the train. So end each constant with a
 * space.
 */

#define D51HIGHT	13 // THIS USED TO BE 10. Edit if changing height of train
#define D51FUNNEL	5 // Horizontal positon of the funnel. Used to be 7
#define D51LENGTH	208 //THIS USED TO BE 83. Edit if changing length of train
#define D51PATTERNS	 6 // Number of animation patterns for the wheels I think

#define D51STR1  "      ====                                                  "
#define D51STR2  "      |  |                                                  "
#define D51STR3  "      |  |                                                  "
#define D51STR4  "      |==|        ________                ___________ "
#define D51STR5  "  _D _|  |_______/        \\__I_I_____===__|_________| "
#define D51STR6  "   |(_)---  |   H\\________/ |   |        =|___ ___|   "
#define D51STR7  "   /     |  |   H  |  |     |   |         ||_| |_||   "
#define D51STR8  "  |      |  |   H  |__------CS-1331-------| [___] |   "
#define D51STR9  "  | ________|___H__/__|_____/[][]~\\_______|       |   "
#define D51STRA  "  |/ |   |-----------I_____I [][] []  D   |=======|__ "

#define D51WHL11 "__/ =| o |=-~~\\  /~~\\  /~~\\  /~~\\ ____Y___________|__ "
#define D51WHL12 " |/-=|___|=    ||    ||    ||    |_____/~\\___/        "
#define D51WHL13 "  \\_/      \\O=====O=====O=====O_/      \\_/            "

#define D51WHL21 "__/ =| o |=-~~\\  /~~\\  /~~\\  /~~\\ ____Y___________|__ "
#define D51WHL22 " |/-=|___|=O=====O=====O=====O   |_____/~\\___/        "
#define D51WHL23 "  \\_/      \\__/  \\__/  \\__/  \\__/      \\_/            "

#define D51WHL31 "__/ =| o |=-O=====O=====O=====O \\ ____Y___________|__ "
#define D51WHL32 " |/-=|___|=    ||    ||    ||    |_____/~\\___/        "
#define D51WHL33 "  \\_/      \\__/  \\__/  \\__/  \\__/      \\_/            "

#define D51WHL41 "__/ =| o |=-~O=====O=====O=====O\\ ____Y___________|__ "
#define D51WHL42 " |/-=|___|=    ||    ||    ||    |_____/~\\___/        "
#define D51WHL43 "  \\_/      \\__/  \\__/  \\__/  \\__/      \\_/            "

#define D51WHL51 "__/ =| o |=-~~\\  /~~\\  /~~\\  /~~\\ ____Y___________|__ "
#define D51WHL52 " |/-=|___|=   O=====O=====O=====O|_____/~\\___/        "
#define D51WHL53 "  \\_/      \\__/  \\__/  \\__/  \\__/      \\_/            "

#define D51WHL61 "__/ =| o |=-~~\\  /~~\\  /~~\\  /~~\\ ____Y___________|__ "
#define D51WHL62 " |/-=|___|=    ||    ||    ||    |_____/~\\___/        "
#define D51WHL63 "  \\_/      \\_O=====O=====O=====O/      \\_/            "

#define D51DEL   "                                                      "

#define COAL01 "    .----------------.    .----------------.    .----------------.    .----------------.    .----------------.    .----------------.    .----------------.             "
#define COAL02 "   | .--------------. |  | .--------------. |  | .--------------. |  | .--------------. |  | .--------------. |  | .--------------. |  | .--------------. |            "
#define COAL03 "   | |     ______   | |  | |    _______   | |  | |              | |  | |     __       | |  | |    ______    | |  | |    ______    | |  | |     __       | |            "
#define COAL04 "   | |   .' ___  |  | |  | |   /  ___  |  | |  | |              | |  | |    /  |      | |  | |   / ____ `.  | |  | |   / ____ `.  | |  | |    /  |      | |            "
#define COAL05 "   | |  / .'   \\_|  | |  | |  |  (__ \\_|  | |  | |    ______    | |  | |    `| |      | |  | |   `'  __) |  | |  | |   `'  __) |  | |  | |    `| |      | |            "
#define COAL06 "   | |  | |         | |  | |   '.___`-.   | |  | |   |______|   | |  | |     | |      | |  | |   _  |__ '.  | |  | |   _  |__ '.  | |  | |     | |      | |            "
#define COAL07 "   | |  \\ `.___.'\\  | |  | |  |`\\____) |  | |  | |              | |  | |    _| |_     | |  | |  | \\____) |  | |  | |  | \\____) |  | |  | |    _| |_     | |            "
#define COAL08 "   | |   `._____.'  | |  | |  |_______.'  | |  | |              | |  | |   |_____|    | |  | |   \\______.'  | |  | |   \\______.'  | |  | |   |_____|    | |            "
#define COAL09 "   | |              | |  | |              | |  | |              | |  | |              | |  | |              | |  | |              | |  | |              | |            "
#define COAL10 "___| '--------------' |__| '--------------' |__| '--------------' |__| '--------------' |__| '--------------' |__| '--------------' |__| '--------------' |            "
#define COAL11 "/   '----------------'    '----------------'    '----------------'    '----------------'    '----------------'    '----------------'    '----------------'             "
#define COAL12 "       |_D__D__D_|_|         |_D__D__D_|_|         |_D__D__D_|_|         |_D__D__D_|_|         |_D__D__D_|_|         |_D__D__D_|_|         |_D__D__D_|_|                "
#define COAL13 "        \\_/   \\_/             \\_/   \\_/             \\_/   \\_/             \\_/   \\_/             \\_/   \\_/             \\_/   \\_/             \\_/   \\_/     "

#define COALDEL "                                                                                                                                                                           "

#define LOGOHIGHT    	 6
#define LOGOFUNNEL  	 4
#define LOGOLENGTH      84
#define LOGOPATTERNS	 6

#define LOGO1  "     ++      +------ "
#define LOGO2  "     ||      |+-+ |  "
#define LOGO3  "   /---------|| | |  "
#define LOGO4  "  + ========  +-+ |  "

#define LWHL11 " _|--O========O~\\-+  "
#define LWHL12 "//// \\_/      \\_/    "

#define LWHL21 " _|--/O========O\\-+  "
#define LWHL22 "//// \\_/      \\_/    "

#define LWHL31 " _|--/~O========O-+  "
#define LWHL32 "//// \\_/      \\_/    "

#define LWHL41 " _|--/~\\------/~\\-+  "
#define LWHL42 "//// \\_O========O    "

#define LWHL51 " _|--/~\\------/~\\-+  "
#define LWHL52 "//// \\O========O/    "

#define LWHL61 " _|--/~\\------/~\\-+  "
#define LWHL62 "//// O========O_/    "

#define LCOAL1 "____                 "
#define LCOAL2 "|   \\@@@@@@@@@@@     "
#define LCOAL3 "|    \\@@@@@@@@@@@@@_ "
#define LCOAL4 "|                  | "
#define LCOAL5 "|__________________| "
#define LCOAL6 "   (O)       (O)     "

#define LCAR1  "____________________ "
#define LCAR2  "|  ___ ___ ___ ___ | "
#define LCAR3  "|  |_| |_| |_| |_| | "
#define LCAR4  "|__________________| "
#define LCAR5  "|__________________| "
#define LCAR6  "   (O)        (O)    "

#define DELLN  "                     "

#define C51HIGHT 11 // THIS USED TO BE 11
#define C51FUNNEL 7
#define C51LENGTH 87 // THIS USED TO BE 87
#define C51PATTERNS 6

#define C51DEL "                                                       "

#define C51STR1 "        ___                                            "
#define C51STR2 "       _|_|_  _     __       __             ___________"
#define C51STR3 "    D__/   \\_(_)___|  |__H__|  |_____I_Ii_()|_________|"
#define C51STR4 "     | `---'   |:: `--'  H  `--'         |  |___ ___|  "
#define C51STR5 "    +|~~~~~~~~++::~~~~~~~H~~+=====+~~~~~~|~~||_| |_||  "
#define C51STR6 "    ||        | ::       H  +=====+      |  |::  ...|  "
#define C51STR7 "|    | _______|_::-----------------[][]-----|       |  "

#define C51WH61 "| /~~ ||   |-----/~~~~\\  /[I_____I][][] --|||_______|__"
#define C51WH62 "------'|oOo|==[]=-     ||      ||      |  ||=======_|__"
#define C51WH63 "/~\\____|___|/~\\_|   O=======O=======O  |__|+-/~\\_|     "
#define C51WH64 "\\_/         \\_/  \\____/  \\____/  \\____/      \\_/       "

#define C51WH51 "| /~~ ||   |-----/~~~~\\  /[I_____I][][] --|||_______|__"
#define C51WH52 "------'|oOo|===[]=-    ||      ||      |  ||=======_|__"
#define C51WH53 "/~\\____|___|/~\\_|    O=======O=======O |__|+-/~\\_|     "
#define C51WH54 "\\_/         \\_/  \\____/  \\____/  \\____/      \\_/       "

#define C51WH41 "| /~~ ||   |-----/~~~~\\  /[I_____I][][] --|||_______|__"
#define C51WH42 "------'|oOo|===[]=- O=======O=======O  |  ||=======_|__"
#define C51WH43 "/~\\____|___|/~\\_|      ||      ||      |__|+-/~\\_|     "
#define C51WH44 "\\_/         \\_/  \\____/  \\____/  \\____/      \\_/       "

#define C51WH31 "| /~~ ||   |-----/~~~~\\  /[I_____I][][] --|||_______|__"
#define C51WH32 "------'|oOo|==[]=- O=======O=======O   |  ||=======_|__"
#define C51WH33 "/~\\____|___|/~\\_|      ||      ||      |__|+-/~\\_|     "
#define C51WH34 "\\_/         \\_/  \\____/  \\____/  \\____/      \\_/       "

#define C51WH21 "| /~~ ||   |-----/~~~~\\  /[I_____I][][] --|||_______|__"
#define C51WH22 "------'|oOo|=[]=- O=======O=======O    |  ||=======_|__"
#define C51WH23 "/~\\____|___|/~\\_|      ||      ||      |__|+-/~\\_|     "
#define C51WH24 "\\_/         \\_/  \\____/  \\____/  \\____/      \\_/       "

#define C51WH11 "| /~~ ||   |-----/~~~~\\  /[I_____I][][] --|||_______|__"
#define C51WH12 "------'|oOo|=[]=-      ||      ||      |  ||=======_|__"
#define C51WH13 "/~\\____|___|/~\\_|  O=======O=======O   |__|+-/~\\_|     "
#define C51WH14 "\\_/         \\_/  \\____/  \\____/  \\____/      \\_/       "
