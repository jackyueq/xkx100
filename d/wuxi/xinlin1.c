// Room: /d/wuxi/xinlin1.c
// Winder 2000/02/22 

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����һƬï�ܵ������֣�һ�߽�������·���ʧ�˷�����������
�ţ����Ȼ���������������ϡ���ˣ������ϱ���ȥ����������ԼԼ��
�����кö��ˣ���ֻ��������Ŀ�����Щ���š�
LONG );
	set("outdoors", "wuxi");
	set("no_clean_up", 0);
	set("exits", ([
		"north" : __DIR__"dayifenduo",
		"south" : __DIR__"eastgate",
		"east"  : __FILE__,
		"west"  : __FILE__,
	]));
	set("coor/x", 400);
	set("coor/y", -750);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

