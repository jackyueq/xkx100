// Room: /d/wuxi/northroad2.c
// Winder 2000/02/22 

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
��ש�ֵ���������С�Ӵӵ��´����е���������߿��Կ���ͨ���
��ı����š������ǵ�����ݣ�����ϲ��ȭ�Ż����д�־���ص�������
��������ȥѧЩ�����ܡ������ǲκ��ã�һ��ŨŨ�ļ��ҩζ������
ʱ�ش�ҩ���ﴫ�������ϱ�ͨ�������ģ��˷ǳ��ضࡣ
LONG );
	set("outdoors", "wuxi");
	set("exits", ([
		"north" : __DIR__"northgate",
		"south" : __DIR__"jinlianqiao",
		"east"  : __DIR__"wuguan",
		"west"  : __DIR__"canhetang",
	]));
	set("objects", ([
			"/d/village/npc/kid" : 1,
	]));
	set("coor/x", 370);
	set("coor/y", -770);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}