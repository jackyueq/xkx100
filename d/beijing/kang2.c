inherit ROOM;

void create()
{
	set("short", "������Ժ");
	set("long", @LONG
����һ���������䳡���м�����ʦ����������������һ��ͺ�����У�
�����ߣ����������������������ͷ������һ������ݸߵ���ʦ�����ֱ�
�������ƺ�Ҳ��һ����书��������һ��СһЩ�����䳡�������Ǻ�Ժ��
�����и������⡣
LONG );
	set("outdoors", "beijing");
	set("exits", ([
		"west" : __DIR__"wuqiku",
		"east" : __DIR__"wuchang",
		"north" : __DIR__"kang3",
		"south" : __DIR__"kang1",
	]));
	set("objects", ([
		__DIR__"npc/shenzhao" : 1,
		__DIR__"npc/qi" : 1,
	]));
	set("coor/x", -180);
	set("coor/y", 4081);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
