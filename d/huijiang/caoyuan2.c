// Room: /d/huijiang/caoyuan2.c
// Last Modified by winder on Sep. 12 2001

inherit ROOM;

void create()
{
	set("short", "��ԭ");
	set("long", @LONG
�������������ݣ��������糿��¶�飬����ͬһ����ɫ�Ĵ�̺��
�㡣��Ⱥ��ţ��������̺�������ŵĵ�㻨�䡣����Ĺ�������Ӷ�
���е�Ƥ�ޣ����Ų�ԭ�ϵ����衣
LONG );
	set("outdoors", "huijiang");
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/sheep" : 2,
	]));
	set("exits", ([ /* sizeof() == 1 */
		"east" : __DIR__"caoyuan",
	]));
	set("coor/x", -50060);
	set("coor/y", 9080);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
