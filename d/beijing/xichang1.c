inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
����һ����������ʯ��ֵ���������ͷ���졣������ȥ��������
�ֵ�������ͷ�����߾����찲�š�һ����Ȳ�����ʱ�ӱ��ߵ�ϷԺ������
�ϱ߾��Ǿ����������ġ��ش��á�ҩ�ꡣ
LONG );
        set("outdoors", "beijing");
	set("exits", ([
		"east"      : __DIR__"tian_anm",
		"west"      : __DIR__"xichang2",
		"south"     : __DIR__"huichunt",
		"north"     : __DIR__"xiyuan",
		"northeast" : "/d/beihai/ximen",
	]));
	set("objects", ([
		__DIR__"npc/flowerg": 1,
	]));
	set("coor/x", -210);
	set("coor/y", 4040);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	me->delete_temp("warned");
	me->delete_temp("hastryup");
	return ::valid_leave(me, dir);
}
