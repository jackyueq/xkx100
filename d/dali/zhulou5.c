//Room: /d/dali/zhulou5.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","������");
	set("long",@LONG
�˼�����¥���㣬��һ����Ĵ��ݣ�����һ����̨��ʮ����ʯ
Χ��һȦ����������һ�����ƣ��ϻ汾�������ͼ����Ȧ�����м���
��С�����ƣ�������������������ţ���̨ǰ���Ʒ������ã�ʱ
������ǰ������Ĥ�ݡ�
LONG);
	set("objects", ([
	   __DIR__"npc/jisi": 1,
	]));
	set("exits",([ /* sizeof() == 1 */
	    "down"  : __DIR__"zhulou4",
	]));
	set("coor/x", -38000);
	set("coor/y", -78990);
	set("coor/z", 20);
	setup();
}

void init()
{
	object me = this_player();
	if(me->query_temp("xuncheng"))
	{
		me->set_temp("dali_xc/zl5",1);
	}
}