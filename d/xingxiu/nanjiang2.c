// /d/xingxiu/nanjiang.c
// Last Modified by winder on Feb. 28 2001

inherit ROOM;

void create()
{
	set("short", "�Ͻ�ɳĮ");
	set("long", @LONG
����Ǻ�嫵���������ɴ�ɳĮ��һ�߽�������·���ʧ�˷���
��е�����ʮ�ֽ��ʣ����ǿ�Щ�뿪�ɡ�
LONG );
	set("outdoors", "xiyu");
	set("exits", ([
		"northeast" : __DIR__"nanjiang",
		"southeast" : __DIR__"nanjiang3",
		"southwest" : __FILE__,
		"northwest" : __FILE__,
		"north"     : __FILE__,
		"south"     : __FILE__,
		"east"      : __FILE__,
		"west"      : "/d/npc/m_weapon/m_room1",
	]));
	set("no_clean_up", 0);
	set("coor/x", -41010);
	set("coor/y", 8990);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	int current_water;

	current_water = me->query("water");
	if (current_water==0)
	{
	}
	if (current_water>0 && current_water<20&& userp(me))
	{
		me->set("water",0);
	}
	if (current_water>20&&userp(me))
	{
		me->set("water",current_water-20);
	}
	if (dir=="east" || dir=="south" || dir=="north") 
		return notify_fail("�����Ǳ���ȥ�������������ɳĮ�еĺ�����¥��\n");
	return ::valid_leave(me, dir);
}

