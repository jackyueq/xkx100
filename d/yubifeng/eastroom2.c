// /yubifeng/eastroom2.c
// Last modified by winder 2003.9.2

inherit ROOM;

void create()
{
	set("short", "���᷿");
	set("long", @long
���᷿ԭ�Ƕ�ׯ��������͵����ڣ����ʡ����硢������һӦ���
֮���뱸����������ǿ�����	
long );
	set("exits", ([
		"west" : __DIR__"zoulang6",
	]));
	set("objects", ([
		__DIR__"npc/miaoruolan" : 1,
		__DIR__"npc/qiner" : 1,
	]));
	set("coor/x", 6140);
	set("coor/y", 5200);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}
