// Room: /d/lingzhou/yushanfang.c

inherit ROOM;

void create()
{
	set("short", "���ŷ�");
	set("long", @LONG
�������ŷ������᷿����λ����������ס�������᷿���ŷ�������
ס�ġ������ǲ񷿡�Ժ�Ӵ�ɨ�ĺܸɾ����м���һ��ˮ����
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
		"west"  : __DIR__"huilang",
		"south" : __DIR__"bingku",
		"north" : __DIR__"chaifang",
	]));
	set("no_clean_up", 0);
	set("resource", ([ /* sizeof() == 1 */
		"water" : 1,
	]));
	set("coor/x", -17955);
	set("coor/y", 32106);
	set("coor/z", 0);

	setup();
	replace_program(ROOM);
}
