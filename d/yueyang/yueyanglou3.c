// Room: /d/yueyang/yueyanglou1.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "����¥��¥");
	set("long", @LONG
��ͥɽˮ��ο�����ǵ������������Ŀ���Ҳ��������������ꡣһ
������͢����������һ����������������¥ͷʱ�������ɽ����������
ͥ�Ĳ���������������������������ͷһ����ɬ��שʯ����������һ
ֱ���������졣վ�ڴ˴�������Զ����¥�Ҹ��顰���Լ�������˭��ʶ
֮�����Ӿ������������꣬����ʷ���������������������������Σ���
ʩ�룬���䣬����ơ�����ǧ���ǡ�
LONG );
	set("no_clean_up", 0);
	set("exits", ([
		"down"  : __DIR__"yueyanglou2",
	]));
	set("coor/x", -1450);
	set("coor/y", -2260);
	set("coor/z", 40);
	setup();
	replace_program(ROOM);
}
