// Room: /beijing/aobai5.c


inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
һ���ţ�һ�������˱Ƕ�����Ѭ����ֱ����ˮ����̨���������̣�
һ���ʷ����ֵļһ����ڳ���,һ����������ʦ��
LONG );
	set("exits", ([
		"south" : __DIR__"aobai3",
	]));
	set("objects", ([
		__DIR__"npc/chushi" : 1,
	]));
	set("coor/x", -210);
	set("coor/y", 4060);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
