// Room: /d/huijiang/shulin2.c
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
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/zhanshi" : 2,
	]));
	set("exits", ([ /* sizeof() == 3 */
		"north" : __DIR__"buluo",
		"west"  : __DIR__"linzhong",
		"east"  : __DIR__"shulin3",
	]));
	set("coor/x", -50050);
	set("coor/y", 9030);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
