// Room: /d/yanziwu/path4.c
// Date: Jan.28 2000 by Winder

inherit ROOM;

void create()
{
	set("short", "�軨С��");
	set("long", @LONG
����������ɽׯ�е�����С���ϡ�С�����������һ����軨����
�����������ɫ�軨��ʱ�з�ɵ���ϷŪ���䡣������ǰ���и�����
��С¥��
LONG );
	set("outdoors", "mantuo");
	set("no_clean_up", 0);
	set("exits", ([
		"north"  : __DIR__"garden",
		"south"  : __DIR__"path3",
	]));
	set("coor/x", 1230);
	set("coor/y", -1280);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}