// shanlu1.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
����ɽ·��������ɽ������ϣ�ɽ·����ʯ������ֻ����һ�˵�
�������Ƽ�Ϊ�վ�����Զ����ȥ��Ⱥɽ���ƣ���춽��£�������������
�۵ף���ʱ���˺�����������Ҫ��Хһ������������һƬ�յء�������
��������ɽ���塣
LONG	);
	set("outdoors", "gumu");
	set("exits", ([
		"southdown" : __DIR__"kongdi",
		"northup"   : __DIR__"zhufeng",
	]));
	set("no_clean_up", 0);
	set("coor/x", -3200);
	set("coor/y", 100);
	set("coor/z", 180);
	setup();
	replace_program(ROOM);
}
