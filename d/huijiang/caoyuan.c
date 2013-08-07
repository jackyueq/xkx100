// Room: /d/huijiang/caoyuan.c
// Last Modified by winder on Sep. 12 2001

inherit ROOM;

void create()
{
	set("short", "��ԭ");
	set("long", @LONG
�����Ĳ�ԭ���������ǰ����Ⱥ��ţ��Χ��������ߣ�Զ����ؽ�
�ʴ���ʱ�д�Ƭ���̳�ӿ��ɲ�Ǽ����������أ����Ǹ����ʱ����
�ֵ�����硣
LONG
	);
	set("outdoors", "huijiang");
	set("exits", ([ /* sizeof() == 4 */
		"southup" : __DIR__"xiepo",
		"north" : __DIR__"caoyuan1",
		"west" : __DIR__"caoyuan2",
		"east" : __DIR__"caoyuan3",
	]));
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/huizhushaonv" : 1,
	]));
	set("coor/x", -50050);
	set("coor/y", 9080);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
