// Room: /yangzhou/dongmenqiao.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","С������");
	set("long",@LONG
С����������ʯ���ɣ�����⻬ƽ������˵��ǰ�������������Զ��
�����ĵ��Ŷ�����������̦������ĺ�ˮ��������Ȼ��������������̦��
���������ݡ���վ�����ϣ�����С�ػ������ߵ����ܵ����ܣ�����ż��
�����Ķ�ͯ����Ц��������ܵ��������е�һ�档
LONG );
	set("outdoors", "yangzhouw");

	set("exits", ([
		"west"  : __DIR__"hejiajie",
		"east"  : __DIR__"jiaowai7",
	]));
	set("objects", ([
		"/d/village/npc/boy": random(5),
	]));
	set("coor/x", 30);
	set("coor/y", -50);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}