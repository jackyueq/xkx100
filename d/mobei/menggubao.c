// Room: /d/mobei/menggubao.c
// Last Modified by winder on May. 25 2001

inherit ROOM;

void create()
{
	set("short", "�ɹŰ�");
	set("long", @LONG
�ɹ���������Ϊ��������ס�ľ�����ëձ����������ͨ����Ϊ��
�Ű��������жѷ��˼���������һ���Ǻ��������������׳������ϣ���
���Ǿ����ٲ��õġ�
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/mumin" : 1,
	]));
	set("exits", ([ /* sizeof() == 1 */
		"east" : __DIR__"buluo1",
	]));

	set("coor/x", -220);
	set("coor/y", 5220);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
