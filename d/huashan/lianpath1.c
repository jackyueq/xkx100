//Roon: lianpath1.c ������С·
//Date: Oct. 2 1997 by Venus

inherit ROOM;

void create()
{
	set("short","������С·");
	set("long",@LONG
С·ͨ�������壬��Χ�������ģ�΢�Ų��������������Ĺȣ����˵�
����
LONG);
	set("outdoors", "huashan");
	set("exits",([ /* sizeof() == 1 */
		"westup"   : __DIR__"lianpath2",
		"northeast": __DIR__"zhenyue",
	]));
	set("objects",([ 
		__DIR__"npc/ying-bailuo" : 1,
	]));
	set("coor/x", -880);
	set("coor/y", 180);
	set("coor/z", 110);
	setup();
	replace_program(ROOM);
}
