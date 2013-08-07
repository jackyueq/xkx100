// Room: /d/quanzhou/taoranju.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "��Ȼ���");
	set("long", @LONG
����ר��Ʒ�������۲�Ҷ�ĵ��̣���������������ž����Ŀ�����
֮�С�ǽ����һ��Ŀ��(sign)��
LONG );
	set("outdoors", "quanzhou");
	set("item_desc", ([
		"sign" : "
�豭(Cha bei)                 ����ʮ��ͭ��
�������豭(Guanying chabei)   ����ʮ��ͭ��
�����豭(Longjing chabei)     ����ʮ��ͭ��
���򻨲豭(Moli chabei)       ����ʮ��ͭ��
��Ƭ�豭(Xiangpian chabei)    ����ʮ��ͭ��\n"
	]));
	set("exits", ([
		"south" : __DIR__"xinmenji",
	]));
	set("objects", ([
		__DIR__"npc/tao" : 1,
	]));
	set("coor/x", 1840);
	set("coor/y", -6570);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
