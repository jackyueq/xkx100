// Room: /d/yueyang/beijie.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ���ֳ��ֿ����ʯ��������ڵش��Ǳ������Ҳ�Ե��徻һ
Щ�������棬��һ��ҩ�̣�����һ����ҩ�죬���顰ͬ���á����֣���
��ܲ����۵����ϡ��ֺš����֡������Ǹ�С�ӻ��̡�
LONG );
	set("outdoors", "yueyang");
	set("no_clean_up", 0);
	set("exits", ([
		"east"  : __DIR__"zahuopu",
		"west"  : __DIR__"yaopu",
		"south" : __DIR__"zhongxin",
		"north" : __DIR__"beimen",
	]));
	set("objects", ([
		__DIR__"npc/xingren" : 1,
		CLASS_D("gaibang")+"/bangzhong" : 1,
	]));
	set("coor/x", -1410);
	set("coor/y", -2260);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
