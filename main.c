/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehaggon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 13:41:48 by ehaggon          #+#    #+#             */
/*   Updated: 2019/06/03 14:44:30 by ehaggon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** -----------------------------===[SYNTAX]===--------------------------------|
** %[parameters][flags][width][.precision][size]type
*/

/*
** |---------------------------===[PARAMETERS]===------------------------------|
** |-----------+---------------------------------------------------------------|
** | Character |                          Description                          |
** |-----------+---------------------------------------------------------------|
** | [n$]      | n is the #'s of the parameter, allowing the same param to be  |
** |           | output multiple times w/ various modifers or dif orders.      |
** |           | If a placeholder specifies a parameter, the rest must follow. |
** |-----------+---------------------------------------------------------------|
** Ex. printf("%3$d %3$d, %1$d %1$ d, %2$d %2$+d", -1, 2, 3)
** Output: 3 3, -1 -1, 2 +2
*/

/*
** -----------------------------===[FLAGS]===----------------------------------|
** | Character   |                        Description                          |
** |-------------+-------------------------------------------------------------|
** | [-] (minus) | Left align the output of this place holder                  |
** | [+] (plus)  | Add '+' for positive signed numeric type ('-' for negative) |
** | [ ] (space) | Add ' ' for positive #', '-' for negative. Ignored if [+]   |
** |             | flag exists.                                                |
** | [0] (zero)  | If 'width' option is specified, prepends 0's. Default add   |
** |             | spaces.                                                     |
** | [#] (hash)  | Alternate form:                                             |
** |             | For [g,G] types, trailing 0's are NOT removed               |
** |             | For [f,F,e,E,g,G], output contains decimal point            |
** |             | For [o,x,X], 0, 0x, 0X, respectively add to non-zero #'s    |
** |-------------+-------------------------------------------------------------|
** Ex. printf("|%1$d| |%1$+d| |%1$ d| |%1$0d| |%1$03d| |%2$.2g| |%2$#g|
** 			|%2$#.0f| |%2$7.3f| |%2$-7.3f| |%3$#.0e|", 1, 21.3, 42.);
** Out:|1| |+1| | 1| |1| |001| |21| |21.3000| |21.| | 21.300| |21.300 | |4.e+01|
*/

/*
** ----------------------------===[WIDTH]===-----------------------------------|
** | Character      |                     Description                          |
** |----------------+----------------------------------------------------------|
** | [*] (asterisk) | Specifies minimum of char to the output. May be omitted  |
** |                | and also can be pass as a dynamic value using *. Can be  |
** |                | used in conjunction with 0 and -                         |
** |----------------+----------------------------------------------------------|
*/

/*
** |---------------------------===[PRECISION]===-------------------------------|
** | Character |                           Description                         |
** |-----------+:--------------------------------------------------------------|
** | [.] (dot) | Specifies maximum limit on the output. For float, it specifies|
** |           |    the #'s of digits to the right of decimal point that the   |
** |           |  output should be rounded. For string, it limits the character|
** |           |                after which should be truncated.               |
** |-----------+---------------------------------------------------------------|
*/

/*
** |-----------------------------===[SIZE]===----------------------------------|
** | Character |                           Description                         |
** |-----------+---------------------------------------------------------------|
** | [h]       | For int type, expect an int_sized arg promoted from a short   |
** | [hh]      | For int type, expect an int_sized arg promoted from a char    |
** | [l]       | For int type, expect a long arg                               |
** |           | For floats, this has no effect                                |
** | [ll]      | For int type, expect a long long arg                          |
** | [L]       | For floats type, expect an long double arg                    |
** | [z]       | For int type, expect a size_t arg                             |
** | [j]       | For int type, expect an int_max arg                           |
** | [t]       | For int type, expect a ptrdiff_t arg                          |
** |-----------+---------------------------------------------------------------|
*/

/*
** |---------------------------===[TYPES]===-----------------------------------|
** | Character |                           Description                         |
** |-----------+---------------------------------------------------------------|
** | [%]       | Prints a literal % (doesn't accept previous fields)           |
** | [d, i]    | Signed decimal int. Similar but different when use w/ scanf() |
** |           | %i is hex or octal if preceded by 0x or 0, respectively       |
** | [u]       | Unsigned decimal int.                                         |
** | [f, F]    | Double in fixed-point notation. Differs in output string for  |
** |           | an inf # or NaN (inf, infinity, nan for f)                    |
** |           | (INF, INFINITY, NAN for F)                                    |
** | [e, E]    | Double in standard form ([-]d.ddde[+/-]ddd). E uses letter E  |
** | [g, G]    | Double in in either normal or exponential notation.           |
** |           | Insignificant zeros to the right of decimal point are not     |
** |           | included. Decimal point is not included for whole numbers.    |
** | [x, X]    | Unsigned int as hex.                                          |
** | [o]       | Unsigned int octal.                                           |
** | [s]       | null-terminated string.                                       |
** | [c]       | character.                                                    |
** | [p]       | void pointer in an implementation-defined format              |
** | [a, A]    | double in hex, starting with 0x or 0X.                        |
** | [n]       | prints nothing, but writes # of chars successfully written    |
** |           | so far into integer pointer parameter.                        |
** |-----------+---------------------------------------------------------------|
*/

// To Do List:
// Learn Dispatch Table to improve coding skills and structure handling✓.
// Study Exam Questions✓;
// Create struct to collect flags ✓; 
// Create a function pointers to handle width✓;
// Collect size✓;
// Putnumber✓;
// Find p->done for nbr w/ pcn✓;
// make struct for float printing✓;
// pad zeroes according to precision✓;


int main(void)
{
//	printf("-------------------------------------STRINGS---------------------------------------\n");
//	char *s = "hi low";
//	printf("ft_printf: %d vs %d :printf #1\n",ft_printf("|%s|\t", s),		printf("|%s|\t", s));
//	printf("ft_printf: %d vs %d :printf #2\n",ft_printf("|%1s|\t", s),		printf("|%1s|\t", s));
//	printf("ft_printf: %d vs %d :printf #3\n",ft_printf("|%2s|\t", s),		printf("|%2s|\t", s));
//	printf("ft_printf: %d vs %d :printf #4\n",ft_printf("|%3s|\t", s),		printf("|%3s|\t", s));
//	printf("ft_printf: %d vs %d :printf #5\n",ft_printf("|%4s|\t", s),		printf("|%4s|\t", s));
//	printf("ft_printf: %d vs %d :printf #6\n",ft_printf("|%5s|\t", s),		printf("|%5s|\t", s));
//	printf("ft_printf: %d vs %d :printf #7\n",ft_printf("|%6s|\t", s),		printf("|%6s|\t", s));
//	printf("ft_printf: %d vs %d :printf #8\n",ft_printf("|%7s|\t", s),		printf("|%7s|\t", s));
//	printf("ft_printf: %d vs %d :printf #9\n",ft_printf("|%8s|\t", s),		printf("|%8s|\t", s));
//	printf("ft_printf: %d vs %d :printf #10\n",ft_printf("|%9s|\t", s),		printf("|%9s|\t", s));
//	//undefined behavior
//	printf("ft_printf: %d vs %d :printf #11\n",ft_printf("|%+1s|\t", s),		printf("|%+1s|\t", s));
//	printf("ft_printf: %d vs %d :printf #12\n",ft_printf("|%+2s|\t", s),		printf("|%+2s|\t", s));
//	printf("ft_printf: %d vs %d :printf #13\n",ft_printf("|%+3s|\t", s),		printf("|%+3s|\t", s));
//	printf("ft_printf: %d vs %d :printf #14\n",ft_printf("|%+4s|\t", s),		printf("|%+4s|\t", s));
//	printf("ft_printf: %d vs %d :printf #15\n",ft_printf("|%+5s|\t", s),		printf("|%+5s|\t", s));
//	printf("ft_printf: %d vs %d :printf #16\n",ft_printf("|%+6s|\t", s),		printf("|%+6s|\t", s));
//	printf("ft_printf: %d vs %d :printf #17\n",ft_printf("|%+7s|\t", s),		printf("|%+7s|\t", s));
//	printf("ft_printf: %d vs %d :printf #18\n",ft_printf("|%+8s|\t", s),		printf("|%+8s|\t", s));
//	printf("ft_printf: %d vs %d :printf #19\n",ft_printf("|%+9s|\t", s),		printf("|%+9s|\t", s));
//	printf("ft_printf: %d vs %d :printf #20\n",ft_printf("|%+01s|\t", s),		printf("|%+01s|\t", s));
//	printf("ft_printf: %d vs %d :printf #21\n",ft_printf("|%+02s|\t", s),		printf("|%+02s|\t", s));
//	printf("ft_printf: %d vs %d :printf #22\n",ft_printf("|%+03s|\t", s),		printf("|%+03s|\t", s));
//	printf("ft_printf: %d vs %d :printf #23\n",ft_printf("|%+04s|\t", s),		printf("|%+04s|\t", s));
//	printf("ft_printf: %d vs %d :printf #24\n",ft_printf("|%+05s|\t", s),		printf("|%+05s|\t", s));
//	printf("ft_printf: %d vs %d :printf #25\n",ft_printf("|%+06s|\t", s),		printf("|%+06s|\t", s));
//	printf("ft_printf: %d vs %d :printf #26\n",ft_printf("|%+07s|\t", s),		printf("|%+07s|\t", s));
//	printf("ft_printf: %d vs %d :printf #27\n",ft_printf("|%+08s|\t", s),		printf("|%+08s|\t", s));
//	printf("ft_printf: %d vs %d :printf #28\n",ft_printf("|%+09s|\t", s),		printf("|%+09s|\t", s));
//	//0 decoy
//	printf("ft_printf: %d vs %d :printf #29\n",ft_printf("|%00s|\t", s),		printf("|%00s|\t", s));
//	printf("ft_printf: %d vs %d :printf #30\n",ft_printf("|%010s|\t", s),		printf("|%010s|\t", s));
//	printf("ft_printf: %d vs %d :printf #31\n",ft_printf("|%001s|\t", s),		printf("|%001s|\t", s));
//	printf("ft_printf: %d vs %d :printf #32\n",ft_printf("|%020s|\t", s),		printf("|%020s|\t", s));
//	printf("ft_printf: %d vs %d :printf #33\n",ft_printf("|%000s|\t", s),		printf("|%000s|\t", s));
//	printf("ft_printf: %d vs %d :printf #34\n",ft_printf("|%0000s|\t", s),		printf("|%0000s|\t", s));
//	printf("ft_printf: %d vs %d :printf #35\n",ft_printf("|%-00s|\t", s),		printf("|%-00s|\t", s));
//	printf("ft_printf: %d vs %d :printf #36\n",ft_printf("|%0-0s|\t", s),		printf("|%0-0s|\t", s));
//	printf("ft_printf: %d vs %d :printf #37\n",ft_printf("|%00-s|\t", s),		printf("|%00-s|\t", s));
//	// Precision no width
//	printf("ft_printf: %d vs %d :printf #38\n",ft_printf("|%.s|\t", s),		printf("|%.s|\t", s));
//	printf("ft_printf: %d vs %d :printf #39\n",ft_printf("|%.0s|\t", s),		printf("|%.0s|\t", s));
//	printf("ft_printf: %d vs %d :printf #40\n",ft_printf("|%.1s|\t", s),		printf("|%.1s|\t", s));
//	printf("ft_printf: %d vs %d :printf #41\n",ft_printf("|%.2s|\t", s),		printf("|%.2s|\t", s));
//	printf("ft_printf: %d vs %d :printf #42\n",ft_printf("|%.3s|\t", s),		printf("|%.3s|\t", s));
//	printf("ft_printf: %d vs %d :printf #43\n",ft_printf("|%.4s|\t", s),		printf("|%.4s|\t", s));
//	printf("ft_printf: %d vs %d :printf #44\n",ft_printf("|%.5s|\t", s),		printf("|%.5s|\t", s));
//	printf("ft_printf: %d vs %d :printf #45\n",ft_printf("|%.6s|\t", s),		printf("|%.6s|\t", s));
//	printf("ft_printf: %d vs %d :printf #46\n",ft_printf("|%.7s|\t", s),		printf("|%.7s|\t", s));
//	printf("ft_printf: %d vs %d :printf #47\n",ft_printf("|%.8s|\t", s),		printf("|%.8s|\t", s));
//	printf("ft_printf: %d vs %d :printf #48\n",ft_printf("|%.9s|\t", s),		printf("|%.9s|\t", s));
//	printf("ft_printf: %d vs %d :printf #49\n",ft_printf("|%.00s|\t", s),		printf("|%.00s|\t", s));
//	printf("ft_printf: %d vs %d :printf #50\n",ft_printf("|%.01s|\t", s),		printf("|%.01s|\t", s));
//	printf("ft_printf: %d vs %d :printf #51\n",ft_printf("|%.02s|\t", s),		printf("|%.02s|\t", s));
//	printf("ft_printf: %d vs %d :printf #52\n",ft_printf("|%.03s|\t", s),		printf("|%.03s|\t", s));
//	printf("ft_printf: %d vs %d :printf #53\n",ft_printf("|%.04s|\t", s),		printf("|%.04s|\t", s));
//	printf("ft_printf: %d vs %d :printf #54\n",ft_printf("|%.05s|\t", s),		printf("|%.05s|\t", s));
//	printf("ft_printf: %d vs %d :printf #55\n",ft_printf("|%.06s|\t", s),		printf("|%.06s|\t", s));
//	printf("ft_printf: %d vs %d :printf #56\n",ft_printf("|%.07s|\t", s),		printf("|%.07s|\t", s));
//	printf("ft_printf: %d vs %d :printf #57\n",ft_printf("|%.08s|\t", s),		printf("|%.08s|\t", s));
//	printf("ft_printf: %d vs %d :printf #58\n",ft_printf("|%.09s|\t", s),		printf("|%.09s|\t", s));
//	//Decoy minus flag
//	printf("ft_printf: %d vs %d :printf #59\n",ft_printf("|%-.s|\t", s),		printf("|%-.s|\t", s));
//	printf("ft_printf: %d vs %d :printf #60\n",ft_printf("|%-.0s|\t", s),		printf("|%-.0s|\t", s));
//	printf("ft_printf: %d vs %d :printf #61\n",ft_printf("|%-.1s|\t", s),		printf("|%-.1s|\t", s));
//	printf("ft_printf: %d vs %d :printf #62\n",ft_printf("|%-.2s|\t", s),		printf("|%-.2s|\t", s));
//	printf("ft_printf: %d vs %d :printf #63\n",ft_printf("|%-.3s|\t", s),		printf("|%-.3s|\t", s));
//	printf("ft_printf: %d vs %d :printf #64\n",ft_printf("|%-.4s|\t", s),		printf("|%-.4s|\t", s));
//	printf("ft_printf: %d vs %d :printf #65\n",ft_printf("|%-.5s|\t", s),		printf("|%-.5s|\t", s));
//	printf("ft_printf: %d vs %d :printf #66\n",ft_printf("|%-.6s|\t", s),		printf("|%-.6s|\t", s));
//	printf("ft_printf: %d vs %d :printf #67\n",ft_printf("|%-.7s|\t", s),		printf("|%-.7s|\t", s));
//	printf("ft_printf: %d vs %d :printf #68\n",ft_printf("|%-.8s|\t", s),		printf("|%-.8s|\t", s));
//	printf("ft_printf: %d vs %d :printf #69\n",ft_printf("|%-.9s|\t", s),		printf("|%-.9s|\t", s));
//	printf("ft_printf: %d vs %d :printf #70\n",ft_printf("|%-.00s|\t", s),		printf("|%-.00s|\t", s));
//	printf("ft_printf: %d vs %d :printf #71\n",ft_printf("|%-.01s|\t", s),		printf("|%-.01s|\t", s));
//	printf("ft_printf: %d vs %d :printf #72\n",ft_printf("|%-.02s|\t", s),		printf("|%-.02s|\t", s));
//	printf("ft_printf: %d vs %d :printf #73\n",ft_printf("|%-.03s|\t", s),		printf("|%-.03s|\t", s));
//	printf("ft_printf: %d vs %d :printf #74\n",ft_printf("|%-.04s|\t", s),		printf("|%-.04s|\t", s));
//	printf("ft_printf: %d vs %d :printf #75\n",ft_printf("|%-.05s|\t", s),		printf("|%-.05s|\t", s));
//	printf("ft_printf: %d vs %d :printf #76\n",ft_printf("|%-.06s|\t", s),		printf("|%-.06s|\t", s));
//	printf("ft_printf: %d vs %d :printf #77\n",ft_printf("|%-.07s|\t", s),		printf("|%-.07s|\t", s));
//	printf("ft_printf: %d vs %d :printf #78\n",ft_printf("|%-.08s|\t", s),		printf("|%-.08s|\t", s));
//	printf("ft_printf: %d vs %d :printf #79\n",ft_printf("|%-.09s|\t", s),		printf("|%-.09s|\t", s));
//	//Decoy space flag
//	printf("ft_printf: %d vs %d :printf #80\n",ft_printf("|% .s|\t", s),		printf("|% .s|\t", s));
//	printf("ft_printf: %d vs %d :printf #81\n",ft_printf("|% .0s|\t", s),		printf("|% .0s|\t", s));
//	printf("ft_printf: %d vs %d :printf #82\n",ft_printf("|% .1s|\t", s),		printf("|% .1s|\t", s));
//	printf("ft_printf: %d vs %d :printf #83\n",ft_printf("|% .2s|\t", s),		printf("|% .2s|\t", s));
//	printf("ft_printf: %d vs %d :printf #84\n",ft_printf("|% .3s|\t", s),		printf("|% .3s|\t", s));
//	printf("ft_printf: %d vs %d :printf #85\n",ft_printf("|% .4s|\t", s),		printf("|% .4s|\t", s));
//	printf("ft_printf: %d vs %d :printf #86\n",ft_printf("|% .5s|\t", s),		printf("|% .5s|\t", s));
//	printf("ft_printf: %d vs %d :printf #87\n",ft_printf("|% .6s|\t", s),		printf("|% .6s|\t", s));
//	printf("ft_printf: %d vs %d :printf #88\n",ft_printf("|% .7s|\t", s),		printf("|% .7s|\t", s));
//	printf("ft_printf: %d vs %d :printf #89\n",ft_printf("|% .8s|\t", s),		printf("|% .8s|\t", s));
//	printf("ft_printf: %d vs %d :printf #90\n",ft_printf("|% .9s|\t", s),		printf("|% .9s|\t", s));
//	printf("ft_printf: %d vs %d :printf #91\n",ft_printf("|% .00s|\t", s),		printf("|% .00s|\t", s));
//	printf("ft_printf: %d vs %d :printf #92\n",ft_printf("|% .01s|\t", s),		printf("|% .01s|\t", s));
//	printf("ft_printf: %d vs %d :printf #93\n",ft_printf("|% .02s|\t", s),		printf("|% .02s|\t", s));
//	printf("ft_printf: %d vs %d :printf #94\n",ft_printf("|% .03s|\t", s),		printf("|% .03s|\t", s));
//	printf("ft_printf: %d vs %d :printf #95\n",ft_printf("|% .04s|\t", s),		printf("|% .04s|\t", s));
//	printf("ft_printf: %d vs %d :printf #96\n",ft_printf("|% .05s|\t", s),		printf("|% .05s|\t", s));
//	printf("ft_printf: %d vs %d :printf #97\n",ft_printf("|% .06s|\t", s),		printf("|% .06s|\t", s));
//	printf("ft_printf: %d vs %d :printf #98\n",ft_printf("|% .07s|\t", s),		printf("|% .07s|\t", s));
//	printf("ft_printf: %d vs %d :printf #99\n",ft_printf("|% .08s|\t", s),		printf("|% .08s|\t", s));
//	printf("ft_printf: %d vs %d :printf #100\n",ft_printf("|% .09s|\t", s),		printf("|% .09s|\t", s));
//	//no precision with width
//	printf("ft_printf: %d vs %d :printf #101\n",ft_printf("|%0.s|\t", s),		printf("|%0.s|\t", s));
//	printf("ft_printf: %d vs %d :printf #102\n",ft_printf("|%1.s|\t", s),		printf("|%1.s|\t", s));
//	printf("ft_printf: %d vs %d :printf #103\n",ft_printf("|%2.s|\t", s),		printf("|%2.s|\t", s));
//	printf("ft_printf: %d vs %d :printf #104\n",ft_printf("|%3.s|\t", s),		printf("|%3.s|\t", s));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%4.s|\t", s),		printf("|%4.s|\t", s));
//	printf("ft_printf: %d vs %d :printf #106\n",ft_printf("|%5.s|\t", s),		printf("|%5.s|\t", s));
//	printf("ft_printf: %d vs %d :printf #107\n",ft_printf("|%6.s|\t", s),		printf("|%6.s|\t", s));
//	printf("ft_printf: %d vs %d :printf #108\n",ft_printf("|%7.s|\t", s),		printf("|%7.s|\t", s));
//	printf("ft_printf: %d vs %d :printf #109\n",ft_printf("|%8.s|\t", s),		printf("|%8.s|\t", s));
//	printf("ft_printf: %d vs %d :printf #110\n",ft_printf("|%9.s|\t", s),		printf("|%9.s|\t", s));
//	//low precision with width
//	printf("ft_printf: %d vs %d :printf #111\n",ft_printf("|%0.1s|\t", s),		printf("|%0.1s|\t", s));
//	printf("ft_printf: %d vs %d :printf #112\n",ft_printf("|%1.1s|\t", s),		printf("|%1.1s|\t", s));
//	printf("ft_printf: %d vs %d :printf #113\n",ft_printf("|%2.1s|\t", s),		printf("|%2.1s|\t", s));
//	printf("ft_printf: %d vs %d :printf #114\n",ft_printf("|%3.1s|\t", s),		printf("|%3.1s|\t", s));
//	printf("ft_printf: %d vs %d :printf #115\n",ft_printf("|%4.1s|\t", s),		printf("|%4.1s|\t", s));
//	printf("ft_printf: %d vs %d :printf #116\n",ft_printf("|%5.1s|\t", s),		printf("|%5.1s|\t", s));
//	printf("ft_printf: %d vs %d :printf #117\n",ft_printf("|%6.1s|\t", s),		printf("|%6.1s|\t", s));
//	printf("ft_printf: %d vs %d :printf #118\n",ft_printf("|%7.1s|\t", s),		printf("|%7.1s|\t", s));
//	printf("ft_printf: %d vs %d :printf #119\n",ft_printf("|%8.1s|\t", s),		printf("|%8.1s|\t", s));
//	printf("ft_printf: %d vs %d :printf #120\n",ft_printf("|%0.1s|\t", s),		printf("|%0.1s|\t", s));
//	//perfect precision with width
//	printf("ft_printf: %d vs %d :printf #121\n",ft_printf("|%0.6s|\t", s),		printf("|%0.6s|\t", s));
//	printf("ft_printf: %d vs %d :printf #122\n",ft_printf("|%1.6s|\t", s),		printf("|%1.6s|\t", s));
//	printf("ft_printf: %d vs %d :printf #123\n",ft_printf("|%2.6s|\t", s),		printf("|%2.6s|\t", s));
//	printf("ft_printf: %d vs %d :printf #124\n",ft_printf("|%3.6s|\t", s),		printf("|%3.6s|\t", s));
//	printf("ft_printf: %d vs %d :printf #125\n",ft_printf("|%4.6s|\t", s),		printf("|%4.6s|\t", s));
//	printf("ft_printf: %d vs %d :printf #126\n",ft_printf("|%5.6s|\t", s),		printf("|%5.6s|\t", s));
//	printf("ft_printf: %d vs %d :printf #127\n",ft_printf("|%6.6s|\t", s),		printf("|%6.6s|\t", s));
//	printf("ft_printf: %d vs %d :printf #128\n",ft_printf("|%7.6s|\t", s),		printf("|%7.6s|\t", s));
//	printf("ft_printf: %d vs %d :printf #129\n",ft_printf("|%8.6s|\t", s),		printf("|%8.6s|\t", s));
//	//Wombo combo perfect precision_width
//	printf("ft_printf: %d vs %d :printf #130\n",ft_printf("|%+- 06.6s|\t", s),		printf("|%+- 06.6s|\t", s));
//	printf("ft_printf: %d vs %d :printf #131\n",ft_printf("|%-+ 06.6s|\t", s),		printf("|%-+ 06.6s|\t", s));
//	printf("ft_printf: %d vs %d :printf #132\n",ft_printf("|%+ -06.6s|\t", s),		printf("|%+ -06.6s|\t", s));
//	printf("ft_printf: %d vs %d :printf #133\n",ft_printf("|%+0 -6.6s|\t", s),		printf("|%+0 -6.6s|\t", s));
//	printf("ft_printf: %d vs %d :printf #134\n",ft_printf("|% +-06.6s|\t", s),		printf("|% +-06.6s|\t", s));
//	printf("ft_printf: %d vs %d :printf #135\n",ft_printf("|%0+- 6.6s|\t", s),		printf("|%0+- 6.6s|\t", s));
//	//Wombo combo width > precision
//	printf("ft_printf: %d vs %d :printf #136\n",ft_printf("|%+- 07.6s|\t", s),		printf("|%+- 07.6s|\t", s));
//	printf("ft_printf: %d vs %d :printf #137\n",ft_printf("|%-+ 08.6s|\t", s),		printf("|%-+ 08.6s|\t", s));
//	printf("ft_printf: %d vs %d :printf #138\n",ft_printf("|% +-09.6s|\t", s),		printf("|% +-09.6s|\t", s));
//	printf("ft_printf: %d vs %d :printf #139\n",ft_printf("|%0-+ 10.6s|\t", s),		printf("|%0-+ 10.6s|\t", s));
//	printf("ft_printf: %d vs %d :printf #140\n",ft_printf("|%+0- 11.6s|\t", s),		printf("|%+0- 11.6s|\t", s));
//	printf("ft_printf: %d vs %d :printf #141\n",ft_printf("|%-0+ 12.6s|\t", s),		printf("|%-0+ 12.6s|\t", s));

//	int n = 0;
//	printf("-------------------------------------D_BASICS---------------------------------------\n");
//	printf("For int n: %d\n", n);
//	printf("ft_printf: %d vs %d :printf #1\n",ft_printf("|%d|\t", n),		printf("|%d|\t", n));
//	printf("ft_printf: %d vs %d :printf #2\n",ft_printf("|%1d|\t", n),		printf("|%1d|\t", n));
//	printf("ft_printf: %d vs %d :printf #3\n",ft_printf("|%2d|\t", n),		printf("|%2d|\t", n));
//	printf("ft_printf: %d vs %d :printf #4\n",ft_printf("|%3d|\t", n),		printf("|%3d|\t", n));
//	printf("ft_printf: %d vs %d :printf #5\n",ft_printf("|%+d|\t", n),		printf("|%+d|\t", n));
//	printf("ft_printf: %d vs %d :printf #6\n",ft_printf("|%+1d|\t", n),		printf("|%+1d|\t", n));
//	printf("ft_printf: %d vs %d :printf #7\n",ft_printf("|%+2d|\t", n),		printf("|%+2d|\t", n));
//	printf("ft_printf: %d vs %d :printf #8\n",ft_printf("|%+3d|\t", n),		printf("|%+3d|\t", n));
//	printf("ft_printf: %d vs %d :printf #9\n",ft_printf("|% d|\t", n),		printf("|% d|\t", n));
//	printf("ft_printf: %d vs %d :printf #10\n",ft_printf("|% 1d|\t", n),	printf("|% 1d|\t", n));
//	printf("ft_printf: %d vs %d :printf #11\n",ft_printf("|% 2d|\t", n),	printf("|% 2d|\t", n));
//	printf("ft_printf: %d vs %d :printf #12\n",ft_printf("|% 3d|\t", n),	printf("|% 3d|\t", n));
//	printf("ft_printf: %d vs %d :printf #13\n",ft_printf("|%-d|\t", n),		printf("|%-d|\t", n));
//	printf("ft_printf: %d vs %d :printf #14\n",ft_printf("|%-1d|\t", n),	printf("|%-1d|\t", n));
//	printf("ft_printf: %d vs %d :printf #15\n",ft_printf("|%-2d|\t", n),	printf("|%-2d|\t", n));
//	printf("ft_printf: %d vs %d :printf #16\n",ft_printf("|%-3d|\t", n),	printf("|%-3d|\t", n));
//	printf("ft_printf: %d vs %d :printf #17\n",ft_printf("|%+-d|\t", n),	printf("|%+-d|\t", n));
//	printf("ft_printf: %d vs %d :printf #18\n",ft_printf("|%+-1d|\t", n),	printf("|%+-1d|\t", n));
//	printf("ft_printf: %d vs %d :printf #19\n",ft_printf("|%+-2d|\t", n),	printf("|%+-2d|\t", n));
//	printf("ft_printf: %d vs %d :printf #20\n",ft_printf("|%+-3d|\t", n),	printf("|%+-3d|\t", n));
//	printf("ft_printf: %d vs %d :printf #21\n",ft_printf("|%+0d|\t", n),	printf("|%+0d|\t", n));
//	printf("ft_printf: %d vs %d :printf #22\n",ft_printf("|%+01d|\t", n),	printf("|%+01d|\t", n));
//	printf("ft_printf: %d vs %d :printf #23\n",ft_printf("|%+02d|\t", n),	printf("|%+02d|\t", n));
//	printf("ft_printf: %d vs %d :printf #24\n",ft_printf("|%+03d|\t", n),	printf("|%+03d|\t", n));
//	printf("ft_printf: %d vs %d :printf #25\n",ft_printf("|%0d|\t", n),		printf("|%0d|\t", n));
//	printf("ft_printf: %d vs %d :printf #26\n",ft_printf("|% 0d|\t", n),	printf("|% 0d|\t", n));
//	printf("ft_printf: %d vs %d :printf #27\n",ft_printf("|% 01d|\t", n),	printf("|% 01d|\t", n));
//	printf("ft_printf: %d vs %d :printf #28\n",ft_printf("|% 02d|\t", n),	printf("|% 02d|\t", n));//check me
//	printf("ft_printf: %d vs %d :printf #29\n",ft_printf("|% 03d|\t", n),	printf("|% 03d|\t", n));
//	printf("ft_printf: %d vs %d :printf #30\n",ft_printf("|%+- 0d|\t", n),	printf("|%+- 0d|\t", n));
//	printf("ft_printf: %d vs %d :printf #31\n",ft_printf("|%+- 01d|\t", n),	printf("|%+- 01d|\t", n));
//	printf("ft_printf: %d vs %d :printf #32\n",ft_printf("|%01d|\t", n),	printf("|%01d|\t", n));
//	printf("ft_printf: %d vs %d :printf #33\n",ft_printf("|%02d|\t", n),	printf("|%02d|\t", n));
//	printf("ft_printf: %d vs %d :printf #34\n",ft_printf("|%03d|\t", n),	printf("|%03d|\t", n));
//	printf("ft_printf: %d vs %d :printf #35\n",ft_printf("|%04d|\t", n),	printf("|%04d|\t", n));
//	printf("ft_printf: %d vs %d :printf #36\n",ft_printf("|%.d|\t", n),		printf("|%.d|\t", n));//start precision checking
//	printf("ft_printf: %d vs %d :printf #37\n",ft_printf("|%.1d|\t", n),	printf("|%.1d|\t", n));
//	printf("ft_printf: %d vs %d :printf #38\n",ft_printf("|%.2d|\t", n),	printf("|%.2d|\t", n));
//	printf("ft_printf: %d vs %d :printf #39\n",ft_printf("|%.3d|\t", n),	printf("|%.3d|\t", n));
//	printf("ft_printf: %d vs %d :printf #40\n",ft_printf("|%.4d|\t", n),	printf("|%.4d|\t", n));
//	printf("ft_printf: %d vs %d :printf #41\n",ft_printf("|%0.d|\t", n),	printf("|%0.d|\t", n));
//	printf("ft_printf: %d vs %d :printf #42\n",ft_printf("|%0.1d|\t", n),	printf("|%0.1d|\t", n));
//	printf("ft_printf: %d vs %d :printf #43\n",ft_printf("|%0.2d|\t", n),	printf("|%0.2d|\t", n));
//	printf("ft_printf: %d vs %d :printf #44\n",ft_printf("|%0.3d|\t", n),	printf("|%0.3d|\t", n));
//	printf("ft_printf: %d vs %d :printf #45\n",ft_printf("|%0.4d|\t", n),	printf("|%0.4d|\t", n));
//	printf("ft_printf: %d vs %d :printf #46\n",ft_printf("|%1.4d|\t", n),	printf("|%1.4d|\t", n));
//	printf("ft_printf: %d vs %d :printf #47\n",ft_printf("|%2.4d|\t", n),	printf("|%2.4d|\t", n));
//	printf("ft_printf: %d vs %d :printf #48\n",ft_printf("|%3.4d|\t", n),	printf("|%3.4d|\t", n));
//	printf("ft_printf: %d vs %d :printf #49\n",ft_printf("|%4.4d|\t", n),	printf("|%4.4d|\t", n));
//	printf("ft_printf: %d vs %d :printf #50\n",ft_printf("|%5.4d|\t", n),	printf("|%5.4d|\t", n));
//	printf("ft_printf: %d vs %d :printf #51\n",ft_printf("|%6.4d|\t", n),	printf("|%6.4d|\t", n));
//	printf("ft_printf: %d vs %d :printf #52\n",ft_printf("|%7.4d|\t", n),	printf("|%7.4d|\t", n));
//	printf("ft_printf: %d vs %d :printf #53\n",ft_printf("|%1.1d|\t", n),	printf("|%1.1d|\t", n));
//	printf("ft_printf: %d vs %d :printf #54\n",ft_printf("|%2.1d|\t", n),	printf("|%2.1d|\t", n));
//	printf("ft_printf: %d vs %d :printf #55\n",ft_printf("|%3.1d|\t", n),	printf("|%3.1d|\t", n));
//	printf("ft_printf: %d vs %d :printf #56\n",ft_printf("|%4.1d|\t", n),	printf("|%4.1d|\t", n));
//	printf("ft_printf: %d vs %d :printf #57\n",ft_printf("|%5.1d|\t", n),	printf("|%5.1d|\t", n));
//	printf("ft_printf: %d vs %d :printf #58\n",ft_printf("|%6.1d|\t", n),	printf("|%6.1d|\t", n));
//	printf("ft_printf: %d vs %d :printf #59\n",ft_printf("|%7.1d|\t", n),	printf("|%7.1d|\t", n));
//	printf("ft_printf: %d vs %d :printf #60\n",ft_printf("|%01.4d|\t", n),	printf("|%01.4d|\t", n));
//	printf("ft_printf: %d vs %d :printf #61\n",ft_printf("|%02.4d|\t", n),	printf("|%02.4d|\t", n));
//	printf("ft_printf: %d vs %d :printf #62\n",ft_printf("|%03.4d|\t", n),	printf("|%03.4d|\t", n));
//	printf("ft_printf: %d vs %d :printf #63\n",ft_printf("|%04.4d|\t", n),	printf("|%04.4d|\t", n));
//	printf("ft_printf: %d vs %d :printf #64\n",ft_printf("|%05.4d|\t", n),	printf("|%05.4d|\t", n));
//	printf("ft_printf: %d vs %d :printf #65\n",ft_printf("|%06.4d|\t", n),	printf("|%06.4d|\t", n));
//	printf("ft_printf: %d vs %d :printf #66\n",ft_printf("|%05.d|\t", n),	printf("|%05.d|\t", n));
//	printf("ft_printf: %d vs %d :printf #67\n",ft_printf("|%1.d|\t", n),	printf("|%1.d|\t", n));
//	printf("ft_printf: %d vs %d :printf #68\n",ft_printf("|%2.d|\t", n),	printf("|%2.d|\t", n));
//	printf("ft_printf: %d vs %d :printf #69\n",ft_printf("|%3.d|\t", n),	printf("|%3.d|\t", n));
//	printf("ft_printf: %d vs %d :printf #70\n",ft_printf("|%4.d|\t", n),	printf("|%4.d|\t", n));
//	printf("ft_printf: %d vs %d :printf #71\n",ft_printf("|%5.d|\t", n),	printf("|%5.d|\t", n));
//	printf("ft_printf: %d vs %d :printf #72\n",ft_printf("|%+.d|\t", n),	printf("|%+.d|\t", n));
//	printf("ft_printf: %d vs %d :printf #73\n",ft_printf("|%+1.2d|\t", n),	printf("|%+1.2d|\t", n));
//	printf("ft_printf: %d vs %d :printf #74\n",ft_printf("|%+2.2d|\t", n),	printf("|%+2.2d|\t", n));
//	printf("ft_printf: %d vs %d :printf #75\n",ft_printf("|%+3.2d|\t", n),	printf("|%+3.2d|\t", n));
//	printf("ft_printf: %d vs %d :printf #76\n",ft_printf("|%+4.2d|\t", n),	printf("|%+4.2d|\t", n));
//	printf("ft_printf: %d vs %d :printf #77\n",ft_printf("|%+01.d|\t", n),	printf("|%+01.d|\t", n));
//	printf("ft_printf: %d vs %d :printf #78\n",ft_printf("|%+02.d|\t", n),	printf("|%+02.d|\t", n));
//	printf("ft_printf: %d vs %d :printf #79\n",ft_printf("|%+03.d|\t", n),	printf("|%+03.d|\t", n));
//	printf("ft_printf: %d vs %d :printf #80\n",ft_printf("|%+04.d|\t", n),	printf("|%+04.d|\t", n));
//	printf("ft_printf: %d vs %d :printf #81\n",ft_printf("|%+04.4d|\t", n),	printf("|%+04.4d|\t", n));
//	printf("ft_printf: %d vs %d :printf #82\n",ft_printf("|%+05.4d|\t", n),	printf("|%+05.4d|\t", n));
//	printf("ft_printf: %d vs %d :printf #83\n",ft_printf("|%+06.4d|\t", n),	printf("|%+06.4d|\t", n));
//	printf("ft_printf: %d vs %d :printf #84\n",ft_printf("|%+07.4d|\t", n),	printf("|%+07.4d|\t", n));
//	printf("ft_printf: %d vs %d :printf #85\n",ft_printf("|%+01.4d|\t", n),	printf("|%+01.4d|\t", n));
//	printf("ft_printf: %d vs %d :printf #86\n",ft_printf("|%+02.4d|\t", n),	printf("|%+02.4d|\t", n));
//	printf("ft_printf: %d vs %d :printf #87\n",ft_printf("|%+03.4d|\t", n),	printf("|%+03.4d|\t", n));
//	printf("ft_printf: %d vs %d :printf #88\n",ft_printf("|%+04.4d|\t", n),	printf("|%+04.4d|\t", n));
//	printf("ft_printf: %d vs %d :printf #89\n",ft_printf("|%+-1.4d|\t", n),	printf("|%+-1.4d|\t", n));
//	printf("ft_printf: %d vs %d :printf #90\n",ft_printf("|%+-2.4d|\t", n),	printf("|%+-2.4d|\t", n));
//	printf("ft_printf: %d vs %d :printf #91\n",ft_printf("|%+-3.4d|\t", n),	printf("|%+-3.4d|\t", n));
//	printf("ft_printf: %d vs %d :printf #92\n",ft_printf("|%+-4.4d|\t", n),	printf("|%+-4.4d|\t", n));
//	printf("ft_printf: %d vs %d :printf #93\n",ft_printf("|%+-5.4d|\t", n),	printf("|%+-5.4d|\t", n));
//	printf("ft_printf: %d vs %d :printf #94\n",ft_printf("|%+-6.4d|\t", n),	printf("|%+-6.4d|\t", n));
//	printf("ft_printf: %d vs %d :printf #95\n",ft_printf("|%+-01.4d|\t", n),	printf("|%+-01.4d|\t", n));
//	printf("ft_printf: %d vs %d :printf #96\n",ft_printf("|%+-02.4d|\t", n),	printf("|%+-02.4d|\t", n));
//	printf("ft_printf: %d vs %d :printf #97\n",ft_printf("|%+-03.4d|\t", n),	printf("|%+-03.4d|\t", n));
//	printf("ft_printf: %d vs %d :printf #98\n",ft_printf("|%+-04.4d|\t", n),	printf("|%+-04.4d|\t", n));
//	printf("ft_printf: %d vs %d :printf #99\n",ft_printf("|%+-05.4d|\t", n),	printf("|%+-05.4d|\t", n));
//	printf("ft_printf: %d vs %d :printf #100\n",ft_printf("|%+-06.4d|\t", n),	printf("|%+-06.4d|\t", n));
//	printf("ft_printf: %d vs %d :printf #101\n",ft_printf("|%+-.d|\t", n),	printf("|%+-.d|\t", n));
//	printf("ft_printf: %d vs %d :printf #102\n",ft_printf("|%+-1.d|\t", n),	printf("|%+-1.d|\t", n));
//	printf("ft_printf: %d vs %d :printf #103\n",ft_printf("|%+-2.d|\t", n),	printf("|%+-2.d|\t", n));
//	printf("ft_printf: %d vs %d :printf #104\n",ft_printf("|%+-3.d|\t", n),	printf("|%+-3.d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%+-4.d|\t", n),	printf("|%+-4.d|\t", n));
//	// basic single flags
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%+d|\t", n),	printf("|%+d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|% d|\t", n),	printf("|% d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%-d|\t", n),	printf("|%-d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%0d|\t", n),	printf("|%0d|\t", n));
//	// basic single multiples flags
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%++d|\t", n),	printf("|%++d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%+++d|\t", n),	printf("|%+++d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%++++d|\t", n),	printf("|%++++d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%+++++d|\t", n),	printf("|%+++++d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%++++++d|\t", n),	printf("|%++++++d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%+++++++d|\t", n),	printf("|%+++++++d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%  d|\t", n),	printf("|%  d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%   d|\t", n),	printf("|%   d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%    d|\t", n),	printf("|%    d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%     d|\t", n),	printf("|%     d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%      d|\t", n),	printf("|%      d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%       d|\t", n),	printf("|%       d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%--d|\t", n),	printf("|%--d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%---d|\t", n),	printf("|%---d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%----d|\t", n),	printf("|%----d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%-----d|\t", n),	printf("|%-----d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%------d|\t", n),	printf("|%------d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%-------d|\t", n),	printf("|%-------d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%00d|\t", n),	printf("|%00d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%000d|\t", n),	printf("|%000d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%0000d|\t", n),	printf("|%0000d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%00000d|\t", n),	printf("|%00000d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%000000d|\t", n),	printf("|%000000d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%0000000d|\t", n),	printf("|%0000000d|\t", n));
//	// plus flag with basic width
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%+1d|\t", n),	printf("|%+1d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%+2d|\t", n),	printf("|%+2d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%+3d|\t", n),	printf("|%+3d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%+4d|\t", n),	printf("|%+4d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%+5d|\t", n),	printf("|%+5d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%+6d|\t", n),	printf("|%+6d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%+7d|\t", n),	printf("|%+7d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%+8d|\t", n),	printf("|%+8d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%+9d|\t", n),	printf("|%+9d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%+10d|\t", n),	printf("|%+10d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%+11d|\t", n),	printf("|%+11d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%+12d|\t", n),	printf("|%+12d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%+13d|\t", n),	printf("|%+13d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%+14d|\t", n),	printf("|%+14d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%+15d|\t", n),	printf("|%+15d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%+16d|\t", n),	printf("|%+16d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%+17d|\t", n),	printf("|%+17d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%+18d|\t", n),	printf("|%+18d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%+19d|\t", n),	printf("|%+19d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%+20d|\t", n),	printf("|%+20d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%+21d|\t", n),	printf("|%+21d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%+22d|\t", n),	printf("|%+22d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%+10000d|\t", n),	printf("|%+10000d|\t", n));//counter malloc
//	// space flag with basic width
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|% 1d|\t", n),	printf("|% 1d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|% 2d|\t", n),	printf("|% 2d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|% 3d|\t", n),	printf("|% 3d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|% 4d|\t", n),	printf("|% 4d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|% 5d|\t", n),	printf("|% 5d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|% 6d|\t", n),	printf("|% 6d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|% 7d|\t", n),	printf("|% 7d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|% 8d|\t", n),	printf("|% 8d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|% 9d|\t", n),	printf("|% 9d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|% 10d|\t", n),	printf("|% 10d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|% 11d|\t", n),	printf("|% 11d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|% 12d|\t", n),	printf("|% 12d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|% 13d|\t", n),	printf("|% 13d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|% 14d|\t", n),	printf("|% 14d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|% 15d|\t", n),	printf("|% 15d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|% 16d|\t", n),	printf("|% 16d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|% 17d|\t", n),	printf("|% 17d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|% 18d|\t", n),	printf("|% 18d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|% 19d|\t", n),	printf("|% 19d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|% 20d|\t", n),	printf("|% 20d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|% 21d|\t", n),	printf("|% 21d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|% 22d|\t", n),	printf("|% 22d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|% 10000d|\t", n),	printf("|% 10000d|\t", n));
//	// minus flag with basic width
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%-1d|\t", n),	printf("|%-1d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%-2d|\t", n),	printf("|%-2d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%-3d|\t", n),	printf("|%-3d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%-4d|\t", n),	printf("|%-4d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%-5d|\t", n),	printf("|%-5d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%-6d|\t", n),	printf("|%-6d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%-7d|\t", n),	printf("|%-7d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%-8d|\t", n),	printf("|%-8d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%-9d|\t", n),	printf("|%-9d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%-10d|\t", n),	printf("|%-10d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%-11d|\t", n),	printf("|%-11d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%-12d|\t", n),	printf("|%-12d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%-13d|\t", n),	printf("|%-13d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%-14d|\t", n),	printf("|%-14d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%-15d|\t", n),	printf("|%-15d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%-16d|\t", n),	printf("|%-16d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%-17d|\t", n),	printf("|%-17d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%-18d|\t", n),	printf("|%-18d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%-19d|\t", n),	printf("|%-19d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%-20d|\t", n),	printf("|%-20d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%-21d|\t", n),	printf("|%-21d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%-22d|\t", n),	printf("|%-22d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%-10000d|\t", n),	printf("|%-10000d|\t", n));
//	// zero flag with basic width
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%01d|\t", n),	printf("|%01d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%02d|\t", n),	printf("|%02d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%03d|\t", n),	printf("|%03d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%04d|\t", n),	printf("|%04d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%05d|\t", n),	printf("|%05d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%06d|\t", n),	printf("|%06d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%07d|\t", n),	printf("|%07d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%08d|\t", n),	printf("|%08d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%09d|\t", n),	printf("|%09d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%010d|\t", n),	printf("|%010d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%011d|\t", n),	printf("|%011d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%012d|\t", n),	printf("|%012d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%013d|\t", n),	printf("|%013d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%014d|\t", n),	printf("|%014d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%015d|\t", n),	printf("|%015d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%016d|\t", n),	printf("|%016d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%017d|\t", n),	printf("|%017d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%018d|\t", n),	printf("|%018d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%019d|\t", n),	printf("|%019d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%020d|\t", n),	printf("|%020d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%021d|\t", n),	printf("|%021d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%022d|\t", n),	printf("|%022d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%010000d|\t", n),	printf("|%010000d|\t", n));
//	// plus flag with basic precision
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%+.d|\t", n),	printf("|%+.d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%+.1d|\t", n),	printf("|%+.1d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%+.2d|\t", n),	printf("|%+.2d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%+.3d|\t", n),	printf("|%+.3d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%+.4d|\t", n),	printf("|%+.4d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%+.5d|\t", n),	printf("|%+.5d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%+.6d|\t", n),	printf("|%+.6d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%+.7d|\t", n),	printf("|%+.7d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%+.8d|\t", n),	printf("|%+.8d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%+.9d|\t", n),	printf("|%+.9d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%+.10d|\t", n),	printf("|%+.10d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%+.11d|\t", n),	printf("|%+.11d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%+.12d|\t", n),	printf("|%+.12d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%+.13d|\t", n),	printf("|%+.13d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%+.14d|\t", n),	printf("|%+.14d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%+.15d|\t", n),	printf("|%+.15d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%+.16d|\t", n),	printf("|%+.16d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%+.17d|\t", n),	printf("|%+.17d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%+.18d|\t", n),	printf("|%+.18d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%+.19d|\t", n),	printf("|%+.19d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%+.20d|\t", n),	printf("|%+.20d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%+.21d|\t", n),	printf("|%+.21d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%+.22d|\t", n),	printf("|%+.22d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%+.10000d|\t", n),	printf("|%+.10000d|\t", n));
//	// minus flag with basic precision
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%-.d|\t", n),	printf("|%-.d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%-.1d|\t", n),	printf("|%-.1d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%-.2d|\t", n),	printf("|%-.2d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%-.3d|\t", n),	printf("|%-.3d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%-.4d|\t", n),	printf("|%-.4d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%-.5d|\t", n),	printf("|%-.5d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%-.6d|\t", n),	printf("|%-.6d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%-.7d|\t", n),	printf("|%-.7d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%-.8d|\t", n),	printf("|%-.8d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%-.9d|\t", n),	printf("|%-.9d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%-.10d|\t", n),	printf("|%-.10d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%-.11d|\t", n),	printf("|%-.11d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%-.12d|\t", n),	printf("|%-.12d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%-.13d|\t", n),	printf("|%-.13d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%-.14d|\t", n),	printf("|%-.14d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%-.15d|\t", n),	printf("|%-.15d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%-.16d|\t", n),	printf("|%-.16d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%-.17d|\t", n),	printf("|%-.17d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%-.18d|\t", n),	printf("|%-.18d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%-.19d|\t", n),	printf("|%-.19d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%-.20d|\t", n),	printf("|%-.20d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%-.21d|\t", n),	printf("|%-.21d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%-.22d|\t", n),	printf("|%-.22d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%-.10000d|\t", n),	printf("|%-.10000d|\t", n));
//	// zero flag with basic precision
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%0.d|\t", n),	printf("|%0.d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%0.1d|\t", n),	printf("|%0.1d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%0.2d|\t", n),	printf("|%0.2d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%0.3d|\t", n),	printf("|%0.3d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%0.4d|\t", n),	printf("|%0.4d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%0.5d|\t", n),	printf("|%0.5d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%0.6d|\t", n),	printf("|%0.6d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%0.7d|\t", n),	printf("|%0.7d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%0.8d|\t", n),	printf("|%0.8d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%0.9d|\t", n),	printf("|%0.9d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%0.10d|\t", n),	printf("|%0.10d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%0.11d|\t", n),	printf("|%0.11d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%0.12d|\t", n),	printf("|%0.12d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%0.13d|\t", n),	printf("|%0.13d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%0.14d|\t", n),	printf("|%0.14d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%0.15d|\t", n),	printf("|%0.15d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%0.16d|\t", n),	printf("|%0.16d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%0.17d|\t", n),	printf("|%0.17d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%0.18d|\t", n),	printf("|%0.18d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%0.19d|\t", n),	printf("|%0.19d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%0.20d|\t", n),	printf("|%0.20d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%0.21d|\t", n),	printf("|%0.21d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%0.22d|\t", n),	printf("|%0.22d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%0.10000d|\t", n),	printf("|%0.10000d|\t", n));
//	// space flag with basic precision
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|% .d|\t", n),	printf("|% .d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|% .1d|\t", n),	printf("|% .1d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|% .2d|\t", n),	printf("|% .2d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|% .3d|\t", n),	printf("|% .3d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|% .4d|\t", n),	printf("|% .4d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|% .5d|\t", n),	printf("|% .5d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|% .6d|\t", n),	printf("|% .6d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|% .7d|\t", n),	printf("|% .7d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|% .8d|\t", n),	printf("|% .8d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|% .9d|\t", n),	printf("|% .9d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|% .10d|\t", n),	printf("|% .10d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|% .11d|\t", n),	printf("|% .11d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|% .12d|\t", n),	printf("|% .12d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|% .13d|\t", n),	printf("|% .13d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|% .14d|\t", n),	printf("|% .14d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|% .15d|\t", n),	printf("|% .15d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|% .16d|\t", n),	printf("|% .16d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|% .17d|\t", n),	printf("|% .17d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|% .18d|\t", n),	printf("|% .18d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|% .19d|\t", n),	printf("|% .19d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|% .20d|\t", n),	printf("|% .20d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|% .21d|\t", n),	printf("|% .21d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|% .22d|\t", n),	printf("|% .22d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|% .10000d|\t", n),	printf("|% .10000d|\t", n));
//	// width vs no precision
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%1.d|\t", n),	printf("|%1.d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%2.d|\t", n),	printf("|%2.d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%3.d|\t", n),	printf("|%3.d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%4.d|\t", n),	printf("|%4.d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%5.d|\t", n),	printf("|%5.d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%6.d|\t", n),	printf("|%6.d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%7.d|\t", n),	printf("|%7.d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%8.d|\t", n),	printf("|%8.d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%9.d|\t", n),	printf("|%9.d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%10000.d|\t", n),	printf("|%10000.d|\t", n));
//	// minus flag width vs no precision
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%-1.d|\t", n),	printf("|%-1.d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%-2.d|\t", n),	printf("|%-2.d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%-3.d|\t", n),	printf("|%-3.d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%-4.d|\t", n),	printf("|%-4.d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%-5.d|\t", n),	printf("|%-5.d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%-6.d|\t", n),	printf("|%-6.d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%-7.d|\t", n),	printf("|%-7.d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%-8.d|\t", n),	printf("|%-8.d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%-9.d|\t", n),	printf("|%-9.d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%-10000.d|\t", n),	printf("|%-10000.d|\t", n));
//	// width vs precision 1
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%1.1d|\t", n),	printf("|%1.1d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%2.1d|\t", n),	printf("|%2.1d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%3.1d|\t", n),	printf("|%3.1d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%4.1d|\t", n),	printf("|%4.1d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%5.1d|\t", n),	printf("|%5.1d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%6.1d|\t", n),	printf("|%6.1d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%7.1d|\t", n),	printf("|%7.1d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%10000.1d|\t", n),	printf("|%10000.1d|\t", n));
//	// minus flag with vs precision 1
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%-1.1d|\t", n),	printf("|%-1.1d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%-2.1d|\t", n),	printf("|%-2.1d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%-3.1d|\t", n),	printf("|%-3.1d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%-4.1d|\t", n),	printf("|%-4.1d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%-5.1d|\t", n),	printf("|%-5.1d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%-6.1d|\t", n),	printf("|%-6.1d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%-7.1d|\t", n),	printf("|%-7.1d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%-10000.1d|\t", n),	printf("|%-10000.1d|\t", n));
//	// width vs lower precision
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%1.3d|\t", n),	printf("|%1.3d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%2.5d|\t", n),	printf("|%2.5d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%3.7d|\t", n),	printf("|%3.7d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%4.9d|\t", n),	printf("|%4.9d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%5.11d|\t", n),	printf("|%5.11d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%6.13d|\t", n),	printf("|%6.13d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%7.15d|\t", n),	printf("|%7.15d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%7.10000d|\t", n),	printf("|%7.1000d|\t", n));
//	// minus flag width vs lower precision
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%-1.3d|\t", n),	printf("|%-1.3d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%-2.5d|\t", n),	printf("|%-2.5d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%-3.7d|\t", n),	printf("|%-3.7d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%-4.9d|\t", n),	printf("|%-4.9d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%-5.11d|\t", n),	printf("|%-5.11d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%-6.13d|\t", n),	printf("|%-6.13d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%-7.15d|\t", n),	printf("|%-7.15d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%-7.10000d|\t", n),	printf("|%-7.10000d|\t", n));
//	// zero flag width vs no precision
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%01.d|\t", n),	printf("|%01.d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%02.d|\t", n),	printf("|%02.d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%03.d|\t", n),	printf("|%03.d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%04.d|\t", n),	printf("|%04.d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%05.d|\t", n),	printf("|%05.d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%06.d|\t", n),	printf("|%06.d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%07.d|\t", n),	printf("|%07.d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%08.d|\t", n),	printf("|%08.d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%09.d|\t", n),	printf("|%09.d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%010000.d|\t", n),	printf("|%010000.d|\t", n));
//	// minus zero flag with no precision
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%-01.d|\t", n),	printf("|%-01.d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%-02.d|\t", n),	printf("|%-02.d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%-03.d|\t", n),	printf("|%-03.d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%-04.d|\t", n),	printf("|%-04.d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%-05.d|\t", n),	printf("|%-05.d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%-06.d|\t", n),	printf("|%-06.d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%-07.d|\t", n),	printf("|%-07.d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%-08.d|\t", n),	printf("|%-08.d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%-09.d|\t", n),	printf("|%-09.d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%-010000.d|\t", n),	printf("|%-010000.d|\t", n));
//	// zero minus flag with no precision
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%0-1.d|\t", n),	printf("|%0-1.d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%0-2.d|\t", n),	printf("|%0-2.d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%0-3.d|\t", n),	printf("|%0-3.d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%0-4.d|\t", n),	printf("|%0-4.d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%0-5.d|\t", n),	printf("|%0-5.d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%0-6.d|\t", n),	printf("|%0-6.d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%0-7.d|\t", n),	printf("|%0-7.d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%0-8.d|\t", n),	printf("|%0-8.d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%0-9.d|\t", n),	printf("|%0-9.d|\t", n));
//	printf("ft_printf: %d vs %d :printf #105\n",ft_printf("|%0-10000.d|\t", n),	printf("|%0-10000.d|\t", n));
//	printf("ft_printf: %d vs %d :printf",ft_printf("%d%+d%-d% d%0d%++++d%----d%0000d%    d%+  +d% ++ d%0--0d%-00-d%+--+d%0  0d%0+- d%0+ -d%0-+ d%0- +d%0 -+d%0 +-d%+0 -d%+0- d%+-0 d%+- 0d%+ 0-d%+ -0d%-0+ d%-0 +d%-+0 d%-+ 0d%- +0d%- 0+d% 0+-d% 0-+d% +0-d% +-0d% -+0d% -0+d%1d%2d%3d%5d%10d%19d%20d%22d%-1d%-2d%-3d%-5d%-10d%-19d%-20d%-22d%.1d%.2d%.3d%.5d%.10d%.19d%.20d%.22d%1.2d%2.3d%3.4d%5.6d%10.11d%19.20d%20.21d%22.23d%1.d%2.1d%3.2d%5.4d%10.9d%19.18d%20.19d%22.21d%1.1d%2.2d%3.3d%5.5d%10.10d%19.19d%20.20d%22.22d%-1.2d%-2.3d%-3.4d%-5.6d%-10.11d%-19.20d%-20.21d%-22.23d%-1.d%-2.1d%-3.2d%-5.4d%-10.9d%-19.18d%-20.19d%-22.21d%-1.1d%-2.2d%-3.3d%-5.5d%-10.10d%-19.19d%-20.20d%-22.22d%01d%02d%03d%05d%010d%019d%020d%022d%-01d%-20d%-03d%-05d%-010d%-019d%-020d%-022d%01.d%02.1d%03.2d%05.4d%010.9d%019.18d%020.19d%022.21d%-02.1d%-03.2d%-05.4d%-010.9d%-019.18d%-020.19d%-022.21d%01.2d%02.3d%03.4d%05.6d%010.11d%019.20d%020.21d%022.23d%-01.2d%-02.3d%-03.4d%-05.6d%-010.11d%-019.20d%-020.21d%-022.23d%01.1d%02.2d%03.3d%05.5d%010.10d%019.19d%020.20d%022.22d%-01.1d%-02.2d%-03.3d%-05.5d%-010.10d%-019.19d%-020.20d%-022.22d%+.d%+1.d%+2.d%+3.d%+20.d%+.1d%+.2d%+.3d%+.20d%+1.1d%+2.2d%+3.3d%+20.20d%+2.1d%+3.1d%+20.1d%+3.2d%+4.3d%+20.6d%+1.2d%+3.4d%+6.9d%+15.20d%+0.d%+01.d%+02.d%+03.d%+020.d%+0.1d%+0.2d%+0.3d%+0.20d%+01.1d%+02.2d%+03.3d%+020.20d%+02.1d%+03.1d%+020.1d%+03.2d%+04.3d%+020.6d%+01.2d%+03.4d%+06.9d%+015.20d% 0.d% 01.d% 02.d% 03.d% 020.d% 0.1d% 0.2d% 0.3d% 0.20d% 01.1d% 02.2d% 03.3d% 020.20d% 02.1d% 03.1d% 020.1d% 03.2d% 04.3d% 020.6d% 01.2d% 03.4d% 06.9d% 015.20d%+ d% +d%0-d%-0d",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0),printf("%d%+d%-d% d%0d%++++d%----d%0000d%    d%+  +d% ++ d%0--0d%-00-d%+--+d%0  0d%0+- d%0+ -d%0-+ d%0- +d%0 -+d%0 +-d%+0 -d%+0- d%+-0 d%+- 0d%+ 0-d%+ -0d%-0+ d%-0 +d%-+0 d%-+ 0d%- +0d%- 0+d% 0+-d% 0-+d% +0-d% +-0d% -+0d% -0+d%1d%2d%3d%5d%10d%19d%20d%22d%-1d%-2d%-3d%-5d%-10d%-19d%-20d%-22d%.1d%.2d%.3d%.5d%.10d%.19d%.20d%.22d%1.2d%2.3d%3.4d%5.6d%10.11d%19.20d%20.21d%22.23d%1.d%2.1d%3.2d%5.4d%10.9d%19.18d%20.19d%22.21d%1.1d%2.2d%3.3d%5.5d%10.10d%19.19d%20.20d%22.22d%-1.2d%-2.3d%-3.4d%-5.6d%-10.11d%-19.20d%-20.21d%-22.23d%-1.d%-2.1d%-3.2d%-5.4d%-10.9d%-19.18d%-20.19d%-22.21d%-1.1d%-2.2d%-3.3d%-5.5d%-10.10d%-19.19d%-20.20d%-22.22d%01d%02d%03d%05d%010d%019d%020d%022d%-01d%-20d%-03d%-05d%-010d%-019d%-020d%-022d%01.d%02.1d%03.2d%05.4d%010.9d%019.18d%020.19d%022.21d%-02.1d%-03.2d%-05.4d%-010.9d%-019.18d%-020.19d%-022.21d%01.2d%02.3d%03.4d%05.6d%010.11d%019.20d%020.21d%022.23d%-01.2d%-02.3d%-03.4d%-05.6d%-010.11d%-019.20d%-020.21d%-022.23d%01.1d%02.2d%03.3d%05.5d%010.10d%019.19d%020.20d%022.22d%-01.1d%-02.2d%-03.3d%-05.5d%-010.10d%-019.19d%-020.20d%-022.22d%+.d%+1.d%+2.d%+3.d%+20.d%+.1d%+.2d%+.3d%+.20d%+1.1d%+2.2d%+3.3d%+20.20d%+2.1d%+3.1d%+20.1d%+3.2d%+4.3d%+20.6d%+1.2d%+3.4d%+6.9d%+15.20d%+0.d%+01.d%+02.d%+03.d%+020.d%+0.1d%+0.2d%+0.3d%+0.20d%+01.1d%+02.2d%+03.3d%+020.20d%+02.1d%+03.1d%+020.1d%+03.2d%+04.3d%+020.6d%+01.2d%+03.4d%+06.9d%+015.20d% 0.d% 01.d% 02.d% 03.d% 020.d% 0.1d% 0.2d% 0.3d% 0.20d% 01.1d% 02.2d% 03.3d% 020.20d% 02.1d% 03.1d% 020.1d% 03.2d% 04.3d% 020.6d% 01.2d% 03.4d% 06.9d% 015.20d%+ d% +d%0-d%-0d",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0));

//	printf("-------------------------------------UNSIGNED_INT---------------------------------------\n");
//	unsigned int u = 0;
//	printf("ft_printf: %d vs %d :printf #1\n", ft_printf("|%u|\t", u),	printf("|%u|\t", u));
//	printf("ft_printf: %d vs %d :printf #2\n", ft_printf("|%1u|\t", u),	printf("|%1u|\t", u));
//	printf("ft_printf: %d vs %d :printf #3\n", ft_printf("|%2u|\t", u),	printf("|%2u|\t", u));
//	printf("ft_printf: %d vs %d :printf #4\n", ft_printf("|%3u|\t", u),	printf("|%3u|\t", u));
//	printf("ft_printf: %d vs %d :printf #5\n", ft_printf("|%4u|\t", u),	printf("|%4u|\t", u));
//	printf("ft_printf: %d vs %d :printf #6\n", ft_printf("|%5u|\t", u),	printf("|%5u|\t", u));
//	printf("ft_printf: %d vs %d :printf #7\n", ft_printf("|%20u|\t", u),	printf("|%20u|\t", u));
//	printf("ft_printf: %d vs %d :printf #8\n", ft_printf("|%21u|\t", u),	printf("|%21u|\t", u));
//	printf("ft_printf: %d vs %d :printf #9\n", ft_printf("|%22u|\t", u),	printf("|%22u|\t", u));
//	printf("ft_printf: %d vs %d :printf #10\n", ft_printf("|%23u|\t", u),	printf("|%23u|\t", u));
//	printf("ft_printf: %d vs %d :printf #11\n", ft_printf("|%24u|\t", u),	printf("|%24u|\t", u));
//	printf("ft_printf: %d vs %d :printf #11\n", ft_printf("|%01u|\t", u),	printf("|%01u|\t", u));
//	printf("ft_printf: %d vs %d :printf #11\n", ft_printf("|%02u|\t", u),	printf("|%02u|\t", u));
//	printf("ft_printf: %d vs %d :printf #11\n", ft_printf("|%03u|\t", u),	printf("|%03u|\t", u));
//	printf("ft_printf: %d vs %d :printf #11\n", ft_printf("|%04u|\t", u),	printf("|%04u|\t", u));
//	printf("ft_printf: %d vs %d :printf #11\n", ft_printf("|%05u|\t", u),	printf("|%05u|\t", u));
//	printf("ft_printf: %d vs %d :printf #11\n", ft_printf("|%06u|\t", u),	printf("|%06u|\t", u));
//	printf("ft_printf: %d vs %d :printf #11\n", ft_printf("|%07u|\t", u),	printf("|%07u|\t", u));
//	printf("ft_printf: %d vs %d :printf #11\n", ft_printf("|%10.u|\t", u),	printf("|%10.u|\t", u));
//	printf("ft_printf: %d vs %d :printf #11\n", ft_printf("|%10.1u|\t", u),	printf("|%10.1u|\t", u));
//	printf("ft_printf: %d vs %d :printf #11\n", ft_printf("|%10.2u|\t", u),	printf("|%10.2u|\t", u));
//	printf("ft_printf: %d vs %d :printf #11\n", ft_printf("|%10.3u|\t", u),	printf("|%10.3u|\t", u));
//	printf("ft_printf: %d vs %d :printf #11\n", ft_printf("|%10.4u|\t", u),	printf("|%10.4u|\t", u));
//	printf("ft_printf: %d vs %d :printf #11\n", ft_printf("|%10.5u|\t", u),	printf("|%10.5u|\t", u));
//	printf("ft_printf: %d vs %d :printf #11\n", ft_printf("|%10.6u|\t", u),	printf("|%10.6u|\t", u));
//	printf("ft_printf: %d vs %d :printf #11\n", ft_printf("|%-10.6u|\t", u),	printf("|%-10.6u|\t", u));
//	printf("ft_printf: %d vs %d :printf #11\n", ft_printf("|%-11.6u|\t", u),	printf("|%-11.6u|\t", u));
//	printf("ft_printf: %d vs %d :printf #11\n", ft_printf("|%-12.6u|\t", u),	printf("|%-12.6u|\t", u));
//	printf("ft_printf: %d vs %d :printf #11\n", ft_printf("|%-13.6u|\t", u),	printf("|%-13.6u|\t", u));
//	printf("ft_printf: %d vs %d :printf #11\n", ft_printf("|%-14.6u|\t", u),	printf("|%-14.6u|\t", u));
//	printf("ft_printf: %d vs %d :printf #11\n", ft_printf("|%-15.6u|\t", u),	printf("|%-15.6u|\t", u));
//	printf("ft_printf: %d vs %d :printf #11\n", ft_printf("|%-16.6u|\t", u),	printf("|%-16.6u|\t", u));
//	printf("ft_printf: %d vs %d :printf #11\n", ft_printf("|%06.6u|\t", u),	printf("|%06.6u|\t", u));
//	printf("ft_printf: %d vs %d :printf #11\n", ft_printf("|%07.6u|\t", u),	printf("|%07.6u|\t", u));
//	printf("ft_printf: %d vs %d :printf #11\n", ft_printf("|%08.6u|\t", u),	printf("|%08.6u|\t", u));
//	printf("ft_printf: %d vs %d :printf #11\n", ft_printf("|%09.6u|\t", u),	printf("|%09.6u|\t", u));
//	printf("ft_printf: %d vs %d :printf #11\n", ft_printf("|%010.6u|\t", u),	printf("|%010.6u|\t", u));
//	printf("ft_printf: %d vs %d :printf #11\n", ft_printf("|%011.6u|\t", u),	printf("|%011.6u|\t", u));
//	printf("ft_printf: %d vs %d :printf #11\n", ft_printf("|%-06.6u|\t", u),	printf("|%-06.6u|\t", u));
//	printf("ft_printf: %d vs %d :printf #11\n", ft_printf("|%-07.6u|\t", u),	printf("|%-07.6u|\t", u));
//	printf("ft_printf: %d vs %d :printf #11\n", ft_printf("|%-08.6u|\t", u),	printf("|%-08.6u|\t", u));
//	printf("ft_printf: %d vs %d :printf #11\n", ft_printf("|%-09.6u|\t", u),	printf("|%-09.6u|\t", u));
//	printf("ft_printf: %d vs %d :printf #11\n", ft_printf("|%-010.6u|\t", u),	printf("|%-010.6u|\t", u));
//	printf("ft_printf: %d vs %d :printf #11\n", ft_printf("|%-011.6u|\t", u),	printf("|%-011.6u|\t", u));
//	printf("ft_printf: %d vs %d :printf #11\n", ft_printf("|%06.1u|\t", u),	printf("|%06.1u|\t", u));
//	printf("ft_printf: %d vs %d :printf #11\n", ft_printf("|%06.2u|\t", u),	printf("|%06.2u|\t", u));
//	printf("ft_printf: %d vs %d :printf #11\n", ft_printf("|%06.3u|\t", u),	printf("|%06.3u|\t", u));
//	printf("ft_printf: %d vs %d :printf #11\n", ft_printf("|%06.4u|\t", u),	printf("|%06.4u|\t", u));
//	printf("ft_printf: %d vs %d :printf #11\n", ft_printf("|%06.5u|\t", u),	printf("|%06.5u|\t", u));
//	printf("ft_printf: %d vs %d :printf #11\n", ft_printf("|%-06.1u|\t", u),	printf("|%-06.1u|\t", u));
//	printf("ft_printf: %d vs %d :printf #11\n", ft_printf("|%-06.2u|\t", u),	printf("|%-06.2u|\t", u));
//	printf("ft_printf: %d vs %d :printf #11\n", ft_printf("|%-06.3u|\t", u),	printf("|%-06.3u|\t", u));
//	printf("ft_printf: %d vs %d :printf #11\n", ft_printf("|%-06.4u|\t", u),	printf("|%-06.4u|\t", u));
//	printf("ft_printf: %d vs %d :printf #11\n", ft_printf("|%-06.5u|\t", u),	printf("|%-06.5u|\t", u));
//	// undefbehav below
//	printf("ft_printf: %d vs %d :printf #11\n", ft_printf("|%+06.6u|\t", u),	printf("|%+06.6u|\t", u));
//	printf("ft_printf: %d vs %d :printf #11\n", ft_printf("|%+07.6u|\t", u),	printf("|%+07.6u|\t", u));
//	printf("ft_printf: %d vs %d :printf #11\n", ft_printf("|%+08.6u|\t", u),	printf("|%+08.6u|\t", u));
//	printf("ft_printf: %d vs %d :printf #11\n", ft_printf("|%+09.6u|\t", u),	printf("|%+09.6u|\t", u));
//	printf("ft_printf: %d vs %d :printf #11\n", ft_printf("|%+010.6u|\t", u),	printf("|%+010.6u|\t", u));
//	printf("ft_printf: %d vs %d :printf #11\n", ft_printf("|%+06.1u|\t", u),	printf("|%+06.1u|\t", u));
//	printf("ft_printf: %d vs %d :printf #11\n", ft_printf("|%+06.2u|\t", u),	printf("|%+06.2u|\t", u));
//	printf("ft_printf: %d vs %d :printf #11\n", ft_printf("|%+06.3u|\t", u),	printf("|%+06.3u|\t", u));
//	printf("ft_printf: %d vs %d :printf #11\n", ft_printf("|%+06.4u|\t", u),	printf("|%+06.4u|\t", u));
//	printf("ft_printf: %d vs %d :printf #11\n", ft_printf("|%+06.5u|\t", u),	printf("|%+06.5u|\t", u));
//	printf("ft_printf: %d vs %d :printf #11\n", ft_printf("|% 06.6u|\t", u),	printf("|% 06.6u|\t", u));
//	printf("ft_printf: %d vs %d :printf #11\n", ft_printf("|% 07.6u|\t", u),	printf("|% 07.6u|\t", u));
//	printf("ft_printf: %d vs %d :printf #11\n", ft_printf("|% 08.6u|\t", u),	printf("|% 08.6u|\t", u));
//	printf("ft_printf: %d vs %d :printf #11\n", ft_printf("|% 09.6u|\t", u),	printf("|% 09.6u|\t", u));
//	printf("ft_printf: %d vs %d :printf #11\n", ft_printf("|% 010.6u|\t", u),	printf("|% 010.6u|\t", u));
//	printf("ft_printf: %d vs %d :printf #11\n", ft_printf("|% 06.1u|\t", u),	printf("|% 06.1u|\t", u));
//	printf("ft_printf: %d vs %d :printf #11\n", ft_printf("|% 06.2u|\t", u),	printf("|% 06.2u|\t", u));
//	printf("ft_printf: %d vs %d :printf #11\n", ft_printf("|% 06.3u|\t", u),	printf("|% 06.3u|\t", u));
//	printf("ft_printf: %d vs %d :printf #11\n", ft_printf("|% 06.4u|\t", u),	printf("|% 06.4u|\t", u));
//	printf("ft_printf: %d vs %d :printf #11\n", ft_printf("|% 06.5u|\t", u),	printf("|% 06.5u|\t", u));
//	// flag cancelling
//	printf("ft_printf: %d vs %d :printf #11\n", ft_printf("|% +06.6u|\t", u),	printf("|% +06.6u|\t", u));
//	printf("ft_printf: %d vs %d :printf #11\n", ft_printf("|% +07.6u|\t", u),	printf("|% +07.6u|\t", u));
//	printf("ft_printf: %d vs %d :printf #11\n", ft_printf("|% +08.6u|\t", u),	printf("|% +08.6u|\t", u));
//	printf("ft_printf: %d vs %d :printf #11\n", ft_printf("|% +09.6u|\t", u),	printf("|% +09.6u|\t", u));
//	printf("ft_printf: %d vs %d :printf #11\n", ft_printf("|% +010.6u|\t", u),	printf("|% +010.6u|\t", u));
//	printf("ft_printf: %d vs %d :printf #11\n", ft_printf("|% +06.1u|\t", u),	printf("|% +06.1u|\t", u));
//	printf("ft_printf: %d vs %d :printf #11\n", ft_printf("|% +06.2u|\t", u),	printf("|% +06.2u|\t", u));
//	printf("ft_printf: %d vs %d :printf #11\n", ft_printf("|% +06.3u|\t", u),	printf("|% +06.3u|\t", u));
//	printf("ft_printf: %d vs %d :printf #11\n", ft_printf("|% +06.4u|\t", u),	printf("|% +06.4u|\t", u));
//	printf("ft_printf: %d vs %d :printf #11\n", ft_printf("|% +06.5u|\t", u),	printf("|% +06.5u|\t", u));
//	printf("ft_printf: %d vs %d :printf #11\n", ft_printf("|%+ 06.6u|\t", u),	printf("|%+ 06.6u|\t", u));
//	printf("ft_printf: %d vs %d :printf #11\n", ft_printf("|%+ 07.6u|\t", u),	printf("|%+ 07.6u|\t", u));
//	printf("ft_printf: %d vs %d :printf #11\n", ft_printf("|%+ 08.6u|\t", u),	printf("|%+ 08.6u|\t", u));
//	printf("ft_printf: %d vs %d :printf #11\n", ft_printf("|%+ 09.6u|\t", u),	printf("|%+ 09.6u|\t", u));
//	printf("ft_printf: %d vs %d :printf #11\n", ft_printf("|%+ 010.6u|\t", u),	printf("|%+ 010.6u|\t", u));
//	printf("ft_printf: %d vs %d :printf #11\n", ft_printf("|%+ 06.1u|\t", u),	printf("|%+ 06.1u|\t", u));
//	printf("ft_printf: %d vs %d :printf #11\n", ft_printf("|%+ 06.2u|\t", u),	printf("|%+ 06.2u|\t", u));
//	printf("ft_printf: %d vs %d :printf #11\n", ft_printf("|%+ 06.3u|\t", u),	printf("|%+ 06.3u|\t", u));
//	printf("ft_printf: %d vs %d :printf #11\n", ft_printf("|%+ 06.4u|\t", u),	printf("|%+ 06.4u|\t", u));
//	printf("ft_printf: %d vs %d :printf #11\n", ft_printf("|%+ 06.5u|\t", u),	printf("|%+ 06.5u|\t", u));

//	printf("-------------------------------------OCTAL---------------------------------------\n");
//	uint16_t u = 10;
//	//printf("ft_printf: %d vs %d :printf #1\n", ft_printf("|%o|\t", u), printf("|%o|\t", u));
//	printf("ft_printf: %d vs %d :printf #2\n", ft_printf("|%o|\t", u), printf("|%o|\t", u));
//	printf("ft_printf: %d vs %d :printf #3\n", ft_printf("|%1o|\t", u), printf("|%1o|\t", u));
//	printf("ft_printf: %d vs %d :printf #4\n", ft_printf("|%2o|\t", u), printf("|%2o|\t", u));
//	printf("ft_printf: %d vs %d :printf #5\n", ft_printf("|%3o|\t", u), printf("|%3o|\t", u));
//	printf("ft_printf: %d vs %d :printf #6\n", ft_printf("|%4o|\t", u), printf("|%4o|\t", u));
//	printf("ft_printf: %d vs %d :printf #7\n", ft_printf("|%-1o|\t", u), printf("|%-1o|\t", u));
//	printf("ft_printf: %d vs %d :printf #8\n", ft_printf("|%-2o|\t", u), printf("|%-2o|\t", u));
//	printf("ft_printf: %d vs %d :printf #9\n", ft_printf("|%-3o|\t", u), printf("|%-3o|\t", u));
//	printf("ft_printf: %d vs %d :printf #10\n", ft_printf("|%-4o|\t", u), printf("|%-4o|\t", u));
//	printf("ft_printf: %d vs %d :printf #11\n", ft_printf("|%0o|\t", u), printf("|%0o|\t", u));
//	printf("ft_printf: %d vs %d :printf #12\n", ft_printf("|%01o|\t", u), printf("|%01o|\t", u));
//	printf("ft_printf: %d vs %d :printf #13\n", ft_printf("|%02o|\t", u), printf("|%02o|\t", u));
//	printf("ft_printf: %d vs %d :printf #14\n", ft_printf("|%03o|\t", u), printf("|%03o|\t", u));
//	printf("ft_printf: %d vs %d :printf #15\n", ft_printf("|%04o|\t", u), printf("|%04o|\t", u));
//	printf("ft_printf: %d vs %d :printf #16\n", ft_printf("|%+o|\t", u), printf("|%+o|\t", u));
//	printf("ft_printf: %d vs %d :printf #17\n", ft_printf("|%+1o|\t", u), printf("|%+1o|\t", u));
//	printf("ft_printf: %d vs %d :printf #18\n", ft_printf("|%+2o|\t", u), printf("|%+2o|\t", u));
//	printf("ft_printf: %d vs %d :printf #19\n", ft_printf("|%+3o|\t", u), printf("|%+3o|\t", u));
//	printf("ft_printf: %d vs %d :printf #20\n", ft_printf("|%+4o|\t", u), printf("|%+4o|\t", u));
//	printf("ft_printf: %d vs %d :printf #21\n", ft_printf("|%-0o|\t", u), printf("|%-0o|\t", u));
//	printf("ft_printf: %d vs %d :printf #22\n", ft_printf("|%-01o|\t", u), printf("|%-01o|\t", u));
//	printf("ft_printf: %d vs %d :printf #23\n", ft_printf("|%-02o|\t", u), printf("|%-02o|\t", u));
//	printf("ft_printf: %d vs %d :printf #24\n", ft_printf("|%-03o|\t", u), printf("|%-03o|\t", u));
//	printf("ft_printf: %d vs %d :printf #25\n", ft_printf("|%-04o|\t", u), printf("|%-04o|\t", u));
//	printf("ft_printf: %d vs %d :printf #26\n", ft_printf("|%.o|\t", u), printf("|%.o|\t", u));
//	printf("ft_printf: %d vs %d :printf #27\n", ft_printf("|%.1o|\t", u), printf("|%.1o|\t", u));
//	printf("ft_printf: %d vs %d :printf #28\n", ft_printf("|%.2o|\t", u), printf("|%.2o|\t", u));
//	printf("ft_printf: %d vs %d :printf #29\n", ft_printf("|%.3o|\t", u), printf("|%.3o|\t", u));
//	printf("ft_printf: %d vs %d :printf #30\n", ft_printf("|%.4o|\t", u), printf("|%.4o|\t", u));
//	printf("ft_printf: %d vs %d :printf #31\n", ft_printf("|%1.o|\t", u), printf("|%1.o|\t", u));
//	printf("ft_printf: %d vs %d :printf #32\n", ft_printf("|%1.1o|\t", u), printf("|%1.1o|\t", u));
//	printf("ft_printf: %d vs %d :printf #33\n", ft_printf("|%2.1o|\t", u), printf("|%2.1o|\t", u));
//	printf("ft_printf: %d vs %d :printf #34\n", ft_printf("|%3.2o|\t", u), printf("|%3.2o|\t", u));
//	printf("ft_printf: %d vs %d :printf #35\n", ft_printf("|%4.3o|\t", u), printf("|%4.3o|\t", u));
//	printf("ft_printf: %d vs %d :printf #36\n", ft_printf("|%5.4o|\t", u), printf("|%5.4o|\t", u));
//	printf("ft_printf: %d vs %d :printf #37\n", ft_printf("|%-1.o|\t", u), printf("|%-1.o|\t", u));
//	printf("ft_printf: %d vs %d :printf #38\n", ft_printf("|%-1.1o|\t", u), printf("|%-1.1o|\t", u));
//	printf("ft_printf: %d vs %d :printf #39\n", ft_printf("|%-2.1o|\t", u), printf("|%-2.1o|\t", u));
//	printf("ft_printf: %d vs %d :printf #40\n", ft_printf("|%-3.1o|\t", u), printf("|%-3.1o|\t", u));
//	printf("ft_printf: %d vs %d :printf #41\n", ft_printf("|%-4.1o|\t", u), printf("|%-4.1o|\t", u));
//	printf("ft_printf: %d vs %d :printf #42\n", ft_printf("|%-5.1o|\t", u), printf("|%-5.1o|\t", u));
//	printf("ft_printf: %d vs %d :printf #43\n", ft_printf("|%-1.2o|\t", u), printf("|%-1.2o|\t", u));
//	printf("ft_printf: %d vs %d :printf #44\n", ft_printf("|%-2.2o|\t", u), printf("|%-2.2o|\t", u));
//	printf("ft_printf: %d vs %d :printf #45\n", ft_printf("|%-3.2o|\t", u), printf("|%-3.2o|\t", u));
//	printf("ft_printf: %d vs %d :printf #46\n", ft_printf("|%-4.2o|\t", u), printf("|%-4.2o|\t", u));
//	printf("ft_printf: %d vs %d :printf #47\n", ft_printf("|%-5.2o|\t", u), printf("|%-5.2o|\t", u));
//	printf("ft_printf: %d vs %d :printf #48\n", ft_printf("|%-1.4o|\t", u), printf("|%-1.4o|\t", u));
//	printf("ft_printf: %d vs %d :printf #49\n", ft_printf("|%-2.4o|\t", u), printf("|%-2.4o|\t", u));
//	printf("ft_printf: %d vs %d :printf #50\n", ft_printf("|%-3.4o|\t", u), printf("|%-3.4o|\t", u));
//	printf("ft_printf: %d vs %d :printf #51\n", ft_printf("|%-4.4o|\t", u), printf("|%-4.4o|\t", u));
//	printf("ft_printf: %d vs %d :printf #52\n", ft_printf("|%-5.4o|\t", u), printf("|%-5.4o|\t", u));
//	printf("ft_printf: %d vs %d :printf #53\n", ft_printf("|%#o|\t", u), printf("|%#o|\t", u));
//	printf("ft_printf: %d vs %d :printf #54\n", ft_printf("|%#1o|\t", u), printf("|%#1o|\t", u));
//	printf("ft_printf: %d vs %d :printf #55\n", ft_printf("|%#2o|\t", u), printf("|%#2o|\t", u));
//	printf("ft_printf: %d vs %d :printf #56\n", ft_printf("|%#3o|\t", u), printf("|%#3o|\t", u));
//	printf("ft_printf: %d vs %d :printf #57\n", ft_printf("|%#4o|\t", u), printf("|%#4o|\t", u));
//	printf("ft_printf: %d vs %d :printf #58\n", ft_printf("|%#.o|\t", u), printf("|%#.o|\t", u));
//	printf("ft_printf: %d vs %d :printf #59\n", ft_printf("|%#1.o|\t", u), printf("|%#1.o|\t", u));
//	printf("ft_printf: %d vs %d :printf #60\n", ft_printf("|%#2.o|\t", u), printf("|%#2.o|\t", u));
//	printf("ft_printf: %d vs %d :printf #61\n", ft_printf("|%#3.o|\t", u), printf("|%#3.o|\t", u));
//	printf("ft_printf: %d vs %d :printf #62\n", ft_printf("|%#4.o|\t", u), printf("|%#4.o|\t", u));
//	printf("ft_printf: %d vs %d :printf #63\n", ft_printf("|%#.1o|\t", u), printf("|%#.1o|\t", u));
//	printf("ft_printf: %d vs %d :printf #64\n", ft_printf("|%#1.1o|\t", u), printf("|%#1.1o|\t", u));
//	printf("ft_printf: %d vs %d :printf #65\n", ft_printf("|%#2.1o|\t", u), printf("|%#2.1o|\t", u));
//	printf("ft_printf: %d vs %d :printf #66\n", ft_printf("|%#3.1o|\t", u), printf("|%#3.1o|\t", u));
//	printf("ft_printf: %d vs %d :printf #67\n", ft_printf("|%#4.1o|\t", u), printf("|%#4.1o|\t", u));
//	printf("ft_printf: %d vs %d :printf #68\n", ft_printf("|%#0o|\t", u), printf("|%#0o|\t", u));
//	printf("ft_printf: %d vs %d :printf #69\n", ft_printf("|%#1.2o|\t", u), printf("|%#1.2o|\t", u));
//	printf("ft_printf: %d vs %d :printf #70\n", ft_printf("|%#2.2o|\t", u), printf("|%#2.2o|\t", u));
//	printf("ft_printf: %d vs %d :printf #71\n", ft_printf("|%#3.2o|\t", u), printf("|%#3.2o|\t", u));
//	printf("ft_printf: %d vs %d :printf #72\n", ft_printf("|%#4.2o|\t", u), printf("|%#4.2o|\t", u));//check me
//	printf("ft_printf: %d vs %d :printf #72\n", ft_printf("|%#5.2o|\t", u), printf("|%#5.2o|\t", u));//check me
//	printf("ft_printf: %d vs %d :printf #73\n", ft_printf("|%#1.3o|\t", u), printf("|%#1.3o|\t", u));
//	printf("ft_printf: %d vs %d :printf #74\n", ft_printf("|%#2.4o|\t", u), printf("|%#2.4o|\t", u));
//	printf("ft_printf: %d vs %d :printf #75\n", ft_printf("|%#3.5o|\t", u), printf("|%#3.5o|\t", u));
//	printf("ft_printf: %d vs %d :printf #76\n", ft_printf("|%#4.6o|\t", u), printf("|%#4.6o|\t", u));
//	printf("ft_printf: %d vs %d :printf #77\n", ft_printf("|%#01o|\t", u), printf("|%#01o|\t", u));
//	printf("ft_printf: %d vs %d :printf #78\n", ft_printf("|%#02o|\t", u), printf("|%#02o|\t", u));
//	printf("ft_printf: %d vs %d :printf #79\n", ft_printf("|%#03o|\t", u), printf("|%#03o|\t", u));
//	printf("ft_printf: %d vs %d :printf #80\n", ft_printf("|%#04o|\t", u), printf("|%#04o|\t", u));
//	printf("ft_printf: %d vs %d :printf #81\n", ft_printf("|%1.o|\t", u), printf("|%1.o|\t", u));
//	printf("ft_printf: %d vs %d :printf #82\n", ft_printf("|%2.o|\t", u), printf("|%2.o|\t", u));
//	printf("ft_printf: %d vs %d :printf #83\n", ft_printf("|%3.o|\t", u), printf("|%3.o|\t", u));
//	printf("ft_printf: %d vs %d :printf #84\n", ft_printf("|%4.o|\t", u), printf("|%4.o|\t", u));
//	printf("ft_printf: %d vs %d :printf #85\n", ft_printf("|%5.o|\t", u), printf("|%5.o|\t", u));
//	printf("ft_printf: %d vs %d :printf #86\n", ft_printf("|%#-2.1o|\t", u), printf("|%#-2.1o|\t", u));
//	printf("ft_printf: %d vs %d :printf #87\n", ft_printf("|%#-2.2o|\t", u), printf("|%#-2.2o|\t", u));
//	printf("ft_printf: %d vs %d :printf #88\n", ft_printf("|%#-2.3o|\t", u), printf("|%#-2.3o|\t", u));
//	printf("ft_printf: %d vs %d :printf #89\n", ft_printf("|%#-3.4o|\t", u), printf("|%#-3.4o|\t", u));
//	printf("ft_printf: %d vs %d :printf #90\n", ft_printf("|%#-4.5o|\t", u), printf("|%#-4.5o|\t", u));
//	printf("ft_printf: %d vs %d :printf #91\n", ft_printf("|%#-5.6o|\t", u), printf("|%#-5.6o|\t", u));
//	printf("ft_printf: %d vs %d :printf #92\n", ft_printf("|%#-1o|\t", u), printf("|%#-1o|\t", u));
//	printf("ft_printf: %d vs %d :printf #93\n", ft_printf("|%#-2o|\t", u), printf("|%#-2o|\t", u));
//	printf("ft_printf: %d vs %d :printf #94\n", ft_printf("|%#-3o|\t", u), printf("|%#-3o|\t", u));
//	printf("ft_printf: %d vs %d :printf #95\n", ft_printf("|%#-4o|\t", u), printf("|%#-4o|\t", u));
//	printf("ft_printf: %d vs %d :printf #96\n", ft_printf("|%#-5o|\t", u), printf("|%#-5o|\t", u));
//	printf("ft_printf: %d vs %d :printf #97\n", ft_printf("|%#-6o|\t", u), printf("|%#-6o|\t", u));
//	printf("ft_printf: %d vs %d :printf #98\n", ft_printf("|%#-6.9o|\t", u), printf("|%#-6.9o|\t", u));
//	printf("ft_printf: %d vs %d :printf #99\n", ft_printf("|%#-6.3o|\t", u), printf("|%#-6.3o|\t", u));//check me
//	printf("ft_printf: %d vs %d :printf #100\n", ft_printf("|%#-2.4o|\t", u), printf("|%#-2.4o|\t", u));
//	printf("ft_printf: %d vs %d :printf #101\n", ft_printf("|%#-7.7o|\t", u), printf("|%#-7.7o|\t", u));

//	printf("-------------------------------------HEXADECIMAL----------------------------------\n");
//	uint16_t u = 0;
//	// for lower x
//	printf("ft_printf: %d vs %d :printf #1\n", ft_printf("|%x|\t", u), printf("|%x|\t", u));
//	printf("ft_printf: %d vs %d :printf #2\n", ft_printf("|%1x|\t", u), printf("|%1x|\t", u));
//	printf("ft_printf: %d vs %d :printf #3\n", ft_printf("|%2x|\t", u), printf("|%2x|\t", u));
//	printf("ft_printf: %d vs %d :printf #4\n", ft_printf("|%3x|\t", u), printf("|%3x|\t", u));
//	printf("ft_printf: %d vs %d :printf #5\n", ft_printf("|%4x|\t", u), printf("|%4x|\t", u));
//	printf("ft_printf: %d vs %d :printf #6\n", ft_printf("|%5x|\t", u), printf("|%5x|\t", u));
//	printf("ft_printf: %d vs %d :printf #7\n", ft_printf("|%6x|\t", u), printf("|%6x|\t", u));
//	printf("ft_printf: %d vs %d :printf #8\n", ft_printf("|%7x|\t", u), printf("|%7x|\t", u));
//	//minus flag
//	printf("ft_printf: %d vs %d :printf #9\n", ft_printf("|%-x|\t", u), printf("|%-x|\t", u));
//	printf("ft_printf: %d vs %d :printf #10\n", ft_printf("|%-1x|\t", u), printf("|%-1x|\t", u));
//	printf("ft_printf: %d vs %d :printf #11\n", ft_printf("|%-2x|\t", u), printf("|%-2x|\t", u));
//	printf("ft_printf: %d vs %d :printf #12\n", ft_printf("|%-3x|\t", u), printf("|%-3x|\t", u));
//	printf("ft_printf: %d vs %d :printf #13\n", ft_printf("|%-4x|\t", u), printf("|%-4x|\t", u));
//	printf("ft_printf: %d vs %d :printf #14\n", ft_printf("|%-5x|\t", u), printf("|%-5x|\t", u));
//	printf("ft_printf: %d vs %d :printf #15\n", ft_printf("|%-6x|\t", u), printf("|%-6x|\t", u));
//	printf("ft_printf: %d vs %d :printf #16\n", ft_printf("|%-7x|\t", u), printf("|%-7x|\t", u));
//	// zero flag
//	printf("ft_printf: %d vs %d :printf #17\n", ft_printf("|%0x|\t", u), printf("|%0x|\t", u));
//	printf("ft_printf: %d vs %d :printf #18\n", ft_printf("|%01x|\t", u), printf("|%01x|\t", u));
//	printf("ft_printf: %d vs %d :printf #19\n", ft_printf("|%02x|\t", u), printf("|%02x|\t", u));
//	printf("ft_printf: %d vs %d :printf #20\n", ft_printf("|%03x|\t", u), printf("|%03x|\t", u));
//	printf("ft_printf: %d vs %d :printf #21\n", ft_printf("|%04x|\t", u), printf("|%04x|\t", u));
//	printf("ft_printf: %d vs %d :printf #22\n", ft_printf("|%05x|\t", u), printf("|%05x|\t", u));
//	printf("ft_printf: %d vs %d :printf #23\n", ft_printf("|%06x|\t", u), printf("|%06x|\t", u));
//	printf("ft_printf: %d vs %d :printf #24\n", ft_printf("|%07x|\t", u), printf("|%07x|\t", u));
//	// basic precision
//	printf("ft_printf: %d vs %d :printf #25\n", ft_printf("|%.x|\t", u), printf("|%.x|\t", u));
//	printf("ft_printf: %d vs %d :printf #26\n", ft_printf("|%.1x|\t", u), printf("|%.1x|\t", u));
//	printf("ft_printf: %d vs %d :printf #27\n", ft_printf("|%.2x|\t", u), printf("|%.2x|\t", u));
//	printf("ft_printf: %d vs %d :printf #28\n", ft_printf("|%.3x|\t", u), printf("|%.3x|\t", u));
//	printf("ft_printf: %d vs %d :printf #29\n", ft_printf("|%.4x|\t", u), printf("|%.4x|\t", u));
//	printf("ft_printf: %d vs %d :printf #30\n", ft_printf("|%.5x|\t", u), printf("|%.5x|\t", u));
//	printf("ft_printf: %d vs %d :printf #31\n", ft_printf("|%.6x|\t", u), printf("|%.6x|\t", u));
//	printf("ft_printf: %d vs %d :printf #32\n", ft_printf("|%.7x|\t", u), printf("|%.7x|\t", u));
//	// width vs precision
//	printf("ft_printf: %d vs %d :printf #33\n", ft_printf("|%1.x|\t", u), printf("|%1.x|\t", u));
//	printf("ft_printf: %d vs %d :printf #34\n", ft_printf("|%1.1x|\t", u), printf("|%1.1x|\t", u));
//	printf("ft_printf: %d vs %d :printf #35\n", ft_printf("|%3.2x|\t", u), printf("|%3.2x|\t", u));
//	printf("ft_printf: %d vs %d :printf #36\n", ft_printf("|%5.3x|\t", u), printf("|%5.3x|\t", u));
//	printf("ft_printf: %d vs %d :printf #37\n", ft_printf("|%9.4x|\t", u), printf("|%9.4x|\t", u));
//	printf("ft_printf: %d vs %d :printf #38\n", ft_printf("|%2.5x|\t", u), printf("|%2.5x|\t", u));
//	printf("ft_printf: %d vs %d :printf #39\n", ft_printf("|%13.6x|\t", u), printf("|%13.6x|\t", u));
//	printf("ft_printf: %d vs %d :printf #40\n", ft_printf("|%3.7x|\t", u), printf("|%3.7x|\t", u));
//	printf("ft_printf: %d vs %d :printf #41\n", ft_printf("|%13.13x|\t", u), printf("|%13.13x|\t", u));
//	printf("ft_printf: %d vs %d :printf #42\n", ft_printf("|%4.4x|\t", u), printf("|%4.4x|\t", u));
//	// minus flag width vs precision	
//	printf("ft_printf: %d vs %d :printf #43\n", ft_printf("|%-1.x|\t", u), printf("|%-1.x|\t", u));
//	printf("ft_printf: %d vs %d :printf #44\n", ft_printf("|%-1.1x|\t", u), printf("|%-1.1x|\t", u));
//	printf("ft_printf: %d vs %d :printf #45\n", ft_printf("|%-3.2x|\t", u), printf("|%-3.2x|\t", u));
//	printf("ft_printf: %d vs %d :printf #46\n", ft_printf("|%-5.3x|\t", u), printf("|%-5.3x|\t", u));
//	printf("ft_printf: %d vs %d :printf #47\n", ft_printf("|%-9.4x|\t", u), printf("|%-9.4x|\t", u));
//	printf("ft_printf: %d vs %d :printf #48\n", ft_printf("|%-2.5x|\t", u), printf("|%-2.5x|\t", u));
//	printf("ft_printf: %d vs %d :printf #49\n", ft_printf("|%-13.6x|\t", u), printf("|%-13.6x|\t", u));
//	printf("ft_printf: %d vs %d :printf #50\n", ft_printf("|%-3.7x|\t", u), printf("|%-3.7x|\t", u));
//	printf("ft_printf: %d vs %d :printf #51\n", ft_printf("|%-13.13x|\t", u), printf("|%-13.13x|\t", u));
//	printf("ft_printf: %d vs %d :printf #52\n", ft_printf("|%-4.4x|\t", u), printf("|%-4.4x|\t", u));
//	// zero flag width vs precision
//	printf("ft_printf: %d vs %d :printf #53\n", ft_printf("|%01.x|\t", u), printf("|%01.x|\t", u));
//	printf("ft_printf: %d vs %d :printf #54\n", ft_printf("|%01.1x|\t", u), printf("|%01.1x|\t", u));
//	printf("ft_printf: %d vs %d :printf #55\n", ft_printf("|%03.2x|\t", u), printf("|%03.2x|\t", u));
//	printf("ft_printf: %d vs %d :printf #56\n", ft_printf("|%05.3x|\t", u), printf("|%05.3x|\t", u));
//	printf("ft_printf: %d vs %d :printf #57\n", ft_printf("|%09.4x|\t", u), printf("|%09.4x|\t", u));
//	printf("ft_printf: %d vs %d :printf #58\n", ft_printf("|%02.5x|\t", u), printf("|%02.5x|\t", u));
//	printf("ft_printf: %d vs %d :printf #59\n", ft_printf("|%013.6x|\t", u), printf("|%013.6x|\t", u));
//	printf("ft_printf: %d vs %d :printf #60\n", ft_printf("|%03.7x|\t", u), printf("|%03.7x|\t", u));
//	printf("ft_printf: %d vs %d :printf #61\n", ft_printf("|%013.13x|\t", u), printf("|%013.13x|\t", u));
//	printf("ft_printf: %d vs %d :printf #62\n", ft_printf("|%04.4x|\t", u), printf("|%04.4x|\t", u));
//	// basic hash
//	printf("ft_printf: %d vs %d :printf #63\n", ft_printf("|%#x|\t", u), printf("|%#x|\t", u));
//	printf("ft_printf: %d vs %d :printf #64\n", ft_printf("|%#1x|\t", u), printf("|%#1x|\t", u));
//	printf("ft_printf: %d vs %d :printf #65\n", ft_printf("|%#2x|\t", u), printf("|%#2x|\t", u));
//	printf("ft_printf: %d vs %d :printf #66\n", ft_printf("|%#3x|\t", u), printf("|%#3x|\t", u));
//	printf("ft_printf: %d vs %d :printf #67\n", ft_printf("|%#4x|\t", u), printf("|%#4x|\t", u));
//	printf("ft_printf: %d vs %d :printf #68\n", ft_printf("|%#5x|\t", u), printf("|%#5x|\t", u));
//	printf("ft_printf: %d vs %d :printf #69\n", ft_printf("|%#6x|\t", u), printf("|%#6x|\t", u));
//	printf("ft_printf: %d vs %d :printf #70\n", ft_printf("|%#7x|\t", u), printf("|%#7x|\t", u));
//	// hash and minus
//	printf("ft_printf: %d vs %d :printf #71\n", ft_printf("|%#-x|\t", u), printf("|%#-x|\t", u));
//	printf("ft_printf: %d vs %d :printf #72\n", ft_printf("|%#-1x|\t", u), printf("|%#-1x|\t", u));
//	printf("ft_printf: %d vs %d :printf #73\n", ft_printf("|%#-2x|\t", u), printf("|%#-2x|\t", u));
//	printf("ft_printf: %d vs %d :printf #74\n", ft_printf("|%#-3x|\t", u), printf("|%#-3x|\t", u));
//	printf("ft_printf: %d vs %d :printf #75\n", ft_printf("|%#-4x|\t", u), printf("|%#-4x|\t", u));
//	printf("ft_printf: %d vs %d :printf #76\n", ft_printf("|%#-5x|\t", u), printf("|%#-5x|\t", u));
//	printf("ft_printf: %d vs %d :printf #77\n", ft_printf("|%#-6x|\t", u), printf("|%#-6x|\t", u));
//	printf("ft_printf: %d vs %d :printf #78\n", ft_printf("|%#-7x|\t", u), printf("|%#-7x|\t", u));
//	// zero and hash
//	printf("ft_printf: %d vs %d :printf #79\n", ft_printf("|%#0x|\t", u), printf("|%#0x|\t", u));
//	printf("ft_printf: %d vs %d :printf #80\n", ft_printf("|%#01x|\t", u), printf("|%#01x|\t", u));
//	printf("ft_printf: %d vs %d :printf #81\n", ft_printf("|%#02x|\t", u), printf("|%#02x|\t", u));
//	printf("ft_printf: %d vs %d :printf #82\n", ft_printf("|%#03x|\t", u), printf("|%#03x|\t", u));
//	printf("ft_printf: %d vs %d :printf #83\n", ft_printf("|%#04x|\t", u), printf("|%#04x|\t", u));
//	printf("ft_printf: %d vs %d :printf #84\n", ft_printf("|%#05x|\t", u), printf("|%#05x|\t", u));
//	printf("ft_printf: %d vs %d :printf #85\n", ft_printf("|%#06x|\t", u), printf("|%#06x|\t", u));
//	printf("ft_printf: %d vs %d :printf #86\n", ft_printf("|%#07x|\t", u), printf("|%#07x|\t", u));
//	// hash and basic precision
//	printf("ft_printf: %d vs %d :printf #87\n", ft_printf("|%#.x|\t", u), printf("|%#.x|\t", u));
//	printf("ft_printf: %d vs %d :printf #88\n", ft_printf("|%#.1x|\t", u), printf("|%#.1x|\t", u));
//	printf("ft_printf: %d vs %d :printf #89\n", ft_printf("|%#.2x|\t", u), printf("|%#.2x|\t", u));
//	printf("ft_printf: %d vs %d :printf #90\n", ft_printf("|%#.3x|\t", u), printf("|%#.3x|\t", u));
//	printf("ft_printf: %d vs %d :printf #91\n", ft_printf("|%#.4x|\t", u), printf("|%#.4x|\t", u));
//	printf("ft_printf: %d vs %d :printf #92\n", ft_printf("|%#.5x|\t", u), printf("|%#.5x|\t", u));
//	printf("ft_printf: %d vs %d :printf #93\n", ft_printf("|%#.6x|\t", u), printf("|%#.6x|\t", u));
//	printf("ft_printf: %d vs %d :printf #94\n", ft_printf("|%#.7x|\t", u), printf("|%#.7x|\t", u));
//	// hash width vs precision
//	printf("ft_printf: %d vs %d :printf #95\n", ft_printf("|%#1.x|\t", u), printf("|%#1.x|\t", u));
//	printf("ft_printf: %d vs %d :printf #96\n", ft_printf("|%#1.1x|\t", u), printf("|%#1.1x|\t", u));
//	printf("ft_printf: %d vs %d :printf #97\n", ft_printf("|%#3.2x|\t", u), printf("|%#3.2x|\t", u));
//	printf("ft_printf: %d vs %d :printf #98\n", ft_printf("|%#5.3x|\t", u), printf("|%#5.3x|\t", u));
//	printf("ft_printf: %d vs %d :printf #99\n", ft_printf("|%#9.4x|\t", u), printf("|%#9.4x|\t", u));
//	printf("ft_printf: %d vs %d :printf #100\n", ft_printf("|%#2.5x|\t", u), printf("|%#2.5x|\t", u));
//	printf("ft_printf: %d vs %d :printf #101\n", ft_printf("|%#13.6x|\t", u), printf("|%#13.6x|\t", u));
//	printf("ft_printf: %d vs %d :printf #102\n", ft_printf("|%#3.7x|\t", u), printf("|%#3.7x|\t", u));
//	printf("ft_printf: %d vs %d :printf #103\n", ft_printf("|%#13.13x|\t", u), printf("|%#13.13x|\t", u));
//	printf("ft_printf: %d vs %d :printf #104\n", ft_printf("|%#4.4x|\t", u), printf("|%#4.4x|\t", u));
//	// hash minus width vs precision
//	printf("ft_printf: %d vs %d :printf #105\n", ft_printf("|%#-1.x|\t", u), printf("|%#-1.x|\t", u));
//	printf("ft_printf: %d vs %d :printf #106\n", ft_printf("|%#-1.1x|\t", u), printf("|%#-1.1x|\t", u));
//	printf("ft_printf: %d vs %d :printf #107\n", ft_printf("|%#-3.2x|\t", u), printf("|%#-3.2x|\t", u));
//	printf("ft_printf: %d vs %d :printf #108\n", ft_printf("|%#-5.3x|\t", u), printf("|%#-5.3x|\t", u));
//	printf("ft_printf: %d vs %d :printf #109\n", ft_printf("|%#-9.4x|\t", u), printf("|%#-9.4x|\t", u));
//	printf("ft_printf: %d vs %d :printf #110\n", ft_printf("|%#-2.5x|\t", u), printf("|%#-2.5x|\t", u));
//	printf("ft_printf: %d vs %d :printf #111\n", ft_printf("|%#-13.6x|\t", u), printf("|%#-13.6x|\t", u));
//	printf("ft_printf: %d vs %d :printf #112\n", ft_printf("|%#-3.7x|\t", u), printf("|%#-3.7x|\t", u));
//	printf("ft_printf: %d vs %d :printf #113\n", ft_printf("|%#-13.13x|\t", u), printf("|%#-13.13x|\t", u));
//	printf("ft_printf: %d vs %d :printf #114\n", ft_printf("|%#-4.4x|\t", u), printf("|%#-4.4x|\t", u));
//	// hash zero width vs precision
//	printf("ft_printf: %d vs %d :printf #115\n", ft_printf("|%#01.x|\t", u), printf("|%#01.x|\t", u));//check me
//	printf("ft_printf: %d vs %d :printf #116\n", ft_printf("|%#01.1x|\t", u), printf("|%#01.1x|\t", u));
//	printf("ft_printf: %d vs %d :printf #117\n", ft_printf("|%#03.2x|\t", u), printf("|%#03.2x|\t", u));
//	printf("ft_printf: %d vs %d :printf #118\n", ft_printf("|%#05.3x|\t", u), printf("|%#05.3x|\t", u));
//	printf("ft_printf: %d vs %d :printf #119\n", ft_printf("|%#09.4x|\t", u), printf("|%#09.4x|\t", u));
//	printf("ft_printf: %d vs %d :printf #120\n", ft_printf("|%#02.5x|\t", u), printf("|%#02.5x|\t", u));
//	printf("ft_printf: %d vs %d :printf #121\n", ft_printf("|%#013.6x|\t", u), printf("|%#013.6x|\t", u));
//	printf("ft_printf: %d vs %d :printf #122\n", ft_printf("|%#03.7x|\t", u), printf("|%#03.7x|\t", u));
//	printf("ft_printf: %d vs %d :printf #123\n", ft_printf("|%#013.13x|\t", u), printf("|%#013.13x|\t", u));
//	printf("ft_printf: %d vs %d :printf #124\n", ft_printf("|%#04.4x|\t", u), printf("|%#04.4x|\t", u));

//	printf("-------------------------------------POINTERS-------------------------------------\n");//let's deal with precision today
//	int p_int_1_pos = 1;
//	int p_int_1_neg = -1;
//	int p_int_0_pos = 0;
//	int p_int_intmax = INT_MAX;
//	int p_int_intmin = INT_MIN;
//	int p_int_10_pos = 10;
//	int p_int_10_neg = -10;
//	int p_int8_max = INT8_MAX;
//	int p_int8_min = INT8_MIN;
//	int p_int16_max = INT16_MAX;
//	int p_int16_min = INT16_MIN;
//	int p_int32_max = INT32_MAX;
//	int p_int32_min = INT32_MIN;
//	long int p_int64_max = INT64_MAX;
//	long int p_int64_min = INT64_MIN;
//	uint8_t p_uint8 = UINT8_MAX;
//	uint16_t p_uint16 = UINT16_MAX;
//	uint32_t p_uint32 = UINT32_MAX;
//	uint64_t p_uint64 = UINT64_MAX;
//	printf("INT = %d\n", p_int_0_pos);
//	// basic width
//	printf("basic width\n");
//	printf("ft_printf: %d vs %d :printf #1\n", ft_printf("|%p|\t", p_int_0_pos), printf("|%p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #2\n", ft_printf("|%1p|\t", p_int_0_pos), printf("|%1p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #3\n", ft_printf("|%2p|\t", p_int_0_pos), printf("|%2p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #4\n", ft_printf("|%3p|\t", p_int_0_pos), printf("|%3p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #5\n", ft_printf("|%4p|\t", p_int_0_pos), printf("|%4p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #6\n", ft_printf("|%5p|\t", p_int_0_pos), printf("|%5p|\t", p_int_0_pos));
//	// basic minus flag
//	puts("basic minus");
//	printf("ft_printf: %d vs %d :printf #7\n", ft_printf("|%-1p|\t", p_int_0_pos), printf("|%-1p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #8\n", ft_printf("|%-2p|\t", p_int_0_pos), printf("|%-2p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #9\n", ft_printf("|%-3p|\t", p_int_0_pos), printf("|%-3p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #10\n", ft_printf("|%-4p|\t", p_int_0_pos), printf("|%-4p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #11\n", ft_printf("|%-5p|\t", p_int_0_pos), printf("|%-5p|\t", p_int_0_pos));
//	// basic zero flag
//	puts("basic zero");
//	printf("ft_printf: %d vs %d :printf #12\n", ft_printf("|%01p|\t", p_int_0_pos), printf("|%01p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #13\n", ft_printf("|%02p|\t", p_int_0_pos), printf("|%02p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #14\n", ft_printf("|%03p|\t", p_int_0_pos), printf("|%03p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #15\n", ft_printf("|%04p|\t", p_int_0_pos), printf("|%04p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #16\n", ft_printf("|%05p|\t", p_int_0_pos), printf("|%05p|\t", p_int_0_pos));
//	// basic minus zero flag
//	puts("basic minus zero");
//	printf("ft_printf: %d vs %d :printf #17\n", ft_printf("|%-01p|\t", p_int_0_pos), printf("|%-01p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #18\n", ft_printf("|%-02p|\t", p_int_0_pos), printf("|%-02p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #19\n", ft_printf("|%-03p|\t", p_int_0_pos), printf("|%-03p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #20\n", ft_printf("|%-04p|\t", p_int_0_pos), printf("|%-04p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #21\n", ft_printf("|%-05p|\t", p_int_0_pos), printf("|%-05p|\t", p_int_0_pos));
//	// basic precision
//	puts("basic precision");
//	printf("ft_printf: %d vs %d :printf #22\n", ft_printf("|%.p|\t", p_int_0_pos), printf("|%.p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #23\n", ft_printf("|%.1p|\t", p_int_0_pos), printf("|%.1p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #24\n", ft_printf("|%.2p|\t", p_int_0_pos), printf("|%.2p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #25\n", ft_printf("|%.3p|\t", p_int_0_pos), printf("|%.3p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #26\n", ft_printf("|%.4p|\t", p_int_0_pos), printf("|%.4p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #27\n", ft_printf("|%.5p|\t", p_int_0_pos), printf("|%.5p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #28\n", ft_printf("|%.p|\t", p_int_0_pos), printf("|%.p|\t", p_int_0_pos));
//	// width = precision
//	puts("width = precision");
//	printf("ft_printf: %d vs %d :printf #29\n", ft_printf("|%1.1p|\t", p_int_0_pos), printf("|%1.1p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #30\n", ft_printf("|%2.2p|\t", p_int_0_pos), printf("|%2.2p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #31\n", ft_printf("|%3.3p|\t", p_int_0_pos), printf("|%3.3p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #32\n", ft_printf("|%4.4p|\t", p_int_0_pos), printf("|%4.4p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #33\n", ft_printf("|%5.5p|\t", p_int_0_pos), printf("|%5.5p|\t", p_int_0_pos));
//	// width < precision (by 1)
//	puts("width < precision (by 1)");
//	printf("ft_printf: %d vs %d :printf #34\n", ft_printf("|%1.2p|\t", p_int_0_pos), printf("|%1.2p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #35\n", ft_printf("|%2.3p|\t", p_int_0_pos), printf("|%2.3p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #36\n", ft_printf("|%3.4p|\t", p_int_0_pos), printf("|%3.4p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #37\n", ft_printf("|%4.5p|\t", p_int_0_pos), printf("|%4.5p|\t", p_int_0_pos));
//	// width < precision (by 2)
//	puts("width < precision (by 2)");
//	printf("ft_printf: %d vs %d :printf #38\n", ft_printf("|%1.3p|\t", p_int_0_pos), printf("|%1.3p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #39\n", ft_printf("|%2.4p|\t", p_int_0_pos), printf("|%2.4p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #40\n", ft_printf("|%3.5p|\t", p_int_0_pos), printf("|%3.5p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #41\n", ft_printf("|%4.6p|\t", p_int_0_pos), printf("|%4.6p|\t", p_int_0_pos));
//	// width < precision (by 5)
//	puts("width < precision (by 5)");
//	printf("ft_printf: %d vs %d :printf #42\n", ft_printf("|%1.6p|\t", p_int_0_pos), printf("|%1.6p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #43\n", ft_printf("|%2.7p|\t", p_int_0_pos), printf("|%2.7p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #44\n", ft_printf("|%3.8p|\t", p_int_0_pos), printf("|%3.8p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #45\n", ft_printf("|%4.9p|\t", p_int_0_pos), printf("|%4.9p|\t", p_int_0_pos));
//	// width > precision (by 1)
//	puts("width > precision (by 1)");
//	printf("ft_printf: %d vs %d :printf #46\n", ft_printf("|%2.1p|\t", p_int_0_pos), printf("|%2.1p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #47\n", ft_printf("|%3.2p|\t", p_int_0_pos), printf("|%3.2p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #48\n", ft_printf("|%4.3p|\t", p_int_0_pos), printf("|%4.3p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #49\n", ft_printf("|%5.4p|\t", p_int_0_pos), printf("|%5.4p|\t", p_int_0_pos));
//	// width > precision (by 2)
//	puts("width > precision (by 2)");
//	printf("ft_printf: %d vs %d :printf #50\n", ft_printf("|%3.1p|\t", p_int_0_pos), printf("|%3.1p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #51\n", ft_printf("|%4.2p|\t", p_int_0_pos), printf("|%4.2p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #52\n", ft_printf("|%5.3p|\t", p_int_0_pos), printf("|%5.3p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #53\n", ft_printf("|%6.4p|\t", p_int_0_pos), printf("|%6.4p|\t", p_int_0_pos));
//	// width > precision (by 5)
//	puts("width > precision (by 5)");
//	printf("ft_printf: %d vs %d :printf #54\n", ft_printf("|%6.1p|\t", p_int_0_pos), printf("|%6.1p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #55\n", ft_printf("|%7.2p|\t", p_int_0_pos), printf("|%7.2p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #56\n", ft_printf("|%8.3p|\t", p_int_0_pos), printf("|%8.3p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #57\n", ft_printf("|%9.4p|\t", p_int_0_pos), printf("|%9.4p|\t", p_int_0_pos));
//	// minus flag width = precision
//	puts("minus flag width = precision");
//	printf("ft_printf: %d vs %d :printf #58\n", ft_printf("|%-1.1p|\t", p_int_0_pos), printf("|%-1.1p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #59\n", ft_printf("|%-2.2p|\t", p_int_0_pos), printf("|%-2.2p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #60\n", ft_printf("|%-3.3p|\t", p_int_0_pos), printf("|%-3.3p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #61\n", ft_printf("|%-4.4p|\t", p_int_0_pos), printf("|%-4.4p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #62\n", ft_printf("|%-5.5p|\t", p_int_0_pos), printf("|%-5.5p|\t", p_int_0_pos));
//	// minus flag width < precision (by 1)
//	puts("minus flag width < precision (by 1)");
//	printf("ft_printf: %d vs %d :printf #63\n", ft_printf("|%-1.2p|\t", p_int_0_pos), printf("|%-1.2p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #64\n", ft_printf("|%-2.3p|\t", p_int_0_pos), printf("|%-2.3p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #65\n", ft_printf("|%-3.4p|\t", p_int_0_pos), printf("|%-3.4p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #66\n", ft_printf("|%-4.5p|\t", p_int_0_pos), printf("|%-4.5p|\t", p_int_0_pos));
//	// minus flag width < precision (by 2)
//	puts("minus flag width < precision (by 2)");
//	printf("ft_printf: %d vs %d :printf #67\n", ft_printf("|%-1.3p|\t", p_int_0_pos), printf("|%-1.3p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #68\n", ft_printf("|%-2.4p|\t", p_int_0_pos), printf("|%-2.4p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #69\n", ft_printf("|%-3.5p|\t", p_int_0_pos), printf("|%-3.5p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #70\n", ft_printf("|%-4.6p|\t", p_int_0_pos), printf("|%-4.6p|\t", p_int_0_pos));
//	// minus flag width < precision (by 5)
//	puts("minus flag width < precision (by 5)");
//	printf("ft_printf: %d vs %d :printf #71\n", ft_printf("|%-1.6p|\t", p_int_0_pos), printf("|%-1.6p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #72\n", ft_printf("|%-2.7p|\t", p_int_0_pos), printf("|%-2.7p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #73\n", ft_printf("|%-3.8p|\t", p_int_0_pos), printf("|%-3.8p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #74\n", ft_printf("|%-4.9p|\t", p_int_0_pos), printf("|%-4.9p|\t", p_int_0_pos));
//	// minus flag width > precision (by 1)
//	puts("minus flag width > precision (by 1)");
//	printf("ft_printf: %d vs %d :printf #75\n", ft_printf("|%-2.1p|\t", p_int_0_pos), printf("|%-2.1p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #76\n", ft_printf("|%-3.2p|\t", p_int_0_pos), printf("|%-3.2p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #77\n", ft_printf("|%-4.3p|\t", p_int_0_pos), printf("|%-4.3p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #78\n", ft_printf("|%-5.4p|\t", p_int_0_pos), printf("|%-5.4p|\t", p_int_0_pos));
//	// minus flag width > precision (by 2)
//	puts("minus flag width > precision (by 2)");
//	printf("ft_printf: %d vs %d :printf #79\n", ft_printf("|%-3.1p|\t", p_int_0_pos), printf("|%-3.1p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #80\n", ft_printf("|%-4.2p|\t", p_int_0_pos), printf("|%-4.2p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #81\n", ft_printf("|%-5.3p|\t", p_int_0_pos), printf("|%-5.3p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #82\n", ft_printf("|%-6.4p|\t", p_int_0_pos), printf("|%-6.4p|\t", p_int_0_pos));
//	// minus flag width > precision (by 5)
//	puts("minus flag width > precision (by 5)");
//	printf("ft_printf: %d vs %d :printf #83\n", ft_printf("|%-6.1p|\t", p_int_0_pos), printf("|%-6.1p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #84\n", ft_printf("|%-7.2p|\t", p_int_0_pos), printf("|%-7.2p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #85\n", ft_printf("|%-8.3p|\t", p_int_0_pos), printf("|%-8.3p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #86\n", ft_printf("|%-9.4p|\t", p_int_0_pos), printf("|%-9.4p|\t", p_int_0_pos));
//	// zero flag width = precision
//	puts("zero flag width = precision");
//	printf("ft_printf: %d vs %d :printf #87\n", ft_printf("|%01.1p|\t", p_int_0_pos), printf("|%01.1p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #88\n", ft_printf("|%02.2p|\t", p_int_0_pos), printf("|%02.2p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #89\n", ft_printf("|%03.3p|\t", p_int_0_pos), printf("|%03.3p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #90\n", ft_printf("|%04.4p|\t", p_int_0_pos), printf("|%04.4p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #91\n", ft_printf("|%05.5p|\t", p_int_0_pos), printf("|%05.5p|\t", p_int_0_pos));
//	// zero flag width < precision (by 1)
//	puts("zero flag width < precision (by 1)");
//	printf("ft_printf: %d vs %d :printf #92\n", ft_printf("|%01.2p|\t", p_int_0_pos), printf("|%01.2p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #93\n", ft_printf("|%02.3p|\t", p_int_0_pos), printf("|%02.3p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #94\n", ft_printf("|%03.4p|\t", p_int_0_pos), printf("|%03.4p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #95\n", ft_printf("|%04.5p|\t", p_int_0_pos), printf("|%04.5p|\t", p_int_0_pos));
//	// zero flag width < precision (by 2)
//	puts("zero flag width < precision (by 2)");
//	printf("ft_printf: %d vs %d :printf #96\n", ft_printf("|%01.3p|\t", p_int_0_pos), printf("|%01.3p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #97\n", ft_printf("|%02.4p|\t", p_int_0_pos), printf("|%02.4p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #98\n", ft_printf("|%03.5p|\t", p_int_0_pos), printf("|%03.5p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #99\n", ft_printf("|%04.6p|\t", p_int_0_pos), printf("|%04.6p|\t", p_int_0_pos));
//	// zero flag width < precision (by 5)
//	puts("zero flag width < precision (by 5)");
//	printf("ft_printf: %d vs %d :printf #100\n", ft_printf("|%01.6p|\t", p_int_0_pos), printf("|%01.6p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #101\n", ft_printf("|%02.7p|\t", p_int_0_pos), printf("|%02.7p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #102\n", ft_printf("|%03.8p|\t", p_int_0_pos), printf("|%03.8p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #103\n", ft_printf("|%04.9p|\t", p_int_0_pos), printf("|%04.9p|\t", p_int_0_pos));
//	// zero flag width > precision (by 1)
//	puts("zero flag width > precision (by 1)");
//	printf("ft_printf: %d vs %d :printf #104\n", ft_printf("|%02.1p|\t", p_int_0_pos), printf("|%02.1p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #105\n", ft_printf("|%03.2p|\t", p_int_0_pos), printf("|%03.2p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #106\n", ft_printf("|%04.3p|\t", p_int_0_pos), printf("|%04.3p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #107\n", ft_printf("|%05.4p|\t", p_int_0_pos), printf("|%05.4p|\t", p_int_0_pos));
//	// zero flag width > precision (by 2)
//	puts("zero flag width > precision (by 2)");
//	printf("ft_printf: %d vs %d :printf #108\n", ft_printf("|%03.1p|\t", p_int_0_pos), printf("|%03.1p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #109\n", ft_printf("|%04.2p|\t", p_int_0_pos), printf("|%04.2p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #110\n", ft_printf("|%05.3p|\t", p_int_0_pos), printf("|%05.3p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #111\n", ft_printf("|%06.4p|\t", p_int_0_pos), printf("|%06.4p|\t", p_int_0_pos));
//	// zero flag width > precision (by 5)
//	puts("zero flag width > precision (by 5)");
//	printf("ft_printf: %d vs %d :printf #112\n", ft_printf("|%06.1p|\t", p_int_0_pos), printf("|%06.1p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #113\n", ft_printf("|%07.2p|\t", p_int_0_pos), printf("|%07.2p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #114\n", ft_printf("|%08.3p|\t", p_int_0_pos), printf("|%08.3p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #115\n", ft_printf("|%09.4p|\t", p_int_0_pos), printf("|%09.4p|\t", p_int_0_pos));
//	// minus zero flag width = precision
//	puts("minus zero flag width = precision");
//	printf("ft_printf: %d vs %d :printf #116\n", ft_printf("|%-01.1p|\t", p_int_0_pos), printf("|%-01.1p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #117\n", ft_printf("|%-02.2p|\t", p_int_0_pos), printf("|%-02.2p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #118\n", ft_printf("|%-03.3p|\t", p_int_0_pos), printf("|%-03.3p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #119\n", ft_printf("|%-04.4p|\t", p_int_0_pos), printf("|%-04.4p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #120\n", ft_printf("|%-05.5p|\t", p_int_0_pos), printf("|%-05.5p|\t", p_int_0_pos));
//	// minus zero flag width < precision (by 1)
//	puts("minus zero flag width < precision (by 1)");
//	printf("ft_printf: %d vs %d :printf #121\n", ft_printf("|%-01.2p|\t", p_int_0_pos), printf("|%-01.2p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #122\n", ft_printf("|%-02.3p|\t", p_int_0_pos), printf("|%-02.3p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #123\n", ft_printf("|%-03.4p|\t", p_int_0_pos), printf("|%-03.4p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #124\n", ft_printf("|%-04.5p|\t", p_int_0_pos), printf("|%-04.5p|\t", p_int_0_pos));
//	// minus zero flag width < precision (by 2)
//	puts("minus zero flag width < precision (by 2)");
//	printf("ft_printf: %d vs %d :printf #125\n", ft_printf("|%-01.3p|\t", p_int_0_pos), printf("|%-01.3p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #126\n", ft_printf("|%-02.4p|\t", p_int_0_pos), printf("|%-02.4p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #127\n", ft_printf("|%-03.5p|\t", p_int_0_pos), printf("|%-03.5p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #128\n", ft_printf("|%-04.6p|\t", p_int_0_pos), printf("|%-04.6p|\t", p_int_0_pos));
//	// minus zero flag width < precision (by 5)
//	puts("minus zero flag width < precision (by 5)");
//	printf("ft_printf: %d vs %d :printf #129\n", ft_printf("|%-01.6p|\t", p_int_0_pos), printf("|%-01.6p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #130\n", ft_printf("|%-02.7p|\t", p_int_0_pos), printf("|%-02.7p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #131\n", ft_printf("|%-03.8p|\t", p_int_0_pos), printf("|%-03.8p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #132\n", ft_printf("|%-04.9p|\t", p_int_0_pos), printf("|%-04.9p|\t", p_int_0_pos));
//	// minus zero flag width > precision (by 1)
//	puts("minus zero flag width > precision (by 1)");
//	printf("ft_printf: %d vs %d :printf #133\n", ft_printf("|%-02.1p|\t", p_int_0_pos), printf("|%-02.1p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #134\n", ft_printf("|%-03.2p|\t", p_int_0_pos), printf("|%-03.2p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #135\n", ft_printf("|%-04.3p|\t", p_int_0_pos), printf("|%-04.3p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #136\n", ft_printf("|%-05.4p|\t", p_int_0_pos), printf("|%-05.4p|\t", p_int_0_pos));
//	// minus zero flag width > precision (by 2)
//	puts("minus zero flag width > precision (by 2)");
//	printf("ft_printf: %d vs %d :printf #137\n", ft_printf("|%-03.1p|\t", p_int_0_pos), printf("|%-03.1p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #138\n", ft_printf("|%-04.2p|\t", p_int_0_pos), printf("|%-04.2p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #139\n", ft_printf("|%-05.3p|\t", p_int_0_pos), printf("|%-05.3p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #140\n", ft_printf("|%-06.4p|\t", p_int_0_pos), printf("|%-06.4p|\t", p_int_0_pos));
//	// minus zero flag width > precision (by 5)
//	puts("minus zero flag width > precision (by 5)");
//	printf("ft_printf: %d vs %d :printf #141\n", ft_printf("|%-06.1p|\t", p_int_0_pos), printf("|%-06.1p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #142\n", ft_printf("|%-07.2p|\t", p_int_0_pos), printf("|%-07.2p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #143\n", ft_printf("|%-08.3p|\t", p_int_0_pos), printf("|%-08.3p|\t", p_int_0_pos));
//	printf("ft_printf: %d vs %d :printf #144\n", ft_printf("|%-09.4p|\t", p_int_0_pos), printf("|%-09.4p|\t", p_int_0_pos));

//	printf("-------------------------------------FLOATS--------------------------------------\n");
//	double f_pos = 9873.000001;
//	double f_neg = -1.5;
//	ft_printf("%f\n", f_pos);
//	printf("@main_ftprintf: |%###-#0000 33...12..#0+0d|", 256);

//	printf("-------------------------------------SIZE_RELATED---------------------------------\n");
//	size_t t= UINT_MAX;
//	// size_t
//	printf("ft_printf: %d vs %d :printf #1\n",ft_printf("|%zd|\t", t),		printf("|%zd|\t", t));
//	printf("ft_printf: %d vs %d :printf #2\n",ft_printf("|%20zd|\t", t),		printf("|%20zd|\t", t));
//	printf("ft_printf: %d vs %d :printf #3\n",ft_printf("|%.18zd|\t", t),		printf("|%.18zd|\t", t));
//	printf("ft_printf: %d vs %d :printf #4\n",ft_printf("|%19.20zd|\t", t),		printf("|%19.20zd|\t", t));
//	printf("ft_printf: %d vs %d :printf #5\n",ft_printf("|%+zd|\t", t),		printf("|%+zd|\t", t));
//	printf("ft_printf: %d vs %d :printf #6\n",ft_printf("|% zd|\t", t),		printf("|% zd|\t", t));
//	// int_max;
//	intmax_t n = INTMAX_MAX;
//	printf("ft_printf: %d vs %d :printf #1\n",ft_printf("|%35jd|\t", n),		printf("|%35jd|\t", n));
//	printf("ft_printf: %d vs %d :printf #2\n",ft_printf("|%035jd|\t", n),		printf("|%035jd|\t", n));
//	printf("ft_printf: %d vs %d :printf #3\n",ft_printf("|%.20jd|\t", n),		printf("|%.20jd|\t", n));
//	printf("ft_printf: %d vs %d :printf #4\n",ft_printf("|%035.20jd|\t", n),		printf("|%035.20jd|\t", n));
//	printf("ft_printf: %d vs %d :printf #5\n",ft_printf("|%jd|\t", n),		printf("|%jd|\t", n));
//	printf("ft_printf: %d vs %d :printf #6\n",ft_printf("|%.jd|\t", n),		printf("|%.jd|\t", n));
//	// ptrdiff_t
//	ptrdiff_t d = PTRDIFF_MIN;
//	printf("ft_printf: %d vs %d :printf #1\n", ft_printf("|%21td|\t", d),		printf("|%21td|\t", d));
//	printf("ft_printf: %d vs %d :printf #2\n", ft_printf("|%021td|\t", d),		printf("|%021td|\t", d));
//	printf("ft_printf: %d vs %d :printf #3\n", ft_printf("|%.td|\t", d),		printf("|%.td|\t", d));
//	printf("ft_printf: %d vs %d :printf #4\n", ft_printf("|%21.20td|\t", d),		printf("|%21.20td|\t", d));

//	printf("------------------------------------ARG_BONUS-----------------------------------\n");
//	printf("NUMBER RELATED\n");
//	// int
//	printf("ft_printf: %d vs %d :printf #1\n", ft_printf("%3$d, %2$d, %1$d \t", 1, 2, 3), printf("%3$d, %2$d, %1$d \t", 1, 2, 3));
//	printf("ft_printf: %d vs %d :printf #2\n", ft_printf("%2$d, %3$d, %1$d \t", 1, 2, 3), printf("%2$d, %3$d, %1$d \t", 1, 2, 3));
//	printf("ft_printf: %d vs %d :printf #3\n", ft_printf("%1$d, %3$d, %2$d \t", 1, 2, 3), printf("%1$d, %3$d, %2$d \t", 1, 2, 3));
//	printf("ft_printf: %d vs %d :printf #4\n", ft_printf("%3$d, %2$d, %2$d \t", 1, 2, 3), printf("%3$d, %2$d, %2$d \t", 1, 2, 3));
	// float
//	printf("ft_printf: %d vs %d :printf #1\n", ft_printf("%3$f, %2$f, %1$f \t", 1.0, 2.0, 3.0), printf("%3$f, %2$f, %1$f \t", 1.0, 2.0, 3.0));
//	printf("ft_printf: %d vs %d :printf #2\n", ft_printf("%2$f, %3$f, %1$f \t", 1.0, 2.0, 3.0), printf("%2$f, %3$f, %1$f \t", 1.0, 2.0, 3.0));
//	printf("ft_printf: %d vs %d :printf #3\n", ft_printf("%1$f, %3$f, %2$f \t", 1.0, 2.0, 3.0), printf("%1$f, %3$f, %2$f \t", 1.0, 2.0, 3.0));
//	printf("ft_printf: %d vs %d :printf #4\n", ft_printf("%3$f, %2$f, %2$f \t", 1.0, 2.0, 3.0), printf("%3$f, %2$f, %2$f \t", 1.0, 2.0, 3.0));
//	// strings
//	printf("STRING RELATED\n");
//	printf("ft_printf: %d vs %d :printf #1\n", ft_printf("%3$s, %2$s, %1$s \t", "hi", "low", "hello"), printf("%3$s, %2$s, %1$s \t", "hi", "low", "hello"));
//	printf("ft_printf: %d vs %d :printf #2\n", ft_printf("%2$s, %3$s, %1$s \t", "hi", "low", "hello"), printf("%2$s, %3$s, %1$s \t", "hi", "low", "hello"));
//	printf("ft_printf: %d vs %d :printf #3\n", ft_printf("%1$s, %2$s, %3$s \t", "hi", "low", "hello"), printf("%1$s, %2$s, %3$s \t", "hi", "low", "hello"));
//	printf("ft_printf: %d vs %d :printf #4\n", ft_printf("%2$s, %2$s, %1$s \t", "hi", "low", "hello"), printf("%2$s, %2$s, %1$s \t", "hi", "low", "hello"));
//	printf("ft_printf: %d vs %d :printf #5\n", ft_printf("%3$s, %2$s, %3$s \t", "hi", "low", "hello"), printf("%3$s, %2$s, %3$s \t", "hi", "low", "hello"));
//	printf("ft_printf: %d vs %d :printf #6\n", ft_printf("%3$s, %2$s, %1$s \t", "hi", "low", "hello"), printf("%3$s, %2$s, %1$s \t", "hi", "low", "hello"));
//	printf("ft_printf: %d vs %d :printf #7\n", ft_printf("%1$s, %2$s, %1$s \t", "hi", "low", "hello"), printf("%1$s, %2$s, %1$s \t", "hi", "low", "hello"));
//	printf("ft_printf: %d vs %d :printf #8\n", ft_printf("%3$s, %3$s, %3$s \t", "hi", "low", "hello"), printf("%3$s, %3$s, %3$s \t", "hi", "low", "hello"));
//	printf("ft_printf: %d vs %d :printf #9\n", ft_printf("%2$s, %2$s, %1$s \t", "hi", "low", "hello"), printf("%2$s, %2$s, %1$s \t", "hi", "low", "hello"));
//	printf("ft_printf: %d vs %d :printf #10\n", ft_printf("%2$s, %2$s, %3$s \t", "hi", "low", "hello"), printf("%2$s, %2$s, %3$s \t", "hi", "low", "hello"));
//	// int mix string
//	printf("ft_printf: %d vs %d :printf #1\n", ft_printf("%3$d, %2$s, %1$d \t", 1, "hi", 3), printf("%3$d, %2$s, %1$d \t", 1, "hi", 3));
	// float mix string (doesn't work lol)
//	printf("ft_printf: %d vs %d :printf #1\n", ft_printf("%2$s %1$f\t", 1.0, "hi"), printf("%2$s %1$f\t",1.0, "hi"));
	// float int mix (doesn't work lol)
//	printf("ft_printf: %d vs %d :printf #1\n", ft_printf("%1$d %2$f\t", 1, 2.0), printf("%1$d %2$f\t", 1, 2.0));
//	printf("ft_printf: %d vs %d :printf #1\n", ft_printf("%2$f %1$d\t", 1, 2.0), printf("%2$f %1$d\t", 1, 2.0));
//	printf("------------------------------------STAR_BONUS------------------------------------\n");
//	int width = 10;
//	int prec = 5;
//	printf("ft_printf: %d vs %d :printf #1\n", ft_printf("|%*d| \t", width, 123), printf("|%*d| \t", width, 123));
//	printf("ft_printf: %d vs %d :printf #2\n", ft_printf("|%+*d| \t", width, 123), printf("|%+*d| \t", width, 123));
//	printf("ft_printf: %d vs %d :printf #3\n", ft_printf("|%-*d| \t", width, 123), printf("|%-*d| \t", width, 123));
//	printf("ft_printf: %d vs %d :printf #4\n", ft_printf("|%+-*d| \t", width, 123), printf("|%+-*d| \t", width, 123));
//	printf("ft_printf: %d vs %d :printf #5\n", ft_printf("|%0*d| \t", width, 123), printf("|%0*d| \t", width, 123));
//	printf("ft_printf: %d vs %d :printf #6\n", ft_printf("|%+0*d| \t", width, 123), printf("|%+0*d| \t", width, 123));
//	printf("ft_printf: %d vs %d :printf #7\n", ft_printf("|%+-0*d| \t", width, 123), printf("|%+-0*d| \t", width, 123));
//	// string
//	char *s = NULL;
//	printf("ft_printf: %d vs %d :printf #1\n", ft_printf("|%*.*s| \t", width, prec, s), printf("|%*.*s| \t", width, prec, s));
//	printf("ft_printf: %d vs %d :printf #2\n", ft_printf("|%0*.*s| \t", width, prec, s), printf("|%0*.*s| \t", width, prec, s));
//	printf("ft_printf: %d vs %d :printf #3\n", ft_printf("|%-*.*s| \t", width, prec, s), printf("|%-*.*s| \t", width, prec, s));
//	// float
//	double f = 123.003456;
//	printf("ft_printf: %d vs %d :printf #1\n", ft_printf("|%*.*f| \t", width, prec, f), printf("|%*.*f| \t", width, prec, f));
//	printf("ft_printf: %d vs %d :printf #2\n", ft_printf("|%0*.*f| \t", width, prec, f), printf("|%0*.*f| \t", width, prec, f));
//	printf("ft_printf: %d vs %d :printf #3\n", ft_printf("|%-*.*f| \t", width, prec, f), printf("|%-*.*f| \t", width, prec, f));
//	printf("ft_printf: %d vs %d :printf #4\n", ft_printf("|%+*.*f| \t", width, prec, f), printf("|%+*.*f| \t", width, prec, f));
//	printf("ft_printf: %d vs %d :printf #4\n", ft_printf("|% *.*f| \t", width, prec, f), printf("|% *.*f| \t", width, prec, f));


//	printf("-------------------------------------BINARY----------------------------------------\n");
//	uint8_t u = 3;
//	printf("returns: %d #1\n", ft_printf("|%b|\t", u));
//	printf("returns: %d #2\n", ft_printf("|%1b|\t", u));
//	printf("returns: %d #3\n", ft_printf("|%2b|\t", u));
//	printf("returns: %d #4\n", ft_printf("|%3b|\t", u));
//	printf("returns: %d #5\n", ft_printf("|%4b|\t", u));
//	printf("returns: %d #6\n", ft_printf("|%5b|\t", u));
//	printf("returns: %d #7\n", ft_printf("|%6b|\t", u));
//	printf("returns: %d #8\n", ft_printf("|%7b|\t", u));
//	printf("returns: %d #9\n", ft_printf("|%-1b|\t", u));
//	printf("returns: %d #10\n", ft_printf("|%-2b|\t", u));
//	printf("returns: %d #11\n", ft_printf("|%-3b|\t", u));
//	printf("returns: %d #12\n", ft_printf("|%-4b|\t", u));
//	printf("returns: %d #13\n", ft_printf("|%-5b|\t", u));
//	printf("returns: %d #14\n", ft_printf("|%-6b|\t", u));
//	printf("returns: %d #15\n", ft_printf("|%-7b|\t", u));
//	printf("returns: %d #16\n", ft_printf("|%.1b|\t", u));
//	printf("returns: %d #17\n", ft_printf("|%.2b|\t", u));
//	printf("returns: %d #18\n", ft_printf("|%.3b|\t", u));
//	printf("returns: %d #19\n", ft_printf("|%.4b|\t", u));
//	printf("returns: %d #20\n", ft_printf("|%.5b|\t", u));
//	printf("returns: %d #21\n", ft_printf("|%.6b|\t", u));
//	printf("returns: %d #22\n", ft_printf("|%3.1b|\t", u));
//	printf("returns: %d #23\n", ft_printf("|%3.2b|\t", u));
//	printf("returns: %d #24\n", ft_printf("|%3.3b|\t", u));
//	printf("returns: %d #25\n", ft_printf("|%3.4b|\t", u));
//	printf("returns: %d #26\n", ft_printf("|%3.5b|\t", u));
//	printf("returns: %d #27\n", ft_printf("|%3.6b|\t", u));
//	printf("returns: %d #28\n", ft_printf("|%4.3b|\t", u));
//	printf("returns: %d #29\n", ft_printf("|%5.3b|\t", u));
//	printf("returns: %d #30\n", ft_printf("|%6.3b|\t", u));
//	printf("returns: %d #31\n", ft_printf("|%-3.2b|\t", u));
//	printf("returns: %d #32\n", ft_printf("|%-4.2b|\t", u));
//	printf("returns: %d #33\n", ft_printf("|%-5.2b|\t", u));
//	printf("returns: %d #34\n", ft_printf("|%-6.2b|\t", u));
//	printf("returns: %d #35\n", ft_printf("|%-7.2b|\t", u));
//	printf("returns: %d #36\n", ft_printf("|%-8.2b|\t", u));
//	printf("returns: %d #37\n", ft_printf("|%-3.3b|\t", u));
//	printf("returns: %d #38\n", ft_printf("|%-5.4b|\t", u));
//	printf("returns: %d #39\n", ft_printf("|%-7.5b|\t", u));
//	printf("returns: %d #40\n", ft_printf("|%-9.6b|\t", u));
//	printf("returns: %d #41\n", ft_printf("|%-11.7b|\t", u));
//	printf("returns: %d #42\n", ft_printf("|%-13.8b|\t", u));
//	printf("returns: %d #43\n", ft_printf("|%-.6b|\t", u));
//	printf("returns: %d #44\n", ft_printf("|%1.6b|\t", u));
//	printf("returns: %d #45\n", ft_printf("|%2.6b|\t", u));
//	printf("returns: %d #46\n", ft_printf("|%3.6b|\t", u));
//	printf("returns: %d #47\n", ft_printf("|%4.6b|\t", u));
//	printf("returns: %d #48\n", ft_printf("|%5.6b|\t", u));
//	printf("returns: %d #49\n", ft_printf("|%6.6b|\t", u));
//	printf("returns: %d #50\n", ft_printf("|%7.6b|\t", u));
//	printf("returns: %d #51\n", ft_printf("|%8.6b|\t", u));
//	printf("returns: %d #52\n", ft_printf("|%9.6b|\t", u));
//	printf("returns: %d #53\n", ft_printf("|%10.6b|\t", u));
//	printf("returns: %d #54\n", ft_printf("|%11.6b|\t", u));
//	printf("returns: %d #55\n", ft_printf("|%12.6b|\t", u));
	//while(1);	
	return (0);
}
