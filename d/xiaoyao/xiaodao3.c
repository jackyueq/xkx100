// xiaodao3.c
// Modified by Winder June.25 2000

inherit ROOM;

void create()
{
	set("short", "�ּ�С��");
	set("long", @LONG
����һ�����ϵ������ּ�С������;�羰��֮���ģ������������
�ض������԰ٻ����ޡ���������������
LONG );
	set("exits", ([
		"south" : __DIR__"qingcaop",
		"north" : __DIR__"muwu2",
	]));
	set("objects", ([
		CLASS_D("xiaoyao")+"/shiqinglu" : 1,
	]));
	set("outdoors", "xiaoyao");
	set("coor/x", 80);
	set("coor/y", -490);
	set("coor/z", 0);
	setup();
//	replace_program(ROOM);
}
void init()
{
	object me;
	
	me = this_player();
	if (getuid(me)=="melody")
	{
		if (me->query_condition("xx_poison"))
		me->clear_condition("xx_poison");
	}
}