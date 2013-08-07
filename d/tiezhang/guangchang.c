// Room: /d/tiezhang/guangchang.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "�㳡");
	set("long", @LONG
ɽ·�е������Ȼ��ÿ���������ǰ������һƬ�ܴ�Ĺ㳡��һ
Щ���ư�ĵ������ش�������䣬�Եú�æµ���ڹ㳡����Χ�кܶ���
ʯ���ķ��ӡ��������������Եøߴ���ΰ������ķ����в�ʱ��ӿ��
������������仹�����Źķ��������
LONG );
	set("exits", ([ /* sizeof() == 4 */
		"west"    : __DIR__"lgfang",
		"east"    : __DIR__"guajia",
		"south"   : __DIR__"shanlu2",
		"northup" : __DIR__"wztang",
	]));
	set("objects", ([ /* sizeof() == 3 */
		__DIR__"npc/huiyi" : 1,
		__DIR__"npc/heiyi" : 2,
	]));
	set("valid_startroom", 1);
	set("no_clean_up", 0);
	set("outdoors", "tiezhang");

	set("coor/x", -2040);
	set("coor/y", -1970);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
	"/clone/board/tiezhang_b"->foo();
}