//Edited by fandog, 01/31/2000

inherit ROOM;

void create ()
{
	set ("short", "����");
	set ("long", @LONG
����һ�����������ȡ������������򸮴��������ߵľ�ͷ�Ǹ�С���á�
LONG);
	set("no_fight", 1);
	set("objects", ([
		__DIR__"npc/qifang" : 1, 
	]));
	set("exits", ([
		"west"  : __DIR__"dating",
		"east"  : __DIR__"ketang",
	]));
  
	set("coor/x", -1488);
	set("coor/y", -2040);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	if (!objectp(present("hu cheng", me)) &&
		dir == "east" &&
		objectp(present("qi fang", environment(me))))
		return notify_fail("�ݷ���ס��˵���ҷ���ж��Դ���������š�\n");

        return ::valid_leave(me, dir);
}