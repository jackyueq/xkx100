// Room: /d/huijiang/caoyuan1.c
// Last Modified by winder on Sep. 12 2001

inherit ROOM;

void create()
{
	set("short", "��ԭ");
	set("long", @LONG
���۵���ݾͲ��ڽ��£����ϸ���Ʈ��������Ĺ��������С����
�Ӷ�Ƥ��������ţ��Զ����ɽɽ���߲����ʣ�һ�ߵĺ�ˮ�ھ����Ĳ�
������ͷ��ӥ���ų���ڿ��л���������
LONG );
	set("outdoors", "huijiang");
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/ox" : 1,
	]));
	set("exits", ([ /* sizeof() == 1 */
		"south" : __DIR__"caoyuan",
		"north" : __DIR__"caoyuan4",
	]));
	set("coor/x", -50050);
	set("coor/y", 9090);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
