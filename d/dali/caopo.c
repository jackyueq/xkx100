//Room: /d/dali/wumeng.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","�������");
	set("long",@LONG
һ��Ƭɽ�³�����ݣ����Ƿ���ţ��ĺõط�������������ߣ�
��ճ�����ɫ������ɽ����ľ�Ѿ����٣������϶��ǵͰ���ľ��ݵء�
���ٸ����Ĵ����ڴ˷�����
LONG);
	set("objects",([
	    __DIR__"npc/muyangren": 1,
	    __DIR__"npc/muyangnu": 1,
	]));
	set("outdoors", "dalin");
	set("exits",([ /* sizeof() == 1 */
	    "west"      : __DIR__"wumeng",
	]));
	set("coor/x", -42000);
	set("coor/y", -52000);
	set("coor/z", 30);
	setup();
}

void init()
{
	object me = this_player();
	if(me->query_temp("xuncheng"))
	{
		me->set_temp("dali_xc/cwcp",1);
	}
}