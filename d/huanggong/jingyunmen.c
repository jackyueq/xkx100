// Room: /d/huanggong/jingyunmen.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������ͨ�����ⶫ·�Ĵ���. �ⶫ·��̫�ϻʵľ���. ���������
������һ����ͤ, �ֳ��Ͻ��ͤ, ���ϳ��������������һ�����, 
�������ա�
LONG
	);
	set("outdoors", "huanggong");
	set("exits", ([ /* sizeof() == 6 */
		 "northwest" : __DIR__"qianqingmen",
		 "southwest" : __DIR__"baohedian",
		 "south"     : __DIR__"yongxiang4",
		 "east"      : __DIR__"jianting",
	]));
	set("no_clean_up", 0);

	set("coor/x", -190);
	set("coor/y", 5270);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}