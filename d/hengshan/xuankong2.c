// Room: /d/hengshan/xuankong2.c
// Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
	set("short", "��������¥");
	set("long", @LONG
�����������µ�����¥��Ҳ���ϱ�ͤ���������ڶ�������ʯѨ����
��Ϊ����¥���ջ��������ȫ���涫�������ϱ�Σ¥���������·ֶϣ�
���Ǽ��ա�
LONG
	);
	set("exits", ([
		"north"   : __DIR__"zhanqiao",
		"southup" : __DIR__"zhandao",
	]));
	set("no_clean_up", 0);
	set("coor/x", 0);
	set("coor/y", 3160);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}

