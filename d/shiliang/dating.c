// Feb. 6, 1999 by Winder
inherit ROOM;
void create()
{
	set("short", "����");
	set("long", @LONG
�������¼Ҵ�լ��͵Ĵ��������ƻ�ͨ�������ڳ����
�Ǿ��ɣ�����������������һ�˰�ߵĴ��ƿ�����������࣬��
�ܵ�ǽ�Ϲ����������ī�͵��ֻ������������п��ң����顰��
���á��������֡��и������������ڰ����������еغ��Ų裬��
���ڳ�˼��ʲô��
LONG
	);
	set("exits", ([ 
		"south" : __DIR__"yuanzi",
		"northwest" : __DIR__"zoulang1",
		"northeast" : __DIR__"zoulang5",
	]));
	set("objects", ([
		__DIR__"npc/wenfangda" : 1,
		__DIR__"npc/yahuan" : 2,
	]));
	set("coor/x", 1610);
	set("coor/y", -1950);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}