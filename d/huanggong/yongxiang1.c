// Room: /d/huanggong/yongxiang1.c

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
		"south" : __DIR__"yongxiang2",
		"north" : __DIR__"longzongmen",
		"east"  : __DIR__"baohedian",
	]));
	set("no_clean_up", 0);

	set("coor/x", -210);
	set("coor/y", 5260);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}