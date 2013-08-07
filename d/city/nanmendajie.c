// Room: /yangzhou/nanmendajie.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short", "���Ŵ��");
	set("long", @LONG
���Ŵ�ֿ��ʮ���ɣ���ש�̵أ�������һ���ɿ�һ�������ˮ
�����ֵ��������Ż���������·�����˷����Ҷ��С������ǹٺӣ�Ҳ��
�ݺӣ������������������ͱ��ҡ�������̫ƽ�ţ��ֶ��ǳ���������
�������ڴ˵�Ե�ʣ����˴��ҴҶ�����
LONG );
	set("outdoors", "yangzhouw");

	set("exits", ([
		"west"  : __DIR__"taipingqiao",
		"east"  : __DIR__"hejiajie",
		"south" : __DIR__"nanmen",
		"north" : __DIR__"shilijie7",
	]));
	set("objects", ([
		"/d/village/npc/girl" : random(5),
	]));
	set("coor/x", 10);
	set("coor/y", -50);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}