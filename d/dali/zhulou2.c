//Room: /d/dali/zhulou2.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","��¥");
	set("long",@LONG
һ���׼��̨����¥������ǽ�ڽ������ӣ���������һ��������
����̨�����ڼ�������¯�����崫ͳϯ�ض�˯�����������޴�����ǽ
���е��죬�����ڳ���ʯ�Ѽ�̨����޼Ҿߡ�
LONG);
	set("objects", ([
	   __DIR__"npc/kid": 1,
	]));
	set("exits",([ /* sizeof() == 1 */
	    "down"   : __DIR__"zhulou1",
	]));
	set("coor/x", -41010);
	set("coor/y", -79000);
	set("coor/z", 10);
	setup();
}

void init()
{
	object me = this_player();
	if(me->query_temp("xuncheng"))
	{
		me->set_temp("dali_xc/zl2",1);
	}
}