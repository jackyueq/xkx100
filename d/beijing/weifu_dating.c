// /beijing/weifu_dating.c
// Last modified by winder 2003.10.10

inherit ROOM;

void create()
{
	set("short", "Τ������");
	set("long", @LONG
�������¹�������Ĵ������൱�Ŀ����������ܵ�ǽ����������
�������˵��漣���������������������ߣ����ϵ��������Ա߻�վ��һ
���ϸ���һ����ʮ������������ӣ������ӹ�����񣬲�ס�Ŀ��ԡ���
��������Τ��ү���鷿���������߷ֱ��������᷿��
LONG );
	set("exits", ([
		"north" : __DIR__"weifu_shufang",
		"south" : __DIR__"weifu_zoulang2",
		"west" : __DIR__"weifu_fangw",
		"east" : __DIR__"weifu_fange",
	]));
	set("objects", ([
		__DIR__"npc/guixinshu" : 1,
		__DIR__"npc/guierniang" : 1,
		__DIR__"npc/guizhong" : 1,
		__DIR__"npc/liudahong" : 1,
	]));
	set("coor/x", -220);
	set("coor/y", 4130);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

