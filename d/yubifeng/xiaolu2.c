// /yubifeng/xiaolu2.c
// Last modified by winder 2003.9.2

inherit ROOM;

void create()
{
	set("short", "С·");
	set("long", @LONG
����һ�������������ССɽ���µ�С·��������ϡ�����������
���Űವ�Ļ�ѩ��ż�����������ɹ���ѩ�Ž��Ӷ��¡�ѩ�����в���
��ӡ�������ƺ��Ǹ���Ұ���߹���
LONG );
	set("exits", ([
		"west"  : __DIR__"xiaolu3",
		"north" : __DIR__"xiaolu1",
	]));
	set("objects", ([
		"/d/baituo/obj/chai" : 1,
	]));
	set("no_clean_up", 0);
	set("outdoors", "yubifeng");
	set("coor/x", 6110);
	set("coor/y", 5140);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
