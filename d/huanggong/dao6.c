// Room: /d/huanggong/dao6.c

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
		"west" : __DIR__"jiao3",
		"east" : __DIR__"shenwumen",
	]));
	set("no_clean_up", 0);

	set("coor/x", -220);
	set("coor/y", 5290);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}