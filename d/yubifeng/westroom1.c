// /yubifeng/westroom1.c
// Last modified by winder 2003.9.2

inherit ROOM;

void create()
{
	set("short", "�鷿");
	set("long", @long
������ׯ�����鷿�ƿ����ţ��������ı�ͼ�飬��������Ǿ��š�
long );
	set("exits", ([
		"east" : __DIR__"zoulang3",
	]));
	set("no_clean_up", 0);
	set("coor/x", 6100);
	set("coor/y", 5190);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}
