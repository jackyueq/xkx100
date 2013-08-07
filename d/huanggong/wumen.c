// Room: /d/huanggong/wumen.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�������Ͻ��ǵ����ţ��ǻʵ��;��������ܽ��ĵط������ɸߵİ�
��ɫ��ǽ�ϣ�����������¥������׳ơ����¥����̨�������Ǹ�����
¥��������䣬�����ż䣬�ʡ����塱��֡���������Ŷ��������е�
����������¥�����������ų����������������Ľ��ܶ�ʽ������ͤ����
ʮ���������ӣ���������¥��������ᣬ����Ρ�롣
LONG
	);
	set("outdoors", "huanggong");
	set("exits", ([ /* sizeof() == 4 */
		"west"  : __DIR__"dao10",
		"east"  : __DIR__"dao1",
		"south" : __DIR__"dianwai",
		"north" : __DIR__"taihemen",
	]));
	set("objects", ([
		__DIR__"npc/yulin" : 2,
		__DIR__"npc/fuchun" : 1,
	]));

	set("coor/x", -200);
	set("coor/y", 5210);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}