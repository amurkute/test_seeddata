/*UnicodeSedFixed*/
/*TMCI18N BEGIN HEADER*/
#if !defined( tmBundle_EXISTS )
/* No Initialisation Required */                                               
#include "tmcilib.h"
/*static struct TMBundle tmBundle = {"guaorac.c",NULL,NULL,NULL,NULL};*/
#define tmBundle_EXISTS
#endif
/*TMCI18N END HEADER*/

/* AUDIT_TRAIL_SCB
-- Solution Centre Baseline 
-- PROJECT : BAN74c
-- MODULE  : GUAORAC
-- SOURCE  : enUS
-- TARGET  : I18N
-- DATE    : Mon Mar 19 12:47:08 2007
END AUDIT_TRAIL_SCB */
/* Object: guaorac.c
   Author: John Morgan
 Mod Date: 4/26/94
  Release: General 2.1
*/

/***************************************************/
/*                                                 */
/*       CONFIDENTIAL BUSINESS INFORMATION         */
/*                                                 */
/*      **********************************         */
/*                                                 */
/*  THIS PROGRAM IS PROPRIETARY INFORMATION OF     */
/* SYSTEMS AND COMPUTER TECHNOLOGY CORPORATION     */
/* AND IS NOT TO BE COPIED, REPRODUCED, LENT OR    */
/* DISPOSED OF, NOR USED FOR ANY PURPOSE OTHER     */
/* THAN THAT FOR WHICH IT IS SPECIFICALLY PROVIDED */
/* WITHOUT THE WRITTEN PERMISSION OF SAID COMPANY  */
/*                                                 */
/***************************************************/

/* AUDIT TRAIL: 2.1                                INIT      DATE           */
/*                                                                          */
/* 1. guaorac.c split into guaorac.c and            JWM    04/26/94         */
/*    guaorac2.pc to support separately compiled                            */
/*    Pro*C modules.  Prototypes and macros moved                           */
/*    to guastdf.h.                                                         */
/*                                                                          */
/* AUDIT TRAIL: 2.1.11                             INIT      DATE           */
/*                                                                          */
/* 1. Added cenpivot for century pivot handling.    JWM    09/19/96         */
/*                                                                          */
/* AUDIT TRAIL: 7.2                                INIT      DATE           */
/*                                                                          */
/* 1. Changed method used to include sqlca.h and    JWM    08/23/05         */
/*    oraca.h, due to change in behavior under                              */
/*    under Oracle10g early releases                                        */
/*                                                                          */
/* AUDIT TRAIL: 8.0                                                         */
/* TAM 10/08/2007                                                           */
/* 1. Internationalization unicode conversion                               */
/* AUDIT TRAIL END                                                          */

/* guaorac.c is intended to be included in Pro*C programs via an
   EXEC SQL INCLUDE statement, as it contains Pro*C code and must
   go through the Pro precompiler.  SQL type definitions and global 
   variables used in the ORACLE support functions (guaorac2.pc) are
   included here.  Note that guastdf.h must be included in the 
   compilation unit, and guastdf.o and guaorac2.o must be linked.
*/

#ifndef _GUAORAC_C_

#include "guastdf.h"

/* Variables defined in this file (including sqlca and oraca) should be 
   defined 'extern' unless it is being included in guaorac2.pc.
*/

#ifdef _GUAORAC2_PC_
#define BANNER_INIT ={0} /*TMCI18N MANUAL FIX. CHANGED FROM _TMC("")*/
#define BANNER_STORAGE_CLASS /* */
#else
#define BANNER_INIT /* */
#define BANNER_STORAGE_CLASS extern
#define ORACA_STORAGE_CLASS extern
#define SQLCA_STORAGE_CLASS extern
#endif

/* Include the SQL and ORACLE communications areas, and signal to Pro*C
   that ORACA should be used.
*/

/* Changed the two includes below from EXEC SQL INCLUDE due to behavior
   of 10g precompiler (multiple levels of EXEC SQL INCLUDE not recognized)
*/

#include <oraca.h>
#include <sqlca.h>
EXEC ORACLE OPTION (ORACA=YES);

/* In order to use the Pro*C 1.4 and above STRING external datatype, it
   is necessary to either use an EXEC SQL var_name IS STRING for each
   variable, or to use EXEC SQL TYPE typedef_name IS STRING(length) for a
   typedef.  To simplify the application code, guastdf.h contains typedefs
   for effective string lengths from 1 to 255 (char[2] through char[256]),
   as well as for a NUMSTR (char[27]).  Here we tell Pro*C that each of
   these is an external STRING datatype, so that ORACLE will take care of
   NULL termination in a C fashion.
*/

EXEC SQL BEGIN DECLARE SECTION;
     /*EXEC SQL TYPE NUMSTR IS STRING(27);*/

     /*EXEC SQL TYPE CHAR2 IS STRING(2);*/
     /*EXEC SQL TYPE CHAR3 IS STRING(3);*/
     /*EXEC SQL TYPE CHAR4 IS STRING(4);*/
     /*EXEC SQL TYPE CHAR5 IS STRING(5);*/
     /*EXEC SQL TYPE CHAR6 IS STRING(6);*/
     /*EXEC SQL TYPE CHAR7 IS STRING(7);*/
     /*EXEC SQL TYPE CHAR8 IS STRING(8);*/
     /*EXEC SQL TYPE CHAR9 IS STRING(9);*/
     /*EXEC SQL TYPE CHAR10 IS STRING(10);*/
     /*EXEC SQL TYPE CHAR11 IS STRING(11);*/
     /*EXEC SQL TYPE CHAR12 IS STRING(12);*/
     /*EXEC SQL TYPE CHAR13 IS STRING(13);*/
     /*EXEC SQL TYPE CHAR14 IS STRING(14);*/
     /*EXEC SQL TYPE CHAR15 IS STRING(15);*/
     /*EXEC SQL TYPE CHAR16 IS STRING(16);*/
     /*EXEC SQL TYPE CHAR17 IS STRING(17);*/
     /*EXEC SQL TYPE CHAR18 IS STRING(18);*/
     /*EXEC SQL TYPE CHAR19 IS STRING(19);*/
     /*EXEC SQL TYPE CHAR20 IS STRING(20);*/
     /*EXEC SQL TYPE CHAR21 IS STRING(21);*/
     /*EXEC SQL TYPE CHAR22 IS STRING(22);*/
     /*EXEC SQL TYPE CHAR23 IS STRING(23);*/
     /*EXEC SQL TYPE CHAR24 IS STRING(24);*/
     /*EXEC SQL TYPE CHAR25 IS STRING(25);*/
     /*EXEC SQL TYPE CHAR26 IS STRING(26);*/
     /*EXEC SQL TYPE CHAR27 IS STRING(27);*/
     /*EXEC SQL TYPE CHAR28 IS STRING(28);*/
     /*EXEC SQL TYPE CHAR29 IS STRING(29);*/
     /*EXEC SQL TYPE CHAR30 IS STRING(30);*/
     /*EXEC SQL TYPE CHAR31 IS STRING(31);*/
     /*EXEC SQL TYPE CHAR32 IS STRING(32);*/
     /*EXEC SQL TYPE CHAR33 IS STRING(33);*/
     /*EXEC SQL TYPE CHAR34 IS STRING(34);*/
     /*EXEC SQL TYPE CHAR35 IS STRING(35);*/
     /*EXEC SQL TYPE CHAR36 IS STRING(36);*/
     /*EXEC SQL TYPE CHAR37 IS STRING(37);*/
     /*EXEC SQL TYPE CHAR38 IS STRING(38);*/
     /*EXEC SQL TYPE CHAR39 IS STRING(39);*/
     /*EXEC SQL TYPE CHAR40 IS STRING(40);*/
     /*EXEC SQL TYPE CHAR41 IS STRING(41);*/
     /*EXEC SQL TYPE CHAR42 IS STRING(42);*/
     /*EXEC SQL TYPE CHAR43 IS STRING(43);*/
     /*EXEC SQL TYPE CHAR44 IS STRING(44);*/
     /*EXEC SQL TYPE CHAR45 IS STRING(45);*/
     /*EXEC SQL TYPE CHAR46 IS STRING(46);*/
     /*EXEC SQL TYPE CHAR47 IS STRING(47);*/
     /*EXEC SQL TYPE CHAR48 IS STRING(48);*/
     /*EXEC SQL TYPE CHAR49 IS STRING(49);*/
     /*EXEC SQL TYPE CHAR50 IS STRING(50);*/
     /*EXEC SQL TYPE CHAR51 IS STRING(51);*/
     /*EXEC SQL TYPE CHAR52 IS STRING(52);*/
     /*EXEC SQL TYPE CHAR53 IS STRING(53);*/
     /*EXEC SQL TYPE CHAR54 IS STRING(54);*/
     /*EXEC SQL TYPE CHAR55 IS STRING(55);*/
     /*EXEC SQL TYPE CHAR56 IS STRING(56);*/
     /*EXEC SQL TYPE CHAR57 IS STRING(57);*/
     /*EXEC SQL TYPE CHAR58 IS STRING(58);*/
     /*EXEC SQL TYPE CHAR59 IS STRING(59);*/
     /*EXEC SQL TYPE CHAR60 IS STRING(60);*/
     /*EXEC SQL TYPE CHAR61 IS STRING(61);*/
     /*EXEC SQL TYPE CHAR62 IS STRING(62);*/
     /*EXEC SQL TYPE CHAR63 IS STRING(63);*/
     /*EXEC SQL TYPE CHAR64 IS STRING(64);*/
     /*EXEC SQL TYPE CHAR65 IS STRING(65);*/
     /*EXEC SQL TYPE CHAR66 IS STRING(66);*/
     /*EXEC SQL TYPE CHAR67 IS STRING(67);*/
     /*EXEC SQL TYPE CHAR68 IS STRING(68);*/
     /*EXEC SQL TYPE CHAR69 IS STRING(69);*/
     /*EXEC SQL TYPE CHAR70 IS STRING(70);*/
     /*EXEC SQL TYPE CHAR71 IS STRING(71);*/
     /*EXEC SQL TYPE CHAR72 IS STRING(72);*/
     /*EXEC SQL TYPE CHAR73 IS STRING(73);*/
     /*EXEC SQL TYPE CHAR74 IS STRING(74);*/
     /*EXEC SQL TYPE CHAR75 IS STRING(75);*/
     /*EXEC SQL TYPE CHAR76 IS STRING(76);*/
     /*EXEC SQL TYPE CHAR77 IS STRING(77);*/
     /*EXEC SQL TYPE CHAR78 IS STRING(78);*/
     /*EXEC SQL TYPE CHAR79 IS STRING(79);*/
     /*EXEC SQL TYPE CHAR80 IS STRING(80);*/
     /*EXEC SQL TYPE CHAR81 IS STRING(81);*/
     /*EXEC SQL TYPE CHAR82 IS STRING(82);*/
     /*EXEC SQL TYPE CHAR83 IS STRING(83);*/
     /*EXEC SQL TYPE CHAR84 IS STRING(84);*/
     /*EXEC SQL TYPE CHAR85 IS STRING(85);*/
     /*EXEC SQL TYPE CHAR86 IS STRING(86);*/
     /*EXEC SQL TYPE CHAR87 IS STRING(87);*/
     /*EXEC SQL TYPE CHAR88 IS STRING(88);*/
     /*EXEC SQL TYPE CHAR89 IS STRING(89);*/
     /*EXEC SQL TYPE CHAR90 IS STRING(90);*/
     /*EXEC SQL TYPE CHAR91 IS STRING(91);*/
     /*EXEC SQL TYPE CHAR92 IS STRING(92);*/
     /*EXEC SQL TYPE CHAR93 IS STRING(93);*/
     /*EXEC SQL TYPE CHAR94 IS STRING(94);*/
     /*EXEC SQL TYPE CHAR95 IS STRING(95);*/
     /*EXEC SQL TYPE CHAR96 IS STRING(96);*/
     /*EXEC SQL TYPE CHAR97 IS STRING(97);*/
     /*EXEC SQL TYPE CHAR98 IS STRING(98);*/
     /*EXEC SQL TYPE CHAR99 IS STRING(99);*/
     /*EXEC SQL TYPE CHAR100 IS STRING(100);*/
     /*EXEC SQL TYPE CHAR101 IS STRING(101);*/
     /*EXEC SQL TYPE CHAR102 IS STRING(102);*/
     /*EXEC SQL TYPE CHAR103 IS STRING(103);*/
     /*EXEC SQL TYPE CHAR104 IS STRING(104);*/
     /*EXEC SQL TYPE CHAR105 IS STRING(105);*/
     /*EXEC SQL TYPE CHAR106 IS STRING(106);*/
     /*EXEC SQL TYPE CHAR107 IS STRING(107);*/
     /*EXEC SQL TYPE CHAR108 IS STRING(108);*/
     /*EXEC SQL TYPE CHAR109 IS STRING(109);*/
     /*EXEC SQL TYPE CHAR110 IS STRING(110);*/
     /*EXEC SQL TYPE CHAR111 IS STRING(111);*/
     /*EXEC SQL TYPE CHAR112 IS STRING(112);*/
     /*EXEC SQL TYPE CHAR113 IS STRING(113);*/
     /*EXEC SQL TYPE CHAR114 IS STRING(114);*/
     /*EXEC SQL TYPE CHAR115 IS STRING(115);*/
     /*EXEC SQL TYPE CHAR116 IS STRING(116);*/
     /*EXEC SQL TYPE CHAR117 IS STRING(117);*/
     /*EXEC SQL TYPE CHAR118 IS STRING(118);*/
     /*EXEC SQL TYPE CHAR119 IS STRING(119);*/
     /*EXEC SQL TYPE CHAR120 IS STRING(120);*/
     /*EXEC SQL TYPE CHAR121 IS STRING(121);*/
     /*EXEC SQL TYPE CHAR122 IS STRING(122);*/
     /*EXEC SQL TYPE CHAR123 IS STRING(123);*/
     /*EXEC SQL TYPE CHAR124 IS STRING(124);*/
     /*EXEC SQL TYPE CHAR125 IS STRING(125);*/
     /*EXEC SQL TYPE CHAR126 IS STRING(126);*/
     /*EXEC SQL TYPE CHAR127 IS STRING(127);*/
     /*EXEC SQL TYPE CHAR128 IS STRING(128);*/
     /*EXEC SQL TYPE CHAR129 IS STRING(129);*/
     /*EXEC SQL TYPE CHAR130 IS STRING(130);*/
     /*EXEC SQL TYPE CHAR131 IS STRING(131);*/
     /*EXEC SQL TYPE CHAR132 IS STRING(132);*/
     /*EXEC SQL TYPE CHAR133 IS STRING(133);*/
     /*EXEC SQL TYPE CHAR134 IS STRING(134);*/
     /*EXEC SQL TYPE CHAR135 IS STRING(135);*/
     /*EXEC SQL TYPE CHAR136 IS STRING(136);*/
     /*EXEC SQL TYPE CHAR137 IS STRING(137);*/
     /*EXEC SQL TYPE CHAR138 IS STRING(138);*/
     /*EXEC SQL TYPE CHAR139 IS STRING(139);*/
     /*EXEC SQL TYPE CHAR140 IS STRING(140);*/
     /*EXEC SQL TYPE CHAR141 IS STRING(141);*/
     /*EXEC SQL TYPE CHAR142 IS STRING(142);*/
     /*EXEC SQL TYPE CHAR143 IS STRING(143);*/
     /*EXEC SQL TYPE CHAR144 IS STRING(144);*/
     /*EXEC SQL TYPE CHAR145 IS STRING(145);*/
     /*EXEC SQL TYPE CHAR146 IS STRING(146);*/
     /*EXEC SQL TYPE CHAR147 IS STRING(147);*/
     /*EXEC SQL TYPE CHAR148 IS STRING(148);*/
     /*EXEC SQL TYPE CHAR149 IS STRING(149);*/
     /*EXEC SQL TYPE CHAR150 IS STRING(150);*/
     /*EXEC SQL TYPE CHAR151 IS STRING(151);*/
     /*EXEC SQL TYPE CHAR152 IS STRING(152);*/
     /*EXEC SQL TYPE CHAR153 IS STRING(153);*/
     /*EXEC SQL TYPE CHAR154 IS STRING(154);*/
     /*EXEC SQL TYPE CHAR155 IS STRING(155);*/
     /*EXEC SQL TYPE CHAR156 IS STRING(156);*/
     /*EXEC SQL TYPE CHAR157 IS STRING(157);*/
     /*EXEC SQL TYPE CHAR158 IS STRING(158);*/
     /*EXEC SQL TYPE CHAR159 IS STRING(159);*/
     /*EXEC SQL TYPE CHAR160 IS STRING(160);*/
     /*EXEC SQL TYPE CHAR161 IS STRING(161);*/
     /*EXEC SQL TYPE CHAR162 IS STRING(162);*/
     /*EXEC SQL TYPE CHAR163 IS STRING(163);*/
     /*EXEC SQL TYPE CHAR164 IS STRING(164);*/
     /*EXEC SQL TYPE CHAR165 IS STRING(165);*/
     /*EXEC SQL TYPE CHAR166 IS STRING(166);*/
     /*EXEC SQL TYPE CHAR167 IS STRING(167);*/
     /*EXEC SQL TYPE CHAR168 IS STRING(168);*/
     /*EXEC SQL TYPE CHAR169 IS STRING(169);*/
     /*EXEC SQL TYPE CHAR170 IS STRING(170);*/
     /*EXEC SQL TYPE CHAR171 IS STRING(171);*/
     /*EXEC SQL TYPE CHAR172 IS STRING(172);*/
     /*EXEC SQL TYPE CHAR173 IS STRING(173);*/
     /*EXEC SQL TYPE CHAR174 IS STRING(174);*/
     /*EXEC SQL TYPE CHAR175 IS STRING(175);*/
     /*EXEC SQL TYPE CHAR176 IS STRING(176);*/
     /*EXEC SQL TYPE CHAR177 IS STRING(177);*/
     /*EXEC SQL TYPE CHAR178 IS STRING(178);*/
     /*EXEC SQL TYPE CHAR179 IS STRING(179);*/
     /*EXEC SQL TYPE CHAR180 IS STRING(180);*/
     /*EXEC SQL TYPE CHAR181 IS STRING(181);*/
     /*EXEC SQL TYPE CHAR182 IS STRING(182);*/
     /*EXEC SQL TYPE CHAR183 IS STRING(183);*/
     /*EXEC SQL TYPE CHAR184 IS STRING(184);*/
     /*EXEC SQL TYPE CHAR185 IS STRING(185);*/
     /*EXEC SQL TYPE CHAR186 IS STRING(186);*/
     /*EXEC SQL TYPE CHAR187 IS STRING(187);*/
     /*EXEC SQL TYPE CHAR188 IS STRING(188);*/
     /*EXEC SQL TYPE CHAR189 IS STRING(189);*/
     /*EXEC SQL TYPE CHAR190 IS STRING(190);*/
     /*EXEC SQL TYPE CHAR191 IS STRING(191);*/
     /*EXEC SQL TYPE CHAR192 IS STRING(192);*/
     /*EXEC SQL TYPE CHAR193 IS STRING(193);*/
     /*EXEC SQL TYPE CHAR194 IS STRING(194);*/
     /*EXEC SQL TYPE CHAR195 IS STRING(195);*/
     /*EXEC SQL TYPE CHAR196 IS STRING(196);*/
     /*EXEC SQL TYPE CHAR197 IS STRING(197);*/
     /*EXEC SQL TYPE CHAR198 IS STRING(198);*/
     /*EXEC SQL TYPE CHAR199 IS STRING(199);*/
     /*EXEC SQL TYPE CHAR200 IS STRING(200);*/
     /*EXEC SQL TYPE CHAR201 IS STRING(201);*/
     /*EXEC SQL TYPE CHAR202 IS STRING(202);*/
     /*EXEC SQL TYPE CHAR203 IS STRING(203);*/
     /*EXEC SQL TYPE CHAR204 IS STRING(204);*/
     /*EXEC SQL TYPE CHAR205 IS STRING(205);*/
     /*EXEC SQL TYPE CHAR206 IS STRING(206);*/
     /*EXEC SQL TYPE CHAR207 IS STRING(207);*/
     /*EXEC SQL TYPE CHAR208 IS STRING(208);*/
     /*EXEC SQL TYPE CHAR209 IS STRING(209);*/
     /*EXEC SQL TYPE CHAR210 IS STRING(210);*/
     /*EXEC SQL TYPE CHAR211 IS STRING(211);*/
     /*EXEC SQL TYPE CHAR212 IS STRING(212);*/
     /*EXEC SQL TYPE CHAR213 IS STRING(213);*/
     /*EXEC SQL TYPE CHAR214 IS STRING(214);*/
     /*EXEC SQL TYPE CHAR215 IS STRING(215);*/
     /*EXEC SQL TYPE CHAR216 IS STRING(216);*/
     /*EXEC SQL TYPE CHAR217 IS STRING(217);*/
     /*EXEC SQL TYPE CHAR218 IS STRING(218);*/
     /*EXEC SQL TYPE CHAR219 IS STRING(219);*/
     /*EXEC SQL TYPE CHAR220 IS STRING(220);*/
     /*EXEC SQL TYPE CHAR221 IS STRING(221);*/
     /*EXEC SQL TYPE CHAR222 IS STRING(222);*/
     /*EXEC SQL TYPE CHAR223 IS STRING(223);*/
     /*EXEC SQL TYPE CHAR224 IS STRING(224);*/
     /*EXEC SQL TYPE CHAR225 IS STRING(225);*/
     /*EXEC SQL TYPE CHAR226 IS STRING(226);*/
     /*EXEC SQL TYPE CHAR227 IS STRING(227);*/
     /*EXEC SQL TYPE CHAR228 IS STRING(228);*/
     /*EXEC SQL TYPE CHAR229 IS STRING(229);*/
     /*EXEC SQL TYPE CHAR230 IS STRING(230);*/
     /*EXEC SQL TYPE CHAR231 IS STRING(231);*/
     /*EXEC SQL TYPE CHAR232 IS STRING(232);*/
     /*EXEC SQL TYPE CHAR233 IS STRING(233);*/
     /*EXEC SQL TYPE CHAR234 IS STRING(234);*/
     /*EXEC SQL TYPE CHAR235 IS STRING(235);*/
     /*EXEC SQL TYPE CHAR236 IS STRING(236);*/
     /*EXEC SQL TYPE CHAR237 IS STRING(237);*/
     /*EXEC SQL TYPE CHAR238 IS STRING(238);*/
     /*EXEC SQL TYPE CHAR239 IS STRING(239);*/
     /*EXEC SQL TYPE CHAR240 IS STRING(240);*/
     /*EXEC SQL TYPE CHAR241 IS STRING(241);*/
     /*EXEC SQL TYPE CHAR242 IS STRING(242);*/
     /*EXEC SQL TYPE CHAR243 IS STRING(243);*/
     /*EXEC SQL TYPE CHAR244 IS STRING(244);*/
     /*EXEC SQL TYPE CHAR245 IS STRING(245);*/
     /*EXEC SQL TYPE CHAR246 IS STRING(246);*/
     /*EXEC SQL TYPE CHAR247 IS STRING(247);*/
     /*EXEC SQL TYPE CHAR248 IS STRING(248);*/
     /*EXEC SQL TYPE CHAR249 IS STRING(249);*/
     /*EXEC SQL TYPE CHAR250 IS STRING(250);*/
     /*EXEC SQL TYPE CHAR251 IS STRING(251);*/
     /*EXEC SQL TYPE CHAR252 IS STRING(252);*/
     /*EXEC SQL TYPE CHAR253 IS STRING(253);*/
     /*EXEC SQL TYPE CHAR254 IS STRING(254);*/
     /*EXEC SQL TYPE CHAR255 IS STRING(255);*/
     /*EXEC SQL TYPE CHAR256 IS STRING(256);*/

     /* DUMMY is intended as a target for SELECT statements whose only
        purpose is to test row existence; early releases of Pro*C 1.4 do
        not allow a null INTO list
     */

     BANNER_STORAGE_CLASS TMCHAR DUMMY[2];

     /* user_pass is used by the login function; it is global to simplify
        value-passing
     */

     BANNER_STORAGE_CLASS TMCHAR user_pass[62] BANNER_INIT;

     /* variables for global institution values */

     BANNER_STORAGE_CLASS int cenpivot;
EXEC SQL END DECLARE SECTION;

#undef BANNER_INIT
#undef BANNER_STORAGE_CLASS

#define _GUAORAC_C_
#endif
