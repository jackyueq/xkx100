// Room: /d/wuxi/road6.c
// Winder 2000/02/22 

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
������������ϡ�ٵĹٵ�����Ȼ��������ʲô�˵���������������
Щ���������������߾Ϳ쵽��Ҫ���ˣ�������ͨ����������ȥ��·��
·��ɾ��úܡ�
LONG );
	set("outdoors", "wuxi");
	set("no_clean_up", 0);
	set("exits", ([
		"south"  : __DIR__"road5",
		"north"  : __DIR__"paotai",
	]));
	set("coor/x", 370);
	set("coor/y", -730);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}