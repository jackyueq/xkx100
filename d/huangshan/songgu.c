// Room: /d/huangshan/songgu.c
// Last Modified by winder on Sep. 27 2001
inherit ROOM;
void create()
{
	set("short", "�ɹ���");
	set("long", @LONG
������ʯ�ף���;����ï��������֦�Ϲ�������ݣ�Խ��������
�����ľ��ĸо�����ǰ����վ���Ȼ��ͬ������ʯ�ױ����ɹ��֣�����
һ�������ĵ��ۣ���ǰ�����纣����̶��������ɫ�����������������
����̶�����ء�
LONG
	);
	set("exits", ([ 
		"north"  : __DIR__"feicui",
		"south"  : __DIR__"diezhang",
		"eastup" : __DIR__"caishi",
	]));
	set("outdoors", "huangshan");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
