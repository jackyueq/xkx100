// /kaifeng/paifang.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "�Ʒ�");
	set("long", @LONG
����һ���ձڣ�����һ����ʯС������ǰ��Զ����һ���Ʒ���ͨ��
�������һ�ߣ�������ԭ���ĵ�ɫ�����Ǹ��ص�ү����ɫ���񣬱�����
��������Ϸ¥��������ǹص���
LONG
	);
	set("outdoors", "kaifeng");
	set("exits", ([
		"north" : __DIR__"xilou",
		"east" : __DIR__"guandi",
		"west" : __DIR__"huiguan",
	]));
	set("objects", ([
		__DIR__"npc/huizhang" : 1,
		__DIR__"npc/pihuoshang" : 1,
	]));

	setup();
	replace_program(ROOM);
}
