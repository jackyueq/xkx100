// Room: /d/huanggong/kunninggong.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
���ǻʺ���޹�. ������ǰ����ϵ�Ǭ�幬, �������Ǭ��, ����
����. ������Ϊ��ذ���. �󹬵Ķ�����Ժ������ʮ������. �����ǻ�
�۴��Ķ���, Ҳ�Ǽ�������������ĵط�.
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
		 "west"  : __DIR__"gong4",
		 "east"  : __DIR__"gong9",
		 "south" : __DIR__"jiaotaidian",
		 "north" : __DIR__"kunningmen",
	]));
	set("objects", ([ /* sizeof() == 4 */
		__DIR__"npc/getong" : 1,
	]));

	set("coor/x", -200);
	set("coor/y", 5310);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}