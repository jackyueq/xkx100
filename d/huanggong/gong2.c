// Room: /d/huanggong/gong2.c

inherit ROOM;

void create()
{
	set("short", "���㹬");
	set("long", @LONG
�����������Ժ. ������һЩ��������, ����Ǻ�����Ů��ס��
�ط�. �����������������ܵ���ν��һ�빬�����ƺ���. �����Ϲ���
һ������Ҷ�:  "ܲ����˳".
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
		"west"  : __DIR__"tinglang1",
		"south" : __DIR__"gong4",
	]));
	set("objects", ([ /* sizeof() == 4 */
		 __DIR__"npc/taohongying": 1,
	]));

	set("coor/x", -210);
	set("coor/y", 5320);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}