//Room: /d/dali/nongtian.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","ũ��");
	set("long",@LONG
һСƬ��ɽ���µ������￪�ѳ�����ũ�����Ϫ������ֲ��ˮ
����̨������ܴ�̶�������ũҵ������ũҵ��ȴ�������Ǹ�Ů����
�Ӵ�ר˾���ԺͲ��㡣
LONG);
	set("objects", ([
	   __DIR__"npc/nongfu1": 1,
	]));
	set("outdoors", "dalis");
	set("exits",([ /* sizeof() == 1 */
	    "north"      : __DIR__"wuding",
	]));
	set("no_clean_up", 0);
	set("coor/x", -41010);
	set("coor/y", -79020);
	set("coor/z", 0);
	setup();
}

void init()
{
	object me = this_player();
	if(me->query_temp("xuncheng"))
	{
		me->set_temp("dali_xc/nt1",1);
	}
}