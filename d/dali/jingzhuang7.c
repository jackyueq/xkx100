//Room: /d/dali/jingzhuang7.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","���߲�");
	set("long",@LONG
�����Ǿ����Ķ�����Բ���ζ���������񷡣��������������
������ʿ�ȡ�
LONG);
	set("exits",([ /* sizeof() == 1 */
	    "down"  : __DIR__"jingzhuang6",
	]));
	set("no_clean_up", 0);
	set("coor/x", -36000);
	set("coor/y", -70400);
	set("coor/z", 60);
	setup();
	replace_program(ROOM);
}