// Room: /d/huanggong/leshou.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������̫�ϻʸ�ʫ, ף�ٵĵط�. ����, ��������ס�ڴ�, ������
��ף������ʮ����, �����óｨ�����ľ����˽��ú�԰, �����ߴ���ǧ
����.
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		 "north" : __DIR__"yihexuan",
		 "south" : __DIR__"yangxin2",
	]));
	set("no_clean_up", 0);

	set("coor/x", -190);
	set("coor/y", 5230);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}