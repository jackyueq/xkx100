// Room: /d/huijiang/shulin3.c
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
		"north" : __DIR__"shulin",
		"west" : __DIR__"shulin2",
	]));
	set("no_clean_up", 0);
	set("coor/x", -50040);
	set("coor/y", 9030);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
