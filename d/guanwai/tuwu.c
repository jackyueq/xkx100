// /guanwai/tuwu.c

inherit ROOM;

void create()
{
	set("short", "С����");
	set("long", @LONG
����һ���û����ݳɵ�С�ݣ����ڴ�ɨ�ĺܸɾ������ܵ�ǽ���Ϲ�
���˸��ֹ��ӣ�ǥ�ӣ���ɽ����С���ӵȹ��ߣ������ƺ��ǲɲ����õ�
���ߡ���������Ļ�������һλ������͵����ˣ��������ź��̴���
LONG );
	set("exits", ([
		"north" : __DIR__"xiaoxiang",
	]));
	set("objects", ([
		__DIR__"npc/heersu" : 1,
	]));
	set("coor/x", 6030);
	set("coor/y", 5210);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}