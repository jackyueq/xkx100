// Room: /d/huijiang/shulin1.c
// Last Modified by winder on Sep. 12 2001

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���ߵ������ֲ���ï�ܣ�ֻ��ϡ��ļ��ã�Զ����ɽ�ϸ����Ű�ѩ��
��ͬ���ϰ�ɫ���Ʋʡ���������໥ײ���Ķ��������Դ���������Ұ��
����ζ�ӽ���������������������ǳǳ��һ�㡣
LONG );
	set("outdoors", "huijiang");
	set("exits", ([ /* sizeof() == 2 */
		"south" : __DIR__"linzhong",
		"east"  : __DIR__"buluo",
	]));
	set("no_clean_up", 0);
	set("coor/x", -50060);
	set("coor/y", 9040);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
