// Room: /beijing/wangfu1.c

inherit ROOM;

void create()
{
	set("short", "���������");
	set("long", @LONG
������һ����æ�Ľֵ��ϣ���ˮ��������������������˶����ϱ�
�����������Ƕ������֡�������һ�������Ľֵ�����֪Ϊ��ȴʮ�����塣
������һ��Ǯׯ�������������������Ľ���������
LONG );
	set("outdoors", "beijing");
	set("exits", ([
		"east" : __DIR__"qianzhua",
		"south" : __DIR__"dongcha2",
		"west" : __DIR__"aobai1",
		"north" : __DIR__"wangfu2",
	]));
	set("objects", ([
		"/d/huashan/npc/youke" : 2,
	]));
	set("coor/x", -180);
	set("coor/y", 4050);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
