// Room: /d/huijiang/gebi2.c
// Last Modified by winder on Sep. 12 2001

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
���ȵ�����ɹ��ãã�ĸ�ڣ�����Ļ�ɳ��ʼ�����СС����ʯ��
���档ɰʯ֮��ĵ����Ͽ�ʼ������ݣ�ǰ�洫����������ˮ��������
��Զ����ˮԴ�ˡ�
LONG);
	set("outdoors", "huijiang");
	set("exits", ([ /* sizeof() == 2 */
		"west" : __DIR__"xiaoxi",
		"east" : __DIR__"shamo4",
	]));
	set("no_clean_up", 0);
	set("coor/x", -50010);
	set("coor/y", 9000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

