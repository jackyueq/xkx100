// Room: /yangzhou/dashixijie.c
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
		"west"  : __DIR__"matou",
		"east"  : __DIR__"dashidongjie",
		"north" : __DIR__"qiqifang",
		"south" : __DIR__"baiyipu",
	]));
	set("no_clean_up", 0);
	set("coor/x", 55);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}