// /kaifeng/xuandemen.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�������ǿ���ı����ţ��������������ǻʳ����ڡ���ǽ�����ø�
���ι̡����ߵĲر���������ǧ�ˣ��������ǵ����˹��Ƴ���֮ʱ����
����ɱ������ɱ���ˡ�
LONG);
	set("objects", ([
		__DIR__"npc/guanbing" : 2,
	]));
	set("outdoors", "kaifeng");
	set("exits", ([
		"south" : __DIR__"road6",
		"north" : __DIR__"jiaowai",
	]));

	setup();
	replace_program(ROOM);
}
