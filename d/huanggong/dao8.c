// Room: /d/huanggong/dao8.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����Ͻ�����Ǽ�Ĺ���. ƽ����һЩ��������ڹ�, ��������·
��. �⹬����ÿ�ն��д�����������Ѳ��, �����ҪС��. �������߸�
�ߵĺ�ǽ, ����Ϊ���������ָ��ֵ�.
LONG
	);
	set("outdoors", "huanggong");
	set("exits", ([ /* sizeof() == 2 */
		"east"  : __DIR__"ciningmen",
		"north" : __DIR__"dao7",
		"south" : __DIR__"xihuamen",
	]));
	set("no_clean_up", 0);

	set("coor/x", -230);
	set("coor/y", 5270);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}