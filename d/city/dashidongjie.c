// Room: /yangzhou/dashidongji.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","��ʿ����");
	set("long",@LONG
���ݵ��ֹ������������������ĵ�����ͭ����ĥ�ƣ����ӡˢ����
�Լ��������������������޲����������¡���ʿ���ϼ������ݴ󲿷ֵ�
�ֹ�������һЩ�ֹ���Ʒ�ĵ��̡�
LONG );
	set("outdoors", "yangzhoue");

	set("exits", ([
		"west"  : __DIR__"dashixijie",
		"east"  : __DIR__"dongmen",
		"north" : __DIR__"caiyidongjie",
		"south" : __DIR__"xiangfenpu",
	]));
	set("no_clean_up", 0);
	set("coor/x", 60);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}