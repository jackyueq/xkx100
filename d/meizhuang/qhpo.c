// /d/meizhuang/qhpo.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;

void create()
{
	set("short", "�滱��");
	set("long", @LONG
��������滱���ˣ��������Ŵ��СС��ǧ��ٹֵĻ������еĻ�
��һֱ���죬�е����������ƣ������������ԼԼ����һ�����������
�������ޣ��������֡�
LONG
	);
	set("outdoors", "meizhuang");
	set("exits", ([ /* sizeof() == 2 */
		"eastup" : __DIR__"xiaodao",
		"north"  : __DIR__"senlin1",
	]));
	set("no_clean_up", 0);

	set("coor/x", 3500);
	set("coor/y", -1440);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
