// Room: /d/huanggong/dao7.c

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
		"north" : __DIR__"jiao3",
		"south" : __DIR__"dao8",
	]));
	set("no_clean_up", 0);

	set("coor/x", -230);
	set("coor/y", 5280);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}