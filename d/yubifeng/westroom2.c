// /yubifeng/westroom2.c
// Last modified by winder 2003.9.2

inherit ROOM;

void create()
{
	set("short", "���᷿");
	set("long", @long
���᷿ԭ�Ƕ�ׯ�������ҵ����ڣ����ʼ�����һӦ���֮���뱸��
��������ǿ�����	
long );
	set("exits", ([
		"east" : __DIR__"zoulang5",
	]));
	set("no_clean_up", 0);
	set("coor/x", 6100);
	set("coor/y", 5200);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}
