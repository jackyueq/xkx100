// /kaifeng/yaqi.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�������Ǽ���۹ٴɵ��̵꣬���Ҳ����Щ�黭��Ʒ��������һ�£�
����������ľ�����ϴ�С����Ĵ���������Ǹ����˼��õġ���ִɣ�
����֮�ණ����ֻ�ܴӵ�̯���ˡ�
LONG
	);
	set("objects", ([
		__DIR__"npc/liuzhanggui" : 1,
	]));
	set("exits", ([
		"west" : __DIR__"road3",
	]));

	setup();
	replace_program(ROOM);
}
