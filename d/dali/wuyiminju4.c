//Room: /d/dali/wuyiminju4.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","�������");
	set("long",@LONG
����һ����ľ����Ƥ��ɵ�������ӡ��˵صĴ�����Ҫ���¸�
��������ʵ�л����ָ������ò�����Ǩ�㣬������ᶼ�ļ�ª��˵��
���ᣬ������˵�������񣬲𡢽��������㡣
LONG);
	set("objects", ([
	   __DIR__"npc/kid": 1,
	]));
	set("exits",([ /* sizeof() == 1 */
	    "north"  : __DIR__"yixibu",
	]));
	set("coor/x", -89990);
	set("coor/y", -70040);
	set("coor/z", 10);
	setup();
}

void init()
{
	object me = this_player();
	if(me->query_temp("xuncheng"))
	{
		me->set_temp("dali_xc/wymj4",1);
	}
}