// /yubifeng/xiaolu3.c
// Last modified by winder 2003.9.2

inherit ROOM;

void create()
{
	set("short", "С·");
	set("long", @LONG
����һ�������������ССɽ���µ�С·��������ϡ�����������
���Űವ�Ļ�ѩ��ż�����������ɹ���ѩ�Ž��Ӷ��¡�ѩ�����в���
��ӡ�������ƺ��Ǹ���Ұ���߹���������������һ����̫�ߵ�Բ�塣
LONG );
	set("exits", ([
		"east"  : __DIR__"xiaolu2",
		"south" : __DIR__"yuanfeng",
	]));
	set("objects", ([
		__DIR__"npc/ping" : 1,
	]));
	set("no_clean_up", 0);
	set("outdoors", "yubifeng");
	set("coor/x", 6100);
	set("coor/y", 5140);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
