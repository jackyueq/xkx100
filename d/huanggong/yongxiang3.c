// Room: /d/huanggong/yongxiang3.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�������������Χ��ͨ��������ɭ�ϣ�����Ī�⣬���������Ĺ�Ů
̫����Ȼ�ܶ࣬����˭Ҳ���Ҵ���һ��������
LONG
	);
	set("outdoors", "huanggong");
	set("exits", ([ /* sizeof() == 3 */
		"north" : __DIR__"yongxiang4",
		"west"  : __DIR__"taihedian",
	]));
	set("no_clean_up", 0);

	set("coor/x", -190);
	set("coor/y", 5250);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}