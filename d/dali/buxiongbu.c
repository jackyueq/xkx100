//Room: /d/dali/buxiongbu.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","���۲�");
	set("long",@LONG
����������·���ǰ��ĵ�һ֧--Щôͽ���۾ӵĵط����˵ؽ�ƫ
Զ������Ҳ��������һƬ����������ƺ�������ɽ��ˮ�㣬ɣ����
��������һƬСƽԭ����Щũ��˼�ɣ���࣬��˿������񸾶�
�÷�˿֯�顣
LONG);
	set("objects", ([
	   __DIR__"npc/bshangfan": 1,
	]));
	set("outdoors", "dalie");
	set("exits",([ /* sizeof() == 1 */
	    "west"   : __DIR__"banshan",
	    "east"   : __DIR__"yangcanfang",
	    "south"  : __DIR__"xingyunhu",
	    "north"  : __DIR__"nongtian5",
	]));
	set("coor/x", -30960);
	set("coor/y", -70640);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}