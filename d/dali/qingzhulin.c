//Room: /d/dali/qingzhulin.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","������");
	set("long",@LONG
һ��Ƭï�ܵ�������������ɽ�����ӳ�ȥ���˼��������ۣ�����
��أ�����¬¹���̨�ĸ�Ů��ǰ����ժ����Ϊʳ������Ҳ����Щ��
������������Ͳ�ͱ�֯��������¨��
LONG);
	set("objects", ([
	   __DIR__"npc/caisunren": 1,
	]));
	set("outdoors", "dalis");
	set("exits",([ /* sizeof() == 1 */
	    "east"   : __DIR__"wuding",
	]));
	set("coor/x", -41020);
	set("coor/y", -79010);
	set("coor/z", 0);
	setup();
}

void init()
{
	object me = this_player();
	if(me->query_temp("xuncheng"))
	{
		me->set_temp("dali_xc/qzl",1);
	}
}