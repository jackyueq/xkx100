// Room: /d/fuzhou/pingshan.c
// Date: May 12, 98  Java

inherit ROOM;

void create()
{
	set("short", "������ɽ");
	set("long", @LONG
��ɽ�ų�Խ��ɽ����ب���ݳǱ���ɽ�»����£�������������ɽ��
����ųǣ������续��
LONG );
	set("exits", ([
		"southdown" : __DIR__"beidajie",
	]));
	set("outdoors", "fuzhou");
	set("no_clean_up", 0);
	set("coor/x", 1840);
	set("coor/y", -6280);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
