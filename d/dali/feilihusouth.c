//Room: /d/dali/feilihusouth.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","�������ϰ�");
	set("long",@LONG
���������Բ����洬��ͷ��������̨�Ĵ������������񷤣�һЩ
���������º����㣬���ʵ��������ڸ�����ϲ�ݡ����ڵȳ���
�����ü�Ǯ��
LONG);
	set("objects", ([
	   __DIR__"npc/yufu": 1,
	]));
	set("outdoors", "dalis");
	set("exits",([ /* sizeof() == 1 */
	    "south"      : __DIR__"hexi",
	]));
	set("coor/x", -39100);
	set("coor/y", -89190);
	set("coor/z", 0);
	setup();
}

void init()
{
	object me = this_player();
	if(me->query_temp("xuncheng"))
	{
		me->set_temp("dali_xc/flh",1);
	}
}