//Edited by fandog, 02/16/2000

inherit ROOM;
void create()
{
	set("short", "����");
	set("long", @LONG
���Ǿ��ݳǶ���һ��С�֡���Ȼ����û�����ַ���������ȴҲ����
Щ����������ȥ�Ҵҡ�������һ�¸߸ߵ�Χǽ��������һ����ݡ�
LONG
	);
	set("outdoors", "jiangling");
	set("exits", ([
		"east"  : __DIR__"chaguan",
		"south" : __DIR__"dongmen",
		"north" : __DIR__"dongjie1",
	]));
	set("objects", ([
		__DIR__"npc/langzhong": 1,
	]));

	set("coor/x", -1470);
	set("coor/y", -2030);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}