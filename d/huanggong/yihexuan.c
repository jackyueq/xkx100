// Room: /d/huanggong/yihexuan.c

inherit ROOM;

void create()
{
	set("short", "�ú���");
	set("long", @LONG
�����Ǭ¡�������鼮������ĵط�, Ҳ��һ���䱦��, ���ж���
��ȫ�������ѹ������鱦����.
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"west"  : __DIR__"yuhuayuan2",
		"south" : __DIR__"leshou",
	]));
	set("no_clean_up", 0);

	set("coor/x", -190);
	set("coor/y", 5240);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}