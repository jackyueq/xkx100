//Room: /d/dali/yujia.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","���");
	set("long",@LONG
���Բ�ר�����ԣ�����������������������һ����ͨ����¥��
�²�ͨ��������Ȧ���޲��������Ĺ��һλ̨�ĸ�Ů����ϸ�ĵ�
"��֯������¥����һ��ľ�ܣ����������ŵ��㣬������ɹ��ɡ�
LONG);
	set("objects", ([
	   __DIR__"npc/funv": 1,
	]));
	set("outdoors", "dalis");
	set("exits",([ /* sizeof() == 1 */
	    "east"  : __DIR__"hexi",
	]));
	set("coor/x", -39110);
	set("coor/y", -89200);
	set("coor/z", 0);
	setup();
}

void init()
{
	object me = this_player();
	if(me->query_temp("xuncheng"))
	{
		me->set_temp("dali_xc/yj",1);
	}
}