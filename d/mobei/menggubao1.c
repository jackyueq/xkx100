// Room: /d/mobei/menggubao1.c
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
	set("exits", ([ /* sizeof() == 1 */
		"west" : __DIR__"buluo1",
	]));
	set("no_clean_up", 0);

	set("coor/x", -200);
	set("coor/y", 5220);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
